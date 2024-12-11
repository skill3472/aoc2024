/*
    Sooo... this one is very suboptimal, but I didn't read the task properly and thought that
    I need to return the actual vector, not it's length... xD
    So it only works w/ the first half (25 iterations), the second one (75) just won't work.
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<long> blink(vector<long> input)
{
    vector<long> res;
    for(int i = 0; i < input.size(); i++)
    {
        string numStr = to_string(input[i]);
        if(input[i] == 0)
        {
            res.push_back(1);
        }
        else if(numStr.length() % 2 == 0)
        {
            int len = numStr.length() / 2;
            string left = "";
            string right = "";
            for(int j = 0; j < len; j++)
            {
                left += numStr[j];
                right += numStr[j+len];
                // cout << left << " " << right << "\n";
            }
            res.push_back(stoi(left));
            res.push_back(stoi(right));
        }
        else
        {
            res.push_back(input[i] * 2024);
        }
    }
    return res;
}

int main() 
{
    vector<long> input = {2, 54, 992917, 5270417, 2514, 28561, 0, 990};
    for(int i = 0; i < 25; i++)
    {
        input = blink(input);
    }
    cout << input.size();
    return 0;
}