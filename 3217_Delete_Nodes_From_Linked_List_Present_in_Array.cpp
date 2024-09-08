#include <bits/stdc++.h>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> no_show(nums.begin(),nums.end());
        ListNode* new_head;
        ListNode* now_node;
        bool first_time_flag = true;
        for(;head!=NULL;){
            printf("%d \n",no_show.count(now_node->val));
            if(no_show.find(now_node->val) == no_show.end()){
                if(first_time_flag){
                    new_head = head;
                    now_node = head;
                    first_time_flag = false;
                }else{
                    now_node->next = head;
                    now_node = now_node->next;
                }
            }
            head = head->next;
        }
        return new_head;
    }
};