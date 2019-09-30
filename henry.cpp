#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
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
        int h, x, b;
        inStream >> h >> b;
        while (h != 1){
            x = (b/h) + 1;
            h = h * x - b;
            b = b * x;
            int g = gcd(h, b);
            h /= g;
            b /= g;
        }
        cout << b << endl;
    }
    inStream.close();
}