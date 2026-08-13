class MinStack {
public:
    stack<int>st;
    stack<int>min;
    int m= INT_MAX;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(min.size()==0 || value<=min.top()) min.push(value);
    }
    
    void pop() {
        if(st.empty()) return ;
        else{
            if(min.top()==st.top()) min.pop();
            st.pop();
        }
    }
    
    int top() {
        if(st.size()!=0) return st.top();
        else return -1;
    }
    
    int getMin() {
        if(min.size()==0) return 0;
        else return min.top();
    }
};
