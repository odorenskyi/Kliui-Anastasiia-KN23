#include <iostream>
#include "ClassLab12_Klui.hpp"

int main(){
    ClassLab12_Klui *classLab12_Klui = new ClassLab12_Klui();
    
    float radius;
    std::cout << "What is the radius? ";
    std::cin >> radius;
    classLab12_Klui->setRadius(radius);
    
    float height;
    std::cout << "What is the height? ";
    std::cin >> height;
    classLab12_Klui->setHeight(height);
    
    std::cout <<"volume: " << classLab12_Klui->calculateVolume() << " , area: "
    << classLab12_Klui->calculateArea() << " " << "\n";
}
