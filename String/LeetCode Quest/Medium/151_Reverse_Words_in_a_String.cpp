class Solution {
public:
    string reverseWords(string s) {
        string fake="";
        vector<string>str;
        int i=0;
        
        while(s[i]!='\0'){
            if(s[i]==' '){
                if(fake.size()!=0){
                    str.push_back(fake);
                    fake.clear();
                }
                i++;
            }
            else{
                fake.push_back(s[i]);
                i++;
            }
        }
        
        if(fake.size()!=0)str.push_back(fake);
        fake.clear();
        for(int i=str.size()-1;i>=0;i--){
            fake+=str[i];
            if(i!=0) fake+=' ';  
        }
        return fake;
        
    }
};