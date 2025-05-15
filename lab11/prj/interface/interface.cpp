#include "interface.h"

void showIntro() {
    cout << "+======================================================================+\n";
    cout << "|                  СИСТЕМА \"Деканат: Облік студентів\"                  |\n";
    cout << "+----------------------------------------------------------------------+\n";
    cout << "|  Розробники:                                                         |\n";
    cout << "|    - Куріщенко   Павло КН-24                                         |\n";
    cout << "|    - Булюкін Володимир КН-24                                         |\n";
    cout << "|    - Радомська   Діана КН-24                                         |\n";
    cout << "|                                                                      |\n";
    cout << "|  Призначення:                                                        |\n";
    cout << "|    Ця програма дозволяє вести облік студентів:                       |\n";
    cout << "|    додавати нові записи, переглядати всю базу,                       |\n";
    cout << "|    шукати за прізвищем та видаляти записи.                           |\n";
    cout << "+======================================================================+\n\n";
}

// Функція для виведення головного меню
void showMainMenu() {
    cout << "Оберіть дію:\n";
    cout << "1. Вивести всю базу даних\n";
    cout << "2. Додати новий запис\n";
    cout << "3. Пошук запису за прізвищем\n";
    cout << "4. Видалити запис\n";
    cout << "0. Завершити програму\n";
    cout << "Ваш вибір: ";
}

//Оновлення екрану
void updateScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Функція для отримання вибору користувача
int getUserChoice() {
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    updateScreen();
    return choice;
}

// Основна функція для вибору операцій
void handleUserChoice() {
    showIntro();
    while (true) {
        showMainMenu();
        switch (getUserChoice()) {
        case 1: printAllRecords(); break;
        case 2: addNewRecord(); break;
        case 3: searchRecordByLastName(); break;
        case 4: removeRecordByFullName(); break;
        case 0: //exitProgram(); return;
        default: cerr << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
}

