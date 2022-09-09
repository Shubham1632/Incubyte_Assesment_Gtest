//
// pch.cpp
// Include the standard header and generate the precompiled header.
//
#include "pch.h"

using namespace std;


    

void StringCalculator::calculate_number(std::string& numbers, int& i, int& ans, int& retflag)
{
    retflag = 1;
    if (isdigit(numbers[i]))
    {
        int temp = 0;
        while ((isdigit(numbers[i]) && i < numbers.size()))
        {
            temp = temp * 10;
            temp += (numbers[i] - '0');
            i++;
        }
        if (temp > 1000)
        {
            retflag = 3; return;
        };
        ans += temp;

    }
}

int StringCalculator::addString(string numbers)
    {
        int ans = 0;
        bool isdel = false;
        char delm;


        if (numbers[0] == '/' && numbers[1] == '/') {
             isdel = true;
             delm = numbers[2];
        }

        for (int i = 0; i < numbers.size(); i++)
        {
            int retflag;
            calculate_number(numbers, i, ans, retflag);
            if (retflag == 3) continue;

            if (numbers[i] <= 'z' && numbers[i] >= 'a')
            {
                if ((numbers[i] == 'n' && numbers[i - 1] == '\\')) {
                    if (isdel == true) {
                        if (numbers[i] == delm) {
                            continue;
                        }
                    }
                    continue;
                }
                ans += numbers[i] - '`';
            }

            if (numbers[i] == '-' && isdigit(numbers[++i]))
            {
                int temp = 0;
                isneg = true;
                while (isdigit(numbers[i]))
                {
                    temp = temp * 10;
                    temp += (numbers[i] - '0');
                    i++;
                }
                temp -= 2 * temp;
                neg.push_back(temp);
                while (numbers[i + 1] != '-' && i < numbers.size())
                {
                    i++;
                }
            }
        }

        if (isneg)
        {

            isneg = false;
            string negstring = "";
            for (int it : neg) {
                negstring += to_string(it);
            }

            throw "Negatives are not allowed " + negstring + "";
        }
        return ans;
    }

