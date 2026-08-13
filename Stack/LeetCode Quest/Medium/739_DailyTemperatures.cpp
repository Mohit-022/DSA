class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ngi (n,n); // next greater index
        vector<int>ans(n,0);
        if(n==1) return ans;  // using temperatures array as a answer array
        stack<int>st; 
        st.push(n-1);
        ngi[n-1]=n;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(!st.empty()) ngi[i] = st.top();
            else ngi[i]=n;

            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans[i]=ngi[i]-i; //temp=ans;
            if(ngi[i]==n) ans[i]=0;// temp=ans
        }
        return ans; 
    }
};