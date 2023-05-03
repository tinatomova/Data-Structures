/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-3/challenges/challenge-3066
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
     unsigned long long p;
    cin >> p;
    unsigned long long counter = 0;
    while (p != 0) {
        for (unsigned long long i = 0; i <= p + 1; i++) {
            unsigned long long n = i * i * i;
            if (n > p) {
                n = (i - 1) * (i - 1) * (i - 1);
                p -= n;
                counter++;
                break;
            }
        }
    }   
    cout << counter;
}

