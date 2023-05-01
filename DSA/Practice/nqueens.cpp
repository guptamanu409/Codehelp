#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool>rows;
unordered_map<int,bool>upper;
unordered_map<int,bool>lower;

void printBoard(vector<vector<char>>&board){

    for(auto ch:board){
        for(auto it:ch) cout<<it<<" ";
        cout<<endl;
    }

    cout<<endl<<endl<<endl<<endl;
}

void saveBoard(vector<vector<char>>&board, vector<vector<string>>&ans){
    vector<string>output;
    for(auto ch:board){
        string temp;
        for(auto it:ch) temp.push_back(it);
        output.push_back(temp);
    }
    ans.push_back(output);
}

bool isSafe(vector<vector<char>>&board, int row, int col, int n){

    
    if(rows[row]==true) return false;
    if(upper[n-1+col-row]==true) return false;
    if(lower[col+row]==true) return false;
    return true;
    
    // bool check = true;
    // //Upper Diagonal
    // int r = row;
    // int c = col;

    // while(r>=0 && c>=0){
    //     if(board[r][c]=='Q'){
    //         check = false;
    //         break;
    //     }
    //     r--;
    //     c--;
    // }
    // if(check == false) return false;
    
    
    
    // //Piche
    // r = row;
    // c= col;
    // while(c>=0){
    //     if(board[r][c]=='Q'){
    //         check = false;
    //         break;
    //     }
    //     c--;
    // }
    // if(check == false) return false;

    // //Lower Diagonal
    
    // r = row;
    // c= col;
    // while(r<n && c>=0){
    //     if(board[r][c]=='Q'){
    //         check = false;
    //         break;
    //     }
    //     r++;
    //     c--;
    // }
    // if(check == false) return false;

    // return true;
}

void nqueens(vector<vector<char>>&board, int col, int n, vector<vector<string>>&ans){
    if(col>=n){
        printBoard(board);
        saveBoard(board,ans);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 'Q';
            rows[row] = true;
            upper[n-1+col-row] = true;
            lower[col+row] = true;
            nqueens(board,col+1,n,ans);
            board[row][col] = '.';
            rows[row] = false;
            upper[n-1+col-row] = false;
            lower[col+row] = false;
        }
    }


}

int main(){

    int n = 4;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    vector<vector<string>>ans;
    printBoard(board);

    nqueens(board,0,n,ans);
    //return ans;



    return 0;
}

