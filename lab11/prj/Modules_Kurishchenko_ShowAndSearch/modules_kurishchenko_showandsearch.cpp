#include "modules_kurishchenko_showandsearch.h"

string printBlock(const string& title) { return "\n• " + title + " •\n"; }

void printRecord(ostream* out, const Student& s) {
    *out << printBlock("Особисті дані");
    *out << "  ПІБ: " << s.name.lastName << " " << s.name.firstName << " " << s.name.middleName << '\n';
    *out << "  Дата народження: " << setw(2) << setfill('0') << s.birthDate.day << "."
         << setw(2) << s.birthDate.month << "." << s.birthDate.year << '\n';
    *out << "  Громадянство: " << s.citizenship << "\n";

    *out << printBlock("Місце народження");
    *out << "  " << s.birthPlace.locality << ", " << s.birthPlace.district
         << " р-н, " << s.birthPlace.region << " обл. (" << s.birthPlace.postalCode << ")\n";

    *out << printBlock("Навчальний заклад до вступу");
    *out << "  Заклад: " << s.graduatedFrom << "\n";
    *out << "  Рік закінчення: " << s.graduationYear << "\n";

    *out << printBlock("Сімейний стан та адреса");
    *out << "  Сімейний стан: " << s.familyStatus << '\n';
    *out << "  Адреса: " << s.address.locality << ", " << s.address.region
         << " обл., " << s.address.district << " р-н. (" << s.address.postalCode << ")\n";

    *out << printBlock("Освіта");
    *out << "  Заклад: " << s.education.institutionName << '\n';
    *out << "  Підрозділ: " << s.education.department.institute << " / "
         << s.education.department.faculty << " / " << s.education.department.department << '\n';
    *out << "  Рівень: " << s.education.educationLevel << '\n';
    *out << "  Напрям: " << s.education.trainingDirection.code << " - " << s.education.trainingDirection.name << '\n';
    *out << "  Спеціальність: " << s.education.specialty.code << " - " << s.education.specialty.name << '\n';
    *out << "  Спеціалізація: " << s.education.specialization.code << " - " << s.education.specialization.name << "\n";
    *out << "+------------------------------------------------------------+\n\n";
}

// Функція для виведення всієї бази даних
void printAllRecords() {
    cout << "Куди бажаєте вивести базу даних?\n"
         << "1. На екран\n"
         << "2. У файл (students_output.txt)\n"
         << "Ваш вибір: ";

    int choice;
    cin >> choice;
    if (cin.fail() || (choice > 2 || choice < 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Некоректне введення. Введіть 1 або 2.\n\n";
        return;
    }
    cin.ignore();

    ostream* out = nullptr;
    ofstream outFile;

    if (choice == 2) {
        outFile.open("students_output.txt", ios::trunc);
        if (!outFile.is_open()) {
            cerr << "Не вдалося відкрити файл для запису.\n";
            return;
        }
        out = &outFile;
    }
    else out = &cout;

    Node* current = head;
    int index = 1;

    while (current) {
        const Student& s = current->data;
        *out << "+------------------------------------------------------------+\n";
        *out << "                           СТУДЕНТ №" << index++ << "\n";
        *out << "+------------------------------------------------------------+";
        printRecord(out, s);
        current = current->next;
    }

    if (choice == 2) {
        outFile.close();
        cout << "Дані успішно збережено у файл 'students_output.txt'\n\n";
    }
}

// Функція для пошуку запису за прізвищем
void searchRecordByLastName() {
    string lastName;
    cout << "Введіть прізвище студента для пошуку: ";
    getline(cin, lastName);

    Node* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data.name.lastName == lastName) {
            found = true;
            const Student& s = current->data;

            cout << "\n+------------------------------------------------------------+\n";
            cout <<   "|                   ІНФОРМАЦІЯ ПРО СТУДЕНТА                  |\n";
            cout <<   "+------------------------------------------------------------+";
            printRecord(&cout, s);
        }
        current = current->next;
    }

    if (!found) {
        cerr << "Студент з прізвищем \"" << lastName << "\" не знайдений.\n\n";
    }
}



