>bfs的过程中，不再用栈空间追踪，而是自定义路径

先看二叉树的回溯:
#回溯 

使用`joined_path` 记录路径，最终用 `pop_back` 恢复现场

## 子集型回溯
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

## 划分型回溯

把分割线看成  `,`   再考虑选或不选
```
vector<vector<string>> ans;
vector<string> path;
int n = string.size();
auto dfs = [&](this auto&& dfs, int i, int start) {//i为当前点，start为自字符串起点
	if (i == n) { //分割完毕
		ans.emplace_back(path);
		return;
	}
	if (i < n - 1) { //在小于n-1时才能不分割，在 i = n-1时必须分割，否则会出现空字符串
		dfs(i + 1, start); 
	}
	if (//条件) {
		path.emplace_back(s.substr(start, i - start + 1));//当前处分割
		dfs (i + 1, i + 1);
		path.pop_back();//恢复现场
	}
};
```
[leetcode131](https://leetcode.cn/problems/palindrome-partitioning/description/) 分割字符串

## 排列型回溯

创建一个 `vector<bool>`用来表示`path`中已有的元素，遍历所有数，若不在`path`中就加入`path` 

```
vector<vector<int>> permute(vector<int>& nums) {

	int n = nums.size();
	vector<int> path(n);
	vector<bool> on_path(n);
	vector<vector<int>> ans;
	auto dfs = [&](this auto&& dfs, int i) -> void {
		if (i == n) {
			ans.emplace_back(path);
			return;
		}
		for (int j = 0; j < n; j++) {
			if (!on_path[j]) {
				path[i] = nums[j];
				on_path[j] = true;
				dfs(i + 1);
				on_path[j] = false;
			}
		}
	};
	dfs(0);
	return ans;
}
```

## 有重复元素的回溯

集合子集的去重。实际上，只有选择重复元素才会产生重复子集，所以可以先排序原集合，再比较下一个元素是否与上一个相同，如果相同则跳过。
构造函数时采用选与不选的思路。注意一定要先写**选**的逻辑，确保每个可能重复的组合至少被选一次

```
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	ranges::sort(nums);
	int n = nums.size();
	vector<int> path;
	vector<vector<int>> ans;
	auto dfs = [&](this auto&& dfs, int i) -> void{
		if (i == n) {
			ans.push_back(path);
			return;
		}
		int x = nums[i];
		//选
		path.push_back(x);
		dfs(i + 1);
		path.pop_back(); //恢复现场
		//不选
		i++;
		while (i < n && nums[i] == x) {
			i++;
		}
		dfs(i);
	};
	dfs(0);
	return ans;
}
```

