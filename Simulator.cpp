//
// Created by stoffel on 12/1/17.
//

#include "Simulator.h"



void Simulator::run() {

}

Simulator::Simulator(unsigned long physicalMemorySizeInBytes, unsigned long pageSizeInBytes, vector<int> &references,
                     PageReplacementAlgorithm *pageReplacement) : physicalMemorySizeInBytes(physicalMemorySizeInBytes),
                                                                  pageSizeInBytes(pageSizeInBytes),
                                                                  references(references),
                                                                  pageReplacement(pageReplacement),
                                                                  memory(physicalMemorySizeInBytes, pageSizeInBytes)
{

}
