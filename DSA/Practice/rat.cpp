#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    
    bool isSafe(vector<vector<int>>&a, int row, int col, vector<vector<bool>>&vis, int n){
        cout<<"Inside safe";
        cout<<" Row "<<row<<" Col "<<col<<" Value "<<a[row][col]<<endl;
        
        if((row<n && row>=0) && (col<n && col>=0) && (a[row][col]==1) && (vis[row][col]==false)) return true;
        return false;
    }
    
    void maze(vector<vector<int>>&a, int row, int col, string out, vector<string>&ans,int n, int dr[],int dc[], char dir[],vector<vector<bool>>&vis){
        if(row==n-1 && col == n-1){
            cout<<"Base case hit"<<endl;
            cout<<out<<endl;
            ans.push_back(out);
            return;
        }

        cout<<"Inside maze"<<endl;
        
        
        for(int i = 0; i<4; i++){
            int newr = row + dr[i];
            int newc = col + dc[i];
            char ch = dir[i];
            if(isSafe(a,newr,newc,vis,n)){
                vis[newr][newc] = true;
                maze(a,newr,newc,out+ch,ans,n,dr,dc,dir,vis);
                vis[newr][newc] = false;
            }
            
        }
    }
    public:
    void findPath(vector<vector<int>> &m, int n, vector<string>&a) {
        // Your code goes here
        //if(m[0][0]==0 || m[n-1][n-1]==0) return {"-1"};
        cout<<"Inside path"<<endl;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        //vector<string>ans;
        string output = "";
        int dr[4] = {1,0,0,-1};
        int dc[4] = {0,-1,1,0};
        char dir[4] = {'D','L','R','U'};
        maze(m,0,0,output,a,n,dr,dc,dir,vis);
        //return ans;
    }
};

int main(){

    Solution s;
    vector<vector<int>>m = {
        {1,0,0},
        {1,1,1},
        {1,1,1}
    };

    vector<string>a;

    s.findPath(m,3,a);
    if(a.size()==0) cout<<"Khali hai"<<endl;
    for(auto it:a) cout<<it<<" ";
    return 0;
}