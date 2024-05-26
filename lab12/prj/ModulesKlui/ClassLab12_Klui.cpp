#include "ClassLab12_Klui.hpp"
#include <cmath>

ClassLab12_Klui::ClassLab12_Klui(): radius(0.0f), height(0.0f)
{
}

float ClassLab12_Klui:: getRadius(){
    return radius;
}

void ClassLab12_Klui:: setRadius(float value){
    radius = value;
}

float ClassLab12_Klui:: getHeight(){
    return height;
}

void ClassLab12_Klui:: setHeight(float value){
    height = value;
}

float ClassLab12_Klui::calculateVolume(){
    return M_PI * radius * radius * height;
}

float ClassLab12_Klui::calculateArea(){
    return calculateVolume() / height;
}
