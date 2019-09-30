#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

string ishappy(int num)
{
    int sum;
    sum = 0;
    vector<int> numlist;
    while (1){
        sum += (num % 10) * (num % 10);
        num = num / 10;
        if (num == 0){
            if (sum == 1){
                return "HAPPY";
            }
            for (int k = 0; k < numlist.size(); k++){
                if (sum == numlist[k]){
                    return "UNHAPPY";
                }
            }
            numlist.push_back(sum);
            num = sum;
            sum = 0;
        }
    }
}

int main()
{
    ifstream inStream;
    int numTestCases;

    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int num;
        inStream >> num;
        cout << ishappy(num) <<endl;
    }
    inStream.close();
}