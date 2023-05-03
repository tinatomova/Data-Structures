/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-10-2021/challenges/cinema-2021
*
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, t, k;
    cin >> n >> m >> t >> k;
    queue<vector<int>> kov;
    vector<vector<int>> mat;
    vector<int> red;
    for (int i = 0; i < m; i++) {
        red.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        mat.push_back(red);
    }
    int idx1, idx2;
    int ill = 0;
    for (int p = 0; p < k; p++) {
        cin >> idx1 >> idx2;
        idx1--; idx2--;
        mat[idx1][idx2] = 1;
        ill++;
        vector<int> vec{ idx1,idx2,0 };
        kov.push(vec);
    }
    for (int i = 0; i < t; i++) {
        while (kov.front()[2] == i) {
            vector<int> toadd;
            if (kov.front()[0] > 0) {
                if (mat[kov.front()[0] - 1][kov.front()[1]] == 0) {
                    ill++;
                    mat[kov.front()[0] - 1][kov.front()[1]] = 1;
                    toadd.push_back(kov.front()[0] - 1);
                    toadd.push_back(kov.front()[1]);
                    toadd.push_back(i + 1);
                    kov.push(toadd);
                    toadd.clear();
                }            
            }
            if (kov.front()[1] > 0) {
                if (mat[kov.front()[0]][kov.front()[1] - 1] == 0) {
                    ill++;
                    mat[kov.front()[0]][kov.front()[1] - 1] = 1;
                    toadd.push_back(kov.front()[0]);
                    toadd.push_back(kov.front()[1] - 1);
                    toadd.push_back(i + 1);
                    kov.push(toadd);
                    toadd.clear();
                }              
            }
            if (kov.front()[0] < n - 1) {
                if (mat[kov.front()[0] + 1][kov.front()[1]] == 0) {
                    ill++;
                    mat[kov.front()[0] + 1][kov.front()[1]] = 1;
                    toadd.push_back(kov.front()[0] + 1);
                    toadd.push_back(kov.front()[1]);
                    toadd.push_back(i + 1);
                    kov.push(toadd);
                    toadd.clear();
                }              
            }
            if (kov.front()[1] < m - 1) {
                if (mat[kov.front()[0]][kov.front()[1] + 1] == 0) {
                    ill++;
                    mat[kov.front()[0]][kov.front()[1] + 1] = 1;
                    toadd.push_back(kov.front()[0]);
                    toadd.push_back(kov.front()[1] + 1);
                    toadd.push_back(i + 1);
                    kov.push(toadd);
                    toadd.clear();
                }             
            }
            kov.pop();
            if (ill == n * m) {
                break;
            }
        }
        if (ill == n * m) {
            break;
        }
    }
    cout << n * m - ill;
}

