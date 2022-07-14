#include <bits/stdc++.h>
using namespace std;

#define N 100

int queue_array[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
	if(rear== N-1)
	{
		cout<<"Queue is Full"<<endl;
	}
	else if((front== -1) && (rear== -1))
	{
		front=rear=0;
		queue_array[rear]=x;
	}
	else
	{
		rear++;
		queue_array[rear]=x;
	}
	
}

void dequeue()
{
 if((front== -1) && (rear== -1))
 {
 	cout<<"Queue is Empty"<<endl;
 }	
 else if(front==rear)
 {
 	front=rear=-1;
 }
 else
 {
 	front++;
 }
}


void peek()
{
 if((front== -1) && (rear== -1))
 {
 	cout<<"Queue is Empty"<<endl;
 }	
 else
 {
 	cout<<queue_array[front]<<endl;
 }
}

void last()
{
 if((front== -1) && (rear== -1))
 {
 	cout<<"Queue is Empty"<<endl;
 }	
 else
 {
 	cout<<queue_array[rear]<<endl;
 }
}


void display()
{

 if((front== -1) && (rear== -1))
 {
 	cout<<"Queue is Empty"<<endl;
 }
 else
 {
 	for(int i=front;i<=rear;i++)
 	{
 		cout<<queue_array[i];
	 }
	 cout<<endl;
	 }	
}

int main()
{
  
  while(1)
  {
    int choice =0;
    int d;
    cout<<"What would you like to do\n";
    cout<<"1 Enqueue an element \n2 Dequeue an Element \n3 Display the Peek Element";
    cout<<"\n4 Display the last Element  \n5 Display \n6 Exit\n";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter data\n";
              cin>>d;
              enqueue(d);
              break;
      case 2: dequeue();
              break;
      case 3: peek();
              break;
      case 4: last();
              break;
      case 5: display();
              break;
      case 6: exit(0);
    }
  }

  return 0;
}








