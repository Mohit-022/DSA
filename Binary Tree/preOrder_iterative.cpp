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
void preorder(tree *root){
    stack<tree*>st;
    st.push(root);
    while(!st.empty()){
        tree *temp=st.top();
        st.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
        
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
    preorder(a);
}