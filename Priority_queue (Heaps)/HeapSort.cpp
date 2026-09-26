#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,5,35,22,65,10,-2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    // printing normal array
    for(int ele : arr){  // inserting in heap
        cout<<ele<<" ";
        maxHeap.push(ele);
        minHeap.push(ele);
    }
    cout<<endl;
    vector<int>deccending;
    while(!maxHeap.empty()){
        int top=maxHeap.top();
        deccending.push_back(top);
        maxHeap.pop();
    }

    
    
    vector<int>ascending;
    while(!minHeap.empty()){
        int top=minHeap.top();
        ascending.push_back(top);
        minHeap.pop();
    }
    cout<<"sorting min to max"<<endl;
    for(int ele : ascending){
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<"sorting max to min "<<endl;
    for(int ele : deccending){
        cout<<ele<<" ";
    }
}