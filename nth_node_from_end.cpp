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

void nth_from_end(node* head,int n)
{
    node *ptr1,*ptr2;
    ptr1=head;
    ptr2=head;
    int c=1;
    while(c<=n)
    {
        if(ptr1==NULL)
        {
            cout<<"-1"<<endl;
            break;
        }
        ptr1=ptr1->next;
        c++;
    }
    while(ptr1!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    cout<<"Nth node from last is: "<<ptr2->data;
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
    cout<<"Enter the value of the n to be find from the end: ";
    int x;
    cin>>x;
    nth_from_end(head,x);
    return 0;
}

