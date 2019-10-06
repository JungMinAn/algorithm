#include <iostream>
#include <fstream>
#include <cstdlib>
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
    for (int i = 0; i<numTestCases; i++){
        int a, b, n, w, sheep, goat;
        inStream >> a >> b >> n >> w;
        int count = 0;
        for (int j = 1; j<n; j++){
            if (a * j + b * (n-j) == w){
                sheep = j;
                goat = n-j;
                count++;
            }
        }
        if (count == 1){
            cout << sheep << " " << goat <<endl;
        }
        else{
            cout << "-1" <<endl;
        }
    }
    inStream.close();
}