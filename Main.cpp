#include <iostream>
#include "BST.h"
#include <stack> 
#include <queue>
#include <string> 
/*TO DO:
FIND HEIGHT 
CHECK IF IT IS BALANCED 
CHECK IF IT IS A BINARY SEARCH TREE
*/



int main() {
  BST obj;
  int option, val;
  bool srch = false;

  do {
   std::cout << "Enter 1 to insert" << std::endl;
   std::cout << "Enter 2 to print" << std::endl;
   std::cout << "Enter 3 to see if a specific value is in the tree already" << std::endl;
   std::cout << "Enter 4 to find the height of the Binary Search Tree" << std::endl;
   std::cout << "Enter 0 to quit" << std::endl;

    std::cin >> option;
    //Node n1;
    Node * new_node = new Node();

    switch (option) {
    case 0:
      break;
    case 1:
      	std::cout <<"INSERT"<<std::endl;
	      std::cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	     std::cin >> val;
	      new_node->value = val;
	      //obj.root= obj.insertRecursive(obj.root,new_node);
	     obj.insert(new_node);
	     std::cout<<std::endl;
         std::cout<<std::endl;
    		break;
      
 
    case 2:
   
      std::cout << "Pre-order recursively" << std::endl;
      obj.preOrder(obj.root);
        std::cout<<std::endl;
      std::cout << "In-order recursively" << std::endl;
      obj.inOrder(obj.root);
        std::cout<<std::endl;
      std::cout << "Post-order recursively" << std::endl;
      obj.postOrder(obj.root);
        std::cout<<std::endl;
      std::cout << "BFS traversal printing" << std::endl;
      obj.BFS(obj.root);
      std::cout<<std::endl;
      std::cout << "Pre-order iteratively" << std::endl;
      obj.iterPreOrder(obj.root);

      std::cout<<std::endl;
      std::cout << "Pre-order iteratively 2" << std::endl;
      obj.iterPreOrder2();
      std::cout<<std::endl;
      std::cout << "In-order iteratively" << std::endl;
      obj.iterInorder(obj.root);
      std::cout<<std::endl;
      std::cout<<std::endl;
      break;

    case 3:
    std::cout <<"SEARCH"<<std::endl;
	std::cout <<"Enter VALUE of the TREE NODE You Want to Search in the BST: ";
    std::cin >> val;
   if(obj.searchIterative(obj.root, val))
   {
    std::cout << "A Node With the Value: "<< val << " is in the Tree!" << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    
   }
   else
   {
     
    std::cout << "A Node With the Value: "<< val << " is NOT the Tree!" << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    
   }

    
    break;

    case 4: 
    std::cout << "Finding Height...." << std::endl;
    std::cout << "The height of the tree is " << obj.FindHeight(obj.root) << std::endl;
    }
    



  } while (option != 0);

  return 0;



}