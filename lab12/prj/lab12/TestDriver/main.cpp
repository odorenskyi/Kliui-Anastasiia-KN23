#include <iostream>
#include "ClassLab12_Klui.hpp"

int main(){
    ClassLab12_Klui *object = new ClassLab12_Klui();
    
    float radius;
    std::cout << "What is the radius? ";
    std::cin >> radius;
    object->setRadius(radius);
    
    float height;
    std::cout << "What is the height? ";
    std::cin >> height;
    object->setHeight(height);
    
    std::cout <<"volume: " << object->calculateVolume() << " , area: "
    << object->calculateArea() << " " << "\n";
}
