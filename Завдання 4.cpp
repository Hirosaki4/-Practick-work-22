#include <iostream>
#include <limits>
#include<Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);  

 int numStudents;
    cout << "Введіть кількість учнів у класі: ";
    cin >> numStudents;

    // Динамічно виділяємо пам'ять для зберігання балів учнів
    int* scores = new int[numStudents];
    int maxScore = numeric_limits<int>::min(); // Початкове значення для пошуку максимуму
    int minScore = numeric_limits<int>::max(); // Початкове значення для пошуку мінімуму

    // Заповнюємо масив балами та шукаємо максимальний і мінімальний бали
    for (int i = 0; i < numStudents; i++) {
        cout << "Введіть бали учня " << i + 1 << ": ";
        cin >> scores[i];
        
        // Оновлюємо максимальний і мінімальний бали, якщо поточний більший або менший
        if (scores[i] > maxScore) maxScore = scores[i];
        if (scores[i] < minScore) minScore = scores[i];
    }

    // Виводимо максимальний і мінімальний бали
    cout << "Максимальний бал: " << maxScore << endl;
    cout << "Мінімальний бал: " << minScore << endl;

    // Звільняємо пам'ять, виділену для масиву
    delete[] scores;
    return 0;
}
