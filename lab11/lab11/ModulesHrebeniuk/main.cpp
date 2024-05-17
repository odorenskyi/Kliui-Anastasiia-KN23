#include <iostream>
#include <string>
#include <fstream>

#include "struct_type_project_1.h"

using namespace std;

void removeCarFromRegister(List *list, std::string stateLicensePlate) {
    Node *current = list->head;

    while (current != nullptr) {
        if (current->data.licensePlate != stateLicensePlate) {
            current = current->next;
            continue;
        }

        if (current == list->head) {
            list->head = current->next;
            if (list->head != nullptr) {
                list->head->previous = nullptr;
            }
        } else if (current == list->tail) {
            list->tail = current->previous;
            if (list->tail != nullptr) {
                list->tail->next = nullptr;
            }
        } else {
            current->previous->next = current->next;
            current->next->previous = current->previous;
        }

        Node *nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
        cout << "Автомобіль з державним номером " << stateLicensePlate << " було видалено з реєстру." << endl;
        return;
    }

    cerr << "Автомобіль з державним номером " << stateLicensePlate << " для видалення не знайдено в реєстрі." << endl;
}

List *loadRegisterData(std::string registerFileName) {
    ifstream registerFile(registerFileName, ios::binary | ios::in);
    if (!registerFile) {
        cerr << "Не вдалось відкрити " << registerFileName << " для того, щоб завантажити реєстр!" << endl;
        return nullptr;
    }

    List *list = new List;
    list->head = nullptr;
    list->tail = nullptr;
    Node *current = list->head;

    size_t stringSize;

    registerFile.seekg(0, registerFile.end);
    auto fileLength = registerFile.tellg();
    registerFile.seekg(0, registerFile.beg);
    while (registerFile.tellg() < fileLength) {
        if (current != nullptr) {
            current->next = new Node;
            current->next->previous = current;
            current = current->next;
        } else {
            list->head = new Node;
            list->head->previous = nullptr;
            current = list->head;
        }

        CarRecord data;
        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.lastName.resize(stringSize);
        registerFile.read((char*) &data.lastName[0], stringSize);

        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.firstName.resize(stringSize);
        registerFile.read((char*) &data.firstName[0], stringSize);

        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.middleName.resize(stringSize);
        registerFile.read((char*) &data.middleName[0], stringSize);

        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.carBrand.resize(stringSize);
        registerFile.read((char*) &data.carBrand[0], stringSize);

        registerFile.read((char*) &data.year, sizeof(int));

        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.registrationDate.resize(stringSize);
        registerFile.read((char*) &data.registrationDate[0], stringSize);

        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.licensePlate.resize(stringSize);
        registerFile.read((char*) &data.licensePlate[0], stringSize);

        registerFile.read((char*) &stringSize, sizeof(size_t));
        data.notes.resize(stringSize);
        registerFile.read((char*) &data.notes[0], stringSize);

        current->data = data;
    }
    registerFile.close();

    if (list->head != nullptr) {
        current->next = nullptr;
        list->tail = current;
    }

    return list;
}

