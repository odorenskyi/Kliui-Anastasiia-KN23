#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


// Функція для заміни підрядка у рядку
string replace_substr(const string& str, const string& old_value, const string& new_value) {
    string result = str;
    auto pos = result.find(old_value);
    while(pos != string::npos) {
        result.erase(pos, old_value.length());
        result.insert(pos, new_value);
        pos = result.find(old_value);
    }
    return result;
}

// Функція для модифікації речення з підрахунком кількості літер
string modify_sentence(const string& sentence) {
    auto result = replace_substr(sentence, "к", "?");
    result = replace_substr(result, "т", "?");
    result = replace_substr(result, "У", "?");
    result = replace_substr(result, "л", "?");
    result = replace_substr(result, "Й", "?");
    
    return result;
}

// Функція для підрахунку кількості символів у рядку з урахуванням UTF-8
size_t utf8_strlen(const string& str)
{
    size_t c,i,ix,q;
    for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
    {
        c = (unsigned char) str[i];
        if      (c>=0   && c<=127) i+=0;
        else if ((c & 0xE0) == 0xC0) i+=1;
        else if ((c & 0xF0) == 0xE0) i+=2;
        else if ((c & 0xF8) == 0xF0) i+=3;
        else return 0;
    }
    return q;
}

// Функція для підрахунку кількості пунктуаційних знаків у рядку
size_t count_punctuations(const string& str) {
    return std::ranges::count(str, '.')
    + std::ranges::count(str, ',')
    + std::ranges::count(str, '?')
    + std::ranges::count(str, '!')
    + std::ranges::count(str, ';');
}


int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Додавання авторської інформації
    outputFile << "Ім'я Прізвище, Установа/Організація, Місто, Країна, 2024 рік" << endl;

    if (inputFile.is_open() && outputFile.is_open()) {
        string sentence;
        getline(inputFile, sentence);
        auto modified = modify_sentence(sentence);

        outputFile << modified << endl;

        string poem1 =
            "В хаті сонячній промінь косо\n"
            "На долівку ляга з вікна...\n"
            "Твої чорні шовкові коси\n"
            "Припорошила вже сивина.\n";
        string poem2 =
            "Коли малим ти вперше став на ноги -\n"
            "Яка ж то радість матері була!\n"
            "Від тихої колиски до порога\n"
            "Вона тебе за руку провела.\n";

        // Вибір вірша залежно від кількості літер і додавання його до файлу
        auto count = utf8_strlen(sentence) - count_punctuations(sentence);
        if (count % 2 == 0) {
            outputFile << poem1;
        } else {
            outputFile << poem2;
        }

        inputFile.close();
        outputFile.close();
    } else {
        cout << "Не вдалося відкрити файл." << endl;
    }

    return 0;
}
