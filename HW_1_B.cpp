#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <numeric>
using namespace std;

int main()
{
    //store the matrix
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    int A,B,C;
    int Ai,Aj,Bi,Bj,Ci,Cj;
    for (int j = 0; j< n; j++)
    {
        vector<int> row = {};
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            if (a == "_")
            row.push_back(-1);
            else 
            row.push_back(stoi(a));
        }
        matrix.push_back(row);
    }
    //replace -1
    bool AT = false;
    bool BT = false;
    bool CT = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            { Ai = i;
             Aj = j;
            matrix[i][j] = -2;
            AT = true;
            break;}
        }
        if (AT)
        break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            { Bi = i;
            Bj = j;
            matrix[i][j] = -3;
            BT = true;
            break;}
        }
        if (BT)
        break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            { Ci = i;
             Cj = j;
            matrix[i][j] = -4;
            CT = true;
            break;}
        }
        if (CT)
        break;
    }
    //穷举出结果
    bool F = true;
    for (int p = 0; p <= n*n; p++)
    { matrix[Ai][Aj] = p;
    
        for (int q = 0; q <= n*n; q++)
        { matrix[Bi][Bj] = q;
            for (int g = 0; g <= n*n; g++)
            {           matrix[Ci][Cj] = g;
                        vector<vector<int>> matrix_f ={};
                        for (int k = 0; k < n; k++)
                        {
                            matrix_f.push_back({});
                        }
                        for (int k = 0; k < n; k++)
                        {
                            for (int a = 0; a < n; a++)
                            {matrix_f[k].push_back(matrix[a][k]);}
                        }
                        //计算对角
                        vector <int> Dia1  = {};
                        vector <int> Dia2  = {};
                        for (int i = 0; i < n; i++)
                        Dia1.push_back(matrix[i][i]);
                        for (int i = 0; i < n; i++)
                        Dia2.push_back(matrix[i][n-i-1]);
                        int Sum1 = accumulate(Dia1.begin(), Dia1.end(), 0);
                        int Sum2 = accumulate(Dia2.begin(), Dia2.end(), 0);
                        vector <vector<bool>> judge ={};
                        for (int h = 0; h< n; h++)
                        {
                            vector<bool> pow = {};
                            for (int v = 0; v < 5; v++)
                            {
                                pow.push_back(false);
                            }
                            judge.push_back(pow);
                        }
                        for (int mn = 0; mn < n-1 ; mn++)
                        {
                            if ( accumulate(matrix[mn].begin(), matrix[mn].end(), 0) == accumulate(matrix[mn+1].begin(), matrix[mn+1].end(), 0))
                            judge[mn][0]=true;
                            if ( accumulate(matrix_f[mn].begin(), matrix_f[mn].end(), 0) == accumulate(matrix_f[mn+1].begin(), matrix_f[mn+1].end(), 0) )
                            judge[mn][1]=true;
                            if ( accumulate(matrix[mn].begin(), matrix[mn].end(), 0) == accumulate(matrix_f[mn].begin(), matrix_f[mn].end(), 0) )
                            judge[mn][2]=true;
                            if ( Sum1 == Sum2 ) 
                            judge[mn][3]=true; 
                            if ( Sum1 == accumulate(matrix[mn].begin(), matrix[mn].end(), 0))
                            judge[mn][4]=true;
                           
                        }
                        for (int h = 0; h< n-1; h++)
                        {
                            for (int e = 0; e < 5; e++)
                            {
                                if (! judge[h][e])
                                {F = false;
                                break;}
                                else 
                                F = true;
                            }
                            if (!F)
                            break;
                        }
                        if (F)
                        break;
                        
            }
                if (F)
                break;
        }
            if (F)
            break;
    }
    //print the result
    for (int k = 0; k < n; k++)
                        {
                            for (int a = 0; a < n; a++)
                            {
                                for (int b = k+1; b < n; b++)
                                {
                                    for (int c = a+1; c < n; c++)
                                    {
                                        if (matrix[k][a] == matrix[b][c])
                                        F = false;
                                    }
                                }
                            }
                        }
    if (F)
    {
        for (int k = 0; k < n; k++)
                        {
                            for (int a = 0; a < n; a++)
                            {cout << matrix[k][a] << " ";}
                            cout << endl;
                        }
    }
    else
    {
        cout << "No solution";
    }
    return 0;
}