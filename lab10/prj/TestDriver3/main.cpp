#include <iostream>
#include <fstream>
#include "ModulesKlui.h"

using namespace std;

int main() {
    size_t b;
    double x, y, z;
    
    cout << "enter x: ";
    cin >> x;
    
    cout << "enter y: ";
    cin >> y;
    
    cout << "enter z: ";
    cin >> z;

    cout << "enter b: ";
    cin >> b;
    
    ofstream output_file("output.txt", ios_base::app);
    if (output_file.is_open()){
        output_file << s_calculation(x, y, z) << endl
            << bitset<sizeof(b)>(b);
        output_file.close();
    }
    
    return 0;
}
