#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int key){
        data = key;
        next = NULL;
    }
}*start = NULL, *q, *p, *r, *temp;

void insertSortedLink(int key){
    p = new Node(key);
    if(start==NULL){
        start = p;
    }else{
        r = start;
        q = start;
        if(q->data>=key){
            temp = start;
            start = p;
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

void printLink(){
    q = start;
    while(q!=NULL){
        cout<<q->data<<" ";
        q = q->next;
    }
}

int main()
{
    int n, num;
    cout<<"Enter the no. of elements to be inserted : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        insertSortedLink(num);
    }
    cout<<"The elements stored as follows : ";
    printLink();
    return 0;
}
