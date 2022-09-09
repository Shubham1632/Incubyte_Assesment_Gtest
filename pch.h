//
// pch.h
// Header for standard system include files.
//

#ifndef STRING_CALC_H
#define STRING_CALC_H




#include "gtest/gtest.h"
#include <vector>
#include<iostream>
#include <Bits.h>

using namespace std;


class StringCalculator
{
private:
    bool isneg = false;
    vector<int> neg;

public:
    void calculate_number(std::string& numbers, int& i, int& ans, int& retflag);
    int addString(string numbers);
    
};

#endif // STRING_CALC_H