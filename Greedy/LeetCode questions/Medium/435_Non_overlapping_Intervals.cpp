#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=0;
        int lastend=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            vector<int>curr=intervals[i];
            if(lastend>curr[0]) ans++;
            else{
                lastend=curr[1];
            }
        }
        return ans;
    }
};