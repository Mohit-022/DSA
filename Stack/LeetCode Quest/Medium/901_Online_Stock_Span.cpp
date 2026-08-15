class StockSpanner {
public:
    vector<int>v;
    stack<int>st;
    vector<int>pgi;
    int i;
    int j;

    StockSpanner() {
        i=0;
        j=0;
    }
    
    int next(int price) {
        v.push_back(price);
        
        int p=0;
        while(!st.empty() && v[st.top()]<=v[i] ) st.pop();
        if(!st.empty()) pgi.push_back(st.top());
        else pgi.push_back(-1);
        st.push(i);
        p=i-pgi[j];
        i++;
        j++;
        return p;

    }

};
