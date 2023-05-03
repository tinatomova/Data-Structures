/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-2/challenges/challenge-3091
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num;
    cin>>num;
    vector<int> vec;
    int toadd;
    for(int i=0;i<num;i++){
        cin>>toadd;
        vec.push_back(toadd);
    }
    int k;
    cin>>k;
    sort(vec.begin(),vec.end());
    long res=0;
    for(int i=0;i<k;i++){
        res+=vec[i];
    }
    cout<<res;
    return 0;
}
