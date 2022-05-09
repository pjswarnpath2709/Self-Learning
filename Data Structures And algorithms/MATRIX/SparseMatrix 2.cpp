#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, pair<int, int>>> VPP;
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void adder(VPP &x1, VPP &x2)
{
    if (x1[x1.size() - 1].first != x2[x2.size() - 1].first || x1[x1.size() - 1].second.first != x2[x2.size() - 1].second.first)
    {
        cout << "cant add these matrices"
             << "\n";
        exit(0);
    }
    VPP resulter;
    VPP ::iterator itr1 = x1.begin();
    VPP ::iterator itr2 = x2.begin();

    while (itr1 != x1.end()-1 && itr2 != x2.end())
    {
        if ((*itr1).ff != (*itr2).ff)
        {
            if ((*itr1).ff > (*itr2).ff)
            {
                resulter.push_back(*itr2);
                itr2++;
            }
            else
            {
                resulter.push_back(*itr1);
                itr1++;
            }
        }
        else
        {
            if ((*itr1).ss.ff > (*itr2).ss.ff)
            {
                resulter.push_back((*itr2));
                itr2++;
            }
            else if ((*itr1).ss.ff < (*itr2).ss.ff)
            {
                resulter.push_back((*itr1));
                itr1++;
            }
            else
            {
                resulter.push_back({(*itr1).ff, {(*itr1).ss.ff, (*itr1).ss.ss + (*itr2).ss.ss}});
                itr1++;
                itr2++;
            }
        }
    }

    int fir = (*(x1.end() - 1)).ff;
    int secfir = (*(x1.end() - 1)).ss.ff;
    int secsec = resulter.size();
    resulter.push_back({fir, {secfir, secsec}});
    for (auto i : resulter)
    {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }
    cout << "\n";
}

int main()
{
    VPP vec[2];
    for (int k = 0; k < 2; k++)
    {
        int m, n;
        // cout << "enter dimensions of sparse matrix";
        cin >> m >> n;
        int arr[m][n];

        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] != 0)
                {
                    vec[k].push_back({i + 1, {j + 1, arr[i][j]}});
                }
            }
        }
        vec[k].push_back({m, {n, vec[k].size()}});

        // for (auto i : vec[k])
        // {
        //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        // }
        // cout << "\n";
    }
    adder(vec[0], vec[1]);
    return 0;
}