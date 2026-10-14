#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi; // pair of int int
bool cmp(pi &a, pi &b){  // a.first->weight, a.second->value
    double r1= (a.second *1.0)/ (a.first*1.0); // a.value/a.weight;
    double r2= (b.second *1.0)/ (b.first*1.0);   // b.value/b.weight
    return r1>r2;
}
double knapsack(vector<int>&weight,vector<int>&value, int n){
    vector<pi>arr;  // vector will store pair
    int s=weight.size();
    for(int i=0;i<s;i++){
        arr.push_back({weight[i],value[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    int i=0;
    double ans=0;
    while(i<s && n>0 ){
        int wt=arr[i].first;
        if(wt <= n){
            ans+=(arr[i].second)*1.0;
            n-=wt;
            
        }
        else{
            ans+= n*( (arr[i].second*1.0)/(arr[i].first*1.0) );
            n=0;
            break;
        }
        i++;
    }
    return ans;
}
int main(){
    vector<int>weight={5, 10, 15, 22, 25};
    vector<int>value={30, 40, 45, 77, 90};
    int n=60;  // n= max capacity 

    double ans=knapsack(weight,value,n);
    cout<<ans;


}