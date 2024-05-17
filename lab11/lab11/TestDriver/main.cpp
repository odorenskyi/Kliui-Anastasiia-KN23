#include <iostream>
#include <ctime>
#include <fstream>
//#include <conio.h>

#include "struct_type_project_1.h"
#include "ModulesHrebeniuk.h"
#include "ModulesHoncharenko.h"
#include "ModulesKlui.h"

#define REGISTER_NAME "register_database"

using namespace std;

void displayMenu() {
    system("cls");
    cout << " ======================= Реєстр МВС України ========================= " << endl;
    cout << "| 1. Додати автомобіль у реєстр                                      |" << endl;
    cout << "| 2. Пошук автомобіля за номером                                     |" << endl;
    cout << "| 3. Видалення автомобіля з реєстру за номерним знаком               |" << endl;
    cout << "| 4. Вивести усі дані з реєстру                                      |" << endl;
    cout << "| 5. Вийти з програми                                                |" << endl;
    cout << " ==================================================================== " << endl;
    cout << "Виберіть опцію: ";
}


void exitApp(List *list) {
    delete list->head;
    delete list->tail;
    delete list;

    exit(0);
}

int main()
{
//    system("chcp 1251 & cls");

    List *list = loadRegisterData("register_database");
    if (list == nullptr) {
        list = new List;
        list->head = nullptr;
        list->tail = nullptr;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice) {
            case 1: {
                addCarInRegister(list);
                saveRegisterData(list, REGISTER_NAME);
                break;
            }
            case 2: {
                string searchLicensePlate;
                cout << "Введіть номер авто для пошуку: ";
                cin >> searchLicensePlate;

                if (searchLicensePlate.empty() || searchLicensePlate.size() > 10) {
                    cout << "Помилка: номерний знак не може бути порожнім та його максимальна довжина повинна бути не більше 10 символів!" << endl;
                    break;
                }

                searchCarInRegister(list, searchLicensePlate);
                break;
            }
            case 3: {
                string removeLicensePlate;
                cout << "Введіть номер авто для видалення: ";
                cin >> removeLicensePlate;

                if (removeLicensePlate.empty() || removeLicensePlate.size() > 10) {
                    cout << "Помилка: номерний знак не може бути порожнім та його максимальна довжина повинна бути не більше 10 символів!" << endl;
                    break;
                }

                removeCarFromRegister(list, removeLicensePlate);
                saveRegisterData(list, REGISTER_NAME);
                break;
            }
            case 4: {
                outputRegisterData(list);
                break;
            }
            case 5: {
                cout << "До побачення!" << endl;
                exitApp(list);
                break;
            }
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }

        cout << "Продовжити роботу застосунку? (y/n): ";
        choice = cin.get();
    } while (choice == 'Y' || choice == 'y');

    exitApp(list);

    return 0;
}
