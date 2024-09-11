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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* now_node = head->next;
        ListNode* pre_node = head;
        for(;now_node!=NULL;){
            int gcd_val = gcd(now_node->val,pre_node->val);
            ListNode* temp_node = new ListNode(gcd_val,now_node);
            pre_node->next = temp_node;
            pre_node=now_node;
            now_node=now_node->next;
        }
        return head;
    }
};