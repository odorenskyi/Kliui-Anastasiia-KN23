// modules_honcharenko.cpp
#include <iostream>
#include <fstream>

#include "ModulesHoncharenko.h"

using namespace std;

void saveRegisterData(List *list, string registerFileName) {
    ofstream registerFile(registerFileName, ios::binary | ios::out);

    if (!registerFile) {
        cerr << "Не вдалось відкрити " << registerFileName << " для того, щоб зберегти реєстр!" << endl;
        return;
    }

    Node *current = list->head;
    size_t stringSize;
    while (current != nullptr) {
        stringSize = current->data.lastName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.lastName[0], stringSize);

        stringSize = current->data.firstName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.firstName[0], stringSize);

        stringSize = current->data.middleName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.middleName[0], stringSize);

        stringSize = current->data.carBrand.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.carBrand[0], stringSize);

        registerFile.write((char*) &current->data.year, sizeof(int));

        stringSize = current->data.registrationDate.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.registrationDate[0], stringSize);

        stringSize = current->data.licensePlate.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.licensePlate[0], stringSize);

        stringSize = current->data.lastName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.lastName[0], stringSize);

        current = current->next;
    }

    registerFile.close();
}


void searchCarInRegister(List* list, string stateLicensePlate) {
    Node* current = list->head;
    while (current != nullptr) {
        if (current->data.licensePlate == stateLicensePlate) {
            cout << "Прізвище: " << current->data.lastName << endl;
            cout << "Ім'я: " << current->data.firstName << endl;
            cout << "По-батькові: " << current->data.middleName << endl;
            cout << "Модель авто: " << current->data.carBrand << endl;
            cout << "Рік: " << current->data.year << endl;
            cout << "Дата регестрації: " << current->data.registrationDate << endl;
            cout << "Номер авто: " << current->data.licensePlate << endl;
            cout << "Нотатки: " << current->data.notes << endl;
            return;
        }
        current = current->next;
    }

    cerr << "Автомобіль з державним номером " << stateLicensePlate << " не знайдено в реєстрі." << endl;
}
