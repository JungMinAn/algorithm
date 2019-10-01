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
        int a, b;
        inStream >> a >> b;
        const int n = a, m = b;
        long long team[1000] = {0}, run[1000] = {0}, hit[1000] = {0}; 
        for (int j = 0; j<m; j++){
            int a, b, p, q;
            inStream >> a >> b >> p >> q;
            run[a-1] += p;
            run[b-1] += q;
            hit[a-1] += q;
            hit[b-1] += p;
        }
        long long max = 0, min = -1;
        for (int j = 0; j<n; j++){
            if ((run[j] == 0) && (hit[j] == 0)){
                continue;
            }
            team[j] = (1000 * (run[j] * run[j]) / ((run[j] * run[j]) + (hit[j] * hit[j])));
            if (max < team[j]){
                max = team[j];
            }
            if (min == -1 || (min > team[j])){
                min = team[j];
            }
        }
        cout << max << endl << min <<endl;
    }
    inStream.close();
}