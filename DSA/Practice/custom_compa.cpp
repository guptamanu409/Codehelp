#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool cmp (string a, string b){ //vector of string toh har index ek string
    return a>b;
}

int main(){

    //string ss ="abdrsfsedfdf";
    vector<string>ss = {"s","s","e","b","z","a"};
    sort(ss.begin(),ss.end(),cmp);
    for(auto it:ss)cout<<it<<" ";

    return 0;
}