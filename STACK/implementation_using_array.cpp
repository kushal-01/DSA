#include <bits/stdc++.h>
using namespace std;

#define N 100

int stack_array[N];
int top=-1;

void push(int num)
{
	if(top==N-1)
	{
		cout<<"Stack is Full"<<endl;
	}
	else
	{
		top++;
		stack_array[top]=num;
	}
}

int pop()
{
	int item;
	if(top== -1)
	{
		cout<<"Stack is Empty"<<endl;
		return 0;
	}
	else
	{
	  item=stack_array[top];
	  top--;
	  return item;	
	}
	
}

int peek()
{
	if(top== -1)
	{
	cout<<"Stack is Empty"<<endl;
		
	}
	else
	{
	 cout<<stack_array[top]<<endl;
	}
}

void display()
{
	if(top== -1)
	{
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			cout<<stack_array[i];
		}
		cout<<endl;
	}
}

int main()
{
  
  while(1)
  {
    int choice =0;
    int d,item;
    cout<<"What would you like to do\n";
    cout<<"1 Push an element \n2 Pop an Element \n3 Display the top Element";
    cout<<"\n4 Display  \n5 Exit\n";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter data\n";
              cin>>d;
              push(d);
              break;
      case 2: item=pop();
              cout<<item<<endl;
              break;
      case 3: item=peek();
              break;
      case 4: display();
              break;
      case 5: exit(0);
    }
  }

  return 0;
}








