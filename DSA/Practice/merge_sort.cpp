#include<bits/stdc++.h>
using namespace std;



//Gap Method (taking ceil value)
//TC = O(logn * nlogN)
//SC = O(1) ignoring auxilary stack space

void merge(int arr[], int low, int mid, int high){
    int total_len = high - low + 1;

    int gap = (total_len/2) + (total_len%2); //ceil value

    while(gap>0){
        int i = low, j = low + gap;
        
        while(j<=high){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;
            j++;
        }
        gap = (gap<=1)? 0 : (gap/2) + (gap%2);
        //gap 1 ke liye bhi chala hai uske bad 0 kara warna infinite loop mein stuck
    }
}


// In Place Merge Sort TC ->>>>> O(n^2 logn) SC = O(1) ignoring auxilary stack space

// void merge(int arr[], int low, int mid, int high){
    
//     int left = low;
//     int right = mid + 1;

//     while(left<=mid && right<=high){
//         if(arr[left]<arr[right]){
//             left++;
//         }

//         else{
//             swap(arr[left],arr[right]);
//             left++;
//             int count = 0;
//             for(int i = right+1; i<=high; i++){
//                 if(arr[i]<arr[right])count++;
//             }
//             swap(arr[right],arr[right+count]);

//         }
//     }
// }


//Standard Merge Sort ->>>>>>> TC =  O(nlogN) SC = O(N)

// void merge(int arr[], int low, int mid, int high){

//     int left = mid - low + 1;
//     int right = high - mid;

//     int *leftA = new int[left+1];
//     int *rightA = new int [right+1];

//     for(int i = 0; i<left; i++){
//         leftA[i] = arr[i+low];
//     }

//     for(int i = 0; i<right; i++){
//         rightA[i] = arr[i+mid+1];
//     }

//     leftA[left] = rightA[right] = INT_MAX;

//     int l = 0, r = 0;

//     for(int i = low; i<=high; i++){
//         if(leftA[l]<=rightA[r]){
//             arr[i] = leftA[l++];
//         }

//         else arr[i] = rightA[r++];
//     }
    

//     delete [] leftA;
//     delete [] rightA;
// }



void mergeSort(int arr[], int low, int high){
    if(low>=high) return;

    int mid = low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){

    int arr[5] = {4,8,6,3,1};
    int n = 5;
    mergeSort(arr,0,n-1);

    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}