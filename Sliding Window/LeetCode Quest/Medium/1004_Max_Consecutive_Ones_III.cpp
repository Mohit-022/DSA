class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0;
        int zcount=0;
        int n=nums.size();
        int length=0;
        while(j<n){
            if(nums[j]==0) zcount++;
            if(zcount>k){
                length=max(length, j-i);
                while(i<n && nums[i]==1) i++;
                i++;
                zcount--;
            }
            j++;
        }
        length=max(length, j-i);
        return length;

    }
};