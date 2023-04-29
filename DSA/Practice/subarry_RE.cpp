#include<bits/stdc++.h>
using namespace std;

void prSub(int arr[], int index, vector<int>&ds, int n){

    for(auto it:ds) cout<<it<<" ";
    cout<<endl;
    if(index>=n) return;

    if(ds.size()>0){
        ds.push_back(arr[index]);
        prSub(arr,index+1,ds,n);
    }

    else{
        for(int i = 0; i<n; i++){
            ds.push_back(arr[i]);
            prSub(arr,i+1,ds,n);
            ds.pop_back();
        }
    }
    ds.pop_back();
}

int main(){

    int arr[5] = {1,2,3,4,5};
    vector<int>ans;
    prSub(arr,0,ans,5);

    return 0;
}