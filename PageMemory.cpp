//
// Created by stoffel on 12/1/17.
//

#include "PageMemory.h"


PageMemory::PageMemory(unsigned long sizeInBytes, unsigned long pageSizeInBytes) : sizeInBytes(sizeInBytes),
                                                                                   pageSizeInBytes(pageSizeInBytes)
{
    this->capacity = (sizeInBytes / pageSizeInBytes);
    this->memory.reserve(this->capacity);
}
