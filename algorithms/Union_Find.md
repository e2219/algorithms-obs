>寻根溯源，我们是不是同一祖先？

**并查集**常用于解决图论的连通性问题（比如一系列节点两两连接后是否成环，无向图连通分量（连通块数量问题），判断两点是否连通）

基本思路是：初始化每个元素为独立集合；遍历所有“关系”，根据关系合并集合或判断是否冲突
- 若属于不同的集合，说明在遍历到该关系之前，两元素并不连通。这时用`Union`合并集合。
- 若属于相同的集合，说明之前两元素已属于同一集合，会出现产生冲突（如出现环结构）。

函数模板：
```
class Union_Find() {
	int cc; //连通集个数
	vector<int> parent;
public:
	Union_Find(int n) {
		cc = n;
		parent.resize(n);
		ranges::iota(parent, 0); //parent{0, 1, 2, ..., n-1}
	}
	int Find(int index) {//通过递归，找到根节点
		if (parent[index] != index) {//不是根节点
			parent[index] = Find(parent, parent[index]);//递归找祖宗，找到后压缩路径
			//把当前节点直接挂到根上
		}
		return parent[index];
	}
	
	void Union(int index1, int index2) {//合并两棵树
		int x = Find(index1), y = Find(index2);
		if (x == y) return; //已经连通，返回;
		parent[x] = y;
		cc -= 1; //每连通两个点，连通块的个数就少1
	}
}
```

***Find 用来查找某个节点所在集合的根节点，Union通过连接根节点把两个集合合并

[leetcode684](https://leetcode.cn/problems/redundant-connection/description/ 冗余连接) 连通成环
[leetcode3493](https://leetcode.cn/problems/properties-graph/description/) 判断两点是否连通

抽象代数 & 图论

**每个元素只被指向一次的情况下，连通集 = 置换的环**

>每次交换一个数到正确的位置，最后一个数自动正确

问题：给定按一定顺序排列的数（1-n乱序），将其按照（1-n升序）的顺序排序，每次交换两个数，最少交换几次？

把每个位置`i`看成一个节点，连一条边:
	原索引 -> 该去的位置

| 图论             | 排列       |
| -------------- | -------- |
| 连通分量           | 环（cycle） |
| 节点             | 位置       |
| 边 i → index[i] | 元素跳转     |
| 一个连通块          | 一个闭环     |

例如 原数组->排列后数组 关于 index 的映射
array: \[2, 3, 4, 1] -> \[1, 2, 3, 4]
index:\[1, 2, 3, 0] (原来索引处的数需要移动到的位置) 这是一个4元素连通集，对应需要交换3次
array: \[2, 1, 4, 3] -> \[1, 2, 3, 4]
index:\[1, 0], \[3, 2] 这是2个2元素连通集，对应需要交换 1 + 1次
规律: k 个节点的连通集-> k - 1次交换
![[4c7756b0d146c81c4e99bd4146f699c5.jpg]]

**排列的最少交换次数 = n - 连通分量数（或 = Σ（每个环大小 - 1））**
