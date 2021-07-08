#include <iostream>
using namespace std;

class node{
        public:
        int data;
        node* next;

        node(int val){
            data=val;
            next=NULL;
        }
};

// void insertAThead(node* &head,int val){
//     node* n = new node(val);
//     n->next = head;
//     head =n;
// }

void insertATTail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// bool search(node* head, int key){
//     node* temp = head;
//     while(temp!=NULL){
//         if(temp->data == key){
//             return true;
//         }
//         temp = temp ->next;
//     }
//     return false;
// }

// void deleteAtHead(node* &head){
//     node* todelete=head;
//     head=head->next;
//     delete todelete;
// }

// void deletion(node* &head, int val){
//     if(head == NULL){
//         return;
//     }
//     if(head->next == NULL){
//         deleteAthead(head);
//     }
//     node* temp = head;
//     while(temp->next->data!=val){
//         temp=temp->next;
//     }
//     node* todelete =temp->next;
//     temp->next = temp->next->next;
//     delete todelete;
// }

// node* reverse(node* &head){
//     node* preptr=NULL;
//     node* curptr=head;
//     node* nextptr;
//     while(curptr!=NULL){
//         nextptr=curptr->next;
//         curptr->next=preptr;
//         preptr=curptr;
//         curptr=nextptr;
//     }
//     return preptr;
// }

node* reversek(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(head!=NULL)
        head->next = reversek(nextptr,k);
    return prevptr;
}


int main(){
    node* head = NULL;
    insertATTail(head,1);
    insertATTail(head,2);
    insertATTail(head,3);
    insertATTail(head,4);
    insertATTail(head,5);
    insertATTail(head,6);
    display(head);
    // cout<<search(head,2)<<endl;
    // deletion(head,2);
    // deleteAtHead(head);
    // node* newhead= reverse(head);
    // display(newhead);

    int k=2;
    node* newhead = reversek(head,k);
    display(newhead);

    return 0;
}
