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
    for (int i = 0; i<numTestCases; i++){
        int n;
        inStream >> n;
        vector<int> v;
        for (int j = 2; j<65; j++){
            int t = n;
            v.clear();
            while (t > 0){
                v.push_back(t % j);
                t /= j;
            }
            if (v.size() <= 1){
                cout << 1 <<endl;
                break;
            }
            bool flag = true;
            for (int k = 0; k<v.size()/2; k++){
                if (*(v.begin() + k) != *(v.rbegin() + k)){
                    flag = false;
                }
            }
            if (flag){
                cout << 1 <<endl;
                break;
            }
            if (j == 64){
                cout << 0 <<endl;
            }
        }

    }
    inStream.close();
}