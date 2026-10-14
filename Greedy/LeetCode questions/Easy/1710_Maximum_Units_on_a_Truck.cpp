#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        int n=boxTypes.size();
        for(int i=0;i<n;i++){
            if(truckSize<boxTypes[i][0]){
                ans+=truckSize*boxTypes[i][1];
                break;
            }
            else{
                ans+=boxTypes[i][0]*boxTypes[i][1];
            }
            truckSize-=boxTypes[i][0];
        }
        return ans;
    }
};
