#include <bits/stdc++.h>
using namespace std;

// Функция для вычисления наибольшего общего делителя (НОД)
// через алгоритм Евклида
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для вычисления наименьшего общего кратного (НОК)
// НОК(a, b) = a * b / НОД(a, b)
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;  // Сначала делим, потом умножаем, чтобы избежать переполнения
}

int main() {
    int n;
    cin >> n;
    
    long long result = 1;
    
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        result = lcm(result, t);  // Последовательно вычисляем НОК всех чисел
    }
    
    cout << result << endl;
    
    return 0;
}
