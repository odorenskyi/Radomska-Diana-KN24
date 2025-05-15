#ifndef STRUCT_TYPE_PROJECT_4_H
#define STRUCT_TYPE_PROJECT_4_H

#include <string>

using namespace std;

// Структура для збереження інформації про інститут, факультет та відділення
struct DepartmentInfo {
    string institute;  // Назва інституту
    string faculty;    // Назва факультету
    string department; // Назва відділення
};

// Структура для збереження пари "шифр + назва" (спеціальність, напрям, спеціалізація)
struct CodeName {
    string code; // Шифр
    string name; // Назва
};

// Структура для збереження інформації про освіту
struct EducationInfo {
    string institutionName;     // Найменування вищого навчального закладу
    DepartmentInfo department;  // Інститут, факультет, відділення
    string educationLevel;      // Рівень освіти (молодший спеціаліст, бакалавр, магістр)
    CodeName trainingDirection; // Напрям підготовки (шифр і назва)
    CodeName specialty;         // Спеціальність (шифр і назва)
    CodeName specialization;    // Спеціалізація (шифр і назва)
};

// Структура для збереження ПІБ студента
struct FullName {
    string lastName;    // Прізвище
    string firstName;   // Ім’я
    string middleName;  // По батькові
};

// Структура для збереження дати народження студента
struct Date {
    int day;   // День
    int month; // Місяць
    int year;  // Рік
};

// Структура для збереження адреси та місця народження студента
struct Address {
    string postalCode; // Поштовий індекс
    string region;     // Область
    string district;   // Район
    string locality;   // Назва населеного пункту
};

// Основна структура, що представляє студента
struct Student {
    FullName name;           // Прізвище, ім’я, по батькові
    Date birthDate;          // Дата народження
    Address birthPlace;      // Місце народження
    string citizenship;      // Громадянство
    string graduatedFrom;    // Навчальний заклад, який закінчив перед вступом
    string graduationYear;   // Рік закінчення попереднього навчального закладу
    string familyStatus;     // Сімейний стан
    Address address;         // Адреса проживання
    EducationInfo education; // Інформація про вищу освіту
};

struct Node { // Вузол однозв'язного списку
    Student data;
    Node* next;

    Node(const Student& studentData) : data(studentData), next(nullptr) {} // Конструктор для зручності створення вузлів
};

extern Node* head;

#endif // STRUCT_TYPE_PROJECT_4_H
