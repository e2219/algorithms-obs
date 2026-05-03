
## 最短路径问题：Dijkstra算法

```
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 100005;

// 邻接表：g[u] 存所有从 u 出发的边
vector<Edge> g[N];

// dist[i]：起点到 i 的当前最短距离
int dist[N];

// vis[i]：是否已经“确定最短路”（是否出队确定过）
bool vis[N];

/*
 * Dijkstra 主函数
 * start：起点
 * n：节点总数
 */
void dijkstra(int start, int n) {

    // 1. 初始化距离数组
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;   // 一开始认为所有点都不可达（无穷大）
        vis[i] = false;  // 所有点都未被确定最短路
    }

    // 2. 起点到自己距离为 0
    dist[start] = 0;

    /*
     * 优先队列（小根堆）
     * 存 (当前距离, 节点编号)
     * 每次取“距离最小的点”
     */
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // 3. 把起点放入队列
    pq.push({0, start});

    // 4. 主循环：只要还有候选点就继续
    while (!pq.empty()) {

        // 4.1 取出当前“距离最小”的点
        auto [d, u] = pq.top();
        pq.pop();

        /*
         * 4.2 如果这个点已经被“确定过最短路”，直接跳过
         * （因为可能有重复入队的旧状态）
         */
        if (vis[u]) continue;

        // 4.3 标记：u 的最短路径已经最终确定
        vis[u] = true;

        /*
         * 5. 用 u 去“松弛”所有邻居 v
         * 即尝试用 u 作为中转点更新 v 的最短距离
         */
        for (auto e : g[u]) {

            int v = e.to;   // 邻居节点
            int w = e.w;    // u -> v 的边权

            /*
             * 5.1 松弛操作（核心）
             *
             * 如果：
             * 起点 → u → v 比当前 dist[v] 更短
             * 就更新 dist[v]
             */
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                /*
                 * 5.2 更新后，把新状态加入队列
                 * （注意：旧的更差状态不会删除，靠 vis[] 忽略）
                 */
                pq.push({dist[v], v});
            }
        }
    }
}
```