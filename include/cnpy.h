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
    template<typename T> std::vector<cha