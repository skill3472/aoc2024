/*
    Sooo... this one is also terrible. To be fair, didn't work properly for the first exercise eiter.
    DFS might be required, not a lot of free time to do that today, so pass ig :c
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

int main() 
{
    ifstream file("in12.txt");
    string tempStr;
    vector<string> input;

    unordered_set<char> plants;
    map<char, int> area;
    map<char, int> circumference;

    while(getline(file, tempStr))
    {
        for(int i = 0; i < tempStr.length(); i++)
        {
            if(!isalpha(tempStr[i]))
                tempStr.erase(i, 1);
        }
        input.push_back(tempStr);
    }

    for(int i = 0; i < input.size(); i++) // i = height, j = width
    {
        for(int j = 0; j < input[i].length(); j++)
        {
            plants.insert(input[i][j]);
            area[input[i][j]] += 1;
            // Check UP
            if(i-1 >= 0) // Not at top-most tile
            {
                if(input[i-1][j] != input[i][j]) // Tile at the top is not the same
                {
                    circumference[input[i][j]] += 1;
                }
            }
            else
            {
                circumference[input[i][j]] += 1;
            }
            // Check DOWN
            if(i+1 < input.size()) // Not at bottom-most tile
            {
                if(input[i+1][j] != input[i][j]) // Tile at the bottom is not the same
                {
                    circumference[input[i][j]] += 1;
                }
            }
            else
            {
                circumference[input[i][j]] += 1;
            }
            // Check LEFT
            if(j-1 >= 0) // Not at left-most tile
            {
                if(input[i][j-1] != input[i][j]) // Tile at the left is not the same
                {
                    circumference[input[i][j]] += 1;
                }
            }
            else
            {
                circumference[input[i][j]] += 1;
            }
            // Check RIGHT
            if(j+1 < input[i].length()) // Not at right-most tile
            {
                if(input[i][j+1] != input[i][j]) // Tile at the right is not the same
                {
                    circumference[input[i][j]] += 1;
                }
            }
            else
            {
                circumference[input[i][j]] += 1;
            }
        }
    }

    int cost = 0;

    for(char plant : plants)
    {
        cout << plant << ": " << area[plant] << " * " << circumference[plant] << " = " << (area[plant]*circumference[plant]) << endl;
        cost += area[plant]*circumference[plant];
    }

    cout << "TOTAL COST: " << cost << endl;

    return 0;
}