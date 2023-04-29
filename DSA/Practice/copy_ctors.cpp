// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        int x;
        int *const y;
    
    public:
        // A(): x(4), y(1){
        //     cout<<x<<" "<<y;
        //     y = 5;
        // }
        A(int _x, int _y): x(_x), y(new int(_y)) {}
        
        void print(){
            //cout<<(*this).x<<" "<<*(*this).y;
            cout<<this->x<<" "<<*(this)->y<<endl;
        }
        
};

int main() {
    // Write C++ code here
    A a(5,6);
    cout<<"Printing for a"<<endl;
    a.print();
    
    A b(a);
    cout<<"Printing for b"<<endl;
    b.print();
    
    b.x=10; // Apni copy mein change
    *b.y=12; // Dono pointing to same mem location
    cout<<"Printing for a"<<endl;
    a.print();
    
    cout<<"Printing for b"<<endl;
    b.print();
    
    
    

    return 0;
}