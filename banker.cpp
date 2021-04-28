/*
 * @Author: Jinqi Xu 
 * @Date: 2021-04-28 16:10:39 
 * @Last Modified by: Jinqi Xu
 * @Last Modified time: 2021-04-28 17:56:17
 */
#include "banker.h"
#include <iostream>
#include <string.h>

using namespace std;

int Available[N] = {3, 3, 2};
int Request[M] = {0};
int Max[M][N] = {{7, 5, 3},
                 {3, 2, 2},
                 {9, 0, 2},
                 {2, 2, 2},
                 {4, 3, 3}};
int Allocation[M][N] = {{0, 1, 0},
                        {2, 0, 0},
                        {3, 0, 2},
                        {2, 1, 1},
                        {0, 0, 2}};
int Need[M][N] = {{7, 4, 3},
                  {1, 2, 2},
                  {6, 0, 0},
                  {0, 1, 1},
                  {4, 3, 1}};
bool Finish[M];

void Print()
{
    cout << "系统各类资源剩余" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << Available[i] << " ";
    }
    cout << endl
         << "系统当前进程资源情况：" << endl;
    cout << "PID\tMax\t\tAllocation\tNeed" << endl;
    for (int i = 0; i < M; i++)
    {
        cout << "P" << i + 1 << "\t";
        for (int j = 0; j < N; j++)
        {
            cout << Max[i][j] << " ";
        }
        cout << "\t\t";

        for (int j = 0; j < N; j++)
        {
            cout << Allocation[i][j] << " ";
        }
        cout << "\t\t";
        for (int j = 0; j < N; j++)
        {
            cout << Need[i][j] << " ";
        }
        cout << endl;
    }
}

void SafePrint(int i, int Work[])
{
    cout << "P" << i + 1 << "\t";
    for (int j = 0; j < N; j++)
    {
        cout << Work[j] - Allocation[i][j] << " ";
    }
    cout << "\t\t";
    for (int j = 0; j < N; j++)
    {
        cout << Allocation[i][j] << " ";
    }
    cout << "\t\t";
    for (int j = 0; j < N; j++)
    {
        cout << Need[i][j] << " ";
    }
    cout << "\t\t";
    for (int j = 0; j < N; j++)
    {
        cout << Work[j] << " ";
    }
    cout << endl;
}

bool isSafe()
{
    int Work[N];
    int temp = 0;
    memset(Work, 0, N);
    for (int i = 0; i < N; i++)
    {
        Work[i] = Available[i];
    }
    for (int i = 0; i < M; i++)
    {
        Finish[i] = false;
    }

    int count = M;
    for (int i = 0; i < M; i++)
    {
        bool flag = true;
        for (int j = 0; j < N; j++)
        {
            if (Need[i][j] != 0)
            {
                flag = false;
                count--;
                break;
            }
        }
        Finish[i] = flag;
    }
    int curProcess = 0;
    while (count != M)
    {
        int num = 0;
        for (int i = 0; i < N; i++)
        {
            if (Finish[curProcess] == false && Need[curProcess][i] <= Work[i])
                num++;
        }
        if (num == N)
        {
            for (int i = 0; i < N; i++)
            {
                Work[i] += Allocation[curProcess][i];
            }
            count++;
            SafePrint(curProcess, Work);
            Finish[curProcess] = true;
        }
        curProcess++;
        if (curProcess >= M)
        {
            curProcess %= M;
            if (temp == count)
                break;
            temp = count;
        }
    }
    bool flag = true;
    for (int i = 0; i < M; i++)
    {
        if (Finish[i] == false)
        {
            flag = false;
            break;
        }
    }
    flag == true ? (cout << "当前系统处于安全状态" << endl) : (cout << "当前系统不安全" << endl);
    return flag;
}