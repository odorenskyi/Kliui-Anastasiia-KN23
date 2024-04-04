#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

int main(){
    ofstream output_file("output.txt", ios_base::app); // Створення об'єкту для запису у файл "output.txt"
    if (output_file.is_open()){ // Перевірка, чи вдалося відкрити файл для запису
        auto now = chrono::system_clock::now(); // Отримання поточного часу
        time_t time_stamp = chrono::system_clock::to_time_t(now); // Перетворення часу у формат time_t
        output_file << ctime(&time_stamp); // Запис часу у файл у форматі читабельної дати та часу
        output_file.close(); // Закриття файлу
    }
    return 0;
}
