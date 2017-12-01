//
// Created by stoffel on 12/1/17.
//

#ifndef ASSIGNMENT5_UTILS_H
#define ASSIGNMENT5_UTILS_H

#include <string>

using std::string;

namespace Utils
{
    string & keepOnlyNumbers(string & str, string & result)
    {
        for(char c : str)
            if(isdigit(c))
                result.push_back(c);
    }
};


#endif //ASSIGNMENT5_UTILS_H
