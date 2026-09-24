class Solution {
public:
    typedef pair<int,int> pi; 
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue< pi  >pq; // maxHeap pair(distance,number)
        for(int i=0;i<arr.size();i++){
            int distance= abs(x-arr[i]);
            pq.push({distance,arr[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            pi ele=pq.top();
            ans.push_back(ele.second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};