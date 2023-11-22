#include <iostream>
#include <vector>
using namespace std;

int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  //全局方向数组
int grid[16][16];                                       //全局地图
int m, n;                                               //全局地图长和宽
int ans = 0;                                            //全局存储答案

void dfs(int x, int y, int gold) {                      //深度优先搜索
    gold += grid[x][y];                                 //把这个格子里的黄金开采出来
    ans = max(ans, gold);                               //答案是最大的数

    int rec = grid[x][y];                               //临时存储当前黄金数量
    grid[x][y] = 0;                                     //标记为不可进入

    for (int d = 0; d < 4; ++d) {                       //四个方向
        int nx = x + dirs[d][0];
        int ny = y + dirs[d][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
            dfs(nx, ny, gold);                          //递归
        }
    }

    grid[x][y] = rec;                                   //还原
}

int getMaximumGold(vector<vector<int>>& grid) {         //主要的运算函数
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; ++i) {                       //初始化
        for (int j = 0; j < n; ++j) {
            ::grid[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {                       //随机进入
        for (int j = 0; j < n; ++j) {
            if (::grid[i][j] != 0) {
                dfs(i, j, 0);                           //开始递归深度优先搜索
            }
        }
    }
    return ans;                                         //返回答案
}

int main()
{
    vector<vector<int>> grid = { {1,0,7},               //输入
                                 {2,0,6},
                                 {3,4,5},
                                 {0,3,0},
                                 {9,0,20} };
    cout << getMaximumGold(grid);                       //输出
	return 0;
}