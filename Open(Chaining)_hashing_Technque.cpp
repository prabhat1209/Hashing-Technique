#include <iostream>

using namespace std;

/*
Loading Factor, λ=n/size
Successful search, t=1+λ/2
Unsuccessful search, t=1+λ 
*/

class Node{
    public:
    int data;
    Node* next;
    Node(int key){
        data = key;
        next = NULL;
    }
} *q, *p, *r, *temp, *h[10];;

int hashIndex(int key){
    return key%10;
}

void insertHash(int key){
    int index = hashIndex(key);
    p = new Node(key);
    if(h[index]==NULL){
        h[index] = p;
    }else{
        r = h[index];
        q = h[index];
        if(q->data>=key){
            temp = h[index];
            h[index] = p;
            p->next = temp;
        }else{
            while(q!=NULL && q->data<key){
                r = q;
                q = q->next;
            }
            temp = r->next;
            r->next = p;
            p->next = temp;
        }
    }
}


void printHash(Node *h){
    q = h;
    while(q!=NULL){
        cout<<q->data<<" ";
        q = q->next;
    }
}

int main()
{
    int n, num;
    for(int i=0;i<10;i++)
        h[i] = NULL;
    cout<<"Enter the no. of elements to be inserted : ";
    cin>>n;
    cout<<"Enter the elements : \n";
    for(int i=0;i<n;i++){
        cin>>num;
        insertHash(num);
    }
    cout<<"Elements stored in Hashing Manner as follows : \n";
    for(int i=0;i<10;i++){
        cout<<"Hash ["<<i<<"] : ";
        printHash(h[i]);
        cout<<endl;
    }
    return 0;
}
