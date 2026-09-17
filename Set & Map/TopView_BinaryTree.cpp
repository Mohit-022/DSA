#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
TreeNode* construct(int arr[], int n){   // constructing binary tree
    TreeNode* root=new TreeNode(arr[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i=1;
    int j=2;
    
    while(i<n && !q.empty()){
        TreeNode* temp=q.front();
        q.pop();

        TreeNode* l;
        TreeNode* r;

        if(arr[i]!=INT_MIN) l=new TreeNode(arr[i]);
        else l=NULL;
        if(j<n && arr[j]!=INT_MIN ) r=new TreeNode(arr[j]);
        else r=NULL;
        
        temp->left=l;
        temp->right=r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;

    }
    return root;
} 
int levels(TreeNode* root){  // find out level of tree
    if(root==NULL) return 0;
    return 1+max(levels(root->left), levels(root->right));
}
void levelPrinting(TreeNode* root,int curr, int levels){   // particular level print krne ke liye
    if(root==NULL) return;
    if(curr==levels){
        cout<<root->val<<" ";
        return;
    }
    levelPrinting(root->left,curr+1,levels);
    levelPrinting(root->right,curr+1,levels);

}
void levelorder(TreeNode* root){  // sare levels alg alg line me print krne ke liye
    if(root==NULL) return;
    int level=levels(root);
    for(int i=1;i<=level;i++){
        levelPrinting(root,1,i);
        cout<<endl;
    }

}
void print(TreeNode* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
void topView(TreeNode* root){
    if(root==NULL) return;

    queue< pair<TreeNode* ,int> >q;
    unordered_map<int,int>m; // first int= level,  second int= value

    pair<TreeNode*,int> r ;
    r.first=root;
    r.second=0;
    q.push(r);

    while(!q.empty()){
        TreeNode* temp=q.front().first;
        int level=q.front().second;
        q.pop();
        if(m.find(level)==m.end()){  // level not exist
            m[level]=temp->val;
        }
        if(temp->left!=NULL) {
            pair<TreeNode*,int> p ;
            p.first=temp->left;
            p.second=level-1;
            q.push(p);
        }
        if(temp->right!=NULL) {
            pair<TreeNode*,int> p ;
            p.first=temp->right;
            p.second=level+1;
            q.push(p);
        }
    }
    vector<int>v;
    int maxLevel=INT_MIN;
    int minLevel=INT_MAX;
    for (auto x:m){
        int level=x.first;
        maxLevel=max(maxLevel,level);
        minLevel=min(minLevel,level);
    }
    for(int i=minLevel;i<=maxLevel;i++){
        // v.push_back(m[i]);
        cout<<m[i]<<" ";
    }
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr,n);  // tree constrution
    // levelPrinting(root, 1, 2);
    // print(root);
    // levelorder(root);
    topView(root);


}