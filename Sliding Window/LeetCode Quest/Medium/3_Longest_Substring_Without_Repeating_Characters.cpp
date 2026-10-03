class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>m; // {char,int} ->first= character hai .. ye v chlega qki int me convert ho jata hai character ASCII value
        int i=0;
        int j=0;
        int length=0;
        while(j<s.size()){
            length=max(length,j-i);
            if(m.find(s[j])!=m.end()){
                while(i<j && s[j]!=s[i]){
                    m.erase(s[i]);
                    i++;
                }
                if(m.find(s[j])!=m.end()) m.erase(s[i]);
                i++;
            }
            m[s[j]]++;
            j++;
        }
        length=max(length,j-i);
        return length;
    }
};