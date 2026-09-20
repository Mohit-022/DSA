class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int>m1,m2;
        
        for(int i=0;i<word1.size();i++){  // filling m1 and m2 (char with frequency)
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        
        // comapring m1 char and m2 char... if different return false
        for(auto x : m1){
            if(m2.find(x.first)==m2.end()) return false;
        }

        unordered_map<int,int> f1,f2;
        for(auto x : m1){ // filing f1 =m1 ke frequency ka frequency 
            f1[x.second]++;
        }
        for(auto x : m2){ // filing f2  = m2 ke frequency ka frequency
            f2[x.second]++;
        }

        // comparing f1 and f2
        for(auto x : f1){
            int key=x.first;
            if(f2[key]!=f1[key]) return false;
        }
        return true;
    }
};