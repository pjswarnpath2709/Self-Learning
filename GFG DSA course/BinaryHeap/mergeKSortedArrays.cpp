

#include <bits/stdc++.h>
using namespace std;

struct Triplet
{

    int val;
    int aPos;
    int vPos;
    Triplet(int val, int apos, int vpos) : val(val), aPos(apos), vPos(vpos)
    {
    }
};
struct MyComp
{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &mat, int k)
{
    priority_queue<Triplet, vector<Triplet>, MyComp> pq;
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        Triplet t(mat[i][0], 0, 0);
        pq.push(t);
    }
    while (!pq.empty())
    {
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap = curr.aPos, vp = curr.vPos;
        if (vp + 1 < mat[ap].size())
        {
            Triplet t(mat[ap][vp + 1], ap, vp + 1);
            pq.push(t);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> arr{{10, 20, 30},
                            {5, 15},
                            {1, 9, 11, 18}};

    vector<int> res = mergeKSortedArrays(arr, 3);
    cout << "Merged array is " << endl;
    for (auto x : res)
        cout << x << " ";
    return 0;
}