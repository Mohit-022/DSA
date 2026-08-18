// negtaive number case is also included
// space problem solved

#include<bits/stdc++.h>
using namespace std;
bool is_digit(char ch){
    return ch>='0' && ch<='9';
}
float calculate(float a, float b, char ch){
    if(ch == '+') return b+a;
    if(ch == '-') return b-a;
    if(ch == '*') return a*b;
    if(ch == '/') return b/a;
}
int priority (char ch){
    if(ch=='+' || ch =='-') return 1;
    else if(ch == '*' || ch== '/') return 2;
}

int main(){
    string s= "-100 - 20 * (2*3 + -2) / 5 + 7 * (6 - 4)";
    int i=0;
    int n=s.size();
    stack<float>nums;
    stack<char>op;
    float k=0;
    string p="";
    while(i<n){
        if(  is_digit(s[i]) ){  
            while( i<n && is_digit(s[i]) ){
                k=k*10 + (s[i]-'0');
                i++;
            }
            nums.push(k);
            k=0;
        }
        else if(s[i]==' ') {
            i++;
        }
        else if(s[i]=='('){
            op.push('(');
            i++;
        }
        else if( s[i]=='+' ||  s[i]=='-' ||  s[i]=='*'  ||  s[i]=='/'  ){

            if(s[i]=='-' && is_digit(s[i+1])){
                i++;
                while( i<n && is_digit(s[i]) ){
                    k=k*10 + (s[i]-'0');
                    i++;
                }
                nums.push(-k);
                k=0;
                
            }
            else if( op.empty()  || op.top()== '(' || priority(s[i])> priority(op.top())  ) {
                op.push( s[i] );
                i++;
            }
            else{
                while(!op.empty() && op.top()!= '(' && priority(s[i])<= priority(op.top())  ){
                    float a=nums.top();
                    nums.pop();
                    float b=nums.top();
                    nums.pop();
                    float c=calculate(a,b,op.top());
                    
                    nums.push(c);
                    op.pop();
                }
                op.push(s[i]);
                i++;
            }
            
        }
        else if(s[i]==')'){
            while(op.top()!='('){
                float a=nums.top();
                nums.pop();
                float b=nums.top();
                nums.pop();
                float c=calculate(a,b,op.top());
                nums.push(c);
                op.pop();
            }
            op.pop();
            i++;
            
        }
        
    }
    while(!op.empty()){
        float a=nums.top();
        nums.pop();
        float b=nums.top();
        nums.pop();
        float c=calculate(a,b,op.top());
        nums.push(c);
        op.pop();
    }
    cout<<nums.top();

}
