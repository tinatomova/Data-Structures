/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-5/challenges/bridge-battle-1
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
// 1-prazna 0-neprazna
//-1 -2 | || | | -7| -8 |2 3
// s = 2 3
using namespace std;
int main() {
    queue<int> res;
    stack<int> last;
    stack<int> positive;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0 && positive.empty() == 1) {
            res.push(x);
            continue;
        }
        if (x > 0) {
            positive.push(x);
            continue;
        }
        if (x < 0 && positive.empty() == 0) {          
            if (-x == positive.top()) {
                positive.pop();
                continue;
            }
            if (-x < positive.top()) {
                continue;
            }
            while ( positive.empty()==0) {
                if (-x > positive.top()) {
                    positive.pop();
                    continue;
                }
                if (-x < positive.top()) {
                    break;
                }
                if (-x == positive.top()) {
                    positive.pop();
                    break;
                }                              
            }
            if (positive.empty() == 1) {
                res.push(x);
            }
        }
    }
    while (positive.empty() == 0) {
        last.push(positive.top());
        positive.pop();
    }
    while (last.empty() == 0) {
        res.push(last.top());
        last.pop();
    }
    if (res.empty() == 1) {
        cout << endl;
    }
    else {
        while (res.empty() == 0) {
            cout << res.front() << ' ';
            res.pop();
        }
    } 
}

