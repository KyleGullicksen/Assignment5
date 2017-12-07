//
// Created by stoffel on 12/4/17.
//

#ifndef ASSIGNMENT5_PAGECACHE_H
#define ASSIGNMENT5_PAGECACHE_H

#include <vector>
#include <unordered_map>
#include <queue>
#include "Page.h"

#define EMPTY -1

using std::unordered_map
using std::vector;
using std::queue;

class PageCache
{
protected:
    vector<Page> cache;
    unordered_map<int, int> virtualToPhysicalAddress;
    queue<int> freeSlots;

    protected long size = 0;
    protected long maxSize = 0;

    int popFreeSlot();
public:
    PageCache(long size);

    bool add(int item);
    bool remove(int item);
    bool replace(int item, int otherItem);
    bool contains(int item);
    Page * getPage(int item);
    bool isFull();
    bool isEmpty();
};


#endif //ASSIGNMENT5_PAGECACHE_H
