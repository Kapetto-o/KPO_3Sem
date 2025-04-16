#include "Deserealizer.h"

void Deserializer::DeserializeData() {
    file.open("D:/GitHub/BSTU/course_2/KPO_3/SE_Asm04/necessary/serializer.bin", ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла для десериализации.\n";
        return;
    }

    unsigned char marker, length;
    while (file.read(reinterpret_cast<char*>(&marker), sizeof(marker))) {
        file.read(reinterpret_cast<char*>(&length), sizeof(length));

        if (marker == textMarker) {
            if (length > 127) {
                cerr << "Длина строки превышает 127 байт.\n";
                break;
            }
            Text.resize(length);
            file.read(&Text[0], length);
        }
        else if (marker == intMarker) {
            if (length != sizeof(Integer)) {
                cerr << "Некорректная длина для целого числа.\n";
                break;
            }
            file.read(reinterpret_cast<char*>(&Integer), length);
        }
        else {
            cerr << "Неизвестный маркер: " << static_cast<int>(marker) << "\n";
            break;
        }
    }

    file.close();
    cout << "Десериализованные данные:\n";
    cout << "Текст: " << Text << "\n";
    cout << "Целое число: " << Integer << "\n";
}

void Deserializer::ConvertToAssembler() {
    fileAsm.open("D:/GitHub/BSTU/course_2/KPO_3/SE_Asm04/necessary/GeneratedASM.asm");
    if (!fileAsm) {
        cerr << "Ошибка открытия файла для ASM.\n";
        return;
    }

    fileAsm ASM_HEAD;

    fileAsm << "TEXT\tDB \"" << Text << "\", 0\n";
    fileAsm << "INTEGER\tDD " << Integer << "\n";

    fileAsm ASM_FOOTER;

    fileAsm.close();
    cout << "ASM файл успешно создан.\n";
}
