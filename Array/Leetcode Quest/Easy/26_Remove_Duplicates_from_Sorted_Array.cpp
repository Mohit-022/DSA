class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int i=0;
        int j=1;
        int n=nums.size();
        while(i<n && j<n){
            while( j<n && nums[j]<=nums[i]){
                j++;
            }
            if(j==n) return i+1;
            else i++;
            swap(nums[i],nums[j]); 
            
            
        }
        return i+1;

    }
};