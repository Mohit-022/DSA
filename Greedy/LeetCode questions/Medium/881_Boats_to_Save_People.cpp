#include<bits/stdc++.h>>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());  // t.c -> o(nlogn)
        int n=people.size();
        int i=0;
        int j=n-1;
        int bCount=0;

        while(i<j){ // TC -> o(n) atmost
            if(people[i]+people[j]>limit){
                bCount++;
                j--;
            }
            else if(people[i]+people[j]<=limit){
                i++;
                j--;
                bCount++;
            }
            else{}
        }
        if(i==j) bCount++;
        return bCount;
    }
};