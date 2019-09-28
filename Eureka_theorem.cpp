#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool iseunum(int eunum[], int n){
    for (int i = 0; i<44; i++){
        for (int j = 0; j<44; j++){
            for (int k = 0; k<44; k++){
                if (eunum[i] + eunum[j] + eunum[k] == n){
                    return 1;
                }
                if (eunum[i] + eunum[j] + eunum[k] > 1000){
                    break;
                }
            }
        }
    }
    return 0;
}
int main()
{   
    ifstream inStream;
    int numTestCases;
    int n;
    int eunum[44];
    for (int i = 1; i<45; i++){
        eunum[i-1] = i*(i+1)/2;
    }
    inStream.open("input.txt");
    if(inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    for (int i = 0; i<numTestCases; i++){
        inStream >> n;
        cout << iseunum(eunum, n);
        cout << endl;
    }
    inStream.close();
}