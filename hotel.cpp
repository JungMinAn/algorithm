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
        int h, w, c;
        inStream >> h >> w >> c;
        int r = 1;
        for (int i = 0; i<c; i++){
            r += 100;
            if ((r/100) > h) {
                r -= h*100;
                r += 1;
            }
        }
        cout << r;
        cout << endl;
    }
    inStream.close();
}
