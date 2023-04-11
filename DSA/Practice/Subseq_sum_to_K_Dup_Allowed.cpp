#include<bits/stdc++.h>
using namespace std;

//Subsequence with sum K (Duplicates allowed) 
//Continuous hai 
void subq(int arr[], int target, int n,int index, vector<int>&ds){
    if(target<0 || index>=n) return;
    if(target==0){
        for(auto it:ds) cout<<it<<" ";
        cout<<endl;
        return;
    }

    //target-=arr[index];
    ds.push_back(arr[index]);
    subq(arr,target-arr[index],n,index,ds);

    //target+=arr[index];
    ds.pop_back();
    subq(arr,target,n,index+1,ds);
}

//Har element se pura starting se loop bar bar lekar
//-------Counting all ways to make a coin----------
//Continuous nahi hai
int coin_change(int arr[], int target, int n){
    if(target<0) return 0;
    if(target==0) return 1;
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans+=coin_change(arr,target-arr[i],n);
    }
    return ans;
}

int minimum_number_of_coins(int arr[], int target, int n){
    if(target==0) return 0;
    if(target<0) return INT_MAX;

    int mini = INT_MAX;
    for(int i = 0; i<n; i++){
        int ans = minimum_number_of_coins(arr,target-arr[i],n);
        if(ans!=INT_MAX){
            mini = min(mini,ans+1); //plus One matlab ek coin lekar bana hoga na 
        }
    }
    return mini;
}

int maxi_adjacent_sum(int arr[], int index, int sum, int n){
    if(index>=n) return sum;

    int max1 = maxi_adjacent_sum(arr,index+2,sum+arr[index],n);
    int max2 = maxi_adjacent_sum(arr,index+1,sum,n);

    return max(max1,max2);
}

int main(){

    int arr[4] = {2,1,4,9};
    vector<int>ds;
    //subq(arr,3,3,0,ds);
    //cout<<coin_change(arr,3,3);
    //cout<<minimum_number_of_coins(arr,5,3);
    cout<<maxi_adjacent_sum(arr,0,0,4);



    return 0;
}