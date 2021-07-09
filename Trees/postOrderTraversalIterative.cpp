#include <iostream>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

// void postOrderRecurrsive(BinaryTreeNode<int> *root)
// {
//   if(root==NULL) {
//     return;
//   }
//   postOrderRecurrsive(root->left);
//   postOrderRecurrsive(root->right);
//   cout<<root->data;
// }

void postOrderIterative(BinaryTreeNode<int> *root){
  if(root==NULL) return;
  stack<BinaryTreeNode<int>*> s1,s2;
  s1.push(root);
  while(!s1.empty()) {
    BinaryTreeNode<int> *currentNode = s1.top();
    s1.pop();
    s2.push(currentNode);
    if(currentNode->left!=NULL) s1.push(currentNode->left);
    if(currentNode->right!=NULL) s1.push(currentNode->right);
  }

  while(s2.size()!=0){
    BinaryTreeNode<int> *ptr=s2.top();
    cout<<ptr->data<<" ";
    s2.pop();
  }
}

int main()
{
  // considering root at level 1.
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
  BinaryTreeNode<int> *node1Atlevel1 = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node2Atlevel1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node1Atlevel2 = new BinaryTreeNode<int>(3);
  BinaryTreeNode<int> *node2Atlevel2 = new BinaryTreeNode<int>(4);
  BinaryTreeNode<int> *node3Atlevel2 = new BinaryTreeNode<int>(5);
  BinaryTreeNode<int> *node4Atlevel2 = new BinaryTreeNode<int>(6);

  // At level 2.
  root->left = node1Atlevel1;
  root->right = node2Atlevel1;

  // At level 3.
  node1Atlevel1->left = node1Atlevel2;
  node1Atlevel1->right = node2Atlevel2;
  node2Atlevel1->left = node3Atlevel2;
  node2Atlevel1->right = node4Atlevel2;

  // postOrderRecurrsive(root);
  cout<<"Iterative post-order traversal is : ";
  postOrderIterative(root);
}
