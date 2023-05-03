/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-3/challenges/doom
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lis(vector<int> const& a);
int main() {
    unsigned int n;
    vector<pair<int, int>> vec;
    cin >> n;
    for (unsigned int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        pair<int, int> p1;
        p1.first = f; p1.second = s;
        vec.push_back(p1);
    }
    sort(vec.begin(), vec.end());
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(vec[i].second);
    }
    cout << lis(v);
}

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
