#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int x, y = 1;

        // step 1: traversing first row
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                x = 0;
            }
        }

        // step 2: travesing 1st column

        for (int j = 0; j < m; j++)
        {
            if (matrix[j][0] == 0)
            {
                y = 0;
            }
        }

        for (int k = 1; k < m; k++)
        {
            for (int z = 1; z < n; z++)
            {
                if (matrix[k][z] == 0)
                {
                    matrix[k][0] = 0;
                    matrix[0][z] = 0;
                }
            }
        }

        // for (int l = 0; l < n; l++)
        // {
        //     if (matrix[0][l] == 0)
        //     {
        //         for (int p = 1; p < m; p++)
        //             matrix[p][l] = 0;
        //     }
        // }

        // for (int o = 0; o < m; o++)
        // {
        //     if (matrix[o][0] == 0)
        //     {
        //         for (int q = 1; q < n; q++)
        //             matrix[o][q] = 0;
        //     }
        // }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {

                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (x == 0)
        {
            for (int a = 0; a < n; a++)

                matrix[0][a] = 0;
        }

        if (y == 0)
        {
            for (int b = 0; b < m; b++)

                matrix[b][0] = 0;
        }
    }
};
