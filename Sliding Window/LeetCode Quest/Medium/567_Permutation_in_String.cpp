#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(unordered_map<char,int>m1,unordered_map<char,int>m2){
        
        for(auto x : m1){
            if(m2.find(x.first)!=m2.end()) {
                if(m1[x.first]!=m2[x.first]) return false;
            }
            else return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        unordered_map<char,int>m1;
        for(int i=0;i<n1;i++){
            m1[s1[i]]++;
        }
        
        unordered_map<char,int>m2;
        for(int i=0;i<n1;i++){
            m2[s2[i]]++;
        }

        int flag=check(m1,m2);
        if(flag==true) return true;

        int i=n1;
        while(i<n2){
            if(m2[s2[i-n1]]==1) m2.erase(s2[i-n1]);
            else m2[s2[i-n1]]--;

            m2[s2[i]]++;
            flag=check(m1,m2);
            if(flag==true) return true;
            i++;
        }
        return flag;
    }
};