/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-9-2021/challenges/weighing-animals
*
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
    vector<long> vec;
    long n, k;
    cin >> n >> k;
    long toadd;
    for (long i = 0; i < n; i++) {
        cin >> toadd;
        vec.push_back(toadd);
    }
    map<long, long> map1;
    for (long i = 0; i < n; i++) {
        map1[vec[i]]++;
    }
    long res = 0;
    map<long, long> map2;
    long idx, idx2;
    for (long i = 0; i < n; i++) {
        idx = vec[i] * k;
        idx2 = vec[i] / k;
        map1[vec[i]]--;
        if (vec[i] % k == 0) {            
            res += map1[idx] * map2[idx2];
        }
        map2[vec[i]]++;
    }
    cout << res;
}