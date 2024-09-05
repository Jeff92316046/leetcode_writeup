#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> vec;
    vector<int> postorder(Node* root) {
        recur(root);
        return vec;
    }
    void recur(Node *now){
        if(now == NULL)return;
        for(int i=0;i<now->children.size();i++){
            recur(now->children[i]);
        }
        vec.push_back(now->val);
    }
};