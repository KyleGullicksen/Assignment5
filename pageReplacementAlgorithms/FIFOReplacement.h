//
// Created by stoffel on 12/4/17.
//

#ifndef ASSIGNMENT5_FIFOREPLACEMENT_H
#define ASSIGNMENT5_FIFOREPLACEMENT_H

#include "Paging.h"
#include <queue>

using std::queue;

class FIFOReplacement : public Paging
{
protected:
    queue<int> order;

public:
    bool read(int address) override;
    bool write(int address) override;

};


#endif //ASSIGNMENT5_FIFOREPLACEMENT_H
