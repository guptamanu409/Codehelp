#include<iostream>
#include<climits>
using namespace std;


int main(){

    int arr[] = {5,6,7,1,2};

    int s = 0;
    int e = 4;
    int mid = s+(e-s)/2;
    int ans = INT_MIN;
    while(s<e){
        if(arr[mid]>arr[mid+1]){
            ans = max(ans, arr[mid]);
            e = mid - 1;
        }

        else{
            s = mid;
        }

        mid = (s+e)/2;
    }

    cout<<ans;

    return 0;
}