#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int n=s.size();
        int length=0;
        int maxlength=0;
        int i=0, j=0;
        int maxfreq=0;
        while(j<n){
            m[s[j]]++;
            maxfreq=max(maxfreq,m[s[j]]);
            length=j-i+1;
            if((length-maxfreq)<=k){
                maxlength=max(length,maxlength);
            }
            else if((length-maxfreq)>k){
                while(i<j && (length-maxfreq)>k){
                    m[s[i]]--;
                    i++;
                    length=j-i+1;
                }
            }
            else {};
            j++;
        }
        maxlength=max(maxlength,j-i);
        return maxlength;
    }
};