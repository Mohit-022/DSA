class Solution {
public:
    bool is_digit(char s){
        return s>='0' && s<='9'; // best use of AND operator
    }
    string decodeString(string s) {
        stack<int>d;
        stack<string>st;   
        int i=0;
        int n=s.size();
        int k=0;
        string p="";
        
        while(i<n){
            if( is_digit(s[i]) ) {
                while( is_digit(s[i]) ){
                    k= k*10 + (s[i]-'0');
                    i++;
                }
                d.push(k);
                k=0;
            }
            else if( s[i]!=']' ){

                st.push( string(1,s[i]) );   // s[i]= character, making this integer 
                i++;
            }
            else{

                while(!st.empty() && st.top()!="["){
                    p= st.top()+p;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                st.push(p);
                p="";
                if( !d.empty() ){
                    for(int j=1; j<=d.top();j++){
                        p=p+st.top();
                    }
                    st.pop();
                    st.push(p);
                    p="";
                    d.pop();
                }
                i++;
                
            }
        }
        if(st.size()==1) return st.top();
        else{
            p="";
            while(!st.empty()){
                p=st.top()+p;
                st.pop();
            }
            return p;
        }
        
    }
};