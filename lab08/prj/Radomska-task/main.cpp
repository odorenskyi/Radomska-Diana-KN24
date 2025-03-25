#include <iostream>
#include <iomanip>
#include <windows.h>
#include "ModulesRadomska.h"

using namespace std;

// 8.2.1 Вивід імені розробника в рамочці
void printDeveloper() {
    cout << "******************************" << endl;
    cout << "* © Радомська Діана          *" << endl;
    cout << "* Усі права захищені         *" << endl;
    cout << "******************************" << endl;
}

// 8.2.2 Логічний вираз a + 10 >= b
int logicalExpression(char a, char b) {
    return (a + 10 >= b) ? 1 : 0;
}

// 8.2.3 Вивід чисел у різних системах
void printNumbers(int x, int y, int z) {
    cout << "Десяткова: " << x << " " << y << " " << z << endl;
    cout << "Шістнадцяткова: " << hex << uppercase << x << " " << y << " " << z << dec << endl;
}
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int x, y, z;
    char a, b;

    // Введення даних
    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть a і b: ";
    cin >> a >> b;

    // Виконання функцій
    printDeveloper();
    cout << "Результат логічного виразу: " << logicalExpression(a, b) << endl;
    printNumbers(x, y, z);

    // Виклик функції з модуля (якщо вона існує)
    cout << "S = " << s_calculation(x, y, z) << endl;

    return 0;
}
