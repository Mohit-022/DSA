class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        long long sum=0;
        
        for(int i=0;i<k;i++){
            m[nums[i]]++;
            sum=sum+nums[i];
        }
        long long maxsum=0;
        if(m.size()==k) maxsum=max(sum,maxsum);
        for(int i=k;i<nums.size();i++){
            
            m[nums[i]]++;
            if(m[nums[i-k]]==1) m.erase(nums[i-k]);
            else m[nums[i-k]]--;
            
            sum=sum+nums[i]-nums[i-k];
            if(m.size()==k) maxsum=max(sum,maxsum);
            
        }
        return maxsum;
        
    }
};