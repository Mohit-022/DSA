class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int> >minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size()==0 || num < maxheap.top()){
            maxheap.push(num);
        }
        else minheap.push(num);
        int x=abs((int)maxheap.size()-(int)minheap.size());  // (int) laganapdega qki size kbhi - me nhi atta to c++ me isko unsigend interger mante hai
        if(x>1){
            if(maxheap.size()>minheap.size()){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            else{
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()) return (maxheap.top()+minheap.top())/2.0;
        else {
            if(maxheap.size()>minheap.size()) return maxheap.top();
            else return minheap.top();
        }
    }
};
