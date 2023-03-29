#include<bits/stdc++.h>
using namespace std;


int main(){

    //int arr[10] = {1,2,3,4,5,6,7,8};

    //vector<int>arr = {1,2,3,4,5,6,7,8,9,10,11};
    vector<int>arr;
    for(int i = 0; i<9; i++)arr.push_back(i);
    //cout<<sizeof(arr);
    //cout<<arr.size()<<endl;
    //cout<<arr.capacity();

    cout<<distance(arr.begin(),arr.end());

    //max element location
    cout<<max_element(arr.begin(),arr.end())-arr.begin();
    
    
    

    return 0;
}