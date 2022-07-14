/*Level order Traversal of a Binary Tree*/
/*TC:  O(n) AS:  O(n) or theta(width)*/
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

void printLevelOrder(node *root){
  if(root==NULL) return;
  queue <node *>q;
  q.push(root);
  while(q.empty()!=true){
    int count=q.size();
    for(int i=0;i<count;i++){
      node *curr= q.front();
      cout<<curr->data<<" ";
      q.pop();
      if(curr->left!=NULL)
        q.push(curr->left);
      if(curr->right!=NULL)
        q.push(curr->right);
    }
  }

}

int main(){
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(4);
  root->left->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(5);
  printLevelOrder(root);
}
