class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>s;
        string rev;
        int count=0;
        for(int i=0;i<words.size();i++){
            rev=words[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end()) {
                count++;
                s.erase(rev);
            }
            else{
                s.insert(words[i]);
            }
        }
        return count;
    }
};