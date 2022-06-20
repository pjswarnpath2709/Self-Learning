#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> vec;
        queue<pair<Node *, int>> qt; // queue<pair<Node *,hd>>
        map<int, int> mp;            // map<hd,nodeVal>
        if (root != nullptr)
        {
            qt.push({root, 0});
        }
        while (!qt.empty())
        {
            int size = qt.size();
            for (int i = 0; i < size; i++)
            {
                pair<Node *, int> p = qt.front();
                qt.pop();
                if (mp.find(p.second) == mp.end())
                {
                    mp.insert({p.second, p.first->data});
                }

                if (p.first->left)
                {
                    qt.push({p.first->left, p.second - 1});
                }
                if (p.first->right)
                {
                    qt.push({p.first->right, p.second + 1});
                }
            }
        }

        for (auto ele : mp)
        {
            vec.push_back(ele.second);
        }
        return vec;
    }
    vector<int> bottomView(Node *root)
    {
        vector<int> vec;
        queue<pair<Node *, int>> qt; // queue<pair<Node *,hd>>
        map<int, int> mp;            // map<hd,nodeVal>
        if (root != nullptr)
        {
            qt.push({root, 0});
        }
        while (!qt.empty())
        {
            int size = qt.size();
            for (int i = 0; i < size; i++)
            {
                pair<Node *, int> p = qt.front();
                qt.pop();
                mp[p.second] = p.first->data;

                if (p.first->left)
                {
                    qt.push({p.first->left, p.second - 1});
                }
                if (p.first->right)
                {
                    qt.push({p.first->right, p.second + 1});
                }
            }
        }

        for (auto ele : mp)
        {
            vec.push_back(ele.second);
        }
        return vec;
    }
};

int main()
{
    return 0;
}