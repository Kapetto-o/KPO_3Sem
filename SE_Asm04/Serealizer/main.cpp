#include "Serealizer.h"
#include<Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    int integer;

    cout << "¬ведите текст (до 127 символов): ";
    getline(cin, text);
    if (text.size() > 127) {
        cerr << "ќшибка: текст слишком длинный.\n";
        return 1;
    }

    cout << "¬ведите целое число: ";
    cin >> integer;

    Serializer serializer(text, integer);
    serializer.SerializeData();

    return 0;
}