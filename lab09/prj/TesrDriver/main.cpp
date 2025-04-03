#include <iostream>
#include "ModulesRadomska.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int months;
    unsigned int N;
    double deposit, max_speed;

    developer_information();

    cout << "Тестування функції (9.1):" << endl;

    cout << "Введіть суму депозиту: ";
    cin >> deposit;
    cout << "Введіть кількість місяців (6 або 12): ";
    cin >> months;

    deposit_calculation(deposit, months);

    cout << "\nТестування функції (9.2):" << endl;

    cout << "Введіть максимальну швидкість вітру (м/с): ";
    cin >> max_speed;

    g_calculation(max_speed);

    cout << "\nТестування функції (9.3):" << endl;

    cout << "Введіть натуральне число N (0 - 9008000): ";
    cin >> N;

    f_calculation(N);

    return 0;
}
