#include <bits/stdc++.h>
using namespace std;
// structure of the node
struct btnode
{
    int data;
    btnode *left;
    btnode *right;

    btnode(int key)
    {
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int main()
{
    return 0;
}
/*

// properties of the bianry trees

class BTproperties
{
private:
    int _daimeter = INT_MIN;
    int _getSize(btnode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + _getSize(root->left) + _getSize(root->right);
    }

    int _getHeight(btnode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lh = _getHeight(root->left);
        int rh = _getHeight(root->right);
        return 1 + max(lh, rh);
    }

    int _getDaimeter(btnode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lh = _getHeight(root->left);
        int rh = _getHeight(root->right);
        _daimeter = max(1 + lh + rh, _daimeter);

        return 1 + max(lh, rh);
    }

    int _getMax(btnode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        int lm = _getMax(root->left);
        int rm = _getMax(root->right);
        return max(root->data, max(lm, rm));
    }

    void _getKthnode(btnode *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }
        if (k == 0 && root != nullptr)
        {
            cout << root->data << " ";
            return;
        }
        else
        {
            _getKthnode(root->left, k - 1);
            _getKthnode(root->right, k - 1);
        }
    }

    void _leftVeiw(btnode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        // iterative version
        queue<btnode *> qt;
        qt.push(root);
        while (!qt.empty())
        {
            int size = qt.size();
            for (int i = 0; i < size; i++)
            {
                btnode *curr = qt.front();
                qt.pop();
                if (i == 0)
                {
                    cout << curr->data << " ";
                }
                if (curr->left)
                {
                    qt.push(curr->left);
                }
                if (curr->right)
                {
                    qt.push(curr->right);
                }
            }
        }
    }

    int _isBalancedBinaryTree(btnode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lh = _isBalancedBinaryTree(root->left);
        if (lh < 0)
        {
            return -2;
        }
        int rh = _isBalancedBinaryTree(root->right);
        if (rh < 0)
        {
            return -1;
        }
        if (abs(lh - rh) > 1)
        {
            return -1;
        }
        return max(lh, rh) + 1;
    }

    bool _hasChildSumProperty(btnode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        // current node ke liye dekhte he sabse phele
        int sum = 0;
        if (root->left)
        {
            sum += root->left->data;
        }
        if (root->right)
        {
            sum += root->right->data;
        }
        return root->data == sum && _hasChildSumProperty(root->left) && _hasChildSumProperty(root->right);
    }

public:
    string size;
    string height;
    string diameter;
    string maxi;
    string haschildSumProperty;
    string isBalancedBinaryTree;
    BTproperties(btnode *root)
    {

        size = "size: " + to_string(_getSize(root));
        height = "height: " + to_string(_getDaimeter(root));
        diameter = "diameter: " + to_string(_daimeter);
        maxi = "maximum: " + to_string(_getMax(root));
        haschildSumProperty = _hasChildSumProperty(root) ? "childSumProperty : true" : "ChildSumProperty: false";
        isBalancedBinaryTree = _isBalancedBinaryTree(root) ? "BalancedBinaryTree : true" : "BalancedBinaryTree :false";
    }

    void getKthnode(btnode *root, int k)
    {
        cout << "getKthNodes: ";
        _getKthnode(root, k);
        cout << "\n";
    }
    void leftVeiw(btnode *root)
    {
        cout << "leftVeiw: ";
        _leftVeiw(root);
        cout << "\n";
    }
};

int main()
{
    btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->left->left = new btnode(40);
    root->left->right = new btnode(50);
    root->right->left = new btnode(60);
    root->right->right = new btnode(70);

    BTproperties *btprop = new BTproperties(root);

    cout << btprop->size << "\n";
    cout << btprop->height << "\n";
    cout << btprop->diameter << "\n";
    cout << btprop->maxi << "\n";
    cout << btprop->haschildSumProperty << "\n";
    cout << btprop->isBalancedBinaryTree << "\n";
    btprop->leftVeiw(root);

    int k;
    cin >> k;
    btprop->getKthnode(root, k);
}

*/

/*

// kind of traversals
//general depth first searches in the binary tree
void preorder(btnode * root){
     if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(btnode* root){
  if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
         cout<<root->data<<" ";
    }
}
void inorder(btnode * root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// level order traversal without using extra loop
void levelorder(btnode * root){
    if(root==nullptr){
        return;
    }

    queue<btnode*> qt;
    qt.push(root);

    while(qt.empty()==false){
        btnode * front = qt.front();
        qt.pop();
        cout<<front->data<<" ";
        if(front->left){
            qt.push(front->left);
        }
        if(front->right){
            qt.push(front->right);
        }
    }
}

// preorder iteravtive inserting things in reverse manner into the stack
void preorderIter(btnode * root){
    if(root==nullptr){
        return;
    }
    stack<btnode *> st;
    st.push(root);
    while(st.empty()==false){
        btnode * top = st.top();
        st.pop();
        if(top){
            cout<<top->data<<" ";
            st.push(top->right);
            st.push(top->left);
        }
    }
}

//inorder iterative using infinite loop and stack
void inorderIter(btnode * root){
   if(root==nullptr){
       return;
   }
   btnode * node = root;
   stack<btnode *> st;
   while(true){
       if(node!=nullptr){
           st.push(node);
           node = node->left;
       }
       else{
           if(st.empty()) break;
           node = st.top();
           st.pop();
           cout<<node->data<<" ";
           node = node->right;
       }
   }
}
//post order iterative using two stacks
void postorderIter2stack(btnode * root){
    if(root==nullptr){
        return;
    }
    btnode *node = root;
    stack<btnode *> st1;
    stack<int> st2;
    st1.push(node);
    while (!st1.empty())
    {
        node = st1.top();
        st1.pop();
        st2.push(node->data);
        if (node->left != nullptr)
        {
            st1.push(node->left);
        }
        if (node->right != nullptr)
        {
            st1.push(node->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
}

//post order iterative using single stack
void postorderIter1stack(btnode * root){
    if(root==nullptr){
        return;
    }
    btnode * node = root;
    stack<btnode *> st;
    while(!st.empty() || node !=nullptr ){
        if(node !=nullptr){
            //explore the left side of the tree
            st.push(node);
            node = node->left;
        }else{

            //chk if the right side exists or not
            btnode * temp = st.top()->right;
            //if it not exists
            if(temp==nullptr){

                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }else{
                node = temp;
            }
        }
    }
}

//all traversals in single loop
void allTraversals(
 btnode * root,
 vector<int> &pre,
 vector<int> &in,
 vector<int> &post
){
    if(root==nullptr){
        return;
    }
    btnode * curr = root;
    stack<pair<btnode *,int>> st;
    st.push({curr,1});
    while(!st.empty()){
        if(st.top().second == 1){
            pre.push_back(st.top().first->data);
            ++st.top().second;
            if(st.top().first->left){
                st.push({st.top().first->left,1});
            }
        }
        else if(st.top().second==2){
            in.push_back(st.top().first->data);
            ++st.top().second;
            if(st.top().first->right){
                st.push({st.top().first->right,1});
            }
        }
        else{
            post.push_back(st.top().first->data);
            st.pop();
        }
    }

}
template <class T>
void printVector(vector<T> &vec){
    for(auto i : vec){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main() {

 btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->left->left = new btnode(40);
    root->left->right = new btnode(50);
    root->right->left = new btnode(60);
    root->right->right = new btnode(70);

     cout << "preorder : ";
    preorder(root);
    cout << "\n";
     cout << "inorder : ";
    inorder(root);
    cout << "\n";
     cout << "postorder : ";
    postorder(root);
    cout << "\n";
    cout << "levelorder : ";
    levelorder(root);
    cout << "\n";
    cout << "preorderIter : ";
    preorderIter(root);
    cout << "\n";
    cout << "inorderIter : ";
    inorderIter(root);
    cout << "\n";
     cout << "postorderIter2stack : ";
    postorderIter2stack(root);
    cout << "\n";
     cout << "postorderIter1stack : ";
    postorderIter1stack(root);
    cout<<"\n";

    vector<int> pre,in,post;
   allTraversals(root,pre,in,post);
   cout<< "pre : " ;
   printVector(pre);
   cout<< "in : " ;
    printVector(in);
   cout<<"post : ";
   printVector(post) ;


    return 0;
}

*/
