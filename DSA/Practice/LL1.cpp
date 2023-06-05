#include<bits/stdc++.h>
using namespace std;

class Temp{

    public:
        int data;
        int *p;
        Temp(int x, int y): data(x), p(new int(y)) {};

};

int main(){

    Temp *a = new Temp(10,20);
    cout<<a->data<<endl; //10
    cout<<(*a).data<<endl; //10

    cout<<a->p<<endl; //Address
    cout<<(*a).p<<endl; //Address

    cout<<*(a)->p<<endl; //20
    cout<<*(*a).p<<endl; //20

    Temp *b(a);
    *(b)->p = 30;

    //Shallow copy toh dono hi change ho gaye
    cout<<*(a)->p<<endl; //30
    cout<<*(b)->p<<endl; //30
    return 0;
}