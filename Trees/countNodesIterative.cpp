#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

int countNodesIterative(BinaryTreeNode<int> *root){
  if(root == NULL){
    return 0;
  }
  queue<BinaryTreeNode<int> *> q;
  int count=0;
  q.push(root);

  // q.empty() returns return true if queue is empty and vice versa.
  while(!q.empty())
  {
    count++;
    BinaryTreeNode<int> *front = q.front();
    q.pop();

    if(front->left != NULL){
      q.push(front->left);
    }

    if(front->right != NULL){
      q.push(front->right);
    }
  }
  return count;
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
  node1Atlevel1->left = node1Atlevel2;
  node1Atlevel1->right = node2Atlevel2;
  node2Atlevel2->left = node3Atlevel2;
  node2Atlevel2->right = node4Atlevel2;

  // count nodes
  cout<<"Total Number of nodes in the given BT are : "<<countNodesIterative(root)<<endl;
}
