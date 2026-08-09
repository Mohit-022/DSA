#include<bits/stdc++.h>
using namespace std;
class vector_stack{
public:
    vector<int>v;
    int s;
    vector_stack(){
        s=0;
    }
    int top(){
        if(s==0){
            cout<<"stack is empty!!"<<endl;
            return-1;
        }else return v[s-1];
    }
    void push(int val){
        v.push_back(val);
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"stack is empty!!"<<endl;
        }else {
            v.pop_back();
            s--;
        }
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0){
            return true;
        }
        else {
            return false;
        }
    }
    void display(){
        for(int x : v ){
            cout<<x<<" ";
        }
        cout<<endl;
    }

};
int main(){
    vector_stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.display();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;


}