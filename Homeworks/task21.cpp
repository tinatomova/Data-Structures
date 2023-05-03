/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-6-2021/challenges/--108
*
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class bst {
public:
    node* root;
    bst() {
        root = nullptr;
    }

    node* add(int d, node* cur) {
        if (cur == nullptr) {
            return new node(d);
        }
        if (d > cur->data) {
            cur->right = add(d, cur->right);
        }
        else if (d < cur->data) {
            cur->left = add(d, cur->left);
        }
        return cur;
    }

    node* m(node* cur)
    {
        node* ncur = cur;
        while (ncur->left != nullptr)
            ncur = ncur->left;
        return ncur;
    }

    node* remove(int d, node* cur) {
        if (cur == nullptr) {
            return cur;
        }
        if (d > cur->data) {
            cur->right = remove(d, cur->right);
        }
        else if (d < cur->data) {
            cur->left = remove(d, cur->left);
        }    
        else {
            if (cur->left == nullptr) {
                node* t = cur->right;
                free(cur);
                return t;
            }
            else if (cur->right == nullptr) {
                node* t = cur->left;
                free(cur);
                return t;
            }
            node* temp = m(cur->right);
            cur->data = temp->data;
            cur->right = remove(temp->data,cur->right);
        }
        return cur;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    vector<int> vecsort;
    int toadd;
    for (int i = 0; i < n; i++) {
        cin >> toadd;
        vec.push_back(toadd);
        vecsort.push_back(toadd);
    }
    sort(vecsort.begin(), vecsort.end());
    toadd = vecsort[n - k]; 
    bst tree;
    for (int i = 0; i < n; i++) {
        tree.root=tree.add(vec[i], tree.root);
    }  
    tree.root=tree.remove(toadd, tree.root);
    queue<node*> Q;
    Q.push(tree.root);
    for(int i = 0; i < n - 1; i++){
        if (Q.front()->left != nullptr) {
            Q.push(Q.front()->left);
        }
        if (Q.front()->right != nullptr) {
            Q.push(Q.front()->right);
        }
        cout<<Q.front()->data<<" ";
        Q.pop();    
    }
}

