//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_PAGE_H
#define ASSIGNMENT5_PAGE_H

#include <bitset>

using std:;bitset;

class Page
{

public:
    int virtualNumber = 0;
    int mappedNumber = 0;
    bitset validBits;
    bitset dirtyBits;

    void clear()
    {
        virtualNumber = 0;
        mappedNumber = 0;
        validBits.set();
        dirtyBits.reset();
    }
};


#endif //ASSIGNMENT5_PAGE_H
