/*
*
Problem:
https://www.hackerrank.com/contests/12-2/challenges/roads-5
*
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> E;
int n;
int m;
vector<int> par;
void u(int first, int second);
int f(int ver);
void M();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);  
    int from, to, q, type;
    cin >> n;
    cin >> m;
    par.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> from;
        cin >> to;
        E.emplace_back(from, to);
    }
    M();
    for (int i = 0; i < m; ++i) {
        u(E[i].first, E[i].second);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> type;
        cin >> from;
        cin >> to;
        if (type == 2) {
            u(from, to);
        }
        else {
            cout << (f(from) == f(to));
        }        
    }
}

int f(int ver) {
    if (par[ver] == ver) {
        return ver;
    }
    return par[ver] = f(par[ver]);
}

void M() {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
}

void u(int first, int second) {
    int root1 = f(first);
    int root2 = f(second);
    if (root1 != root2) {
        par[root2] = root1;
    }
    else {
        return;
    }
}
