class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>ngi2(n,-1);
        stack<int>st;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums2[i]>st.top()){
                st.pop();
            }
            if(!st.empty()) ngi2[i]=st.top();
            else ngi2[i]=-1;
            st.push(nums2[i]);
        }
        int j=0;
        for(int i=0;i<nums1.size();i++){
            j=0;
            while(j<n && nums1[i]!=nums2[j]){
                j++;
            }
            nums1[i]=ngi2[j];
        }
        return nums1;
        
    }
};