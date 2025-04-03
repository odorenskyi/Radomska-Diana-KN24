#include <cmath>
#include <iostream>
#include <bitset>
#include <limits>
#include <windows.h>
#include "ModulesRadomska.h"

using namespace std;

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    char choice;
    char exit_choice;
    double x, y, z;
    double deposit_amount;
    int deposit_term;
    double wind_speed;
    unsigned int number;

    developer_information();

    do {
        cout << "\nВведіть символ (k, h, g, f): ";
        cin >> choice;

        switch (choice) {
            case 'k':
                cout << "Введіть значення x, y, z: ";
                cin >> x >> y >> z;

                double result;
                result = s_calculation(x, y, z);

                if (isnan(result)) {
                    cout << "Помилка: логарифм невизначений (x-y має бути більше 0)" << endl;
                } else {
                    cout << "Результат обчислення: " << result << endl;
                }
                break;

            case 'h':
                cout << "Введіть суму депозиту: ";
                cin >> deposit_amount;
                cout << "Введіть термін депозиту (6 або 12 місяців): ";
                cin >> deposit_term;
                deposit_calculation(deposit_amount, deposit_term);
                break;

            case 'g':
                cout << "Введіть максимальну швидкість вітру (м/с): ";
                cin >> wind_speed;
                g_calculation(wind_speed);
                break;

            case 'f':
                cout << "Введіть число (не більше 9008000): ";
                cin >> number;
                f_calculation(number);
                break;

            default:
                cout << "\a"; // Звуковий сигнал
                cout << "Помилкове введення! Використовуйте символи k, h, g або f." << endl;
        }

        cout << "\nБажаєте вийти з програми? (d/D/c для виходу, будь-який інший символ для продовження): ";
        cin >> exit_choice;

        // Очищення буфера вводу
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (exit_choice != 'd' && exit_choice != 'D' && exit_choice != 'c');

    cout << "Програма завершена." << endl;
    return 0;
}
