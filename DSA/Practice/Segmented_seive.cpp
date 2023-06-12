#include<bits/stdc++.h>
using namespace std;

class Solution{


    vector<bool>seiveOE(int n){
        vector<bool>seive(n+1,true);
        
        seive[0]=seive[1] = false;
        
        for(int i = 2; i*i<=n; i++){
            if(seive[i]){
                int j = i*i;
                while(j<n){
                    seive[j] = false;
                    j+=i;
                }
            }
        }
        return seive;
    }


    public:
        long long primeProduct(long long L, long long R){
            // code here
            
            vector<bool>seive = seiveOE(sqrt(R));
            vector<int>baseP;
            for(int i = 0; i<seive.size(); i++){
                if(seive[i]) baseP.push_back(i);
            }
            
            vector<bool>segS(R-L+1,true);
            
            for(auto it : baseP){
                long long firstMul = (L/it)*it;
                if(firstMul<L) firstMul+=it;
                
                for(long long int i = max(firstMul,(long long)it*it); i<=R; i+=it){
                    segS[int(i-L)] = false;
                }
            }
            long long mod = 1e9 + 7;
            long long ans = 1;
            
            for(int i = 0; i<segS.size(); i++){
                if(segS[i]==1) {
                    ans = ans*i;
                    ans = ans*mod;
                }
            }
            return ans;
        }
};

int main(){

    Solution so;

    cout<<so.primeProduct(110,130);

    return 0;
}

