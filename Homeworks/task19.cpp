/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-6-2021/challenges/1-266
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> res(n);
    vector<pair<int, int>> p(n-1);
    for (int i = 0; i < n - 1; i++) {
        int f, s;
        cin >> f >> s;
        p[i].first = f;
        p[i].second = s;
    }
    for (int i = n - 2; i >= 0; i--) {
        res[p[i].first] += res[p[i].second] + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}
