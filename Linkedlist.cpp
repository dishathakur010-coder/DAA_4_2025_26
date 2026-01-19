#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class list{
    node *head,*tail;
public:
    list(){
        head=NULL;
        tail=NULL;
    }
    void insertatend(int item){
        node *temp=new node;
        temp->data=item;
        temp->next=NULL;
        if(head==NULL){
            head=tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
    void insertatfirst(int item){
        node *temp=new node;
        temp->data=item;
        temp->next=head;
        head=temp;
    }
    void insertatspecificpos(int item,int pos){
        if(pos==1){
            insertatfirst(item);
            return;
        }
        node *temp=new node;
        temp->data=item;
        node *curr=head;
        for(int i=1;i<pos-1 && curr!=NULL;i++){
            curr=curr->next;
        }
        if(curr==NULL){
            cout<<"Invalid position\n";
            delete temp;
            return;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
    void deleteatfirst(){
        if(head==NULL) return;
        node *temp=head;
        head=head->next;
        delete temp;
    }
    void deleteatend(){
        if(head==NULL) return;
        if(head->next==NULL){
            delete head;
            head=tail=NULL;
            return;
        }
        node *curr=head;
        while(curr->next->next!=NULL){
            curr=curr->next;
        }
        delete curr->next;
        curr->next=NULL;
        tail=curr;
    }
    void deleteatspecificpos(int pos){
        if(pos==1){
            deleteatfirst();
            return;
        }
        node *curr=head;
        for(int i=1;i<pos-1 && curr!=NULL;i++){
            curr=curr->next;
        }
        if(curr==NULL || curr->next==NULL){
            cout<<"Invalid position\n";
            return;
        }
        node *temp=curr->next;
        curr->next=temp->next;
        delete temp;
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};
int main(){
    list l;
    l.insertatend(8);
    l.insertatend(7);
    l.insertatend(9);
    l.display();
    l.insertatspecificpos(5,2);
    l.display();
    l.deleteatspecificpos(3);
    l.display();
}
