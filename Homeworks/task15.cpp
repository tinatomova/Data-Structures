/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-5/challenges/lekcii
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string in;
    cin >> in;
    int size = in.size();
    int arr[62];
    int p[62];
    vector<int> res;
    for (int i = 0; i < 62; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (in[i] >= '0' && in[i] <= '9') {
            arr[in[i] - 48]++;
            p[in[i] - 48] = i;
        }
        if (in[i] >= 'A' && in[i] <= 'Z') {
            arr[in[i] - 55]++;
            p[in[i] - 55] = i;
        }
        if (in[i] >= 'a' && in[i] <= 'z') {
            arr[in[i] - 61]++;
            p[in[i] - 61] = i;
        }
    }
    for (int i = 0; i < 62; i++) {
        if (arr[i] == 1) {
            res.push_back(p[i]);
        }
    }
    sort(res.begin(), res.end());
    for (unsigned int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}