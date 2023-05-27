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
        if(arr[i]>allocate) return false; //Not possible to allocate this book at all

        if(sum+arr[i]>allocate){ //Allocate the books to the student
            count++;
            sum = arr[i];
            if(count>m) return false;
        }
        else sum+=arr[i];
    }
    return true;
}

bool painters_partition(int arr[], int n, int time, int painters){
    int c = 1;
    int sum = 0;

    for(int i = 0; i<n; i++){
        if(arr[i]>time) return false; // Not possible to paint the board in given time

        if(arr[i]+sum>time){ //Allocate the boards to the painter
            c++;
            sum = arr[i];
            if(c>painters) return false;
        }

        else sum+=arr[i];
    }
    return true;
}

bool aggressive_cows(int arr[], int gap, int n, int cows){
    int c = 1;
    int placed = arr[0];

    for(int i = 1; i<n; i++){
        if(arr[i]-placed>=gap){
            c++;
            placed = arr[i];
            if(c==cows) return true;
        }
    }
    return false;
}



int main(){

    ios::sync_with_stdio(false); //Removes sync between printf and cout
    cin.tie(NULL); //Removes sync between cin and cout

    int arr[] = {10,1,2,7,5};
    int n = sizeof(arr)/sizeof(int);

    //cout<<b_s(arr,n,10);

    //cout<<div_two_num(2,5,2);

    //cout<<any_peak(arr,n);

    //int max_pages = accumulate(arr,arr+n,0);

    //int max_time = accumulate(arr,arr+n,0);


    sort(arr,arr+n);
    int max_gap = arr[n-1]-arr[0];
    int ans = 0;

    int s = 0;
    int e = max_gap;

    int mid = s+(e-s)/2;
    // while(s<=e){
    //     // if(book_allocate(arr,n,mid,3)){
    //     //     ans = mid;
    //     //     e = mid - 1;
    //     // }

    //     // if(painters_partition(arr,n,mid,3)){
    //     //     ans = mid;
    //     //     e = mid - 1;
    //     // }

    //     else s = mid + 1;

    //     mid = s+(e-s)/2;
    // }

    //Aggressive Cows
    while(s<=e){
        if(aggressive_cows(arr,mid,n,3)){
            ans = mid;
            s = mid + 1;
        }

        // if(painters_partition(arr,n,mid,3)){
        //     ans = mid;
        //     e = mid - 1;
        // }

        else e = mid - 1;

        mid = s+(e-s)/2;
    }
    cout<<ans;

    return 0;
}