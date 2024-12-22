#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

vector<int> SortVector(vector<int> vector)
{
    int n = vector.size();
    for(int i = 0; i < n; i++)
    {
        bool isSwapped = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(vector[j] > vector[j+1])
            {
                int temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
                isSwapped = true;
            }
        }
        if(!isSwapped)
            break;
    }
    return vector;
}

int main()
{
    vector<int> list1;
    vector<int> list2;

    // Getting the file into the vectors
    ifstream file("in1.txt");
    string line;
    int spacePos;
    while(getline(file, line))
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ')
                spacePos = i;
        }
        list1.push_back(stoi(line.substr(0, spacePos)));
        list2.push_back(stoi(line.substr(spacePos+1, line.length()-spacePos)));
    }
    list1 = SortVector(list1);
    list2 = SortVector(list2);
    
    vector<int> diff;
    int sumDiff = 0;
    for(int i = 0; i < list1.size(); i++)
    {
        diff.push_back(abs(list1[i] - list2[i]));
        sumDiff += diff[i];
    }
    cout << "Part 1: " << sumDiff << endl;

    // Part 2
    int similarityScore = 0;
    for(int i = 0; i < list1.size(); i++)
    {
        int repetitions = 0;
        for(int j = 0; j < list2.size(); j++)
        {
            if(list1[i] == list2[j])
                repetitions++;
        }
        similarityScore += list1[i] * repetitions;
    }
    cout << "Part 2: " << similarityScore << endl;
}