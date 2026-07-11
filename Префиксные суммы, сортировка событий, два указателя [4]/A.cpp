#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    // Разностный массив размера N+2 (для удобства с r+1)
    vector<long long> diff(N + 2, 0);
    
    // Обработка запросов
    for (int i = 0; i < Q; i++) {
        int l, r;
        long long v;
        cin >> l >> r >> v;
        
        // Добавляем v начиная с позиции l
        diff[l] += v;
        // Убираем v после позиции r
        diff[r + 1] -= v;
    }
    
    // Получение итогового массива через префиксные суммы
    vector<long long> result(N + 1, 0);
    long long current = 0;
    for (int i = 1; i <= N; i++) {
        current += diff[i];
        result[i] = current;
    }
    
    // Вывод результата
    for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
