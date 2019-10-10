#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int abs(int n){
    if (n < 0){
        return -n;
    }
    return n;
}

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
        int n, k;
        inStream >> n >> k;
        vector<int> nlist;
        for (int j = 0; j<n; j++){
            int temp;
            inStream >> temp;
            nlist.push_back(temp);
        }
        sort(nlist.begin(), nlist.end());
        if ((k >= nlist[n-1] + nlist[n-2]) || k <= nlist[0] + nlist[1]){
            //cout << k << (nlist[n-1] + nlist[n-2]) << (nlist[0] + nlist[1]) <<endl;
            cout << 1 << endl;
            continue;
        }
        int count = 0;
        int mdif = -1, bdif, dif;
        bool ismin = false;
        int idx1 = 0, idx2 = n/2, flag = 1;
        bdif = abs((nlist[idx2] + nlist[idx1]) - k);
        while (idx1 < nlist.size() - 2){
            //cout << nlist[idx2] << " " << nlist[idx1] << " bdif = " << bdif <<endl;
            if (idx2 + flag == nlist.size() || idx2 + flag == idx1){
                flag = -flag;
                ismin = true;
                continue;
            }
            dif = abs((nlist[idx2 + flag] + nlist[idx1]) - k);
            //cout << nlist[idx2 + flag] << " " << nlist[idx1] << " dif = " << dif <<endl;
            if (bdif <= dif){
                if (ismin || bdif == dif){
                    if (mdif == -1 || mdif > bdif){
                        //cout << mdif << " > " << bdif <<endl;
                        mdif = bdif;
                        count = 1;
                        if (bdif == dif){
                            count = 2;
                        }

                    }
                    else if (mdif == bdif){
                        count++;
                        if (bdif == dif){
                            count++;
                        }
                    }
                    //cout << "at " << nlist[idx1] << " :  the mdif is " << bdif <<endl;
                    //cout << "count is " << count << " at mdif is " << mdif <<endl;
                    idx1++;
                    if (idx1 == idx2){
                        idx2++;
                    }
                    bdif = abs((nlist[idx2] + nlist[idx1]) - k);
                    ismin = false;
                    continue;
                }
                ismin = true;
                flag = -flag;
                continue;
            }
            bdif = dif;
            idx2 = idx2 + flag;
        }
        cout << count <<endl;

    }
    inStream.close();
}