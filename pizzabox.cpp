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
        int n, m, o;
        inStream >> n >> m;
        int box[1000][1000];
        bool flags[1000][1000] = {0};
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                inStream >> o;
                box[i][j] = o;
            }
        }
        for (int i = 0; i<n; i++){
            int flag = 0, max = 0;
            for (int j = 0; j<m; j++){
                if (max < box[i][j]){
                    max = box[i][j];
                    flag = j;
                }
            }
            flags[i][flag] = true;
        }

        for (int i = 0; i<m; i++){
            int flag = 0, max = 0;
            for (int j = 0; j<n; j++){
                if (max < box[j][i]){
                    max = box[j][i];
                    flag = j;
                }
            }
            flags[flag][i] = true;
        }
        long long count = 0;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (!flags[i][j]){
                    count += box[i][j];
                }
            }
        }
        cout << count <<endl;
    }
    inStream.close();
}