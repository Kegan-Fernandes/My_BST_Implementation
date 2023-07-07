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
            std::cout << "The node has been added!" << std::endl;
        }
        else{
            Node* temp = root; 
            while(temp!= NULL)
            {
                //check the case that the value is a duplicate. 
                if(temp->value == nodeTOadd->value)
                {
                    std::cout << "This tree does not allow any duplicates, please enter a differnet value when prompted to do so" << std::endl;
                    return;
                }
                if((nodeTOadd->value < temp->value )&& (temp->left == NULL))
                {
                    temp->left = nodeTOadd;
                    std::cout << "The node has been added!" << std::endl;
                    break;
                }
                else if(nodeTOadd->value < temp->value)
                {
                    temp = temp->left;
                }
                else if((nodeTOadd->value > temp->value )&& (temp->right == NULL))
                {
                    temp->right = nodeTOadd;
                    std::cout << "The node has been added!" << std::endl;
                    break;
                }
                else if(nodeTOadd->value > temp->value)
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

int BST::FindHeight(Node* node)
{
    if (node == NULL)
    {
        return -1;
    }
    int Lheight = FindHeight(node->left);
    int Rheight = FindHeight(node->right);

    return (std::max(Lheight, Rheight) + 1);
}

int BST::BalancedCheckHelper(Node* node)
{

    if (node == NULL)
    {
        return 0;
    }

    int Lheight = BalancedCheckHelper(node->left);
    int Rheight = BalancedCheckHelper(node->right);

    if(Lheight == -1 || Rheight == -1)
    {
        return -1;
    }

    if(std::abs((Lheight - Rheight)) > 1)
    {
        return -1;
    }

    return (std::max(Lheight, Rheight) + 1);
} 

bool BST::BalancedCheck(Node* node)
{
    if(BalancedCheckHelper(node) != -1)
    {
        return true;
    }

    return false;
}

bool BST::isBSThelper(Node* node, int min, int max)
{
    if (node == NULL)
    {
        return true;
    }

    if(node->value > min && node->value < max && isBSThelper(node->left, min, node->value) 
    && isBSThelper(node->right, node->value, max)  )
    {
        return true;
    }
    return false;
    

}

bool BST::isBST(Node* node)
{
    if(node == NULL)
    {
        return true;
    }
    return isBSThelper(node, INT_MIN, INT_MAX);
}


Node* BST::minNode(Node* node)
{
   Node* temp = node;
   while (temp->left != NULL)
   {
     temp = temp->left;
   }
   return temp;
}
/*
case 1: node to be delted has no children
case 2: node to be delted has one children
case 3: node to be deleted has two children
*/
Node* BST::deleteNode(Node* node, int v)
{
    if(node == NULL)
    {
        std::cout << "The tree does not have any nodes to be deleted" << std::endl;
        return node;
    }
    else if(v < node->value)
    {
        node->left = deleteNode(node->left, v);
    }
    else if(v > node->value)
    {
        node->right = deleteNode(node->right, v);
    }
    else
    {
        if(node->left == NULL && node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        else if(node->left == NULL)
        {
            Node* temp = node;
            node = node->right;
            delete temp;

        }
        else if(node->right == NULL)
        {
            Node* temp = node;
            node = node->left;
            delete temp;


        }
        else
        {
            Node* temp = minNode(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
    }
    return node;
}