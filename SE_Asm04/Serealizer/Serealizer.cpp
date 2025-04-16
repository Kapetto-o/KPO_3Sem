#include "Serealizer.h"

void Serializer::SerializeData() {
    file.open("D:/GitHub/BSTU/course_2/KPO_3/SE_Asm04/necessary/serializer.bin", ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла для сериализации.\n";
        return;
    }

    file.put(textMarker);
    unsigned char textLength = static_cast<unsigned char>(Text.size());
    file.put(textLength);
    file.write(Text.data(), textLength);

    file.put(intMarker);
    unsigned char intSize = sizeof(Integer);
    file.put(intSize);
    file.write(reinterpret_cast<const char*>(&Integer), intSize);

    file.close();
    cout << "Данные успешно сериализованы.\n";
}