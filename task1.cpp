/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-1/challenges/the-first-challenge-v53
*
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
     string str;
    cin >> str;
    int size=str.size();
    char c;
    cin >> c;
    vector<int> res;
    for ( int i=0; i < size; i++) {
        res.push_back(-1);
    }
    bool flag = 0;
    int dir = 0;
    for ( int i = 0; i < size; i++) {
        if (str[i] == c) {
            flag = 1;
            dir = 0;
            res[i] = dir;
        }
        if (str[i] != c && flag == 1) {
            dir++;
            res[i] = dir;
        }
    }
    flag = 0; dir = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str[i] == c) {
            flag = 1;
            dir=0;
        }
        if (str[i] != c && flag == 1) {

            dir++;
            if (res[i] > dir|| res[i]==-1) {
                res[i] = dir;
            }
            
        }
    }
    for (int i = 0; i <size; i++) {
        cout << to_string(res[i]) << " ";
    }
    return 0;
}
