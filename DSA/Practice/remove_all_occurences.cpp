#include<bits/stdc++.h>
using namespace std;

int fin(string &s, string &tar){
    //int ans = INT_MAX;
    //cout<<" Fin ke andar ye string aai hai "<<s <<" S ka size "<<s.size()<< " tar ka size "<<tar.size();
    //cout<< " Difference "<<s.size()-tar.size(); //Unsigned mein -1 toh =======>>>>>>>>    2^64 - 1
    //cout<<endl;
    bool check = false;
    for(int i = 0; i<=(int)(s.size()-tar.size()); i++){ //Isiliye explicitly typecast kara hai
        //cout<<" Iss string ke liye loop mein aya hun "<< s<<endl;
        check = !check;
        for(int j = 0; j<tar.size(); j++){
            if(s[i+j]!=tar[j]){
                check = !check;
                break;
            }
        }
        if(check){
            //cout<<" Iss i ko return kar raha hun "<<i;
            return i;
        } 
    }
    //cout<<" Max return kar raha hun ";
    return INT_MAX;
}

void rem(string &s, string &tar){
    if(s.size()==0) return;
    int index = fin(s,tar);
    //cout<<" String "<<s;
    //cout<<" Index "<<index;

    if(index!=INT_MAX){
        string left = s.substr(0,index);
        string right = s.substr(index+tar.size(),s.size());
        //cout<<" Left "<<left;
        //cout<<" Right "<<right;
        s = left+right;
        //cout<<" New String "<<s<<endl;

        rem(s,tar);
    }
    else return;

    return;
}


int main(){

    string s = "ccctltctlltlb";
    string tar = "ctl";
    //rem(s,tar);
    //cout<<" Final Answer "<<s;

    //cout<<(0>-1);

    //for(int i = 0; i<=-2; i++) cout<<"ajeeb"<<endl;
    // cout<<s.size()<<" "<<tar.size()<<endl;
    // cout<<tar.size()-s.size();
    // string big = "1234";
    // string small = "12";
    // cout<<small.size()<<" "<<big.size()<<endl;
    // cout<<small.size()-big.size();
    //cout<<(int)(small.size()-big.size());
    //4294967296
    unsigned int a = -5;
    cout<<a;

    return 0;
}