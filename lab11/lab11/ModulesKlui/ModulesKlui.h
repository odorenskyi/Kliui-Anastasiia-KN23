#ifndef MODULESKLUI_H_INCLUDED
#define MODULESKLUI_H_INCLUDED

#include "struct_type_project_1.h"

void outputRegisterData(List *list);
void outputRegisterData(List *list, const std::string &outputFileName);
void outputRegisterData(Node *node, std::basic_ostream<char> &stream);

void addCarInRegister(List *list);
void addCarInRegister(List *list, CarRecord record);

#endif // MODULESHREBENIUK_H_INCLUDED
