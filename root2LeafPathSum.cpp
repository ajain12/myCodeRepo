/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */

bool isLeafNode(Node * node)
{
    if(node == NULL)
        return false;
    if(node->left == NULL && node->right == NULL)
        return true;
    return false;
}
bool hasPathSum(Node *node, int sum)
{
    if(node == NULL)
        return false;
    bool isLeaf = isLeafNode(node);
    bool isfound = false;
    
    if(sum - node->data == 0)
        return isLeaf;
    else if(sum - node->data < 0)
        return false;
    else if(sum - node->data > 0 && isLeaf)
        return false;
    else
    {
        if(node->left != NULL)
            isfound = hasPathSum(node->left, sum - node->data);
        
        if(isfound)
            return true;
        else if(node->right != NULL)
            isfound = hasPathSum(node->right, sum - node->data);
    }
    
    return isfound;
}