#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>a{4,8,9,7,6,3,2};
    int n = a.size();

    for(int i = 1; i<n; i++){
        bool swapped = false;
        for(int j = 0; j<n-i; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped = true;
            }
        }
        if(swapped = false) break;
    }

    for(auto it:a)cout<<it<<" ";

    return 0;
}