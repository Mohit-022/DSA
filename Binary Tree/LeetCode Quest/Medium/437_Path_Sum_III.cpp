 
class Solution {
public:
    void helper(TreeNode* root, int targetSum,long long currSum, int &count){
        if(root==NULL) return ;
        currSum+=root->val;
        if(currSum==targetSum){
            count+=1;
        }
        helper(root->left, targetSum,currSum,count);
        helper(root->right, targetSum,currSum,count);
        return;
    }
    int counter(TreeNode* root, int targetSum,int &count){
        if(root== NULL) return 0;
        helper(root,targetSum,0,count);
        counter(root->left, targetSum,count);
        counter(root->right, targetSum,count);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        return counter(root,targetSum,count);

    }
};