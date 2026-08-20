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
int sum(tree *root){
    if(root==NULL) return 0;
    return root->val +sum(root->left) + sum(root->right);
}
int size(tree *root){
    if(root==NULL) return 0;
    return 1+size(root->left)+size(root->right);
}
int level(tree *root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
int height(tree * root){
    return level(root)-1;
}
int max_number(tree *root){
    if(root== NULL) return INT_MIN;
    return max( max(root->val, max_number(root->left)), max_number(root->right));
}
int min_number(tree *root){
    if(root== NULL) return INT_MAX;
    return min( min(root->val, min_number(root->left)), min_number(root->right));
}
void display(tree *root){
    if(root ==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
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
    tree *i=new tree(-9);

    a->left=b;  //root node
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    g->right=h;
    h->right=i;

    display(a);
    cout<<endl;
    cout<<"size:- "<<size(a)<<endl;
    cout<<"level:- "<<level(a)<<endl;
    cout<<"height:- "<<height(a)<<endl;
    cout<<"sum:- "<<sum(a)<<endl;
    cout<<"maximum number in tree:- "<<max_number(a)<<endl;
    cout<<"minimum nuber in tree:- "<<min_number(a)<<endl;


}