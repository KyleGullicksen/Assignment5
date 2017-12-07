//
// Created by stoffel on 12/1/17.
//

#include "Simulator.h"


Simulator::Simulator(unsigned long physicalMemorySizeInBytes, unsigned long pageSizeInBytes, vector<int> &references,
                     Paging *pageReplacement) : physicalMemorySizeInBytes(physicalMemorySizeInBytes),
                                                                  pageSizeInBytes(pageSizeInBytes),
                                                                  references(references),
                                                                  paging(pageReplacement)
{

}


void Simulator::run()
{
    //Record the start time and the end time as well
    int virtualAddress = 0;

    for(int virtualAddressWithReadWriteBit : references)
    {
        virtualAddress = virtualAddressWithReadWriteBit / 10;

        if((virtualAddressWithReadWriteBit % 10) % 2) //If the least sig bit is even, than read the given slot number
            paging->read(virtualAddress);
        else
            paging->write(virtualAddress);
    }
}

void Simulator::processReference(int reference)
{
}
