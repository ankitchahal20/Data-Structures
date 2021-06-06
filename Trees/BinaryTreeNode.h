template<typename T>
class BinaryTreeNode {
public:
  // left and right pointer to point the left and right subtree of the BinaryTree.
  T data;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  // constructor for the BinaryTreeNode class.
  BinaryTreeNode(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  }

  // Destructor for the BinaryTreeNode class.
  ~BinaryTreeNode() {
    delete left;
    delete right;
  }
};
