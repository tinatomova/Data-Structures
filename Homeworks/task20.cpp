/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-6-2021/challenges/top
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector < pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        p[i].first = f;
        p[i].second = s;
    }  
    vector<vector<int>> vec(n);
    vec[0].push_back(0);
    vec[0].push_back(0);
    vec[0].push_back(0);
    for (int i = 0; i < n-1; i++) {
        if (p[i].first != -1) {
            vec[p[i].first].push_back(vec[i][0] - 1);
            vec[p[i].first].push_back(vec[i][1] - 1);
            vec[p[i].first].push_back(p[i].first);
        }
        if (p[i].second != -1) {
            vec[p[i].second].push_back(vec[i][0] + 1);
            vec[p[i].second].push_back(vec[i][1] - 1);
            vec[p[i].second].push_back(p[i].second);
        }
    } 
    sort(vec.begin(), vec.end()); 
    for (int i = vec.size() - 1; i >0 ; i--) {
        if (vec[i][2] == -1) {
            continue;
        }
        int m = i - 1;     
        while (vec[i][0] == vec[m][0] && m >= 0) {         
            if (vec[i][1] == vec[m][1]) {
                vec[i][2] = -1;
                m--;             
            }
            else {
                vec[m][2] = -1;
                m--;              
            }
            if (m < 0) {
                break;
            }           
        }       
        i = m+1;      
    }
    for (int i = 0; i <n; i++) {
        if (vec[i][2] != -1) {
            cout << vec[i][2] << " ";
        }
    }
    return 0;
}
