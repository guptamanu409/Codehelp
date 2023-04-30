#include<bits/stdc++.h>
using namespace std;



//2 Approaches

// Brute Approach

// Create another visited array like you create in Rat in a Maze then as you pass it mark it in the Visited array.
// Now we have to check Above and Down, Left and Right from this [row] [col] location. If we reach the end i.e, 0 or n then we return the index.
// This approach will give you TLE so let's optimize it.

// Better

// Create two array of size row and col and just increase the count.
// check the row array with col size and col array with row size. Try it on a paper and you will get it.
// Complexity
// Time complexity: O(m*n) + O(K) -> K array traversing
// Space complexity: O(m*n) for unordered map

class Solution {

private:
    bool check(vector<vector<int>>&vis, int ro, int co,int row, int col){
        //cout<<"Andar aya bhi hai tu" <<row<<" "<<col<<endl;
        bool r = true;
        bool c = true;
        
        int r1 = row;
        int c1 = col;
        
        while(c1>=0){
            if(vis[r1][c1]==0){
                r = false;
                break;
            }
            c1--;
        }
        
        
        if(r){
            c1 = col;
            r1 = row;
            while(c1<co){
                if(vis[r1][c1]==0){
                    r = false;
                    break;
                }
                c1++;
            }   
        }
        if(r) return true;
        
        
        c1 = col;
        r1 = row;
        while(r1>=0){
            if(vis[r1][c1]==0){
                c = false;
                break;
            }
            r1--;
        }
        
        if(c){
            c1 = col;
            r1 = row;
            while(r1<ro){
                if(vis[r1][c1]==0){
                    c = false;
                    break;
                }
                r1++;
            }   
        }
        if(c) return true;
        
        return false;
        
    }
    
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int n1 = arr.size();

        // New way of creating Dynamic array 
        int *temp_r{ new int[r]{} };
        int *temp_c{ new int[c]{}};
        //Creates a Dynamic Array and initialize it with 0


        //vector<vector<int>>vis(r,vector<int>(c,0));
        unordered_map<int,pair<int,int>>mp;
        
        //Mapping matrix num with row and col
        // So we can access them in O(logn) time
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        
        //for(auto it:mp) cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        int ans = -1;
        for(int i = 0; i<n1; i++){
            int row = mp[arr[i]].first;
            int col = mp[arr[i]].second;
            //vis[row][col] = 1;
            //bool temp = check(vis,r,c,row,col);
            //cout<<" Value of temp "<<temp<<endl;
            // if(temp){
            //     ans = i;
            //     break;
            // }

            temp_r[row]++;
            temp_c[col]++;

        //      column se match      row se match
            if(temp_r[row]==c || temp_c[col]==r){
                ans = i;
                break;
            }
        }

        delete [] temp_r; //Prevent Memory Leak
        delete [] temp_c; //Prevent Memory Leak
        return ans;
        
        
    }
};