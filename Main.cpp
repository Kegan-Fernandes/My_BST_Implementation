#include <iostream>
#include "BST.h"
#include <stack> 
#include <queue>
#include <string> 
/*TO DO:
Add a delete node function 
*/



int main() {
  BST obj;
  int option, val;
  int num;
  bool srch = false;

  do {
   std::cout << "Enter 1 to inser a value in to the Binary Search Tree" << std::endl;
   std::cout << "Enter 2 to print out the nodes in the Binary Search Tree" << std::endl;
   std::cout << "Enter 3 to see if a specific value is in the Binary Search Treea already" << std::endl;
   std::cout << "Enter 4 to find the height of the Binary Search Tree" << std::endl;
   std::cout << "Enter 5 to check if the Binary Search Tree is balanced " << std::endl;
   std::cout << "Enter 6 to chekc if the tree is a valid Binary Search Tree" << std::endl;
   std::cout << "Enter 7 to delete a node from the Binary Search Tree" << std::endl;
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
    break;
    case 5: 
    std::cout << "Checking to see if the tree is balanced...." << std::endl;
    if(obj.BalancedCheck(obj.root) == true)
    {
        std::cout << "The Binary Search Tree is Balanced!." << std::endl;
    }
    else
    std::cout << "The Binary Search Tree is not Balanced!." << std::endl;
    break;

    case 6:
    std::cout <<"Checking to see if the tree is a valid Binary Search Tree...." << std::endl;
    if(obj.isBST(obj.root))
    {
        std::cout << "It is Valid!" << std::endl;
    }
    else
    std::cout << "It is Valid!" << std::endl;
    break;

    case 7: 
    std::cout << "Enter the value of the Node you want to delete: ";
    std::cin>> num;

    //first search and see if a node with that value exists
     if(obj.searchIterative(obj.root, num))
   {
    obj.root = obj.deleteNode(obj.root, num);
    std::cout<<std::endl;
   }
   else
   {
     
    std::cout << "A Node With the Value: "<< num << " is NOT the Tree and cannot be deleted!" << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    
   }



    }
    




  } while (option != 0);

  return 0;



}