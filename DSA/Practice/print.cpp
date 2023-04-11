#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    if(n==0) return;

    cout<<arr[0];

    print(arr+1,n-1);
}

int maxi(int arr[], int n){
    if(n==0) return 0;

    int temp = maxi(arr+1,n-1);

    return (arr[0]>temp)? arr[0] : temp;
}

bool isPresent (char ch[], char target){
    if(ch[0] == '\0') return false;
    

    return (ch[0]==target || isPresent(ch+1,target));
}

int isPresentIndex(char ch[], char index ,char target){
    if(ch[index]=='\0') return -1;
    if(ch[index]==target) return index;

    int ans = isPresentIndex(ch, index+1,target);
    return (ans==-1)? -1 : ans;
}

int freq(char ch[], char target){
    if(ch[0]=='\0') return 0;

    int first = 0, rem = 0;

    first += (ch[0]==target)? 1 : 0;
    rem = freq(ch+1,target);

    return first + rem;
}

bool checkSorted(int arr[], int index, int n){
    if(index==n-1) return true;

    return (arr[0]<arr[1] && checkSorted(arr+1,index+1,n));
}

int binary_ser(int arr[], int s, int e, int target){
    int ans = 0;
    if(s>e) return -1;

    int mid = s+(e-s)/2;
    if(arr[mid]==target) return mid;
    if(arr[mid]>target) ans = binary_ser(arr,s,mid-1,target);
    else ans = binary_ser(arr,mid+1,e,target);

    return ans;

}

int main(){

    int arr[] = {1,2,3,4,5};

    //print(arr,5);
    //cout<<maxi(arr,5);

    char ch[10] = "babbar";
    //cout<<ch<<endl;
    //cout<<ch+1;
    //cout<<isPresent(ch,'i');

    //cout<<isPresentIndex(ch,0,'l');

    //cout<<freq(ch,'c');

    //cout<<checkSorted(arr,0,5);

    cout<<binary_ser(arr,0,4,0);


    return 0;
}