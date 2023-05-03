/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-7/challenges/zoros-mask
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

string dtob(int num) {
    string str="";
    for (int i = 0; i < 20; i++) {
        str += '0';
    }
    for (int i = 19; num > 0; i--) {
        if (num % 2 == 1) {
            str[i] = '1';
        }
        num /= 2;
    }
    return str;
}

void add(set<string>& s, string toadd, int idx) { 
    if (idx == 20) {
        s.insert(toadd);
        return;
    }
    s.insert(toadd);
    if (toadd[idx] == '0') {
        add(s, toadd, idx + 1);
        return;
    }   
    string l = toadd;
    string r = toadd;
    if (toadd[idx] == '1') {
        l[idx] = '0';
        r[idx] = '1';
        add(s, l, idx + 1);
        add(s, r, idx + 1);       
    }
}

int main() {
    set<string> s;
    int n;
    cin >> n;
    int toadd;
    for (int i = 0; i < n; i++) {
        cin >> toadd;
        string bin = dtob(toadd);
        add(s, bin, 0);
    }
    cout << s.size();
}

