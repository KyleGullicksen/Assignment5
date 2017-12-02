//
// Created by stoffel on 12/1/17.
//

#include "PageMemory.h"


PageMemory::PageMemory(unsigned long sizeInBytes, unsigned long pageSizeInBytes) : sizeInBytes(sizeInBytes),
                                                                                   pageSizeInBytes(pageSizeInBytes)
{
    this->capacity = (sizeInBytes / pageSizeInBytes);

    //Mark every index as free
    for (int index = 0; index < this->capacity; ++index) {
        freeSlots.push(index);
    }
}

void PageMemory::read(int slotNumber)
{
    if (slotNumber < 0 || slotNumber >= capacity)
        return;

    PageMemorySlot & slot = this->get(slotNumber);
    slot.readCount++;
}

void PageMemory::write(int slotNumber) {
    if (slotNumber < 0 || slotNumber >= capacity)
        return;

    PageMemorySlot & slot = this->get(slotNumber);
    slot.writeCount++;
}

PageMemorySlot &PageMemory::get(int slotNumber) {
    return memory.at(slotNumber);
}

PageReplacementAlgorithm *PageMemory::getPageReplacementAlgorithm() const {
    return pageReplacementAlgorithm;
}

void PageMemory::setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm) {
    PageMemory::pageReplacementAlgorithm = pageReplacementAlgorithm;
}
