#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void inOrderRecurrsive(BinaryTreeNode<int> *root)
{
  if(root==NULL) {
    return;
  }
  inOrderRecurrsive(root->left);
  cout<<root->data;
  inOrderRecurrsive(root->right);
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

  // count nodes
  cout<<"Recurrsive inorder traversal is : ";
  inOrderRecurrsive(root);
}
