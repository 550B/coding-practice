/*
*功能: 列选主元消元法
*@Author: lzyws739307453
*@Language: C++
*@File Name: Gauss.cpp
*@Create Time: 2019年05月05日 星期日
*/
#include <iostream>
using namespace std;
const int MAXN = 5;
//输出矩阵
void printM(double a[][MAXN], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++)
            printf("%10f,", a[i][j]);
        printf("\n");
    }
}
//选择列主元并进行消元
void SelectColE(double a[][MAXN], int n) {
    double temp; //用于记录消元时的因数
    for (int i = 1; i <= n; i++) {
        int r = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[j][i]) > fabs(a[r][i]))
                r = j;
        if (r != i)
            for (int j = i; j <= n + 1; j++)
                swap(a[i][j], a[r][j]);//与最大主元所在行交换
        for (int j = i + 1; j <= n; j++) {//消元
            temp = a[j][i] / a[i][i];
            for (int k = i; k <= n + 1; k++)
                a[j][k] -= a[i][k] * temp;
        }
        printf("第%d列消元后：\n", i);
        printM(a, 3);
    }
}
//高斯消元法(列选主元)
void Gauss(double a[][MAXN], int n) {
    SelectColE(a, n);//列选主元并消元成上三角
    printf("上三角的结果：\n");
    printM(a, 3);
    for (int i = n; i >= 1; i--) {//回代求解
        for (int j = i + 1; j <= n; j++)
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
}
//测试函数
int main() {
    double a[4][MAXN] = {
        {0,   0,   0,   0,   0},
        {0,   2,   1,  -1,   8},
        {0,  -3,  -1,   2, -11},
        {0,  -2,   1,   2,  -3}
    };
    Gauss(a, 3);
    for (int i = 1; i <= 3; i++)
        printf("X%d = %9f\n", i, a[i][4]);
    return 0;
}