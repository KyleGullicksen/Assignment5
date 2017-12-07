//
// Created by stoffel on 12/4/17.
//

#ifndef ASSIGNMENT5_LEASTRECENTLYUSED_H
#define ASSIGNMENT5_LEASTRECENTLYUSED_H

#include <queue>
#include "Paging.h"

using std::queue;

enum Transaction {READ, WRITE};

struct Action
{
    Transaction transaction;
    int virtualAddress = 0;
};

class LeastRecentlyUsed : public Paging
{
protected:
    queue<Action> actionQueue;
    void recordAction(int virtualAddress, Transaction transaction);
    Action popOldestAction();
    void addOKill(int address);
public:
    bool read(int address) override;
    bool write(int address) override;

};


#endif //ASSIGNMENT5_LEASTRECENTLYUSED_H
