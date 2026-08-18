class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        int n= path.size();
        string p="";
        stack<string>st;
        while(i<n){
            if(path[i]=='/'){
                while( i<n && path[i]=='/'){
                    i++;
                }
                
            }
            else if(path[i]=='.'){
                p="";
                while( i<n && path[i]!='/'){
                    p=p+path[i];
                    i++;
                }
                st.push( p);
                p="";
                if(st.top()==".") st.pop();
                else if(st.top()==".."){
                    st.pop();
                    if(!st.empty() )st.pop();
                }
            }
            else {
                p="";
                while( i<n && path[i]!='/'){
                    p=p+path[i];
                    i++;
                }
                st.push(p);
                p="";
            }
        }
        p="";
        while(!st.empty()){
            
            p=st.top()+p;
            p="/"+p;
            st.pop();
        }
        if(p.size()==0) return "/";
        return p;
    }
};