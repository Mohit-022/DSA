#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int> >pq;
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        while(k!=0){
            int ele=pq.top();
            if(ele==0) break;
            if(ele>0){ // if positive number is found.. keep negating smallest element
                if(k%2==0) return sum; 
                else{
                    sum-=2*ele;
                    return sum;
                }
            }
            else{  // pq.top = negative number;
                pq.pop();
                pq.push(ele*-1);
                sum-=ele;
                sum+= (-1*ele);
            }
            k--;
        }
        return sum;
    }
};