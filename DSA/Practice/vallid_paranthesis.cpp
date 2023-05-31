#include<bits/stdc++.h>
using namespace std;

int perm(vector<char>&brackets, int n, int s = 0){
    if(s>=n){
        int sum = 0;
        // (()))( will tell that it's invalid
        for(auto it:brackets){
            if(it=='(')++sum;
            else --sum;

            if(sum<0)return 0;
        }
        for(auto it:brackets)cout<<it<<" ";
        cout<<endl;
        return 1;
    }
    int count = 0;
    for(int i = s; i<n; i++){
        if(i!=s && brackets[i]==brackets[i-1])continue;
        swap(brackets[i],brackets[s]);
        if(brackets[0]==')') break;
        count+=perm(brackets,n,s+1);
        swap(brackets[i],brackets[s]);
    }
    return count;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //vector<char>brackets = {'(','(','(',')',')',')'};
    vector<char>brackets = {'(','(','(','(','(','(','(','(',')',')',')',')',')',')',')',')'};
    cout<<perm(brackets,brackets.size());

    return 0;
}