class Solution {
public:
    typedef pair<int, vector<int> >piv; // pair of int & vector
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< piv >pq;
        for(int i=0; i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dis= x*x + y*y;
            pq.push({dis,points[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            piv p=pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
    }
};