/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
bool isLeafNode(Node *root)
{
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}
bool isSumTreeUtil(Node * root, int& sum)
{
    if(root == NULL)
        return false;
    
    if(isLeafNode(root))
    {
        sum = root->data;
        return true;
    }
    
    int leftSum = 0;
    int rightSum = 0;
    bool isLeftSumTree = false;
    bool isRightSumTree = false;
    if(root->left)
        isLeftSumTree = isSumTreeUtil(root->left, leftSum);

    if(root->right && isLeftSumTree)
        isRightSumTree = isSumTreeUtil(root->right, rightSum);
        
    if(isLeftSumTree && isRightSumTree)
    {
        if(root->data == leftSum + rightSum)
        {
            sum = root->data + leftSum + rightSum;
            return true;
        }
    }
    return false;
}

bool isSumTree(Node* root)
{
     if(root == NULL)
        return true;
    
    int sum = 0;
    return isSumTreeUtil(root, sum);
}