#include "BST.h"

BST::BST()
{
    root = NULL;
}

void BST::insert(Node* nodeTOadd)
    {
        if(root == NULL)
        {
            root = nodeTOadd;
        }
        else{
            Node* temp = root; 
            while(temp!= NULL)
            {
                //check the case that the value is a duplicate. 
                if(root->value == temp->value)
                {
                    std::cout << "This tree does not allow any duplicates, please enter a differnet value when prompted to do so" << std::endl;
                    return;
                }
                if((nodeTOadd->value < root->value )&& (root->left == NULL))
                {
                    root->left = nodeTOadd;
                    std::cout << "The node has been added!" << std::endl;
                    break;
                }
                else if(nodeTOadd->value < root->value)
                {
                    temp = temp->left;
                }
                else if((nodeTOadd->value > root->value )&& (root->right == NULL))
                {
                    root->right = nodeTOadd;
                    std::cout << "The node has been added!" << std::endl;
                    break;
                }
                else if(nodeTOadd->value > root->value)
                {
                    temp = temp->right;
                }
                
            }
        }


    }

    //Recursive method to insert a node into the Binary search Tree 

    Node* BST::insertRecursive(Node* r, Node* n)
    {
        if(r == NULL)
        {
            r = n;
            std::cout << "The node has been added!" << std::endl;
            return r;
        }
       
        if(n->value < r->value)
        {
            r->left = insertRecursive(r->left, n);
        }
        else if(n->value > r->value)
        {
            r->right = insertRecursive(r->right, n);
        }
        else
       {
        std::cout << "Sorry, no duplicates allowed in this binary search tree" << std::endl;
        return r;
       } 
       return r;
    }

//********************PRINT THE TREE IN PREORDER, INORDER, POSTORDER, AND BREATH FIRST WAY******************
void BST::preOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }
    std::cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void BST::inOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }
  
    inOrder(node->left);
    std::cout << node->value << " ";
    inOrder(node->right);
}
void BST::postOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }
    
    inOrder(node->left);
    inOrder(node->right);
    std::cout << node->value << " ";
}

//iteratively doing preorder, inoder and post order
//use stack

void BST::iterPreOrder(Node* node)
{
    if(node == NULL){
        std::cout << "Nothing to print"  << std::endl;
        return;
    }
    std::stack<Node*> stak;
    stak.push(node);
     Node* temp;
    while (!stak.empty())
    {
        temp = stak.top();
        stak.pop();
        std::cout<< temp->value << " ";
        if(temp->right != NULL)
        {
            stak.push(temp->right);
        }
        if(temp->left != NULL)
        {
            stak.push(temp->left);
        }
    }
    return;
}

// Or we can try and use the root vaiable driectly from the bst class insead of passing a node in the parameter 
void BST::iterPreOrder2()
{
    if(root == NULL){
        std::cout << "Nothing to print"  << std::endl;
        return;
    }
    std::stack<Node*> stak;
    stak.push(root);
    while (!stak.empty())
    {
        Node* temp = stak.top();
        stak.pop();

        std::cout<< temp->value << " ";
        if(temp->right != NULL)
        {
            stak.push(temp->right);
        }
        if(temp->left != NULL)
        {
            stak.push(temp->left);
        }
    }
    return;
}



void BST::iterInorder(Node* node)
{
    
    std::stack<Node*> stak;
    Node* temp = node;
    bool loop = true;

    while(loop)
    {
        if(temp != NULL)
        {
            stak.push(temp);
            temp = temp->left;
            
        }
        else
        {
            if(stak.empty())
            {
                break;
            }
            temp = stak.top();
            stak.pop();
            std::cout << temp->value << " ";
            temp = temp->right;
        }

    }
    return;
   
}





//iteratively implementing breathfirst traversal using queue

void BST::BFS(Node* node)
{
    if (node == NULL)
    {
        std::cout << "No Nodes To Print" << std::endl;
        return;
    }
    std::queue <Node*> q;
    Node* temp = node;
    q.push(temp);
    while(!q.empty())
    {
        temp = q.front();
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        q.pop();
        std::cout << temp->value << " ";
    }


return;

}

//NOw SEARCH METHOD. RETURN TRUE IF A GIVE NODE VALUE IS FOUND, FALSE OTHERWISE 
// recursive method. from the main, pass in the root node and the value to be searched
bool BST::searchRecursively(Node* node, const int& x)
{
    if(node == NULL)
    {
        return false;
    }
    if(x == node->value)
    {
        return true;
    }
    else if(x < node->value)
    {
        return searchRecursively(node->left, x);
    }
     else if(x > node->value)
    {
        return searchRecursively(node->right, x);
    }
    else 
    return false;
}

bool BST::searchIterative(Node* node, int x)
{
    if(node == NULL)
    {
        return false;
    }
    Node* temp = node;
    while(temp!= NULL)
    {
        if(x == temp->value)
        {
            return true;
        }
        else if(x < temp->value)
        {
            temp = temp->left;
      
        }
        else
        {
            temp = temp->right;
      
        }
    }
    return false;
}
