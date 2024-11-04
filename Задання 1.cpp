#include <iostream>
#include<Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  
    int numEmployees;
    cout << "Введіть кількість працівників: ";
    cin >> numEmployees;

    // Динамічно виділяємо пам'ять для зберігання зарплат
    double* salaries = new double[numEmployees];
    double sum = 0;

    // Заповнюємо масив зарплатами, введеними користувачем
    for (int i = 0; i < numEmployees; i++) {
        cout << "Введіть зарплату працівника " << i + 1 << ": ";
        cin >> salaries[i];
        sum += salaries[i]; // Додаємо зарплату до загальної суми
    }

    // Виводимо середню зарплату
    cout << "Середня заробітна плата: " << sum / numEmployees << endl;

    // Звільняємо пам'ять, виділену для масиву
    delete[] salaries;
    return 0;
}
