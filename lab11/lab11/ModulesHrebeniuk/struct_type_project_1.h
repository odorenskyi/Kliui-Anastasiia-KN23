#ifndef STRUCT_TYPE_PROJECT_1_H_INCLUDED
#define STRUCT_TYPE_PROJECT_1_H_INCLUDED

#include <string>

struct CarRecord {
  std::string lastName;
  std::string firstName;
  std::string middleName;
  std::string carBrand;
  int year;
  std::string registrationDate;
  std::string licensePlate;
  std::string notes;
};

struct Node {
  CarRecord data;
  Node *previous;
  Node *next;
};

struct List {
  Node *head;
  Node *tail;
};

#endif // STRUCT_TYPE_PROJECT_1_H_INCLUDED
