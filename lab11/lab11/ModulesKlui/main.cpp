#include <fstream>
#include <iostream>
#include "ModulesKlui.h"

using namespace std;

void outputRegisterData(List *list){
    if (list->head == nullptr) {
        cout << "Реєстр порожній, додайте перший запис через меню." << endl;
        return;
    }

    outputRegisterData(list->head, cout);
}

void outputRegisterData(List *list, const string &outputFileName){
    ofstream output_file(outputFileName);
    outputRegisterData(list->head, output_file);
    output_file.close();
}

void outputRegisterData(Node *node, basic_ostream<char> &stream) {
    Node *current = node;
    while(current != nullptr) {
        stream << " ==================================================================== " << endl;
        stream << "| Прізвище: " << current->data.lastName << endl;
        stream << "| Ім'я: " << current->data.firstName << endl;
        stream << "| По батькові: " << current->data.middleName << endl;
        stream << "| Марка автомобіля: " << current->data.carBrand << endl;
        stream << "| Рік: " << current->data.year << endl;
        stream << "| Дата Реєстрації: " << current->data.registrationDate << endl;
        stream << "| Номерний знак: " << current->data.licensePlate << endl;
        stream << "| Примітки: " << current->data.notes << endl;
        stream << " ==================================================================== " << endl;

        current = current->next;
    }
}

void addCarInRegister(List *list) {
    CarRecord record;
    bool isValid;

    do {
        cout << "Ім'я: ";
        cin >> record.firstName;
        cin.ignore();

        isValid = !record.firstName.empty() && record.firstName.size() < 50;
        if (!isValid) {
            cout << "Помилка: ім'я не може бути порожнім та його максимальна довжина повинна бути не більше 50 символів!" << endl;
        }
    } while (!isValid);

    do {
        cout << "Ім'я по батькові: ";
        cin >> record.middleName;
        cin.ignore();

        isValid = !record.middleName.empty() && record.middleName.size() < 50;
        if (!isValid) {
            cout << "Помилка: ім'я по батькові не може бути порожнім та його максимальна довжина повинна бути не більше 50 символів!" << endl;
        }
    } while (!isValid);

    do {
        cout << "Прізвище: ";
        cin >> record.lastName;
        cin.ignore();

        isValid = !record.lastName.empty() && record.lastName.size() < 50;
        if (!isValid) {
            cout << "Помилка: прізвище не може бути порожнім та його максимальна довжина повинна бути не більше 50 символів!" << endl;
        }
    } while (!isValid);

    do {
        cout << "Марка автомобіля: ";
        cin >> record.carBrand;
        cin.ignore();

        isValid = !record.carBrand.empty() && record.carBrand.size() < 50;
        if (!isValid) {
            cout << "Помилка: марка автомобіля не може бути порожньою та її максимальна довжина повинна бути не більше 50 символів!" << endl;
        }
    } while (!isValid);

    do {
        cout << "Рік: ";
        cin >> record.year;
        cin.ignore();

        isValid = record.year >= 1885 && record.year <= 2024;
        if (!isValid) {
            cout << "Помилка: рік повинен бути числом від 1885 до 2024!" << endl;
        }
    } while (!isValid);

    do {
        cout << "Дата Реєстрації: ";
        cin >> record.registrationDate;
        cin.ignore();

        isValid = !record.registrationDate.empty();
        if (!isValid) {
            cout << "Помилка: дата реєстрації не може бути порожньою!" << endl;
        }
    } while (!isValid);

    do {
        cout << "Номерний знак: ";
        cin >> record.licensePlate;
        cin.ignore();

        isValid = !record.licensePlate.empty() && record.licensePlate.size() < 10;
        if (!isValid) {
            cout << "Помилка: номерний знак не може бути порожнім та його максимальна довжина повинна бути не більше 10 символів!" << endl;
        }
    } while (!isValid);

    cout << "Примітки: ";
    getline(cin, record.notes);

    addCarInRegister(list, record);
}

void addCarInRegister(List *list, CarRecord record){
    Node *node = new Node;
    node->next = nullptr;
    node->data = record;

    if (list->tail) {
      node->previous = list->tail;
      list->tail->next = node;
      list->tail = node;
    } else if (list->head == nullptr) {
      node->previous = nullptr;
      list->head = node;
      list->tail = node;
    }
}
