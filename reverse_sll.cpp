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

node* reverse_sll(node *head)
{
    node *prev,*next,*curr;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
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
    head=reverse_sll(head);
    cout<<"Reversed Linked List: ";
    display(head);
    return 0;
}

