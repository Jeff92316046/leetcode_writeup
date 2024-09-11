#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        if(start>goal){
            for(;start>0;){
                if(start%2!=goal%2){
                    count++;
                }
                start/=2;
                goal/=2;
            }
            return count;
        }else if(start<goal){
            for(;goal>0;){
                if(start%2!=goal%2){
                    count++;
                }
                start/=2;
                goal/=2;
            }
            return count;
        }else{
            return 0;
        }
    }
};