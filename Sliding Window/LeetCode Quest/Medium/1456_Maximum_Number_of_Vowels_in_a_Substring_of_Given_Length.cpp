class Solution {
public:
    bool is_vowel(char ch){
        if(ch== 'a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            if(is_vowel(s[i])){
                sum++;
            }
        }
        int maxsum=sum;
        for(int i=k;i<s.size();i++){
            if(is_vowel(s[i])) sum++;
            if(is_vowel(s[i-k])) sum--;
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};