>递归之父，回溯之骨

关于递归：“**不要一开始就陷入细节**”
整体出发，不要想子问题的过程，而要想怎么拆分成子问题，想想子问题的结果

树结构：
```
 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
```

![[c2055d82a8b231a394fd3efd8f54dd7a.jpg]]
```
//前序遍历：对于每个节点，记录自身，然后访问左子树，最后访问右子树
void preorder(ListNode* root, vector<int>& res) {
	if (root == nullptr) return;
	res.push_back(root->val);
	preorder(root->left, res); 
	preorder(root->right, res);
}

//中序遍历：对于每个节点，访问左子树->回来记录自身->访问右子树
void inorder(ListNode* root, vector<int>& res) {
	if (root == nullptr) return;
	preorder(root->left, res);
	res.push_back(root->val);
	preorder(root->right, res);
}

//后序遍历：对于每个节点，访问左子树->回来->访问右子树->回来->记录自身
void postorder(ListNode* root, vector<int>& res) {
	if (root == nullptr) return;
	postorder(root->left, res);
	postorder(root->right, res);
	res.push_back(root);
}
//注意函数体一定是按引用传递，否则每次调用都只会修改外层
```

ChatGPTの终极总结：

- 前序：**见面就处理（先自己）**
- 中序：**夹在中间处理（左 → 自己 → 右）**
- 后序：**最后才处理（先孩子 → 再自己）**

递归 lambda 语法
```
[&](...) {...}
[捕获列表](参数列表) -> 返回类型 {函数体};
参数列表：(this auto&& dfs, ...) 显示调用自己
	auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) -> void {
		......
	};
```

**dfs的递归调用不会变，关键是内部的逻辑，何时更新，何时返回**
[leetcode623](https://leetcode.cn/problems/add-one-row-to-tree/ 在二叉树中加入一行)建议也看下官解

递是前序，类似前序遍历的处理逻辑，从根节点开始，处理当前节点，往下递
归是后序，类似后序遍历的处理逻辑，先往下递，从叶节点开始处理，往上归

例如，获取二叉树的最大深度：
```
//递:
int maxDepth(TreeNode* root) {
	int ans = 0;
	auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) -> void{
		if (node == nullptr) return;
		depth++;
		ans = max(ans, depth);
		dfs(node->left, depth);
		dfs(node->right, depth);
	}
	dfs(root, 0);
	return ans;
}

//归:
int maxDepth(TreeNode* root) {
	if (root == nullptr) return 0;
	int left_h = maxDepth(root->left);
	int right_h = maxDepth(root->right);
	return max(left_h, right_h) + 1;
}
```

## 二叉树剪枝

给你一棵以 `root` 为根的二叉树和一个整数 `target` ，请你删除所有值为 `target` 的 **叶子节点** 。

注意，一旦删除值为 `target` 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 `target` ，那么这个节点也应该被删除。



```
TreeNode* removeLeafNodes(TreeNode* root, int target) {
	if (!root) return nullptr;
	root->left = removeLeafNodes(root->left, target);
	root->right = removeLeafNodes(root->right, target);
	if (!root->left && !root->right && root->val == target) {
		return nullptr;
	}
	return root;
}
```

## 回溯

摘自某扣友
```
什么时候用参数递归，什么时候用回溯递归？一句话总结：当你用不可变对象（string, int, bool）的时候用参数，当你想用可变对象（list, set）/ 对空间复杂度要求高 的时候用回溯。

1. 因为string不可变，所以你可以大胆把它当递归参数，每一次发生新的dfs调用，string_path都被重新复制出一个新的，所以层层递归不会相互影响，你可以得到答案。---Note：这也是为什么参数型递归的空间复杂度高于回溯型递归，因为在不断复制string_path。
    
2. 但是，如果你用list当递归参数，由于list可变，你在不同层的调用dfs修改的是同一个公共list_path，会把list弄乱。  
    解决方式是用回溯+pop：  
    2.1 假设你站在节点A，已知A有2个子节点：B和C。  
    2.2 你想先探索B，于是你进入新dfs调用看到了B，所以现在的path就是AB【对应代码是`path.append(str(node.val))` 】；  
    2.3 接着，你继续往深处走，尝试处理AB的下一层或者下下层【对应代码就是if else block】：
    

```python
if node.left is None and node.right is None:  # 叶子节点
  ans.append("->".join(path))
else:
  dfs(node.left)
  dfs(node.right)

2.4 当你用上述`if else`把B的子树全部处理完之后，你会想要退回到A的状态（因为退回到A，才能看C）。也就是，你需要先pop B，让list_path恢复到【状态A】，对应代码是`path.pop()`。
```

>用其他方式存储当前状态，省去复制参数的过程

代码实现：
```
vector<string> binaryTreePaths(TreeNode* root){
	vector<string> ans;
	vector<string> path;
	auto dfs = [&](this auto&& dfs, TreeNode* node) -> void{
		if (node == nullptr) return;
		path.push_back(to_string(node->val));
		if (!node->left && !node->right) {
			string joined_path;
			for (int i = 0; i < path.size; i++) {
				if (i > 0) {
					joined_path += "->";
				}
				joined_path += path[i];
			}
			ans.push_back(joined_path);
		}
		else {
			dfs(node->left);
			dfs(node->right);
		}
		path.pop_back(); //回溯最近状态
	};
	dfs(root);
	return ans;
}
```

## 构造二叉树

给两个数组，是二叉树前序遍历和中序遍历的结果，还原出原二叉树
![[Pasted image 20260501220817.png|697]]
```
unordered_map<int, int> index;//中序遍历的值->索引对应

TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
	if (preRight > preLeft) return nullptr;
	int pre_root = preLeft;
	int pIndex = index[inorder[pre_root]]; //中序遍历根节点索引
	TreeNode* root = new TreeNode(preorder[pre_root]);//根节点的值是前序遍历第一个节点
	int size_left_subtree = pIndex - inLeft; //左子树长度
	root->left = myBuildTree(preorder, inorder, preLeft + 1, preLeft + size_left_subtree, inLeft, pIndex - 1);
	root->right = myBuildTree(preorder, inorder, preLeft + size_left_subtree + 1, preRight, pIndex + 1, inRight);
	return root;
}
```

## 增删节点

[leetcode701](https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/ 插入节点) 不论节点值为多少，都存在一种不改变原树结构的方法
[leetcode450](https://leetcode.cn/problems/delete-node-in-a-bst/description/) 分类讨论，递归：删除某节点，若非叶节点，则要移动其他节点。可先删除要移动的节点，再替换当前节点（类似链表的删除节点的一种方法）


## 二叉树BFS

用堆来维护当前层的所有节点
```
//层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
	if (root == nullptr) return {};
	
	vector<vector<int>> ans;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		vector<int> vals;
		for (int n = q.size(); n--;) {
			auto node = q.front();
			q.pop();
			vals.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
	ans.push_back(move(vals));
	}

	return ans;
}
```

