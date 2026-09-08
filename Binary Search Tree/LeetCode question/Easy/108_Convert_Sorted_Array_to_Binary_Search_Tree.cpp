
class Solution {
public:
    TreeNode* Build(vector<int>& nums, int lo, int hi){
        if(lo>hi) return NULL;
        int mid= lo + (hi-lo)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left=Build(nums,lo,mid-1);
        root->right=Build(nums, mid+1,hi);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return Build(nums,0,n-1);
    }
};
