
# DFS 

>用递归的方法，朝各个方向走到头直到无路可走

典型例题：岛屿的数量

```
// 0 1 岛屿


void dfs(vector<vector<char> & grid, int i, int j) {
	int m = grid.size(), n = grid[0].size()  //获取整块网格的行列数
	if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') //无路可走（遇水或到达边界） {
		return; //结束当前递归
	}
	grid[i][j] = '2'; //标记已经走过的路，避免重复访问，否则将无限递归下去
	dfs(grid, i, j + 1);
	dfs(grid, i, j - 1);
	dfs(grid, i + 1, j);
	dfs(grid, i - 1, j);
}

int numIslands(vector<vector<char>> & grid) {
	int m = grid.size(), n = grid[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) { //逐个陆地遍历
			if (grid[i][j] == '1') //未涉足，标记，增加答案，dfs走到头 {
				ans++;
				dfs(grid, i, j);
			}
		}
	}
	return ans;
}
```