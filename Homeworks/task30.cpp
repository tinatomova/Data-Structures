/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-11-2021/challenges/shortest-paths-2
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(long long ver);
const int N = 100001;
pair<long long, long long> d[N];
vector<pair<long long, long long>>G[N];

int main() {
    long long n, m, c, u, v;
    cin >> m >> n;
    for (long long i = n; i > 0; i--){
        cin >> u >> v >> c;
        G[u].push_back({ v, c });
    }
    dijkstra(1);
    if (d[m].second == 0) {
        cout << "-1 0";
    }
    else cout << d[m].first << " " << d[m].second;
    return 0;
}

void dijkstra(long long ver){
    priority_queue< pair<long long, long long>, vector <pair<long long, long long>>, greater<pair<long long, long long>> > Q;
    for (long long i = 0; i < N; i++) {
        d[i].first = LLONG_MAX;
        d[i].second = 0;
    }
    Q.push({ 0,ver });
    d[ver].first = 0;
    d[ver].second = 1;
    while (Q.empty() == 0){
        long long cur = Q.top().second;
        long long curcost = Q.top().first;
        Q.pop();
        if (curcost > d[cur].first) {
            continue;
        }
        for (pair<long long, long long> nextv : G[cur]){
            long long next = nextv.first, nextcost = nextv.second;
            if (d[next].first == curcost + nextcost) {
                d[next].second = (d[next].second+d[cur].second)%1000000007;
            }
            else if (d[next].first > curcost + nextcost){
                Q.push({ nextcost + curcost, next });
                d[next].first = curcost + nextcost;
                d[next].second = d[cur].second%1000000007;
            }
        }
    }
}