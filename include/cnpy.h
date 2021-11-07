//Copyright (C) 2011  Carl Rogers
//Released under MIT License
//license available in LICENSE file, or at http://www.opensource.org/licenses/mit-license.php

#ifndef LIBCNPY_H_
#define LIBCNPY_H_

#include<string>
#include<stdexcept>
#include<sstream>
#include<vector>
#include<cstdio>
#include<typeinfo>
#include<iostream>
#include<cassert>
#include<zlib.h>
#include<map>

namespace cnpy {

    struct NpyArray {
        char* data;
        std::vector<unsigned int> shape;
        unsigned int word_size;
        bool fortran_order;
        void destruct() {delete[] data;}
    };
    
    struct npz_t : public std::map<std::string, NpyArray>
    {
        void destruct()
        {
            npz_t::iterator it = this->begin();
            for(; it != this->end(); ++it) (*it).second.destruct();
        }
    };

    char BigEndianTest();
    char map_type(const std::type_info& t);
    template<typename T> std::vector<char> create_npy_header(const T* data, const unsigned int* shape, const unsigned int ndims);
    void parse_npy_header(FILE* fp,unsigned int& word_size, unsigned int*& shape, unsigned int& ndims, bool& fortran_order);
    void parse_zip_footer(FILE* fp, unsigned short& nrecs, unsigned int& global_header_size, unsigned int& global_header_offset);
    npz_t npz_load(std::string fname);
    NpyArray npz_load(std::string fname, std::string varname);
    NpyArray npy_load(std::string fname);

    template<typename T> std::vector<char>& operator+=(std::vector<char>& lhs, const T rhs) {
        //write in little endian
        for(char byte = 0; byte < sizeof(T); byte++) {
            char val = *((char*)&rhs+byte); 
            lhs.push_back(val);
        }
        return lhs;
    }

    template<> std::vector<char>& operator+=(std::vector<char>& lhs, const std::string rhs); 
    template<> std::vector<char>& operator+=(std::vector<char>& lhs, const char* rhs); 


    template<typename T> std::string tostring(T i, int pad = 0, char padval = ' ') {
        std::stringstream s;
        s << i;
        return s.str();
    }

    template<typename T> void npy_save(std::string fname, const T* data, const unsigned int* shape, const unsigned int ndims, std::string mode = "w") {
        FILE* fp = NULL;

        if(mode == "a") fp = fopen(fname.c_str(),"r+b");

        if(fp) {
            //file exists. we need to append to it. read the header, modify the array size
            unsigned int word_size, tmp_dims;
            unsigned int* tmp_shape = 0;
            bool fortran_order;
            parse_npy_header(fp,word_size,tmp_shape,tmp_dims,fortran_order);
            assert(!fortran_order);

            if(word_size != sizeof(T)) {
                std::cout<<"libnpy error: "<<fname<<" has word size "<<word_size<<" but npy_save appending data sized "<<sizeof(T)<<"\n";
                assert( word_size == sizeof(T) );
            }
            if(tmp_dims != ndims) {
                std::cout<<"libnpy error: npy_save attempting to append misdimensioned data to "<<fname<<"\n";
                assert(tmp_dims == ndims);
            }

            for(int i = 1; i < ndims; i++) {
                if(shape[i] != tmp_shape[i]) {
                    std::cout<<"libnpy error: npy_save attempting to append misshaped data to "<<fname<<"\n";
                    assert(shape[i] == tmp_shape[i]);
                }
            }
            tmp_shape[0] += shape[0];

            fseek(fp,0,SEEK_SET);
            std::vector<char> header = create_npy_header(data,tmp_shape,ndims);
            fwrite(&header[0],sizeof(char),header.size(),fp);
            fseek(fp,0,SEEK_END);

            delete[] tmp_shape;
        }
        else {
            fp = fopen(fname.c_str(),"wb");
            std::vector<char> header = create_npy_header(data,shape,ndims);
            fwrite(&header[0],sizeof(char),header.size(),fp);
        }

        unsigned int nels = 1;
        for(int i = 0;i < ndims;i++) nels *= shape[i];

        fwrite(data,sizeof(T),nels,fp);
        fclose(fp);
    }

    template<typename T> void npz_save(std::string zipname, std::string fname, const T* data, const unsigned int* shape, const unsigned int ndims, std::string mode = "w")
    {
        //first, append a .npy to the fname
        fname += ".npy";

        //now, on with the show
        FILE* fp = NULL;
        unsigned short nrecs = 0;
        unsigned int global_header_offset = 0;
        std::vector<char> global_header;

        if(mode == "a") fp = fopen(zipname.c_str(),"r+b");

        if(fp) {
            //zip file exists. we need to add a new npy file to it.
            //first read the footer. this gives us the offset and size of the global header
            //then read and store the global header. 
            //below, we will write the the new data at the start of the global header then append the global header and footer below it
            unsigned int global_header_size;
            parse_zip_footer(fp,nrecs,global_header_size,global_header_offset);
            fseek(fp,global_header_offset,SEEK_SET);
            global_header.resize(global_header_size);
            size_t res = fread(&global_header[0],sizeof(char),global_header_size,fp);
            if(res != global_header_size){
                throw std::runtime_error("npz_save: header read error while adding to existing zip");
            }
            fseek(fp,global_header_offset,SEEK_SET);
        }
        else {
            fp = fopen(zipname.c_str(),"wb");
        }

        std::vector<char> npy_header = create_npy_header(data,shape,ndims);

        unsigned long nels = 1;
        for (int m=0; m<ndims; m++ ) nels *= shape[m];
        int nbytes = nels*sizeof(T) + npy_header.size();

        //get the CRC of the data to be added
        unsigned int crc = crc32(0L,(unsigned char*)&npy_header[0],npy_header.size());
        crc = crc32(crc,(unsigned char*)data,nels*sizeof(T));

        //build the local header
        std::vector<char> local_header;
        local_header += "PK"; //first part of sig
        local_header += (unsigned short) 0x0403; //second part of sig
     