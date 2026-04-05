/*差分数组：用于快速修改数组中的元素

  

## 原理 ##
对数组中 \[left, right] 数据进行相同的修改时，可转化为对差分数组 left, right + 1 两个元素的修改

原理解析：假设存在数组 arr = \[3, 5, 8, 8, 10]
对应差分数组 diff = \[3, 2, 3, 0, 2] (即diff\[0] = arr\[0], diff\[i] = arr\[i] - arr\[i - 1])
这表明，差分数组可以轻易的还原为原数组，即 arr\[0] = diff\[0], arr\[i] = diff\[i] + diff\[i - 1] + ...
此时，如果对 arr 的 \[1, 3] 的元素都加 10， 即 arr' = \[3, 15, 18, 18, 10]
对应 diff' = \[3, 12, 3, 0, -8], 也就是对 diff 的 1 元素 +10， 4 元素 -10
这样就实现了对区间内数据的统一更改。

## 适用情景 ##
对区间内数据统一修改，并判断修改时元素是否符合特定条件。例如：被覆盖元素个数，列车上下车， 连续区间合并...

## 二维差分数组 ##
d\[i]\[j] = a\[i]\[j] - a\[i - 1]\[j] - a\[i]\[j - 1] + a\[i]\[j]
a\[i]\[j] = 求和d\[x]\[y](x <= i, y <= j);
d\[i]\[j] 表示 从 (i, j) 这个点开始， 右下方矩形所有元素都有 d\[i]\[j] 的增量
因此，如果对 a\[i1]\[j1] —— a\[i2]\[j2] 的所有元素增加 k , 相当于在 d 上修改：
-> d\[i1]\[j1] += k; d\[i1]\[j2 + 1] -= k; d\[i2 + 1]\[j1] -= k; d\[i2 + 1]\[j2 + 1] += k(多减的部分加回来)
再通过对二维数组的前缀和求和，得到更改后的新矩阵的各个元素。
差分与前缀和， 就像导数与原函数。 导数到原函数需要积分， 差分数组到原数组需要累加求前缀和。

根据差分数组合并区间：
	[leetcode2848](https://leetcode.cn/problems/points-that-intersect-with-cars/description/ 区间覆盖点数目)
区间离散化：
	[leetcode56](https://leetcode.cn/problems/merge-intervals/description/ 合并区间)
不连续区间：
	[leetcode2406](https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/description/ 将区间分为最少组数) 找被最多个区间覆盖的点，就是要分的组数