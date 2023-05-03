/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-1/challenges/challenge-3065
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
    vector<int> vec;
    int toadd;
    for(int i=0;i<n;i++){
        cin>>toadd;
        vec.push_back(toadd);
    }
    vector<int> found;
    for(int i=0;i<n+1;i++){
        found.push_back(0);
    }
    for(int i=0;i<n;i++){
        if(vec[i]<=n&&vec[i]>0){
            found[vec[i]]++;
        }
    }
    int res=0;
    for(int i=1;i<n+1;i++){
        if(found[i]==0){
            res=i;
            break;
        }
        
    }
    if(res==0){
        res=n+1;
    }
    cout<<res;
    return 0;
}