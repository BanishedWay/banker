/*
 * @Author: Jinqi Xu 
 * @Date: 2021-04-28 16:17:21 
 * @Last Modified by: Jinqi Xu
 * @Last Modified time: 2021-04-28 17:56:21
 */
#include <iostream>
#include "banker.h"

using namespace std;

int main()
{
    int numP, num;
    Print();
    cout << "PID\tWork\t\tAllocation\tNeed\t\tWork+Allocation" << endl;
    bool flag = isSafe();

    while (flag)
    {
        cout << "请输入要分配的进程：(1-5):0(结束)" << endl;
        cin >> numP;
        if (numP == 0)
        {
            exit(0);
        }
        else if (numP <= 5 && numP > 0)
        {
            numP--;
            cout << "请输入分配的资源数：" << endl;
            for (int i = 0; i < N; i++)
            {
                cin >> Request[i];
            }
            num = 0;
            for (int i = 0; i < N; i++)
            {
                Available[i] -= Request[i];
                Allocation[numP][i] += Request[i];
                Need[numP][i] -= Request[i];
                if (Need[numP][i] == 0)
                {
                    num++;
                }
            }
            if (num == N)
            {
                //释放已完成进程
                for (int i = 0; i < N; i++)
                {
                    Available[i] += Allocation[numP][i];
                }
                cout << "分配进程" << numP + 1 << "成功，所有资源释放完毕" << endl;
            }
            else
            {
                cout << "分配进程未完成" << endl;
            }
            Print();
            cout << "PID\tWork\t\tAllocation\tNeed\t\tWork+Allocation" << endl;
            if (!isSafe())
            {
                for (int i = 0; i < N; i++)
                {
                    Available[i] += Request[i];
                    Allocation[numP][i] -= Request[i];
                    Need[numP][i] += Request[i];
                }
                cout << "资源不足，分配失败，进程等待" << endl;
            }
        }
        else
        {
            cout << "请重新输入：\n";
        }
    }
    system("pause");
    return 0;
}
