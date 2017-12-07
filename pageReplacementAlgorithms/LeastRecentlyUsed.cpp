//
// Created by stoffel on 12/4/17.
//

#include "LeastRecentlyUsed.h"

bool LeastRecentlyUsed::read(int address)
{
    //See if the cache has this value

    recordAction(address, READ);

    return true;
}

bool LeastRecentlyUsed::write(int address)
{

    recordAction(address, WRITE);
}

void LeastRecentlyUsed::recordAction(int virtualAddress, Transaction transaction)
{
    Action action;
    action.virtualAddress = virtualAddress;
    action.transaction = transaction;

    actionQueue.push(action);
}

Action LeastRecentlyUsed::popOldestAction()
{
    Action oldest = actionQueue.front();
    actionQueue.pop();

    return oldest;
}

void LeastRecentlyUsed::addOKill(int address)
{
    if(cache.contains(address))
        return;

    if(cache.isFull())
        cache.replace(popOldestAction().virtualAddress, address);
}
