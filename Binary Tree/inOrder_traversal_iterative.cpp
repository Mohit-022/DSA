#include<bits/stdc++.h>
using namespace std;
class tree{
public:
    int val;
    tree *left;
    tree *right;

    tree(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};
void inorder(tree* root){
    stack<tree*>st;
    tree* node=root;
    
    while(!st.empty() || node!=NULL ){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{ // node is NULL
            tree* temp=st.top();
            st.pop();
            cout<<temp->val<<" ";
            node=temp->right;
        }
    }
}

int main(){
    
    tree *a=new tree(1);   // root node
    tree *b=new tree(2);
    tree *c=new tree(3);
    tree *d=new tree(4);
    tree *e=new tree(5);
    tree *f=new tree(6);
    tree *g=new tree(7);
    // tree *h=new tree(8);
    // tree *i=new tree(9);

    a->left=b;  //root node
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    // g->right=h;
    // h->right=i;
    inorder(a);
    
}