
class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi){
        if(prelo>prehi) return NULL;
        TreeNode* root= new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        int i=0;
        while(i<=prehi){
            if(pre[prelo]==in[i]) break;
            i++;
        }
        int leftCount=i-prelo;
        int rightCount=inhi-i;
        root->left=build(pre, prelo+1, prelo+leftCount, in, inlo, i-1);
        root->right=build(pre, prelo+leftCount+1, prehi, in, i+1, inhi);
        return root;


    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        return build(pre, 0, n-1, in, 0, n-1);
        
    }
};