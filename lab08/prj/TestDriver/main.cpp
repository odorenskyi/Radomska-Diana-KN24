#include <iostream>
#include <windows.h>
#include "ModulesRadomska.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double x, y, z;
    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;

    try {
        cout << "S = " << s_calculation(x, y, z) << endl;
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
