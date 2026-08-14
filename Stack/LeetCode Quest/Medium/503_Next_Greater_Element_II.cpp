class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ngi(n,-1);
        stack<int>st;
        st.push(nums[n-1]);
        int i=n-1;
        int j=INT_MIN;  // store max number
        while(i>=0){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()) ngi[i]=st.top();
            
            st.push(nums[i]);
            if(j<nums[i]) j=nums[i];
            i--;
        }
        i=n-1;
        while(i>=0 && !st.empty() && nums[i]!=j){
            while(!st.empty() && st.top()<=nums[i]){
            st.pop();
            }
            if(!st.empty() ) ngi[i]=st.top();
            st.push(nums[i]);
            i--;
        }
        return ngi;
    }
};