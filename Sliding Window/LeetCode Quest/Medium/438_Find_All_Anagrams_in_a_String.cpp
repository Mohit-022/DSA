#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(unordered_map<char,int>m1,unordered_map<char,int>m2){
        for(auto x: m2){
            if(m1.find(x.first)!=m1.end()){
                if(m1[x.first]!=m2[x.first]) return false;
            }
            else return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>m2;  // stores all element of string p with frequency
        int n1=s.size();
        int n2=p.size();
        for(int i=0;i<n2;i++){
            m2[p[i]]++;
        }
        unordered_map<char,int>m1; // stores all element of string s with frequency
        for(int i=0;i<n2;i++){
            m1[s[i]]++;
        }

        if(check(m1,m2)==true) ans.push_back(0);
        int i=n2;

        while(i<n1){
            if(m1[s[i-n2]]==1) m1.erase(s[i-n2]);
            else m1[s[i-n2]]--;
            m1[s[i]]++;
            if(check(m1,m2)==true) ans.push_back(i-n2+1);
            i++;
        } 
        return ans;   

    }
};