//SinglyLinkedList (Insert,Delete,Search,Print)
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *next;
  Node(int x)
  {
    data=x;
    next=NULL;
  }
};

Node *insertFirst(Node *head, int data)
{
  Node *temp = new Node(data);
  if(head==NULL) return temp;  // empty list
  temp->next=head;
  return temp;
}

Node *insertLast(Node *head, int data)
{
  Node *temp = new Node(data);
  if(head==NULL) return temp;
  Node *curr=head;
  while(curr->next!=NULL)
  {
    curr=curr->next;
  }
  curr->next=temp;
  return head;
}

Node *insertpos(Node *head, int data, int pos)
{
    Node *temp = new Node(data);
    Node *curr =head;
    if(pos==1)
    {
      temp->next=head;
      return temp;
    }

    for(int i=1;i<=pos-2 && curr!=NULL;i++)
    curr=curr->next;
    if(curr==NULL)
    return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

Node *deleteFirst(Node *head)
{
  if(head==NULL)
  {
    cout<<"Empty List\n";
    return NULL;
  }
  Node *temp=head->next;
  delete head;
  return temp;
}

Node *deleteLast(Node *head)
{
  if (head==NULL)
  {
    cout<<"Empty List\n";
    return NULL;
  }
  if(head->next==NULL)
  {
    delete head;
    return NULL;
  }
  Node *curr=head;
  while(curr->next->next!=NULL)
  curr=curr->next;
  delete (curr->next);
  curr->next=NULL;
  return head;
}

Node *deletePos(Node* head, int pos)
{
  if(head==NULL)
  {
    cout<<"empty list\n";
    return NULL;
  }
  Node *curr=head;
  if(pos==0)
  {
    curr=head->next;
    delete(head);
    return curr;
  }

  for(int i=0;i<pos-1 && curr!=NULL;i++)
  curr=curr->next;
  if(curr==NULL || curr->next==NULL)
  {
    cout<<"Position out of index\n";
    return head;
  }
  Node *temp=curr->next->next;
  delete (curr->next);
  curr->next=temp;
  return head;
}

void print(Node *head)
{
  Node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

void search(Node *head , int data)
{
  int pos=1;
  if(head==NULL)
  {
    cout<<"empty list\n";
    return;
  }
  Node *temp=head;
  while(temp!=NULL)
  {
    if(temp->data==data)
    {
      cout<<pos<<endl;
      return;
    }
    pos++;
    temp=temp->next;
  }
  cout<<"NOT FOUND"<<endl;
}

int main()
{
  //Creating new Linked list
  int x;
  cout<<"Print data for head\n";
  cin>>x;
  Node *head=new Node(x);
  while(1)
  {
    int choice =0;
    int d=0,pos=0;
    cout<<"What would you like to do\n";
    cout<<"1 Insert at Beginning \n2 Insert at Last \n3 Insert at any postion";
    cout<<"\n4 Delete at Beginning \n5 Delete at Last \n6 Delete at any position";
    cout<<"\n7 Display \n8 Search \n9 Exit\n";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter data\n";
              cin>>d;
              head=insertFirst(head,d);
              break;
      case 2: cout<<"Enter data\n";
              cin>>d;
              head=insertLast(head,d);
              break;
      case 3: cout<<"Enter data\n";
              cin>>d;
              cout<<"Enter pos\n";
              cin>>pos;
              head=insertpos(head,d,pos);
              break;
      case 4: head=deleteFirst(head);
              break;
      case 5: head=deleteLast(head);
              break;
      case 6: cout<<"Enter pos\n";
              cin>>pos;
              head=deletePos(head,pos-1);
              break;
      case 7: print(head);
              break;
      case 8: cout<<"Enter data\n";
              cin>>d;
              search(head,d);
              break;
      case 9: exit(0);
    }
  }

  return 0;
}
