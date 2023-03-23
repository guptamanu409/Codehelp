#include<bits/stdc++.h>
using namespace std;


int odd_fr_even(vector<int>&a){
    int s = 0;
    int e = a.size()-1;
    int mid = s+(e-s)/2;

    int ans = 0;
    while(s<=e){

        if(s==e){
            ans = a[s];
            break;
        }

        if(mid&1){
            if(mid+1<a.size() && a[mid]==a[mid+1]) e = mid - 1;
            else s = mid + 1;
        }

        else{
            if(mid+1<a.size() && a[mid]==a[mid+1]) s = mid + 2;
            else{
                ans = a[mid];
                e = mid;
            }
        }

        mid = s+(e-s)/2;
    }

    return ans;
}


int main(){

    vector<int>a{1,2,2,3,3,4,4};
    cout<<odd_fr_even(a);

    return 0;
}