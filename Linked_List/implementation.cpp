#include<bits/stdc++.h>
using namespace std;
class node {
public:
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LinkedList{
public: 
    node *head;
    node *tail;
    int size;
    LinkedList(){
        head=tail=NULL;
        size=0;
    }
    void addHead(int val){
        node *temp=new node(val); // making temporary node to store value, i will add this node at head
        temp->next=head;
        head=temp;
        if(size==0) tail=head;
        size++;
    }
    void addTail(int val){
        if(size==0) addHead(val);
        else {
            node* temp=new node(val); // making temporary node to store value, i will add this node at tail
            tail->next=temp;
            tail=temp;
            size++;
        } 
    }
    void insert(int val, int index){
        
        if(index>size || index<0 ){
            cout<<"invalid index..!!"<<endl;
            return;
        }
        else if(index==0) addHead(val);
        else if(index==size) addTail(val);
        else {
            node* temp=new node(val);   // making node to store value which i want to add
            node*t=head; // traversal node
            for(int i=1;i<=index-1;i++){
                t=t->next;
            }
            temp->next=t->next;
            t->next=temp;
            size++;
        }
    }
    void deleteHead(){
        if(size==0){
            cout<<"LinkedList is empty.."<<endl;
            return;
        }else if(size==1) head=tail=NULL;
        else head=head->next;
        size--;
    }
    
    void deleteTail(){
        if(size==0) {
            cout<<"linkedlist is empty..."<<endl;
            return;
        }
        else if(size==1) head=tail=NULL;
        else {
            node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
        }
        size--;
    }
    int get(int index){
        
        if(index>=size || index<0 ){
            cout<<"invalid index..!!"<<endl;
            return -1;
        }
        else if(index==0) return head->val;
        else if(index==size-1) return tail->val;
        else {
            node*t=head; // traversal node
            for(int i=0;i<index;i++){
                t=t->next;
            }
            return t->val;
        }
    }
    void display(){  // this will print linked list value
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        if(size==0) cout<<"linket list is empty..";
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.addTail(10);
    ll.addTail(20);
    ll.addTail(30);
    ll.addHead(00);
    ll.addHead(-1);
    ll.insert(300,4);
    ll.display();

    ll.deleteHead();
    ll.display();

    ll.deleteTail();
    ll.display();
    cout<<ll.get(0)<<endl;
    cout<<ll.get(4)<<endl;

    /*   commands

    addTail() = to add any elements in last of list
    addHead() = to add any element in the beggining of list
    insert(index)  = to insert element at any index
    get(index) = to get elements of any index
    deleteHead() = to delete head of list
    deleteTail() = to delete tail of list
    deleteIndex(index) = to delete elements of given index
*/


}