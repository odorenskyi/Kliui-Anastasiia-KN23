#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

int main(){
    ofstream output_file("output.txt", ios_base::app);
    if (output_file.is_open()){
        auto now = chrono::system_clock::now();
        time_t time_stamp = chrono::system_clock::to_time_t(now);
        output_file << ctime(&time_stamp);
        output_file.close();
    }
    return 0;
}
