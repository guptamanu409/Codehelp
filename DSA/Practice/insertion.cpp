#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>a{4,7,8,2,6,4,3,1,2};
    int n = a.size();

    for(int i = 1; i<n; i++){
        int temp = a[i];
        int j = i-1;
        for( ;j>=0; j--){
            if(a[j]>temp){
                a[j+1] = a[j];
            }
            else break;
        }
        a[j+1] = temp;
    }

    for(auto it:a) cout<<it<<" ";

    return 0;
}