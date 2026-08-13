class MyStack {
public:
    queue<int>q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        int n=q.size();
        for(int i=1;i<=n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int p=q.front();
        q.pop();
        return p;
    }
    
    int top() {
        int n=q.size();
        for(int i=1;i<=n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int p=q.front();
        q.pop();
        q.push(p);
        return p;
        
    }
    
    bool empty() {
        if(!q.empty()) return false;
        else return true; 
    }
};

