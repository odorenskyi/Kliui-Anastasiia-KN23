#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

int main(){
    ofstream output_file("output.txt", ios_base::app);
    if (output_file.is_open()){
        auto now = std::chrono::system_clock::now();
        std::time_t time_stamp = std::chrono::system_clock::to_time_t(now);
        output_file << std::ctime(&time_stamp);
        output_file.close();
    }
    return 0;
}
