/*
*
Problem:
Task17: https://www.hackerrank.com/contests/sda-hw-5/challenges/challenge-2695
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int min(queue<int>& Q, int s);
int main() {
    queue<int> Q;
    vector<int> res;
    int n, w;
    cin >> n >> w;
    int toadd;
    for (int i = 0; i < w; i++) {
        cin >> toadd;
        Q.push(toadd);
    }
    int fmin = min(Q, w);
    res.push_back(fmin);
    for (int i = w; i < n; i++) {
        cin >> toadd;
        if (Q.front() != fmin) {
            if (toadd <= fmin){
                res.push_back(toadd);
                fmin = toadd;
            }
            else {
                res.push_back(fmin);
            }
            Q.push(toadd);
            Q.pop();
        }
        else {
            Q.push(toadd);
            Q.pop();
            fmin = min(Q, w);
            res.push_back(fmin);
            continue;
        }
    }
    long long sum = 0;
    for (unsigned int i = 0; i < res.size(); i++) {
        sum += res[i];
    }
    cout << sum;
}
int min(queue<int>& Q, int s)
{
    int min = Q.front();
    for (int i=0; i < s; i++) {
        int temp = Q.front();
        if (temp < min) {
            min = temp;
        }
        Q.pop();
        Q.push(temp);
    }
    return min;
}
