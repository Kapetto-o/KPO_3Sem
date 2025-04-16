#include "Deserealizer.h"
#include<Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Deserializer deserializer;
    deserializer.DeserializeData();
    deserializer.ConvertToAssembler();

    return 0;
}