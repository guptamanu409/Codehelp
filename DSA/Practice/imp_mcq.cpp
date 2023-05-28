#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false); // removes sync between cout and printf

    cin.tie(NULL); //removes sync between cin and cout

    // int a,b=10;
    // cout<<a<<" "<<b;

    // short i=2300, j=4322;
	// cout<<"i+j="<<(i+j);

    // int i=0;
	// i=i+1;
	// cout<<i;
	// /*print i \*/i=i+1;
	// cout<<++i;


    // int n;
	// cin >> n;
	// bool isPrime = true;
    // for(int i=2;i<n;i++){
    //     if(n%i == 0){
    //         isPrime = false; 
    //         break;
    //     }
    // }
	// if(isPrime){
	// 	cout<<"Prime"<<endl;	
	// }
	// else{
	// 	cout<<"Not Prime"<<endl;	
	// }


    // int x = 5,y;
    // y = ++x * ++x;
    // cout<<x<<" "<<y<<endl;

    // y = (x++) * (x++);
    // cout<<x<<" "<<y<<endl;

    
    
    
    //cout<<-7+1;
    

    // cout<<(~-4);
    // cout<<(!0);

    //cout<<(int)log10(7789);

    vector<int>temp;

    for(int i = 1; i<=10; i++)temp.push_back(i);

    vector<int>:: iterator res;
    res = max_element(temp.begin(),temp.end());
    if(res!=temp.end()) cout<<"hai ismein";
    *res = 0;
    cout<<*res;
    return 0;
}