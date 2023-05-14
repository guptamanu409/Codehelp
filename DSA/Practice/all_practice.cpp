#include<bits/stdc++.h>
using namespace std;


bool b_s(int arr[], int n, int tar=0){

    int s = 0;
    int e = n-1;

    int mid = s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==tar) return true;
        if(arr[mid]<tar)s = mid+1;
        else e = mid - 1;
        mid = s+(e-s)/2;
    }

    return false;
}

double point_ke_bad(int div, int quo, int divi, int precision){
    double ans = quo*1.0;
    double step = 0.1;

    for(int i = 0; i<precision; i++){
        for(double j = ans; (div*j)<divi; j+=step){
            ans = j;
        }
        step = step/10;
    }

    return ans;

}

double div_two_num(int div, int divi, int pre){

    int s = 0;
    int e = divi;
    int mid = s+(e-s)/2;

    int ans = 0;
    while(s<=e){
        if(div*mid>divi) e = mid-1;
        else{
            ans = mid;
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }
    return point_ke_bad(div,ans,divi,pre);
}

int any_peak(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(mid+1<n && arr[mid]>arr[mid+1] && mid-1>=0 && arr[mid]>arr[mid-1]) return mid;
        if(mid+1<n && arr[mid]>arr[mid+1]) e = mid;
        else s = mid + 1;
        mid = s+(e-s)/2;
    }
    return -1;
}

bool book_allocate(int arr[], int n, int allocate, int m){
    int sum = 0;
    int count = 1;

    for(int i = 0; i<n; i++){
        if(sum+arr[i]>allocate){
            count++;
            sum = arr[i];
            if(count>m) return false;
        }
        else sum+=arr[i];
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false); //Removes sync between printf and cout
    cin.tie(NULL); //Removes sync between cin and cout

    int arr[] = {12,34,67,90};
    int n = sizeof(arr)/sizeof(int);

    //cout<<b_s(arr,n,10);

    //cout<<div_two_num(2,5,2);

    //cout<<any_peak(arr,n);

    int max_pages = accumulate(arr,arr+n,0);
    int ans = 0;

    int s = 0;
    int e = max_pages;

    int mid = s+(e-s)/2;
    while(s<=e){
        if(book_allocate(arr,n,mid,2)){
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;

        mid = s+(e-s)/2;
    }
    cout<<ans;

    return 0;
}