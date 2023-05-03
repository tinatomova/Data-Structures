/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-2/challenges/logging-monitoring-alerting
*
*/

#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
     int num;
    cin>>num;
    vector<string> hour;
    vector<string> date;
    string toadd="";
    for(int i=0;i<num;i++){
        cin>>toadd;
        hour.push_back(toadd);
        toadd="";
        cin>>toadd;
        date.push_back(toadd);
        toadd="";
    }
    
    vector<pair<long long,int>> res;
    long long r=0;
    pair<long long,int> p;
    for(int i=0;i<num;i++){
        r=0;
        for(int j=6;j<10;j++){
            r+=date[i][j]-'0';
            r*=10;
            
        }
        r+=date[i][3]-'0';
        r*=10;
        r+=date[i][4]-'0';
        r*=10;
        
        r+=date[i][0]-'0';
        r*=10;
        r+=date[i][1]-'0';
        r*=10;
        
        r+=hour[i][0]-'0';
        r*=10;
        
        r+=hour[i][1]-'0';
        r*=10;
       
        r+=hour[i][3]-'0';
        r*=10;
        r+=hour[i][4]-'0';
        r*=10;
        r+=hour[i][6]-'0';
        r*=10;
        r+=hour[i][7]-'0';
        p.first=r;
        p.second=i+1;
        res.push_back(p);
        
    }
    sort(res.begin(),res.end());
    for(int i=0;i<num;i++){
        cout<<res[i].second<<endl;
    }
    return 0;
}
