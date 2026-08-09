class Solution {
public:
    void swapStr(vector<char>&s,int i,int j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        // we can use in-built "swap" function but for revision i wrote self defined "swapStr" function
        while(i<j){
            swapStr(s,i,j); // swap(s[i],s[j]) ->this will also work
            i++;
            j--;
        }
    }
};