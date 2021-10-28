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
        ret