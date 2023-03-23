#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int bin_ser(vector<int>&a, int x, int s, int e){
    int mid = s+(e-s)/2;

    while(s<=e){
        if(a[mid]==x) return mid;

        if(a[mid]>x)e= mid - 1;
        else s = mid + 1;
        mid = s+(e-s)/2;
    }
    return -1;
}


int expo_ser(vector<int>&a,int x){
    int n = a.size();
    if(a[0]==x) return 0;

    int i = 1;
    while(i<a.size() && a[i]<=x){
        i*=2;
    }

    return bin_ser(a,x,i/2, min(i,n-1));
}


int main(){

    vector<int>a{3,4,5,6,11,13,14,15,56,70};
    cout<<expo_ser(a,99);


    return 0;
}