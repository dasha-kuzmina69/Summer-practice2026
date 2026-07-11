#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, s;
    cin >> n >> m >> s;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    // dist[i] - кратчайшее расстояние от s до i
    // Используем long long, т.к. расстояния могут быть большими
    const long long INF = 4e18;
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;
    
    // Основная часть алгоритма Форда-Беллмана
    // Релаксируем все рёбра n-1 раз
    for (int i = 0; i < n - 1; i++) {
        bool any = false;
        for (const auto& e : edges) {
            // Если из u уже есть путь, пытаемся улучшить путь до v
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                any = true;
            }
        }
        // Если на итерации не было изменений, можно закончить раньше
        if (!any) break;
    }
    
    // Проверка на отрицательные циклы, достижимые из стартовой вершины
    // Запускаем ещё одну релаксацию всех рёбер
    vector<int> neg_cycle(n + 1, 0); // 1 - вершина достижима из отрицательного цикла
    queue<int> q;
    
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            // Если расстояние можно улучшить после n-1 итераций,
            // значит e.v лежит на отрицательном цикле или достижима из него
            if (!neg_cycle[e.v]) {
                neg_cycle[e.v] = 1;
                q.push(e.v);
            }
        }
    }
    
    // BFS для распространения пометок о достижимости из отрицательного цикла
    vector<vector<int>> graph(n + 1);
    for (const auto& e : edges) {
        graph[e.u].push_back(e.v);
    }
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : graph[v]) {
            if (!neg_cycle[to]) {
                neg_cycle[to] = 1;
                q.push(to);
            }
        }
    }
    
    // Проверяем, есть ли отрицательный цикл на пути к какой-либо вершине
    for (int i = 1; i <= n; i++) {
        if (neg_cycle[i]) {
            cout << "Negative cycle\n";
            return 0;
        }
    }
    
    // Вывод результатов
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "inf";
        } else {
            cout << dist[i];
        }
        if (i != n) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
