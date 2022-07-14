/*Reverse Level order Traversal of a Binary Tree*/
/*TC:  O(n) */
#include<bits/stdc++.h>
using namespace std;

class node {
public:
  int data;
  node *left, *right;
};

/*Allocating memory and initialising*/
node* newNode(int data){
  node* Node= new node();
  Node->left = NULL;
  Node->right = NULL;
  Node->data = data;
  return Node;
}
/*enqueue right child followed by left and push curr node in stack*/
void printreverseLevelOrder(node *root){
  if(root==NULL) return;
  queue <node *>q;
  stack <node *> s;
  node* curr;
  q.push(root);
  while(q.empty()!=true){
      curr= q.front();
      s.push(curr);
      q.pop();
      if(curr->right!=NULL)
        q.push(curr->right);
      if(curr->left!=NULL)
        q.push(curr->left);
  }

  while(s.empty()==false){
    curr=s.top();
    cout<<curr->data<<" ";
    s.pop();
  }

}

int main(){
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->right = newNode(4);
  root->right->left = newNode(5);
  root->right->right = newNode(6);
  printreverseLevelOrder(root);
}
