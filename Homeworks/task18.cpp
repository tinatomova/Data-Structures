/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-5/challenges/challenge-3105
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {
    vector<int>competitors;
    queue<int> que;
    vector<queue<int>> allques;
    int N, comprtitor, Days = 0, lCount = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> comprtitor;
        competitors.push_back(comprtitor);
    }
    que.push(competitors[0]);
    allques.push_back(que);
    for (int i = 1; i < N; i++) {
        if (competitors[i] < allques[lCount].back()) {       
            allques[lCount].push(competitors[i]);
        }
        else {
            lCount++;
            queue<int> q;
            q.push(competitors[i]);
            allques.push_back(q);
        }
    }
    while (allques.size() != 1) {
        for (int i = allques.size() - 1; i >= 1; i--) {
            allques[i].pop();
            if (allques[i].front()<allques[i - 1].back()) {
                while (allques[i].empty()==0) {
                    allques[i - 1].push(allques[i].front());
                    allques[i].pop();
                }
            }
            if (allques[i].empty()) {
                allques.erase(allques.begin() + i);
            }
        } 
        Days++;
    }
    printf("%d", Days);
    return 0;
}