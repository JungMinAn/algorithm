#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
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
        int n;
        inStream >> n;
        int card[10000] = {0};
        for (int j = 0; j<n; j++){
            inStream >> card[j];
        }
        sort(card, card + n);
        // for (int j = 0; j<n; j++){
        //     cout << card[j] << " ";
        // }
        //cout <<endl;
        int c1, c2, c3, c4;
        c1 = card[0] * card[1];
        c2 = card[0] * card[1] * card[n-1];
        c3 = card[n-1] * card[n-2];
        c4 = card[n-1] * card[n-2] * card[n-3];
        //cout << c1 << " " << c2 << " " << c3 << " " << c4 <<endl;
        int clist[4] = {c1, c2, c3, c4};
        sort(clist, clist + 4);
        cout << clist[3] <<endl;
    }
    inStream.close();
}