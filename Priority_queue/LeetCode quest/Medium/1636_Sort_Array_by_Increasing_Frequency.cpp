class Solution {
public:
    typedef pair< int, int> pi; // pair of int
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m; // element, frequency
        for(int ele : nums){
            m[ele]++;
        }
        priority_queue< pi,vector<pi>, greater<pi>  >pq; // pi is pair of( {freq,element} ) -> minheap
        
        for(auto x : m){
            pq.push({x.second,-x.first});  // minus(-) krke store kiya taki agr 2 number ki freq same ho to largest elemnt ko compare kre ..largest ko - kr diya to oo smallest ban jaeyge
        }
        
        vector<int>ans;
        while(!pq.empty()){
            int ele=-pq.top().second;  // minus kiya tha uor to ab yha wapas shi kr diya
            int freq=pq.top().first;
            while(freq--!=0){
                ans.push_back(ele);
            }
            pq.pop();
        }
       
        return ans;

    } 
};