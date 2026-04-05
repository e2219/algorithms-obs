## 语法

\#include \<queue>

初始化：std::queue<> q;
入队：queue.push(element) / deque.push_front(element) / deque.push_back(element) 双端队列需分从队首还是队尾入队
出队：queue.pop() / deque.pop_front() / deque.pop_back();

[leetcode649](https://leetcode.cn/problems/dota2-senate/description/ Dota2参议院) 用队列将两队分流，根据索引大小模拟出队过程

## 单调队列(与滑动数组结合)

指定 k 个一组的滑动窗口，求这个窗口中元素的最大值。

想象一个折线图，在从左到右遍历的过程中，已经离开窗口的元素永远不可能是最大值，在一个窗口中会存在一个最大值。用双端队列来储存**索引**，**当前窗口的最大值索引放在队首**。窗口向右滑动，如果新入队的元素小于队尾元素，就入队，因为在后续遍历的过程中，它们可能是其他窗口的最大值。反之，如果进入窗口的元素大于等于队尾元素，说明之前的队尾元素无论如何也不可能成为最大值，应该离开队列(**pop_back()**)。当滑动窗口队首的元素（是一个索引）小于遍历的 i - k + 1 时，说明这个数应该离开窗口(**pop_front()**)。 这样就保证了队列的元素个数始终小于k，且队列最左侧是当前窗口最大值的索引。**队列储存滑动窗口中可能成为最大值的元素索引**

*及时去掉无用数据，保证双端队列有序*


代码模板：
```
vector<int> maxSlidingWindow(vector<int>& nums, int k){
	int n = nums.size();
	vector<int> ans(n - k + 1); //答案的元素个数是 n - k + 1
	deque<int> q; //创建单调双端队列储存当前滑动窗口最大值
	for (int i = 0; i < n; i++) {
		while (!q.empty() && nums[q.back()] <= nums[i]) { //进入窗口的元素大于队尾
			q.pop_back();
		}
		q.push_back(i);
		int left = i - k + 1; //判断何时开始更新答案，以及队首元素是否该出队
		if (q.front() < left) { //元素离开窗口
			q.pop_front();
		}
		if (left >= 0) { //窗口元素个数足够时，更新答案
			ans[left] = nums[q.front()];
		}
	}
	return ans;
}
```

[leetcode239](https://leetcode.cn/problems/sliding-window-maximum/ 滑动窗口元素最大值)
[leetcode1438](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/ 绝对值不超过限制的最长连续子数组) 两个队列分别维护最大值和最小值，窗口右侧不断扩大，若最大减最小大于绝对值，窗口左侧缩小，再判断是否出队


