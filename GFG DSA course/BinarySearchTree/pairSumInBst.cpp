

#include <bits/stdc++.h>
using namespace std;

struct bstnode
{
    int data;
    bstnode *left;
    bstnode *right;
    bstnode(int key)
    {
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};
bool hasPairSum(bstnode *root, int sum, unordered_set<int> &st)
{
    if (root == nullptr)
    {
        return false;
    }
    if (hasPairSum(root->left, sum, st))
    {
        return true;
    }
    if (st.count(sum - root->data))
    {
        return true;
    }
    st.insert(root->data);
    return hasPairSum(root->right, sum, st);
}

int main()
{
    bstnode *root = new bstnode(10);  
    root->left = new bstnode(8);  
    root->right = new bstnode(20);  
    root->left->left = new bstnode(4);
    root->left->right = new bstnode(9);
    root->right->left = new bstnode(11);
    root->right->right = new bstnode(30);  
    root->right->right->left = new bstnode(25);
        
    int sum=33;
    unordered_set<int> s;    
    cout<<hasPairSum(root,sum,s)<<" \n";
          
    return 0;  
}