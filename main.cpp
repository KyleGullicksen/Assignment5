#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

#include "Utils.h"
#include "Simulator.h"

using namespace std;

#define PAGE_SIZE_COMMAND_LINE_STRING "--pageSize"
#define PHYSICAL_MEMORY_COMMAND_LINE_STRING "--ram"

struct CommandLineOptions
{
    long pageSizeInBytes = 0;
    long physicalRamSizeInBytes = 0;
};

unordered_set<long> powersOfTwo;

void populatePowersOfTwo()
{
    powersOfTwo.insert(256);
    powersOfTwo.insert(512);
    powersOfTwo.insert(1024);
    powersOfTwo.insert(2048);
    powersOfTwo.insert(4096);
    powersOfTwo.insert(8192);
}

//1 reference / line
vector<int> & parseReferencesFile(const char filename[], vector<int> & references)
{
    ifstream input(filename, ios::in);
    string currentReference = "";

    for(string currentLine; getline(input, currentLine); currentReference.clear())
    {
        Utils::keepOnlyNumbers(currentLine, currentReference);

        if(currentReference.empty())
            continue;

        references.push_back(stoi(currentReference));
    }
}

//<program name> --ram <value> --pageSize <value>
//Ram and pageSize required.

CommandLineOptions & extractCommandLineOptions(int argc, char ** argv, CommandLineOptions & commandLineOptions)
{
    if(argc != 5) {
        cout << "Unexpected number of parameters recieved; 5 were expected. Exiting." << endl;
        exit(0xBAD);
    }

    for (int index = 1; index < argc; ++index)
    {
        if(argv[index] == PAGE_SIZE_COMMAND_LINE_STRING)
        {
            ++index;
            commandLineOptions.pageSizeInBytes = stol(argv[index]);
        }
        else if(argv[index] == PHYSICAL_MEMORY_COMMAND_LINE_STRING)
        {
            ++index;
            commandLineOptions.physicalRamSizeInBytes = stol(argv[index]);
        }
    }


    //Valid input?
    if(powersOfTwo.find(commandLineOptions.pageSizeInBytes) == powersOfTwo.end()) {
        cout << "Invalid page size specified. The page size must be a power of 2 from [256-8192]" << endl;
        exit(0xBAD);
    }

    if(powersOfTwo.find(commandLineOptions.physicalRamSizeInBytes) == powersOfTwo.end())
    {
        cout << "Invalid page size specified. The page size must be a power of 2 from [256-8192]" << endl;
        exit(0xBAD);
    }

    return commandLineOptions;
}

int main(int argc, char ** argv)
{
    populatePowersOfTwo();

    CommandLineOptions commandLineOptions;
    extractCommandLineOptions(argc, argv, commandLineOptions);

    vector<int> references;
    parseReferencesFile("references.txt", references);

    cout << "Simulation of Page Replacement Algorithm" << endl;
    cout << "Author:Mr Kyle and Mr Ben" << endl;
    cout << "Date: 5/7/2014" << endl;
    cout << "Course: CS433 (Operating Systems)" << endl;
    cout << "Description : Analyzes efficiency of random, FIFO, and LRU\n page replacement algorithms with a given page size and\nphysical pageMemory size on a machine with 128 MB of logical pageMemory." << endl;

    PageReplacementAlgorithm * pageReplacementAlgorithm = nullptr;

    Simulator simulator(commandLineOptions.physicalRamSizeInBytes, commandLineOptions.pageSizeInBytes, references, pageReplacementAlgorithm);
}