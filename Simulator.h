//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_SIMULATOR_H
#define ASSIGNMENT5_SIMULATOR_H

#include <vector>
#include "pageReplacementAlgorithms/Paging.h"
#include "Process.h"

using std::vector;

class Simulator
{
protected:
    unsigned long physicalMemorySizeInBytes = 0;
    unsigned long pageSizeInBytes = 0;

    vector<int> memory;
    vector<int> & references;
    Paging * paging = nullptr;
    Process * runningProcess = nullptr;

public:
    Simulator(unsigned long physicalMemorySizeInBytes, unsigned long pageSizeInBytes, vector<int> &references,
              Paging *pageReplacement);

    void run();
};


#endif //ASSIGNMENT5_SIMULATOR_H
