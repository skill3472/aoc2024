/*
    Sooo... this one is very suboptimal, but I didn't read the task properly and thought that
    I need to return the actual vector, not it's length... xD
    So it only works w/ the first half (25 iterations), the second one (75) just won't work.
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct MaybeTuple {
    int num1;
    int num2 = -1;
};

void printVector(vector<long> input)
{
    for(int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << "\n";
}

vector<long> blink(vector<long> input)
{
    map<int, MaybeTuple> cache;

    MaybeTuple cache0;
    cache0.num1 = 1;
    cache[0] = cache0;

    vector<long> res;
    for(int i = 0; i < input.size(); i++)
    {
        if(cache.find(input[i]) != cache.end())
        {
            res.push_back(cache[input[i]].num1);
            if(cache[input[i]].num2 != -1)
                res.push_back(cache[input[i]].num2);
            continue;
        }
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
            long leftInt = stol(left);
            long rightInt = stol(right);
            res.push_back(leftInt);
            res.push_back(rightInt);

            MaybeTuple temp;
            temp.num1 = leftInt;
            temp.num2 = rightInt;
            cache[input[i]] = temp;
        }
        else
        {
            long a = input[i] * 2024;
            res.push_back(a);
            MaybeTuple temp;
            temp.num1 = a;
            cache[input[i]] = temp;
        }
    }
    // printVector(res);
    return res;
}

int main() 
{
    vector<long> input = {2, 54, 992917, 5270417, 2514, 28561, 0, 990};
    for(int i = 0; i < 50; i++)
    {
        input = blink(input);
    }
    cout << input.size();
    return 0;
}