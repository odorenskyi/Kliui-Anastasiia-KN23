#ifndef ClassLab12_Klui_hpp
#define ClassLab12_Klui_hpp

class ClassLab12_Klui{
private:
    float radius;
    float height;
public:
    ClassLab12_Klui();
    
    float getRadius();
    void setRadius(float value);
    
    float getHeight();
    void setHeight(float value);
    
    float calculateVolume();
    
    float calculateArea();
};

#endif /* ClassLab12_Klui_hpp */
