/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-7/challenges/minimum-xor-3
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s;
    s.insert(0);
    int n;
    cin >> n;
    int toadd;
    cin >> toadd;
    s.insert(toadd);
    int min = 0 ^ toadd;
    cout << min << endl;
    for (int i = 1; i < n; i++) {
        cin >> toadd;
        set<int>::iterator low = s.lower_bound(toadd);
        if (*low != toadd) {        
            int nmin;
            if (low != s.end()&&s.count(*low)==1) {
                nmin = toadd ^ *low;
                if (min > nmin) {
                    min = nmin;
                }
            }
            low--;
            nmin = toadd ^ *low;
            if (min > nmin) {
                min = nmin;
            }
            s.insert(toadd);
        }     
        cout << min << endl;
    }  
    return 0;
}