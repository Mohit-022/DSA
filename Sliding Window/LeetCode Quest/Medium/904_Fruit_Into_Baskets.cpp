class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        int maxcount=0;
        int count=0;
        unordered_map<int,int>m;

        while(j<fruits.size()){
           
            m[fruits[j]]++;
            if(m.size()>2){
                maxcount=max(j-i,maxcount);
                while(i<j && m.size()!=2){
                    if(m[fruits[i]]==1) m.erase(fruits[i]);
                    else m[fruits[i]]--;
                    i++;
                }
                
            }
            j++;
        }
        if(m.size()<=2 )maxcount=max(j-i,maxcount);
        return maxcount;
    }
};