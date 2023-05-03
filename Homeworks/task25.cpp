/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-9-2021/challenges/1-126-1
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_multiset<int> keys;
    vector<int> k;
    int key;
    for (int i = 0; i < n; i++) {
        cin >> key;
        k.push_back(key);
    }
    int door;
    int doorsbreak = 0;
    for (int i = 0; i < n; i++) {
        keys.insert(k[i]);
        cin >> door;
        auto search = keys.find(door);
        if (search != keys.end()) {
        keys.erase(search);
        }
        else {
            doorsbreak++;
        }   
    }
    cout << doorsbreak;   
}

