#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
public:
    int arr[50];
    int idx;
    MaxHeap(){
        idx=1;
    }
    int top(){
        if(idx>1) return arr[1];
        else {
            cout<<"heap is empty!!"<<endl;
            return INT_MIN;
        }
    }
    void push(int val){
        arr[idx]=val;
        int child=idx;
        int parent=(child)/2;
        idx++;
        while(parent>=1){
            if(arr[parent]<arr[child]) {
                swap(arr[child], arr[parent]);
            }
            else break;
            child=parent;
            parent=parent/2;
        }
        
    }
    int size(){
        return idx-1;
    }
    bool empty(){
        if(idx>1) return false;
        else return true;
    }
    void pop(){
        if(idx==1){
            cout<<"heap is empty!!"<<endl;
            return;
        }
        idx--;
        int i=1;
        arr[i]=arr[idx];
        while(i<idx){
            
            int left=2*i;
            int right=(2*i)+1;
            
            if(left<idx && right<idx){
                if(arr[left]>arr[i] || arr[right]>arr[i]){
                    int maxval=max(arr[left],arr[right]);
                    if(maxval==arr[left]){
                        swap(arr[i],arr[left]);
                        i=left;
                    }
                    else{
                        swap(arr[i],arr[right]);
                        i=right;
                    }
                }
            }
            else if(right>=idx && left<idx){
                if(arr[left]>arr[i]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
                break;
            }
            else break;
        }
    }

};
int main(){
    MaxHeap pq;
    pq.push(10);
    pq.push(9);
    pq.push(8);
    pq.push(50);
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.push(90);
    pq.push(900);
    pq.push(9000);
    pq.push(-40);
    
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.pop();
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.pop();
    cout<<pq.top()<<" "<<pq.size()<<endl;
    
}