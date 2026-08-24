// Pre Order traversal

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

void PreOrder_display(tree *root){
    if(root ==NULL) return;  // base class
    cout<<root->val<<" ";   // printing tree in pre order
    PreOrder_display(root->left);    
    PreOrder_display(root->right);
}
void InOrder_display(tree *root){
    if(root ==NULL) return;  
     
    InOrder_display(root->left); 
    cout<<root->val<<" ";     
    InOrder_display(root->right);
}
void PostOrder_display(tree *root){
    if(root ==NULL) return;  
    
    PostOrder_display(root->left);    
    PostOrder_display(root->right);
    cout<<root->val<<" ";   
}
int main(){
    
    tree *a=new tree(1);   // root node
    tree *b=new tree(2);
    tree *c=new tree(3);
    tree *d=new tree(4);
    tree *e=new tree(5);
    tree *f=new tree(6);
    tree *g=new tree(7);
    tree *h=new tree(8);
    tree *i=new tree(9);

    a->left=b;  //root node
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    g->right=h;
    h->right=i;

    // pre order traversal
    PreOrder_display(a);  
    cout<<endl;
    // in order traversal
    InOrder_display(a);
    cout<<endl;
    //post order traversal
    PostOrder_display(a);
    cout<<endl;
    


}