#include <iostream>
#include<Windows.h>
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);  

 int numProducts;
    cout << "Введіть кількість товарів: ";
    cin >> numProducts;

    // Динамічно виділяємо пам'ять для зберігання вартості товарів
    double* prices = new double[numProducts];
    double totalCost = 0;

    // Заповнюємо масив цінами товарів
    for (int i = 0; i < numProducts; i++) {
        cout << "Введіть вартість товару " << i + 1 << ": ";
        cin >> prices[i];
        totalCost += prices[i]; // Додаємо вартість товару до загальної суми
    }

    // Виводимо загальну вартість усіх товарів
    cout << "Загальна вартість усіх товарів: " << totalCost << endl;

    // Звільняємо пам'ять, виділену для масиву
    delete[] prices;
    return 0;
}
