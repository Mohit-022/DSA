class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        int n=heights.size();
        vector<int>nsei(n,n);  // next smaller element index 
        vector<int>psei(n,-1);    // previous smaller element index
        stack<int>st;
        int mx=INT_MIN;
        int area=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) psei[i]=-1;
            else psei[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while( !st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()) nsei[i]=n;
            else nsei[i]=st.top();

            st.push(i);

            // yhi pe area nikal kr... max v store kr rha hu mx me... bad me mx return kr dunga
            
            area= (nsei[i]-psei[i]-1)*heights[i]; 
            mx=max(mx,area);
        }
        return mx;
    }
};