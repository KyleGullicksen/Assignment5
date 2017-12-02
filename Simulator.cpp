//
// Created by stoffel on 12/1/17.
//

#include "Simulator.h"


Simulator::Simulator(unsigned long physicalMemorySizeInBytes, unsigned long pageSizeInBytes, vector<int> &references,
                     PageReplacementAlgorithm *pageReplacement) : physicalMemorySizeInBytes(physicalMemorySizeInBytes),
                                                                  pageSizeInBytes(pageSizeInBytes),
                                                                  references(references),
                                                                  pageReplacement(pageReplacement),
                                                                  pageMemory(physicalMemorySizeInBytes, pageSizeInBytes)
{

}


void Simulator::run()
{
    //Record the start time and the end time as well
    int slotNumber = 0;

    for(int reference : references)
    {
        slotNumber = reference / 10;

        if((reference % 10) % 2) //If the least sig bit is even, than read the given slot number
            pageMemory.read(slotNumber);
        else
            pageMemory.write(slotNumber);
    }
}

void Simulator::processReference(int reference)
{
}
