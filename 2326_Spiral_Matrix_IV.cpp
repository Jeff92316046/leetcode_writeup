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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix_t;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            matrix_t.push_back(temp);
        }
        int count=0;
        /* for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                printf("%d ",matrix_t[i][j]);
            }
            printf("\n");
        } */
        ListNode* temp = head;
        vector<int> temp_vec;
        for(int i=0;temp!=NULL;i++){
            count++;
            temp_vec.push_back(temp->val);
            temp = temp->next;
        }
        int cursor_m = 0;
        int cursor_n = 0;
        int m_counter = 0;
        int n_counter = 0;
        int m_count = m-1;
        int n_count = n;
        bool move_m_or_n = false;//true = m,false = n
        bool m_plus_or_minus = true;// true = +,false = -
        bool n_plus_or_minus = true;// true = +,false = -
        bool list_first = true;
        /* printf("%d\n",count); */
        for(int i=0;i<m*n;i++){
            /* printf("--------\n"); */
            
            if(i<count){
                matrix_t[cursor_m][cursor_n] = temp_vec[i];
            }else{
                matrix_t[cursor_m][cursor_n] = -1;
            }
            list_first = false;
            if(move_m_or_n){
                
                if(m_counter < m_count-1){
                    if(m_plus_or_minus){
                        cursor_m++;
                    }else{
                        cursor_m--;
                    }
                }
                m_counter++;
                if(m_counter == m_count){
                    m_count--;
                    m_counter = 0;
                    m_plus_or_minus = !m_plus_or_minus;
                    move_m_or_n = !move_m_or_n;
                    list_first = true;
                }
                
                
            }else{
                if(n_counter < n_count-1){
                    if(n_plus_or_minus){
                        cursor_n++;
                    }else{
                        cursor_n--;
                    }

                }
                n_counter++;
                if(n_counter == n_count){
                    n_count--;
                    n_counter = 0;
                    n_plus_or_minus = !n_plus_or_minus;
                    move_m_or_n = !move_m_or_n;
                    list_first = true;
                }
                
                
                
            }    
            if(list_first){
                if(move_m_or_n){
                    if(m_plus_or_minus){
                        cursor_m++;
                    }else{
                        cursor_m--;
                    }
                }else{
                    if(n_plus_or_minus){
                        cursor_n++;
                    }else{
                        cursor_n--;
                    }
                }
            }
            /* printf("%d %d %d %d\n",cursor_m,cursor_n,m_counter,n_counter);
            printf("%d %d\n",m_count,n_count); */
        }
        return matrix_t;
    }
};