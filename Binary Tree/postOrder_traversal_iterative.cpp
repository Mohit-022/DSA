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
void postorder(tree* root){
    stack<tree*>st;
    vector<int>v;
    st.push(root);
    while(!st.empty()){
        tree* temp=st.top();
        st.pop();
        
        if(temp->left!=NULL) st.push(temp->left);
        if(temp->right!=NULL) st.push(temp->right);
        v.push_back(temp->val);
    }
    reverse(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "; 
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
    postorder(a);
    
}