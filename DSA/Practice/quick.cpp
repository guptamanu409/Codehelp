#include<bits/stdc++.h>
using namespace std;


//Using ending index
int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int start = low - 1;
    int j = low;
    while(j<high){
        if(arr[j]<pivot){
            ++start;
            swap(arr[start],arr[j]);
        }
        j++;
    }
    start++;
    swap(arr[high],arr[start]);
    return start;
}


//Using starting index
// int partition(int arr[], int low, int high){

//     int pivot = arr[low];
//     int pivotIn = low;

//     int count = 0;
//     for(int i = low+1; i<=high; i++){
//         if(arr[i]<pivot)count++;
//     }

//     pivotIn +=count;
//     swap(arr[low],arr[pivotIn]);

//     while(low<pivotIn && high > pivotIn){
//         while(arr[low]<pivot) low++;
//         while(arr[high]>pivot) high--;

//         if(low<pivotIn && high>pivotIn) swap(arr[low++],arr[high--]);
//     }
//     return pivotIn;
// }


void quicksort(int arr[], int n, int low, int high){
    if(low>=high) return;

    int pivot = partition(arr,low, high);
    quicksort(arr,n,low,pivot-1);
    quicksort(arr,n,pivot+1,high);
}

int main(){

    int arr[5] = {5,4,7,8,9};
    int n = 5;

    quicksort(arr,n,0,n-1);

    for(int i = 0; i<n; i++) cout<<arr[i] <<" "; 

    return 0;
}