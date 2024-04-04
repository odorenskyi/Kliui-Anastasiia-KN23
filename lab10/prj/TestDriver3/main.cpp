#include <iostream>
#include <fstream>
#include "ModulesKlui.h"

using namespace std;

int main() {
    size_t b; // Оголошуємо змінну b
    double x, y, z; // Оголошуємо змінні x, y, z
    
    // Просимо користувача ввести значення x
    cout << "enter x: ";
    cin >> x;
    
    // Просимо користувача ввести значення y
    cout << "enter y: ";
    cin >> y;
    
    // Просимо користувача ввести значення z
    cout << "enter z: ";
    cin >> z;

    // Просимо користувача ввести значення b
    cout << "enter b: ";
    cin >> b;
    
    // Відкриваємо файл для запису результатів
    ofstream output_file("output.txt", ios_base::app);
    if (output_file.is_open()){ // Перевіряємо, чи вдалося відкрити файл
        // Записуємо результат обчислення s_calculation(x, y, z) у файл, а також значення b
        output_file << s_calculation(x, y, z) << endl
            << bitset<sizeof(b)>(b);
        output_file.close(); // Закриваємо файл
    }
    
    return 0;
}
