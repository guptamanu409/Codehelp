#include<bits/stdc++.h>
using namespace std;

class Parking{
    private:
        int b,m,s;    
    public:
        // int b,m,s;
        Parking(){
            cout<<"aisi hi"<<endl;
        }

        // Parking(int b, int m, int s){
        //     b = this->b;
        //     // --b;
        //     cout<<b<<" "<<this->b<<endl;
            
        //     m = this->m;
        //     // --m;
        //     cout<<m<<" "<<this->m<<endl;
            
        //     s = this->s;
        //     // --s;
        //     cout<<s<<" "<<this->s<<endl;

        // }

        Parking(int b, int m, int s): b(b), m(m), s(s){
                   //     b = this->b;
            --b;
            cout<<b<<" "<<this->b<<endl;
            
            //     m = this->m;
            --m;
            cout<<m<<" "<<this->m<<endl;
            
            //     s = this->s;
            --s;
            cout<<s<<" "<<this->s<<endl;
        };


};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Parking *q = new Parking(); //Parametrized banaya hai toh Default bhi khud banao
    Parking *p = new Parking(10,20,0);

    return 0;
}