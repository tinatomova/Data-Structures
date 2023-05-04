/*
*
Problem:
https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3157
*
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> map1;
    int toadd;
    int sum = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        cin >> toadd;
        res.push_back(toadd);
        map1[toadd]++;
    }
    for (int i = 0; i < n; i++) {
        if (map1[res[i]] % 2 != 0) {
            sum += res[i];          
        }      
    }
    cout << sum;
}

