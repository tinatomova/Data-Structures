/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-4/challenges/exam-5-1
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* pr;

    node(int d, node* n = nullptr, node* p = nullptr) {
        data = d;
        next = n;
        pr = p;
    }  
};
class list {
public:
    node* head;
    node* tail;
    node* middle;
    int size;

    list() {
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        size = 0;
    }

    void push_back(int n) {
        if (head == nullptr) {
            head = new node(n);
            tail = head;
            size++;        
        }
        else {
            node* topush = new node(n);
            topush->pr = tail;
            tail->next = topush;
            tail = tail->next;
            size++;
        }
        if (size == 1) {
            middle = head;
        }
        if (size % 2 == 0) {
            middle = middle->next;
        }
    }

    void pop_back() {
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
            size=0;
            return;
        }
        node* t = tail;
        if (tail != nullptr) {
            tail = tail->pr;
            tail->next = nullptr;
            size--;
            if (size % 2 == 1) {
                middle = middle->pr;
            }
            delete t;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    list l;
    string str;
    string num;
    int e;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "add") {
            cin >> num;
            e = stoi(num);
            l.push_back(e);        
        }
        if (str == "gun") {
            l.pop_back();           
        }
        if (str == "milen") {
            if (l.head != l.tail) {
                node* newtail = l.middle->pr;
                l.head->pr = l.tail;
                l.tail->next = l.head;
                l.middle->pr = nullptr;
                newtail->next = nullptr;
                node* oldhead = l.head;
                node* oldtail = l.tail;
                l.head = l.middle;
                l.tail = newtail;
                if (l.size % 2 == 0) {
                    l.middle = oldhead;
                }
                if (l.size % 2 == 1) {
                    l.middle = oldtail;
                }
            }
        }
    }
    cout << l.size << endl;
    while (l.head != nullptr) {
        cout << l.head->data << ' ';
        l.head = l.head->next;
    }
}
