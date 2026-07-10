#include <iostream>
#include <vector>
#include <algorithm> // для std::reverse

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Создаем массив и считываем элементы
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Обрабатываем запросы
    while (true) {
        int l, r;
        cin >> l >> r;
        
        // Проверка на конец ввода
        if (l == 0 && r == 0) {
            break;
        }
        
        // В задаче индексация с 1, а в C++ с 0
        // Поэтому вычитаем 1 из l
        l--;  // переводим в 0-индексацию
        r--;  // переводим в 0-индексацию
        
        // Разворачиваем подмассив с l по r (включительно)
        // reverse принимает итераторы [first, last)
        reverse(arr.begin() + l, arr.begin() + r + 1);
    }
    
    // Выводим результат
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " "; // пробел между элементами
    }
    cout << endl;
    
    return 0;
}
