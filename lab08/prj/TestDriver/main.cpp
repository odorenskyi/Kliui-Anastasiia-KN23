#include "ModulesKlui.h"
#include <iostream>

int main() {
    // Оголошення змінних
    double x, y, z;
    
    // Введення та зчитування значень x, y, z
    std::cout << "Enter x: ";
    std::cin >> x;
    
    std::cout << "Enter y: ";
    std::cin >> y;
    
    std::cout << "Enter z: ";
    std::cin >> z;
    
    // Виведення результату обчислення s_calculation()
    std::cout << "S = " << s_calculation(x, y, z) << std::endl;
    return 0;
}
