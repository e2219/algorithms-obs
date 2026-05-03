
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

# 从树到 BFS

## 遍历 

现有一棵由 `n` 个节点组成的无向树，节点编号从 `0` 到 `n - 1` ，共有 `n - 1` 条边。

给你一个二维整数数组 `edges` ，长度为 `n - 1` ，其中 `edges[i] = [ai, bi]` 表示树中节点 `ai` 和 `bi` 之间存在一条边。另给你一个整数数组 `restricted` 表示 **受限** 节点。

在不访问受限节点的前提下，返回你可以从节点 `0` 到达的 **最多** 节点数目_。_

注意，节点 `0` **不** 会标记为受限节点。

```
class Solution{
	vector<vector<int>> grid //用于构造图
public:
	int dfs(int x, int fa) //以fa为父节点的节点x能访问到的所有节点数
{
	int cnt = 1; //保证 x 是可访问到的一个节点
	for (int y : grid[x]) { //以x为父节点的所有节点能访问到的节点数
		if (y != fa) { //fa是已访问的节点，这一步是防止无向图的某一边被计数两次
			cnt += dfs(y, x);
		}
	}
	return cnt;
} 	
	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
		unordered_set<int> r(restricted.begin(), restricted.end()); //用于快速判断节点是否可访问
		for (auto& edge : edges) { //构造无向图
			int x = edge[0], int y = edge[1]; 
			if (!r.contains(x) && !r.contains(y)) {
				grid[x].push_back(y);
				grid[y].push_back(x);
			}
		}
		return dfs(0, -1);
	}
}
```

[leetcode1466 重新规划路线](https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/) 用pair中的 1/0 来表示有向边