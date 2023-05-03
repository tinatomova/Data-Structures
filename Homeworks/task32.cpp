/*
*
Problem:
https://www.hackerrank.com/contests/12-2/challenges/2-146
*
*/

#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

struct E {
    long long from;
    long long to;
    long long us;
    long long pe;
    long long idx;
    void con(long long f, long long t, long long u, long long p, long long i) {
        from = f;
        to = t;
        us = u;
        pe = p;
        idx = i;
    }
    inline bool operator<(const E& rhs) const {
        if (this->us < rhs.us) {
            return 1;
        }
        if (this->us > rhs.us) {
            return 0;
        }
        return this->pe > rhs.pe;
    }
    inline bool operator>(const E& rhs) { return rhs < *this; }
};

E edge[1000000];
long long m, n, par[1000000], D[1000000];
void M();
void K();
void U(long long f, long long t);
long long F(long long ver);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    long long a1, a2, a3, a4;
    for (long long i = 0; i < m; i++) {
        cin >> a1 >> a2 >> a3 >> a4;
        edge[i].con(a1, a2, a3, a4, i + 1);
    }
    K();
}

void M() {
    for (long long i = 0; i < n; ++i) {
        D[i] = 0;
        par[i] = i;
    }
}

long long F(long long ver) {
    if (ver == par[ver]) {
        return ver;
    }
    return par[ver] = F(par[ver]);
}

void U(long long f, long long t) {
    long long root1 = F(f);
    long long root2 = F(t);
    if (D[root1] > D[root2]) {
        par[root2] = root1;
    }
    else {
        par[root1] = root2;
    }
    if (D[root1] == D[root2]) {
        D[root2]++;
    }
}

void K() {
    M();
    sort(edge, edge + m);
    for (long long i = 0; i < m; i++) {
        long long from = edge[i].from;
        long long to = edge[i].to;
        if (F(from) != F(to)) {
            U(from, to);
            cout << edge[i].idx << endl;
        }
    }
}