#include<bits/stdc++.h>

using namespace std;


struct Node
{
    int data;
    Node* left, * right;
}; 


struct Node* newNode(int data)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}

//Function to compare every node of subtree with the tree where the root of subtree matches a node in tree
bool comparetree(Node* t_root,Node* s_root)
{
    if(t_root==NULL && s_root==NULL)
    return 1;
    
    if(t_root==NULL || s_root==NULL)
    return 0;
    
    if(t_root->data==s_root->data)
    return (comparetree(t_root->left,s_root->left)&&comparetree(t_root->right,s_root->right));
    else
    return 0;
}

bool isSubtree(Node*  t_root ,Node* s_root)
{
    //if subtree is NULL it is a subtree of every tree
    if(s_root==NULL)
    return 1;
    
    if(t_root==NULL)
    return 0;
    
    if(comparetree(t_root,s_root))
    return 1;
    
    return(isSubtree(t_root->right,s_root) || isSubtree(t_root->left,s_root));
    
}

bool testemptytrees()
{
    struct Node *T =NULL;
    
    struct Node *S =NULL;
    
    return(isSubtree(T, S));
}

bool testemptysubtree()
{
    struct Node *T =newNode(10);
    
    struct Node *S =NULL;
    
    return(isSubtree(T, S));
}

bool testemptytree()
{
    struct Node *T =NULL;
    
    struct Node *S =newNode(10);
    
    return(!isSubtree(T, S));   
}

bool testnotsubtree()
{
    struct Node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 

    struct Node *S    = newNode(10);
    S->right          = newNode(60);
    S->left           = newNode(4);
    S->left->right    = newNode(30);  
    
    return(!isSubtree(T, S)); 
}

bool testsametrees()
{
    struct Node *T    = newNode(10);
    T->right          = newNode(60);
    T->left           = newNode(4);
    T->left->right    = newNode(30); 

    struct Node *S    = newNode(10);
    S->right          = newNode(60);
    S->left           = newNode(4);
    S->left->right    = newNode(30); 
    
    return(isSubtree(T,S));
}

bool test()
{
    return(testemptytrees() && testemptysubtree() && testemptytree() && testnotsubtree() && testsametrees());
}
int main()
{

    struct Node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 

    struct Node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        cout<<"Is a subtree";
    else
        cout<<"Not a subtree";
        
    cout<<test();
        
    return 0;
    
        
}
