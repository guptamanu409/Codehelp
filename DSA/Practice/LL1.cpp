#include<bits/stdc++.h>
using namespace std;

class Temp{

    public:
        int data;
        int *p;
        Temp(int x, int y): data(x), p(new int(y)) {};

};

class Node{

    public:
        //int temp = 10;
        int data;
        Node* next;
        Node(int data): data(data), next(nullptr) {};

        ~Node(){
            cout<<" Dtor Called "<<endl;
            //delete next; //dusre sabka data bhi delete ho raha hai..... Iss node se age ki puri LL delete 😎
            //next = nullptr;
            this->next = nullptr;
            
        }
};

void printf(Node* &head){ //& copy nahi sidha reference hai head ko
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main(){

    // Temp *a = new Temp(10,20);
    // cout<<a->data<<endl; //10
    // cout<<(*a).data<<endl; //10

    // cout<<a->p<<endl; //Address
    // cout<<(*a).p<<endl; //Address

    // cout<<*(a)->p<<endl; //20
    // cout<<*(*a).p<<endl; //20

    // Temp *b(a);
    // *(b)->p = 30;

    // //Shallow copy toh dono hi change ho gaye
    // cout<<*(a)->p<<endl; //30
    // cout<<*(b)->p<<endl; //30

    // set<Temp*>mp;
    // mp.insert(b);

    Node *f = new Node(10);
    Node *s = new Node(20);
    Node *t = new Node(30);
    f->next = s;
    s->next = t;
    // s = NULL;
    // cout<<s->next->data;

    //t = NULL;
    //cout<<s->next->data;

    //delete f;
    // t = NULL;
    // Node *temp = s->next;
    // cout<<(s->next==NULL)<<endl;
    // cout<<(t==NULL)<<endl;
    // cout<<(temp==NULL)<<endl;
    // cout<<f->data<<endl;
    // cout<<(s->data)<<endl;
    // cout<<(t->data)<<endl;
    
    // printf(f);

    // t = NULL; // data and next are still the same..... Made no difference 
    // printf(f);

    delete t;
    //t = NULL;
    printf(f);


    return 0;
}