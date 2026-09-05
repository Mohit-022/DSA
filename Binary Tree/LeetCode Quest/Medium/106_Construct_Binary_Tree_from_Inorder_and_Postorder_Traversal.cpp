
class Solution {
public:
    TreeNode* Build(vector<int>& in,int inStart,int inEnd, vector<int>& post, int postStart,int postEnd){
        if(inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(post[postStart]);

        int i=inStart;
        while(i<inEnd){
            if(post[postStart]==in[i]) break;
            i++;
        }
        int rightCount=i-inStart;
        int leftCount=inEnd-i;
        root->right= Build(in, inStart, i-1, post, postStart+1, postStart+rightCount);
        root->left= Build(in, i+1, inEnd, post, postStart+rightCount+1, postEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=post.size();
        reverse(in.begin(), in.end());
        reverse(post.begin(), post.end());
        return Build(in,0,n-1, post, 0, n-1);
        
    }
};