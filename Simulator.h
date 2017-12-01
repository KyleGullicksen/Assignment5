//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_SIMULATOR_H
#define ASSIGNMENT5_SIMULATOR_H

#include <vector>
#include "pageReplacementAlgorithms/PageReplacementAlgorithm.h"
#include "Process.h"
#include "PageMemory.h"

using std::vector;

class Simulator
{
protected:
    unsigned long physicalMemorySizeInBytes = 0;
    unsigned long pageSizeInBytes = 0;
    vector<int> & references;
    PageReplacementAlgorithm * pageReplacement = nullptr;
    Process * runningProcess = nullptr;
    PageMemory memory;

public:
    Simulator(unsigned long physicalMemorySizeInBytes, unsigned long pageSizeInBytes, vector<int> &references,
              PageReplacementAlgorithm *pageReplacement);

    void run();
};


#endif //ASSIGNMENT5_SIMULATOR_H
