#include <iostream>
#include<Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

 int numHouseholds;
    cout << "Введіть кількість домогосподарств: ";
    cin >> numHouseholds;

    // Динамічно виділяємо пам'ять для зберігання обсягу споживання води
    double* waterConsumption = new double[numHouseholds];
    double total = 0;

    // Заповнюємо масив даними про споживання води
    for (int i = 0; i < numHouseholds; i++) {
        cout << "Введіть споживання води для домогосподарства " << i + 1 << " (л): ";
        cin >> waterConsumption[i];
        total += waterConsumption[i]; // Додаємо споживання до загальної суми
    }

    // Виводимо середнє споживання води
    cout << "Середнє споживання води: " << total / numHouseholds << " л" << endl;

    // Звільняємо пам'ять, виділену для масиву
    delete[] waterConsumption;
    return 0;
}
