#include <iostream>
#include <unordered_map>
#include "BinaryTreeNode.h"
using namespace std;

void BTWidth(BinaryTreeNode<int> *root, int level, unordered_map<int,int> &widthMap){
  if(root==NULL) return;

  widthMap[level]++;
  BTWidth(root->left,level+1,widthMap);
  BTWidth(root->right,level+1,widthMap);
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

  // delcaring an unordered_map to store number of nodes at each level
  unordered_map<int,int> widthMap;
  BTWidth(root,1,widthMap);
  int maxWidth=-1;
  for(auto it :widthMap){
    maxWidth = max(maxWidth,it.second);
  }
  cout<<"Width of the BT is "<<maxWidth<<endl;

}
