//
// Created by stoffel on 12/4/17.
//

#include "PageCache.h"

bool PageCache::add(int item)
{
    if(size >= maxSize)
        return false;

    //Is this item already stored?
    if(this->contains(item))
        return false;

    //Add this item to the virtual address map, and assign it to a physical slot
    int slotNumber = popFreeSlot();
    virtualToPhysicalAddress[item] = slotNumber;

    //Create a new page
    Page page;
    page.mappedNumber = slotNumber;
    page.virtualNumber = item;
    cache[slotNumber] = page;
    size++;

    return true;
}

bool PageCache::remove(int item)
{
    if(!this->contains(item))
        return false;

    int slotNumber = virtualToPhysicalAddress[item];
    freeSlots.push(slotNumber); //Don't hard delete the page; just mark it as erased
    virtualToPhysicalAddress[item] = EMPTY;
    size--;
    return true;
}

bool PageCache::replace(int item, int otherItem)
{
    if(!this->contains(item))
        return false;

    //Item's slot number
    int slotNumber = virtualToPhysicalAddress.at(item);

    //Invalidate item in the virtual memory map
    virtualToPhysicalAddress[item] = EMPTY;

    //Item's page
    Page & storedPage = cache[slotNumber];

    //clear item's page
    storedPage.clear();

    //Set storedPage to otherItem
    storedPage.mappedNumber = slotNumber;
    storedPage.virtualNumber = otherItem;

    //Add otherItem to the virtual map
    virtualToPhysicalAddress[otherItem] = slotNumber;
    return true;
}

bool PageCache::contains(int item)
{
    return virtualToPhysicalAddress.find(item) != virtualToPhysicalAddress.end() && virtualToPhysicalAddress.at(item) != EMPTY;
}

PageCache::PageCache(long size) : maxSize(size)
{
    //Initially, mark all of the slots as free
    for (int index = 0; index < size; ++index) {
        freeSlots.push(index);
    }

    cache.reserve(size);
}

int PageCache::popFreeSlot()
{
    int slotNumber = freeSlots.front();
    freeSlots.pop();

    return slotNumber;
}

Page *PageCache::getPage(int item)
{
    if(!this->contains(item))
        return nullptr;

    int slotNumber = virtualToPhysicalAddress.at(item);
    return &(cache[slotNumber]);
}


bool PageCache::isFull() {
    return
        size >= maxSize;
}

bool PageCache::isEmpty() {
    return
        size == 0;
}


