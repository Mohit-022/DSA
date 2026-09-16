class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(m.find(arr[i])!=m.end()){
                m[arr[i]]++;
            }
            else{
                m[arr[i]]=1;
            }
        }
        unordered_set<int>s;
        for(auto ele : m){
            int freq=ele.second;
            if( s.find(freq)!=s.end() ){
                return false;
            }
            else{
                s.insert(freq);
            }
        }
        return true;
    }
};