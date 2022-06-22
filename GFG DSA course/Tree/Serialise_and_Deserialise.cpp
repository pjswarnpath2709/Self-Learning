#include <bits/stdc++.h>
using namespace std;

/*

stringstream and getline together : ->

 We can use getline() function to split a sentence on the basis of a character. Let’s look at an example to understand how it can be done.

 example for this : ->
// C++ program to understand the use of getline() function
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;

    getline(cin, S);

    stringstream X(S);

    while (getline(X, T, ' ')) {
        cout << T << endl;
    }

    return 0;
}
//input: ->
Hello, Faisal Al Mamun. Welcome to GfG!

//output: ->
Hello,
Faisal
Al
Mamun.
Welcome
to
GfG!

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }
        string s = "";
        queue<TreeNode *> qt;
        qt.push(root);
        while (!qt.empty())
        {
            TreeNode *curr = qt.front();
            qt.pop();
            if (curr == nullptr)
            {
                s.append("#,");
            }
            else
                s.append(to_string(curr->val) + ",");

            if (curr != nullptr)
            {
                qt.push(curr->left);
                qt.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> qt;
        qt.push(root);
        while (!qt.empty())
        {
            TreeNode *curr = qt.front();
            qt.pop();
            // getting the left node for the object
            getline(s, str, ',');
            if (str == "#")
            {
                curr->left = nullptr;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                qt.push(leftNode);
            }
            // getting the right node for the object
            getline(s, str, ',');
            if (str == "#")
            {
                curr->right = nullptr;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                qt.push(rightNode);
            }
        }
        return root;
    }
};
int main()
{

    return 0;
}
