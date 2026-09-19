class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string> >m;
        
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            if(m.find(str)!=m.end()){
                m[str].push_back(strs[i]);
            }else{
                m[str]={strs[i]};
            }
        }
        for(auto x: m){
            ans.push_back(x.second);
        }
        return ans;
    }
};