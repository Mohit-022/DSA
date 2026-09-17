class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>m;   // first int = digit ,  second int = frequency
        int n=digits.size();
        for(int i=0;i<n;i++){  // filling map with (digit,frequency)
            m[digits[i]]++;
        }
        vector<int>v;
        for(int i=100;i<999;i+=2){  // loop 1
            int x=i;
            int a=x%10;  // once place
            x=x/10;
            int b=x%10;   // 10th place
            x=x/10;
            int c=x;   // 100th place

            if( m.find(a)!=m.end() ){
                m[a]--;   // if exist subtract frequecy of a
                if(m[a]==0) m.erase(a);
                if( m.find(b)!=m.end() ){ 
                    m[b]--;   // subtracting freq of b
                    if(m[b]==0) m.erase(b); 
                    if( m.find(c)!=m.end() ){
                        v.push_back(i);  // pushing element in vector if all the three conditions are ture
                    }
                    m[b]++;   // adding freq of b
                }
                m[a]++;  // adding frequecy of a
            }
        }
        return v;
        
    }
};