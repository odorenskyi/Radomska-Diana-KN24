#include <iostream>
#include <windows.h>
#include "ModulesRadomska.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    cout << "Оберіть завдання для виконання (1, 2 або 3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            task_10_1("input.txt", "output.txt");
            break;
        case 2:
        task_10_2("output.txt");
        break;
        case 3:
        {
        double x, y, z;
        unsigned int b;

        cout << "Введіть значення x: ";
        cin >> x;
        cout << "Введіть значення y: ";
        cin >> y;
        cout << "Введіть значення z: ";
        cin >> z;
        cout << "Введіть значення b: ";
        cin >> b;

        task_10_3(x, y, z, b, "output.txt");
        break;
    }
    default:
            cout << "Неправильний вибір! Спробуйте ще раз." << endl;
            break;
    }

    cout << "Завдання виконано!" << endl;
    return 0;
}
