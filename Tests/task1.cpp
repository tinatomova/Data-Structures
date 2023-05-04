/*
*
Problem:
https://www.hackerrank.com/contests/sda-2021-2022-test4-nov30/challenges/challenge-3148
*
*/

#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

struct Compare1{
    bool operator()(pair<int,int> a, pair<int,int> b){   
        return a.first > b.first;
    }
};

int main(){
    priority_queue < pair<int, int>,vector<pair<int,int>>, Compare1> q;
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    vector<int> wait;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        pair<int, int> p(i, t);
        vec.push_back(p);
    }
    int time = vec[0].first;
    int count = 0;
    while (q.size() || count < n) {
        while (vec[count].first <= time && count < n) {
            pair<int, int>p1(vec[count].second, count);
            q.push(p1);
            count++;
        }
        int j;
        if (q.empty()==1) {
             time = vec[count].first;
        }
        else {        
            j = q.top().second;
            q.pop();
            time += vec[j].second;
            wait.push_back(time - vec[j].first);
        }
    }
    sort(wait.begin(), wait.end());
    cout << wait[0] << " " << wait[n - 1];
}

