#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node* next;
};

node* create(node *head,int n)
{
    node *temp;
    head=new node;
    cin>>head->data;
    head->next=NULL;
    temp=head;
    for(int i=0 ; i<n-1 ; i++)
    {
        temp->next=new node;
        temp=temp->next;
        cin>>temp->data;
        temp->next=NULL;
    }
    return head;
}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void find_mid(node* head)
{
    node *fast,*slow;
    fast=head;
    slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Mid Value is: "<<slow->data<<endl;
}

int main()
{
    int n;
    node *head;
    cout<<"Enter the number of nodes..: ";
    cin>>n;
    cout<<"Enter numbers: "<<endl;
    head=create(head,n);
    cout<<"Linked List: ";
    display(head);
    find_mid(head);
    return 0;
}
