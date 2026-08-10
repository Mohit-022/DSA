class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char>st;
        int i=0;
        int n=s.size();
        while(s[i]!='\0'){
            if( s[i]=='('  || s[i]=='{'  || s[i]=='[' ){
                st.push(s[i]);
                i++;
            }
            else if( s[i]==')' || s[i]=='}' || s[i]==']'  ){
                if(st.empty() ) return false;
                else if( st.top()=='(' && s[i]==')' ){
                    st.pop();
                    i++;
                }
                else if(st.top()=='{' && s[i]=='}'){
                    st.pop();
                    i++;
                }
                else if( st.top()=='[' && s[i]==']'){
                    st.pop();
                    i++;
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};