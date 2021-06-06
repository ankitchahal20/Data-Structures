#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int calculateHeightRecurrsive(BinaryTreeNode<int> *root){
  if(root == NULL){
    return 0;
  }
  /*
  calculating the height of the each subtree.
  int lh = calculateHeightRecurrsive(root->left);
  int rh = calculateHeightRecurrsive(root->right);
  return 1 + max(lh,rh);
  */
  return 1 + max(calculateHeightRecurrsive(root->left), calculateHeightRecurrsive(root->right));
}

int main()
{
  // considering root at level 0.
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
  BinaryTreeNode<int> *node1Atlevel1 = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node2Atlevel1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node1Atlevel2 = new BinaryTreeNode<int>(3);
  BinaryTreeNode<int> *node2Atlevel2 = new BinaryTreeNode<int>(4);
  BinaryTreeNode<int> *node3Atlevel2 = new BinaryTreeNode<int>(5);
  BinaryTreeNode<int> *node4Atlevel2 = new BinaryTreeNode<int>(6);

  // At level 1.
  root->left = node1Atlevel1;
  root->right = node2Atlevel1;

  // At level 2.
  root->left->left = node1Atlevel2;
  root->left->right = node2Atlevel2;
  root->right->left = node3Atlevel2;
  root->right->right = node4Atlevel2;

  // count nodes
  cout<<"Height of given BT is : "<<calculateHeightRecurrsive(root)<<endl;
}
