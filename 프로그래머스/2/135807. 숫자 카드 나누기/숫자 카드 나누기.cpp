#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int minA = arrayA[0];
    int minB = arrayB[0];
    
    for(int i = 1; i < arrayA.size(); i++)
    {
        minA = gcd(arrayA[i], minA);
        minB = gcd(arrayB[i], minB);
    }
    
    for(int i = 0; i < arrayB.size(); i++)
    {
        if(arrayB[i] % minA == 0)
        {
            minA = 0;
            break;
        }
    }
    
    for(int i = 0; i < arrayA.size(); i++)
    {
        if(arrayA[i] % minB == 0)
        {
            minB = 0;
            break;
        }
    }
    
    return max(minA, minB);
}