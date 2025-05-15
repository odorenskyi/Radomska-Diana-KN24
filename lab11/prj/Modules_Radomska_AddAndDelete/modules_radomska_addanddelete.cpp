#include "modules_radomska_addanddelete.h"

void getValidatedInput(string& field, const string& prompt) {
    while (true) {
        cout << prompt;
        getline(cin, field);
        if (!field.empty()) break;
        cerr << "Поле не може бути порожнім. Спробуйте ще раз.\n";
    }
}

// Функція для введення цілих чисел з перевіркою на коректність
void getValidatedInput(int& field, const string& prompt) {
    while (true) {
        cout << prompt;
        cin >> field;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Будь ласка, введіть коректне ціле число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break; // Виходимо з циклу, якщо введено коректне число
        }
    }
}

// Функція для додавання запису
void addNewRecord() {
    Student newStudent;

    cout << "\n• Введення персональних даних студента •\n";
    getValidatedInput(newStudent.name.lastName,   "  Введіть прізвище: ");
    getValidatedInput(newStudent.name.firstName,  "  Введіть ім'я: ");
    getValidatedInput(newStudent.name.middleName, "  Введіть по батькові: ");

    cout << "\n• Введення дати народження •\n";
    getValidatedInput(newStudent.birthDate.day,   "  День: ");
    getValidatedInput(newStudent.birthDate.month, "  Місяць: ");
    getValidatedInput(newStudent.birthDate.year,  "  Рік: ");

    cout << "\n• Введення місця народження •\n";
    getValidatedInput(newStudent.birthPlace.postalCode, "  Поштовий індекс: ");
    getValidatedInput(newStudent.birthPlace.region,     "  Область: ");
    getValidatedInput(newStudent.birthPlace.district,   "  Район: ");
    getValidatedInput(newStudent.birthPlace.locality,   "  Населений пункт: ");

    cout << "\n• Інші персональні дані •\n";
    getValidatedInput(newStudent.citizenship,    "  Громадянство: ");
    getValidatedInput(newStudent.graduatedFrom,  "  Навчальний заклад, що закінчив: ");
    getValidatedInput(newStudent.graduationYear, "  Рік закінчення: ");
    getValidatedInput(newStudent.familyStatus,   "  Сімейний стан: ");

    cout << "\n• Введення адреси проживання •\n";
    getValidatedInput(newStudent.address.postalCode, "  Поштовий індекс: ");
    getValidatedInput(newStudent.address.region,     "  Область: ");
    getValidatedInput(newStudent.address.district,   "  Район: ");
    getValidatedInput(newStudent.address.locality,   "  Населений пункт: ");

    cout << "\n• Введення інформації про освіту у ЗВО •\n";
    getValidatedInput(newStudent.education.institutionName,       "  Назва закладу: ");
    getValidatedInput(newStudent.education.department.institute,  "  Інститут: ");
    getValidatedInput(newStudent.education.department.faculty,    "  Факультет: ");
    getValidatedInput(newStudent.education.department.department, "  Відділення: ");
    getValidatedInput(newStudent.education.educationLevel,        "  Рівень освіти: ");

    cout << "\n• Напрям підготовки •\n";
    getValidatedInput(newStudent.education.trainingDirection.code, "  Шифр напряму: ");
    getValidatedInput(newStudent.education.trainingDirection.name, "  Назва напряму: ");

    cout << "\n• Спеціальність •\n";
    getValidatedInput(newStudent.education.specialty.code, "  Шифр спеціальності: ");
    getValidatedInput(newStudent.education.specialty.name, "  Назва спеціальності: ");

    cout << "\n• Спеціалізація •\n";
    getValidatedInput(newStudent.education.specialization.code, "  Шифр спеціалізації: ");
    getValidatedInput(newStudent.education.specialization.name, "  Назва спеціалізації: ");

    // Додавання нового вузла
    Node* newNode = new Node(newStudent);
    if (head == nullptr) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    cout << "\n+------------------------------------------------------------+\n";
    cout <<   "|                   НОВИЙ ЗАПИС УСПІШНО ДОДАНО               |\n";
    cout <<   "+------------------------------------------------------------+\n";
    cout <<   " Студента з прізвищем " << newStudent.name.lastName << " успішно додано в систему!\n";
}

// Функція для видалення запису
void removeRecordByFullName() {
    string lastName, firstName, middleName;

    cout << "\n=== Вилучення запису студента ===\n";
    getValidatedInput(lastName, "Введіть прізвище: ");
    getValidatedInput(firstName, "Введіть ім'я: ");
    getValidatedInput(middleName, "Введіть по батькові: ");

    // Перевірка, чи перший елемент — це той, кого потрібно видалити
    while (head != nullptr &&
           head->data.name.lastName == lastName &&
           head->data.name.firstName == firstName &&
           head->data.name.middleName == middleName) {

        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "\n+----------------------------------------------------+\n";
        cout <<   "|                ЗАПИС УСПІШНО ВИДАЛЕНО              |\n";
        cout <<   "+----------------------------------------------------+\n";
        cout << " " << lastName << " " << firstName << " " << middleName << " був(ла) видалений(а).\n";
        return;
    }

    // Проходимо по списку, шукаючи вузол, що йде ПІСЛЯ потрібного
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        Student& s = current->next->data;

        if (s.name.lastName == lastName &&
            s.name.firstName == firstName &&
            s.name.middleName == middleName) {

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;

            cout << "\n+----------------------------------------------------+\n";
            cout <<   "|                ЗАПИС УСПІШНО ВИДАЛЕНО              |\n";
            cout <<   "+----------------------------------------------------+\n";
            cout << " " << lastName << " " << firstName << " " << middleName << " був(ла) видалений(а).\n";
            return;
        }

        current = current->next;
    }

    cerr << "\nСтудента з таким ПІБ не знайдено.\n";
}
