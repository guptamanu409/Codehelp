#include<iostream>
using namespace std;

int main(){

    int arr[] = {3,3,3,3,3};
    int i = 0;
    while(i<5){
        int index = arr[i] - 1;

        if(arr[i]!=arr[index]) swap(arr[i],arr[index]);

        else i++;
    }

    for(int i = 0; i<5; i++) cout<<arr[i]<<" ";

    cout<<endl;

    for(int i = 0; i<5; i++){
        if(i+1!=arr[i]) cout<<i+1<<" ";
    }

    return 0;
}