#include "bits/stdc++.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp = head;
        for(;temp!=NULL;){
            count++;
            temp = temp->next;
        }
        int yui = count%k;
        int sa = count/k;
        vector<ListNode*> vec;  
        ListNode* now_node = head;
        ListNode* pre_node = new ListNode(0,head);
        printf("%d %d\n",sa,yui);
        for(int i=0;i<yui;i++){
            vec.push_back(now_node);
            for(int j=0;j<sa+1;j++){
                now_node = now_node->next;
                pre_node = pre_node->next;
            }
            pre_node->next = NULL;
            pre_node = new ListNode(0,now_node);
        }
        for(int i=0;i<k-yui;i++){
            vec.push_back(now_node);
            for(int j=0;j<sa;j++){
                now_node = now_node->next;
                pre_node = pre_node->next;
            }
            pre_node->next = NULL;
            pre_node = new ListNode(0,now_node);
        }
        return vec;
    }
};