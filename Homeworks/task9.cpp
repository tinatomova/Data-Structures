/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-3/challenges/challenge-3074
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned int n, m;
    cin >> n >> m;
    vector<unsigned int> t;
    vector<unsigned int> p;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int num;
        cin >> num;
        t.push_back(num);
    }
    sort(t.begin(), t.end());
    for (unsigned int i = 0; i < m; i++) {
        unsigned int num;
        cin >> num;
        p.push_back(num);
    }
    for (unsigned int i = 0; i < m; i++) {      
        vector<unsigned int>::iterator low = lower_bound(t.begin(), t.end(), p[i]);
        unsigned int j=low-t.begin();
        if(j==0){
            p[i]=t[j];
        }
        if (j > 0 && j < n) {
            if (p[i] == t[j]) { continue; }
            else {
                unsigned int s = t[j - 1];
                if (p[i] - s > t[j] - p[i]) {
                    p[i] = t[j];
                }
                else {
                    p[i] = s;
                }
            }
        }
        if(j==n){
            p[i]=t[j-1];
        }
    }
    for (unsigned int i = 0; i < m; i++) {
        cout << p[i]<<endl;
    }  
    return 0;
}
