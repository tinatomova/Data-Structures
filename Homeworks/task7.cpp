/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-2/challenges/challenge-3089
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
    cin>>n;
    vector<double> iner;
    vector<vector<double>> outer;
    double f, s;
    for(int i=0;i<n;i++){
        cin>>f>>s;
        iner.push_back(f*f/s);
        iner.push_back(f);
        iner.push_back(i+1);
        outer.push_back(iner);
        iner.clear();
    }
    sort(outer.rbegin(),outer.rend());
    for(int i=0;i<n;i++){
        cout<<outer[i][2]<<" ";
    }
    return 0;
}
