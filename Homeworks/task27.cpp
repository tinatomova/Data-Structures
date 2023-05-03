/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-9-2021/challenges/longest-match
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int res = 0;
    string str1, str2;
    cin >> str1 >> str2;
    int size1 = str1.size(); int size2 = str2.size();
    vector<vector<int>> vec;
    vector<int> toadd(size2 + 1);
    for (int i; i <= size2; i++) {
        toadd[i] = 0;
    }
    vec.push_back(toadd);
    vec.push_back(toadd);
    for (int i = 0; i < size1; i++) {                
        for (int j = 0; j < size2; j++) {
            if (str1[i] != str2[j]) {
                vec[(i + 1) % 2][j + 1] = 0;
            }
            else {              
                vec[(i + 1) % 2][j + 1] = vec[i % 2][j] + 1;
                if (vec[(i + 1) % 2][j + 1] > res) {
                    res = vec[(i + 1) % 2][j + 1];
                }
            }
        }
    }  
    cout << res;
    return 0;   
}
