//reverse array usig iterative approach
//TC: O(n)
#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

int main()
{

  int n; //size of array
  cout<<"Enter size of array:";
  cin>>n;
  int arr[100];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  //swap first and last element and increment first by 1 and decrement last by 1 till n/2(mid)
  for(int i=0;i<n/2;i++)
  {
    int temp=arr[i];
    arr[i]=arr[n-1-i];
    arr[n-1-i]=temp;
  }
  display(arr,n);
  return 0;

}
