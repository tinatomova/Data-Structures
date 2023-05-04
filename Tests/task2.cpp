/*
*
Problem:
https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3156
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string,int> map1;
    string toadd;
    vector<string> res;
    for (int i = 0; i < n; i++) {
        cin >> toadd;
        res.push_back(toadd);
        map1[toadd]++;
    }
    for (int i = 0; i < n; i++) {
        cout << map1[res[i]] << " ";
    }
}

