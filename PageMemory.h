//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_MEMORY_H
#define ASSIGNMENT5_MEMORY_H

#include <vector>
#include "PageMemorySlot.h"

using std::vector;

class PageMemory
{
protected:
    unsigned long sizeInBytes = 0;
    unsigned long pageSizeInBytes = 0;
    unsigned long capacity = 0;
    vector<PageMemorySlot> memory;
public:
    PageMemory(unsigned long sizeInBytes, unsigned long pageSizeInBytes);
};


#endif //ASSIGNMENT5_MEMORY_H
