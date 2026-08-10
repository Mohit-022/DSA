#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LL_Stack{
public:
    int s;
    node *head;
    node *tail;
    LL_Stack(){
        s=0;
        head=tail=NULL;
    }
    void push(int val){
        node *temp=new node(val);
        if(s==0){
            head=temp;
            tail=head;
        }
        else {
            tail->next=temp;
            tail=temp;
        }
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"stack is empty "<<endl;
        }else if(s==1){
            delete tail;
            head=tail=NULL;
            s--;
        }
        else {
            node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            temp->next=NULL;
            tail=temp;
            s--;
        }
    }
    int top(){
        if(s==0) {
            cout<<"stack is empty !!  ";
            return -1;
        }
        else return tail->val;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        else return false;
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LL_Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.display();

}