#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 105;
int n, m;

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w):u(u),v(v),w(w) {}
};

struct node {
    int d, u;
    node(int d, int u):d(d),u(u) {}
    friend bool operator < (node a, node b) {
        return a.d > b.d;
    }
};

vector<Edge> edges;
vector<int> G[maxn];
int dist[maxn]; // 存放起点到i点的最短距离
int vis[maxn]; // 标记是否访问过
int p[maxn]; // 存放路径

void spfa(int s) {
    queue<node> q;
    for (int i = 0; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    memset(vis, 0, sizeof(vis));
    q.push(node(0, s));
    while (!q.empty()) {
        node now = q.front(); q.pop();
        int u = now.u;
        vis[u] = 0;
        for (int i = 0; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
            if (dist[e.v] > dist[u] + e.w) {
                dist[e.v] = dist[u] + e.w;
                p[e.v] = u;
                if (!vis[e.v]) {
                    vis[e.v] = 1;
                    q.push(node(dist[e.v], e.v));
                }
            }
        }
    }
}

void addedge(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    int sz = edges.size();
    G[u].push_back(sz - 1);
}

void init() {
    for(int i = 0; i <= n; i++) G[i].clear();
    edges.clear();
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n + m == 0) break;
        init();
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        spfa(1);
        printf("%d\n",dist[n]);
    }
    return 0;
}
