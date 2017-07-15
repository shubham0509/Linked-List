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
    node *mid;
    mid=head;
    int c=0;
    while(head->next!=NULL)
    {
        c++;
        if(c%2!=0)
            mid=mid->next;
        head=head->next;
    }
    cout<<"Middle Element: "<<mid->data<<endl;
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
