#include <iostream>
#include<Windows.h>
using namespace std;

int main() {
      SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numRooms;
    cout << "Введіть кількість кімнат у готелі: ";
    cin >> numRooms;

    // Динамічно створюємо масив вказівників для зберігання бронювань кожної кімнати
    int** booking = new int*[numRooms];
    int maxBookedDays = 0; // Максимальна кількість заброньованих днів
    int maxRoom = -1;      // Номер кімнати з найбільшою кількістю бронювань

    for (int i = 0; i < numRooms; i++) {
        int days;
        cout << "Введіть кількість днів для кімнати " << i + 1 << ": ";
        cin >> days;

        // Динамічно виділяємо масив для днів бронювання в кожній кімнаті
        booking[i] = new int[days];
        int bookedDays = 0; // Лічильник заброньованих днів для поточної кімнати

        for (int j = 0; j < days; j++) {
            cout << "Введіть статус для дня " << j + 1 << " (1 - заброньовано, 0 - вільно): ";
            cin >> booking[i][j];
            
            // Підрахунок заброньованих днів
            if (booking[i][j] == 1) bookedDays++;
        }

        // Виводимо кількість заброньованих та вільних днів для поточної кімнати
        cout << "Кімната " << i + 1 << " - Заброньовані дні: " << bookedDays
             << ", Вільні дні: " << days - bookedDays << endl;

        // Оновлюємо кімнату з найбільшою кількістю заброньованих днів
        if (bookedDays > maxBookedDays) {
            maxBookedDays = bookedDays;
            maxRoom = i + 1;
        }

        // Звільняємо пам'ять, виділену для масиву днів поточної кімнати
        delete[] booking[i];
    }

    // Виводимо номер кімнати з найбільшою кількістю заброньованих днів
    cout << "Кімната з найбільшою кількістю заброньованих днів: " << maxRoom << endl;

    // Звільняємо пам'ять, виділену для масиву вказівників
    delete[] booking;

    return 0;
}
