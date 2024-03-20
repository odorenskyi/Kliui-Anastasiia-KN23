#include <math.h>
#include "ModulesKlui.h"
#include <iostream>
#ifdef __APPLE__
#   include <AppKit/AppKit.h>
#endif

double s_calculation (double x, double y, double z) {
    return fabs (pow (y*z, fabs (x)) - y/ M_PI - sqrt(x)) ;
}


// Ввести сумму покупки в гривнях
int read_data (){
    int x;
    std::cout << "Введіть суму покупки в гривнях: ";
    std::cin >> x;
    return x;
}

// Вивести результат
void output_result (int x, double y){
    std::cout << "Кількість нарахованих бонусів - " <<
    x << ", за покупку та сума до сплати з врахуванням знижки у гривнях - " << y << std::endl;
}

// Вираховування кількості бонусів
int number_bonus (int x){
    int bonus = 0;
    if (x >= 100 && x < 200){
        bonus = 1;
    } else if (x >= 200 && x < 500){
        bonus = 5;
    } else if (x >= 500 && x < 1000){
        bonus = 10;
    } else if (x >= 1000 && x < 2500){
        bonus = 50;
    } else if (x >= 2500 && x < 5000){
        bonus = 150;
    } else if (x >= 5000){
        bonus = 300;
    }
    return bonus;
}

// Конвертування бонусів в знижку
double discount_bonuses (int bonus){
    return bonus * 0.25;
}



// Функція конвертування t градусів з Фіренгейта у Цельсія
double degree_conversion(double f) {
    return (5.0 / 9.0) * (f - 32.0);
}

double degree_fahrenheit (){
    double f;
    std::cout << "Введіть кількість градусів Фіренгейта: ";
    std:: cin >> f;
    return f;
}

void degrees_celsius (double f){
    std::cout << "Градуси у шкалі цельсія: " << f << std::endl;
}


// Функція підрахунку кількості бінарних 0 або 1 у числі N
unsigned short calculate_number(unsigned short n){
    auto counter = 0;
    bool k = (n & 0b10000) == 0b10000;
    for(auto i = 0; i < 16 ; i++) {
      if ((n & 1) == 1) {
          counter++;
      }
    n = n >> 1;
    }
    if (k) {
       return counter;
    }
    return 16 - counter;
}

unsigned short natural_number(){
    unsigned short N;
    std::cout << "Введіть число від 0 до 51950: ";
    std:: cin >> N;
    return N;
}

void output_result(unsigned short n) {
    std::cout << "Результат: " << n << std::endl;
}


int last() {
    char choice;

    do {
        std::cout << "Введіть символ j, z, x, c або v, V, A для виходу: ";
        std::cin >> choice;

        // Перевірка введеного символу
        switch (choice) {
            case 'j':
                task_8_1();
                break;
            case 'z':
                task_9_1();
                break;
            case 'x':
                task_9_2();
                break;
            case 'c':
                task_9_3();
                break;
            case 'v':
                // Вихід з програми
                std::cout << "Дякую за використання програми. До побачення!\n";
                exit(0);
            default:
                // Відтворення звукового сигналу про помилку
#ifdef __APPLE__
                NSBeep(); // звуковий сигнал про помилку на macOS
#else
                std::cout << '\a'; // звуковий сигнал про помилку
#endif
                std::cout << "Неправильне введення. Спробуйте ще раз.\n";
        }
    } while (true);

    return 0;
}


void task_9_1() {
    
    int total_sum = read_data();
    int total_bonus = number_bonus(total_sum);
    double total_discount = discount_bonuses(total_bonus);
    output_result(total_bonus, total_sum - total_discount);
}


void task_9_2() {
    double f = degree_fahrenheit();
    double c = degree_conversion(f);
    degrees_celsius(c);
}

void task_9_3() {
    last();
}


void  task_8_1() {
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
}
