/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-8-2021/challenges/elitism
*
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
      cout << fixed << setprecision(1);
    int n;
    cin >> n;
    priority_queue<int,vector<int>, greater<int>> higher;
    priority_queue<int> lower;   
    int toadd;
    cin>>toadd;
    cout<<double(toadd)<<"\n";
    if(n>1){
        int toadd2;
    cin>>toadd2;
    cout<<double(double(toadd+toadd2)/2)<<"\n";
    if(toadd<toadd2){
        lower.push(toadd);
        higher.push(toadd2);
    }
    else{
        lower.push(toadd2);
        higher.push(toadd);
    }
    for(int i=0;i<n-2;i++){
        cin>>toadd;
        if(lower.size()==higher.size()){
            if(toadd<lower.top()){
                lower.push(toadd);
                cout<<double(lower.top())<<"\n";
            }
            else{
                higher.push(toadd);
                cout<<double(higher.top())<<"\n";
            }
        }
        else if(lower.size()>higher.size()){
            if(toadd<lower.top()){
                lower.push(toadd);
                higher.push(lower.top());
                lower.pop();               
            }
            else{
                higher.push(toadd);
            }
            cout<<(double(lower.top())+double(higher.top()))/2<<"\n";
        }
        else if(lower.size()<higher.size()){
            if(toadd>higher.top()){
                higher.push(toadd);
                lower.push(higher.top());
                higher.pop();               
            }
            else{
                lower.push(toadd);
            }
            cout<<(double(lower.top())+double(higher.top()))/2<<"\n";
        }
    }
    }
    return 0;
}