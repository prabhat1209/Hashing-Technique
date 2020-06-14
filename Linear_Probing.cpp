#include <iostream>
# define SIZE 10

using namespace std;

//Deletion is not suitable in Linear Probing because it is much time taking.
//Loading Factor, λ = n/size , must be λ<=0.5
//Average successful search, t=(1/λ)ln(1/(1-λ))
//Average unsuccessful search, t=1/(1-λ)

int hashIndex(int key){
    return key%SIZE;
}

int probe(int H[],int key){
    int i = 0;
    int index = hashIndex(key);
    while(H[(index+i)%SIZE]!=0){
        i++;
    }
    return (index+i)%SIZE;
}

void insertHash(int H[],int key){
    int index = hashIndex(key);
    if(H[index]==0)
        H[index] = key;
    else{
        index = probe(H,key);
        H[index] = key;
    }    
    
}

int searchHash(int H[],int key){
    
    int index = hashIndex(key);
    int i=0;
    while(H[index+i]!=key){
        if(H[index+i]==0)
            return -1;
        i++;
    }
    return (index+i)%SIZE;
}

int main()
{
    int key;
    int H[10] = {0};
    insertHash(H,35);
    insertHash(H,25);
    insertHash(H,24);
    insertHash(H,26);
    insertHash(H,16);
    
    cout<<"Enter the element to be search : ";
    cin>>key;
    
    cout<<"The element "<<key<<" present at index "<<searchHash(H,key)<<endl;
    
    return 0;
}
