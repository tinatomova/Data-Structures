/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-2/challenges/challenge-3088
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void contingsort(vector<int> & vec, int i);
int main()
{
    int n;
    cin >> n;
    string in;
    cin >> in;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        if (in[i] >= '0' && in[i] <= '9') {
            num.push_back(in[i]-48);
        }
        if (in[i] >= 'a' && in[i] <= 'z') {
            num.push_back(in[i]-86);
        }
        if (in[i] >= 'A' && in[i] <= 'Z') {
            num.push_back(in[i]-28);
        }
    }
    contingsort(num, n);
    
    
    string out("");
    for (int i = 0; i < n; i++) {
        char s;
        if (num[i] >= 0 && num[i] <= 9) {
            s = (num[i] + 48);
            out += s;
        }
        if (num[i] >= 11 && num[i] <= 36) {
            s = (num[i] + 86);
            out += s;
        }
        if (num[i] >= 37 && num[i] <= 62) {
            s = (num[i] + 28);
            out += s;
        }
    }
    cout << out;
}
void contingsort(vector<int>& vec, int n) {
    vector<char> veccopy;
    for (int i = 0; i < n; ++i) {
        veccopy.push_back(vec[i]);
    }
    vector<int> count(63);
    for(int i =0;i<62;i++){
        //cout<<count[i]<<" ";
    }
    //cout<<"*";
    for (int i = 0; i < n; ++i) {
        count[vec[i]]++;
    }
    for (int i = 1; i <= 62; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++) {
        vec[count[veccopy[i]] - 1] = veccopy[i];
        count[veccopy[i]]--;
    }
}
