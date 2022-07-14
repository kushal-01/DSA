//reverse array using recursive approach
//TC: O(n)
#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

//swap first and last element and recursively call reverse with first =first+1 and last=last-1 until first>=last
int* reverse(int arr[],int start,int end)
{
  if(start>=end)
  return arr;
  swap(arr[start],arr[end]);
  reverse(arr,start+1,end-1);
  return arr;
}
int main()
{

  int n; //size of array
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  reverse(arr,0,n-1);
  display(arr,n);
  return 0;

}
