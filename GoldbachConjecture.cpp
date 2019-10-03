#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    bool isnotprime[1001] = {0};
    isnotprime[1] = 1;
    for (int i = 2; i<32; i++){
        if (!isnotprime[i]){
            int t = 2;
            while(i*t < 1001){
                isnotprime[i*t] = 1;
                t++;
            }
        }
    }

    for (int i = 0; i<numTestCases; i++){
        int n;
        inStream >> n;
        for (int j = n/2; j>1; j--){
            if (!isnotprime[j] && !isnotprime[n-j]){
                cout << j << " " << n-j <<endl;
                break;
            }
        }

    }
    inStream.close();
}