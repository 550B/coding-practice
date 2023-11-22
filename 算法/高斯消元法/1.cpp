/*
*����: ��ѡ��Ԫ��Ԫ��
*@Author: lzyws739307453
*@Language: C++
*@File Name: Gauss.cpp
*@Create Time: 2019��05��05�� ������
*/
#include <iostream>
using namespace std;
const int MAXN = 5;
//�������
void printM(double a[][MAXN], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++)
            printf("%10f,", a[i][j]);
        printf("\n");
    }
}
//ѡ������Ԫ��������Ԫ
void SelectColE(double a[][MAXN], int n) {
    double temp; //���ڼ�¼��Ԫʱ������
    for (int i = 1; i <= n; i++) {
        int r = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[j][i]) > fabs(a[r][i]))
                r = j;
        if (r != i)
            for (int j = i; j <= n + 1; j++)
                swap(a[i][j], a[r][j]);//�������Ԫ�����н���
        for (int j = i + 1; j <= n; j++) {//��Ԫ
            temp = a[j][i] / a[i][i];
            for (int k = i; k <= n + 1; k++)
                a[j][k] -= a[i][k] * temp;
        }
        printf("��%d����Ԫ��\n", i);
        printM(a, 3);
    }
}
//��˹��Ԫ��(��ѡ��Ԫ)
void Gauss(double a[][MAXN], int n) {
    SelectColE(a, n);//��ѡ��Ԫ����Ԫ��������
    printf("�����ǵĽ����\n");
    printM(a, 3);
    for (int i = n; i >= 1; i--) {//�ش����
        for (int j = i + 1; j <= n; j++)
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
}
//���Ժ���
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