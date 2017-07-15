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
    head=new node;
    cout<<"Enter numbers:"<<endl;
    cin>>head->data;
    head->next=NULL;

    node *temp;
    temp=head;
    for(int i=1 ; i<n ; i++)
    {
        temp->next=new node;
        temp=temp->next;
        cin>>temp->data;
        temp->next=NULL;
    }
    return head;
}

void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node* swapping(node *head,int a,int b)
{
    if(a==b)
        return head;
    node *prevX,*currX;
    prevX=NULL;
    currX=head;
    //for finding the previous and the current nodes of a
    while(currX!=NULL && currX->data!=a)
    {
        prevX=currX;
        currX=currX->next;
    }

    node *prevY,*currY;
    prevY=NULL;
    currY=head;
    //for finding the previous and the current nodes of b
    while(currY!=NULL && currY->data!=b)
    {
        prevY=currY;
        currY=currY->next;
    }

    if(currX==NULL || currY==NULL)
        return head;

    //if a is not the head
    if(prevX!=NULL)
        prevX->next=currY;
    else //make b as the head
        head=currY;

    //if b is not the head
    if(prevY!=NULL)
        prevY->next=currX;
    else // make a as the head
        head=currX;

    node *temp;
    temp=currX->next;
    currX->next=currY->next;
    currY->next=temp;

    return head;
}

int main()
{
    int n,a,b;
    node *head;
    head=NULL;
    cout<<"Enter no. of nodes ..?"<<endl;
    cin>>n;
    head=create(head,n);
    cout<<"Enter the elements to be swapped.."<<endl;
    cin>>a>>b;
    cout<<"Before swapping :"<<endl;
    display(head);
    display(head);
    head=swapping(head,a,b);
    cout<<"After swapping :"<<endl;
    display(head);
    return 0;
}
