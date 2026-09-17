class Solution {
public:
    int rev(int n){
        int r=0;
        while(n!=0){
            r*=10;
            r+=n%10;
            n=n/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m; // first int= nums[ele],  second int =frequency
        long long count=0;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
            if( m.find(nums[i])==m.end() ){   // if nums[i] not exist in map
                m[nums[i]]++;
            }
            else{  // if nums[i] exist in map
                count=count%1000000007;
                count+=(long long) (m[nums[i]]); 
                m[nums[i]]++;
            }
        }
        return count % 1000000007;

    }
};