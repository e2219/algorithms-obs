>bfs的过程中，不再用栈空间追踪，而是自定义路径

先看二叉树的回溯:
#回溯 

使用`joined_path` 记录路径，最终用 `pop_back` 恢复现场

## 一般回溯
```
//获取一个集合的所有子集:选与不选
vector<vector<int>> subsets(vector<int> &nums) {
	vector<vector<int>> ans;
	int n = nums.size();
	vector<int> path;
	auto dfs = [&](this auto&& dfs, int i) -> void //i表示从第i个元素到第n个元素的构造{
		if (i == n) {
			ans.emplace_back(path);
			return;
		}
		// 考虑nums[i]选与不选
		
		dfs(i + 1); //不选择 nums[i]，考虑下一个元素选不选
		path.push_back(nums[i]); //选择nums[i]
		dfs(i + 1); //考虑下一个数选不选
		path.pop_back(); //恢复现场，撤销 push_back()
	};
	dfs(0);
	return ans;
	
}
```