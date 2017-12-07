//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_PAGEREPLACEMENTALGORITHM_H
#define ASSIGNMENT5_PAGEREPLACEMENTALGORITHM_H


#include "../PageCache.h"

class Paging
{
protected:
    PageCache cache;
public:
    virtual bool read(int address) = 0;
    virtual bool write(int address) = 0;
};


#endif //ASSIGNMENT5_PAGEREPLACEMENTALGORITHM_H
