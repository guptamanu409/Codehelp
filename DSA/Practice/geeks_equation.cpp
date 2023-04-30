#include<bits/stdc++.h>
using namespace std;

long long evaluateA(long long A, long long K)
{
    // code here
    if(K==0) return 1;
    
    return (long long)((long long)((long long)(long long)pow(A,K) + (long long)evaluateA(A,K-1)) % (long long)1000000007);
}

int main(){
    cout<<evaluateA(42,428);
    return 0;
}