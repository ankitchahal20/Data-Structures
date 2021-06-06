#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

int calculateHeightRecurrsive(BinaryTreeNode<int> *root){
  if(root == NULL){
    return 0;
  }

  queue<BinaryTreeNode<int> *> q;
  q.push(root);

  int height=0;

  while(!q.empty())
  {
    // finding the total nodes at a current level.
    int nodesAtCurrentLevel = q.size();

    /* 1) add all the nodes of next level in the queue
       2) and delete all the nodes in the current level
    */
    while(nodesAtCurrentLevel > 0)
    {
      BinaryTreeNode<int> *front=q.front();
      q.pop();

      if(front->left != NULL) {
        q.push(front->left);
      }

      if(front->right != NULL) {
        q.push(front->right);
      }
      nodesAtCurrentLevel--;
    }
    //increment height for each level.
    height++;
  }
  return height;
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
