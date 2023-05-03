/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-1/challenges/challenge-3068
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
   string word;
    cin>>word;
    int num;
    cin>>num;
    char s;
    cin>>s;
    int size=word.size();
    int sinoneword=0;
    for(int i=0;i<size;i++){
        if(word[i]==s){
            sinoneword++;
        }
    }
    int res=0;
    if(sinoneword!=0){
        res=sinoneword*(num/size);
        for(int i=0;i<num%size;i++){
            if(word[i]==s){
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}