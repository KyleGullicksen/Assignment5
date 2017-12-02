//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_MEMORY_H
#define ASSIGNMENT5_MEMORY_H

#include <vector>
#include <stack>
#include <unordered_map>
#include "PageMemorySlot.h"
#include "pageReplacementAlgorithms/PageReplacementAlgorithm.h"

using std::vector;
using std::stack;
using std::unordered_map;

class PageMemory
{
protected:
    unsigned long sizeInBytes = 0;
    unsigned long pageSizeInBytes = 0;
    unsigned long capacity = 0;

    vector<PageMemorySlot> memory;

    stack<int> freeSlots;
    stack<int> usedSlots;
    unordered_map<int, int> mapVirtualAddressToVectorIndex;

    PageReplacementAlgorithm * pageReplacementAlgorithm;

public:
    PageMemory(unsigned long sizeInBytes, unsigned long pageSizeInBytes);
    void read(int slotNumber);
    void write(int slotNumber);
    PageMemorySlot & get(int slotNumber);

    PageReplacementAlgorithm *getPageReplacementAlgorithm() const;
    void setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm);
};


#endif //ASSIGNMENT5_MEMORY_H
