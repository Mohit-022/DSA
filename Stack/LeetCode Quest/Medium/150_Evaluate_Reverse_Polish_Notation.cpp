class Solution {
public:
    int cal(string s,int a, int b){
        if(s=="+") return b+a;
        if(s=="-") return b-a;
        if(s=="*") return b*a;
        if(s=="/") return b/a;
        return 0;
    }
    bool isDigit(string s){
        if(s=="+" || s=="-" || s=="/"|| s=="*") return false;
        else return true;
    }
    int evalRPN(vector<string>& tokens) {
        
        int i=0;
        int n=tokens.size();
        if(n==1) return stoi(tokens[0]);
        stack<int>st;
        while(i<n){
            
            if(isDigit(tokens[i])==false){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=cal(tokens[i],a,b);
                st.push(c);
            }
            else{
                int p=stoi(tokens[i]);
                st.push(p);
            }
            i++;
        }
        return st.top();

    }
};