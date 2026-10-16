#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int result=0;
        int n=answers.size();
        for( int i=0;i<n;i++){
            if(answers[i]==0){
                result++;
                continue;
            }
            if(m.find(answers[i])!=m.end()){
                m[answers[i]]++;
                if( m[answers[i]] == answers[i] ){
                    m.erase(answers[i]);
                }
                
            }
            else {
                result+=(answers[i]+1);
                m[answers[i]]=0;
            }

        }
        
        return result;
    }
};