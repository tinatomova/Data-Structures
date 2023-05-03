/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-10-2021/challenges/if-you-reading-this-get-baited
*
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> vecC(10000);
vector<int> vecI(10000);
vector<vector<int>>vecvec(10000);
vector<bool> vecB;
vector<int> C;
int start = 0; int endE = 0;
bool dfs(int v);
void iscyc(int n);

int main() {
    int q, e, n;
    cin >> q;
    while (q--) {
        cin >> e;
        n = e;
        while (e--) {
            int f, t;
            cin >> f >> t;
            --f; --t;
            vecvec[f].push_back(t);
        }
        iscyc(n);
        vecvec.clear();
        vecvec.resize(10000);
        C.clear();
    }
    return 0;
}
bool dfs(int z) {
    vecC[z] = 1;
    for (int w : vecvec[z]) {
        if (vecC[w] == 0) {
            vecI[w] = z;
            if (dfs(w))
                return 1;
        }
        else if (vecC[w] == 1) {
            endE = z;
            start = w;
            return 1;
        }
    }
    vecC[z] = 2;
    return 0;
}
void iscyc(int n){
    fill(vecI.begin(), vecI.end(), -1);
    fill(vecC.begin(), vecC.end(), 0);
    start = -1;
    for (int i = 0; i < n; i++) {
        if (vecC[i] == 0 && dfs(i)) {
            break;
        }
    }
    if (start != -1) {
        C.push_back(start);
        for (int v = endE; v != start; v = vecI[v]) {
            C.push_back(v);
        }
        C.push_back(start);
        reverse(C.begin(), C.end());
        cout << "1 ";
    }
    else {
        cout << "0 ";
    }
}
