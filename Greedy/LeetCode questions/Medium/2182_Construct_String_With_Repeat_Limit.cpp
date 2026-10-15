#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<char,int>pci; // pci ->pair of char & int
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>m;
        priority_queue<pci>pq;

        int n=s.size();

        for(int i=0;i<n;i++){   // pushing into maps
            m[s[i]]++;
        }
        string ans="";

        for(auto p : m){
            pq.push(p);
        }
        while(!pq.empty()){
            pci largest=pq.top();
            pq.pop();
            int len=min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                ans+=largest.first;
            }
            pci secondLargest;
            if(largest.second-len >0){
                if(pq.size()>0){
                    secondLargest=pq.top();
                    pq.pop();
                    ans+=secondLargest.first;
                    
                }
                else {
                    return ans;
                }
                if(secondLargest.second-1 > 0){
                    pq.push({secondLargest.first,secondLargest.second-1});
                }
                pq.push({largest.first,largest.second-len});

            }
        }
        return ans;
    }

};