#include "binary-tree/BinaryTree.hpp"

int main()
{
  BinaryTree bt("5,3,6,2,4,null,null,1");
  bt.inorder();
  bt.postorder();
  bt.preorder();
}