class Solution {
public:
    typedef pair< int, int>pi; // pair of int
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;   // element, frequncy
        for(int ele : nums){
            m[ele]++;
        }
        priority_queue<pi, vector<pi>, greater<pi> >pq;  // pair of( frequncy, element ) -> minheap
        for( auto x : m){
            int freq=x.second;
            int ele=x.first;
            pq.push({freq,ele});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};