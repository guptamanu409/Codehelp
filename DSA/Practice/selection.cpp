#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>arr{4,5,7,6,2,4,6};

    int n = arr.size();

    for(int i = 0; i<n-1; i++){
        int mini = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[mini]) mini = j;
        }

        swap(arr[i],arr[mini]);
    }

    for(auto it:arr) cout<<it<<" ";

    return 0;
}