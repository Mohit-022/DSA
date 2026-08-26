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
tree* construct(int arr[], int n){
    
    tree*root =new tree(arr[0]);
    queue<tree*>q;
    q.push(root);
    int i=1;
    int j=2;
    

    while(i<n && !q.empty()){
        tree *temp=q.front();
        q.pop();

        tree* l;
        tree* r;

        if(arr[i] !=INT_MIN) l=new tree(arr[i]);
        else l=NULL;

        if(j <n && arr[j]!=INT_MIN) r=new tree(arr[j]);
        else r=NULL;

        temp->left=l;
        temp->right=r;

        if(l!=NULL ) q.push(l);
        if(r!=NULL ) q.push(r);
        i+=2;
        j+=2;

    }
    return root;

}
void levelorder(tree *root){
    queue<tree*>q;
    q.push(root);
    while(!q.empty()){
        tree* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        
    }
}
int main(){

    int arr[]={1,2,3,INT_MIN,4,5,6,7,8,INT_MIN,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    tree* root=construct(arr,n);
    levelorder(root);

}