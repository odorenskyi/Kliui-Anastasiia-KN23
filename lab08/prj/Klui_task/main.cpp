#include "ModulesKlui.h"
#include <iostream>

void print_nmae() {
    // Виведення імені розробника
    std::cout << "Developed: Klui Anastasia©" << std::endl;
}

void print_result(char a, char b) {
    bool result = (a + 7 == b);
    if (result) {
        // Якщо результат істинна
        std::cout << "Результат: true" << std::endl;
    } else {
        // В іншому випадку
        std::cout << "Результат: false" << std::endl;
    }
}

void print_numbers(double x, double y, double z){
    // Виведення чисел у шістнадцятковій та десятковій системах числення
    std::cout << "x у шістнадцятковій системі числення: " << std::hex << x << std::endl;
    std::cout << "x в десятковій системі числення: " << x << std::endl;

    std::cout << "y у шістнадцятковій системі числення: " << std::hex << y << std::endl;
    std::cout << "y в десятковій системі числення: " << y << std::endl;
    
    std::cout << "z у шістнадцятковій системі числення: " << std::hex << z << std::endl;
    std::cout << "z в десятковій системі числення: " << z << std::endl;
    
    // Виведення результату обчислення s_calculation
    std::cout << "S = " << s_calculation(x, y, z) << std::endl;
}

int main() {
    double x, y, z;
    char a, b;
    
    // Введення значеннь x, y, z, a та b
    std::cout << "Enter x: ";
    std::cin >> x;
    
    std::cout << "Enter y: ";
    std::cin >> y;
    
    std::cout << "Enter z: ";
    std::cin >> z;
    
    std::cout << "Enter a: ";
    std::cin >> a;
    
    std::cout << "Enter b: ";
    std::cin >> b;
    
    print_nmae();
    print_result(a, b);
    print_numbers(x, y, z);
    
    return 0;
}
