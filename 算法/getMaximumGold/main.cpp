#include <iostream>
#include <vector>
using namespace std;

int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  //ȫ�ַ�������
int grid[16][16];                                       //ȫ�ֵ�ͼ
int m, n;                                               //ȫ�ֵ�ͼ���Ϳ�
int ans = 0;                                            //ȫ�ִ洢��

void dfs(int x, int y, int gold) {                      //�����������
    gold += grid[x][y];                                 //�����������Ļƽ𿪲ɳ���
    ans = max(ans, gold);                               //����������

    int rec = grid[x][y];                               //��ʱ�洢��ǰ�ƽ�����
    grid[x][y] = 0;                                     //���Ϊ���ɽ���

    for (int d = 0; d < 4; ++d) {                       //�ĸ�����
        int nx = x + dirs[d][0];
        int ny = y + dirs[d][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
            dfs(nx, ny, gold);                          //�ݹ�
        }
    }

    grid[x][y] = rec;                                   //��ԭ
}

int getMaximumGold(vector<vector<int>>& grid) {         //��Ҫ�����㺯��
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; ++i) {                       //��ʼ��
        for (int j = 0; j < n; ++j) {
            ::grid[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {                       //�������
        for (int j = 0; j < n; ++j) {
            if (::grid[i][j] != 0) {
                dfs(i, j, 0);                           //��ʼ�ݹ������������
            }
        }
    }
    return ans;                                         //���ش�
}

int main()
{
    vector<vector<int>> grid = { {1,0,7},               //����
                                 {2,0,6},
                                 {3,4,5},
                                 {0,3,0},
                                 {9,0,20} };
    cout << getMaximumGold(grid);                       //���
	return 0;
}