class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // ye nhi kr skte qki ..kya pata do stones ko minus krke likha or unka weight array me present stones se kam ho gya

        // sort(stones.begin(),stones.end()); 
        // int cal=0;
        // for(int i=stones.size()-1;i>=0;i--){
        //     stones[i]=abs(stones[i]-cal);
        //     cal=stones[i];
        // }
        // return cal;

        priority_queue<int>pq;
        for(int ele : stones){
            pq.push(ele);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            pq.push(abs(a-b));

        }
        return pq.top();
    }
};