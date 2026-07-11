#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    // Создаем список смежности для графа
    vector<vector<int>> g(n + 1);
    
    // Читаем ребра
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Граф неориентированный
    }
    
    // Вектор расстояний, изначально все -1 (недостижимы)
    vector<int> dist(n + 1, -1);
    
    // Очередь для BFS
    queue<int> q;
    
    // Начинаем с вершины k
    dist[k] = 0;
    q.push(k);
    
    // BFS
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        // Перебираем всех соседей
        for (int to : g[v]) {
            if (dist[to] == -1) { // Если еще не посещали
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    
    // Выводим расстояния от 1 до n
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
