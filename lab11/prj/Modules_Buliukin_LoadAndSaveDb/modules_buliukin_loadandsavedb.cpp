#include "modules_buliukin_loadandsavedb.h"

void loadDatabaseFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Не вдалося відкрити файл: " << filename << '\n';
        return;
    }

    while (!in.eof()) {
        Student s;

        getline(in, s.name.lastName);
        if (s.name.lastName.empty()) break; // Якщо порожній рядок — кінець

        getline(in, s.name.firstName);
        getline(in, s.name.middleName);
        in >> s.birthDate.day >> s.birthDate.month >> s.birthDate.year;
        in.ignore();
        getline(in, s.birthPlace.postalCode);
        getline(in, s.birthPlace.region);
        getline(in, s.birthPlace.district);
        getline(in, s.birthPlace.locality);
        getline(in, s.citizenship);
        getline(in, s.graduatedFrom);
        in >> s.graduationYear;
        in.ignore();
        getline(in, s.familyStatus);
        getline(in, s.address.postalCode);
        getline(in, s.address.region);
        getline(in, s.address.district);
        getline(in, s.address.locality);
        getline(in, s.education.institutionName);
        getline(in, s.education.department.institute);
        getline(in, s.education.department.faculty);
        getline(in, s.education.department.department);
        getline(in, s.education.educationLevel);
        getline(in, s.education.trainingDirection.code);
        getline(in, s.education.trainingDirection.name);
        getline(in, s.education.specialty.code);
        getline(in, s.education.specialty.name);
        getline(in, s.education.specialization.code);
        getline(in, s.education.specialization.name);

        Node* newNode = new Node(s);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    in.close();
}

void saveDatabaseToFile(const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Не вдалося зберегти базу даних у файл: " << filename << '\n';
        return;
    }

    Node* current = head;
    while (current) {
        const Student& s = current->data;
        out << s.name.lastName << '\n'
            << s.name.firstName << '\n'
            << s.name.middleName << '\n'
            << s.birthDate.day << ' ' << s.birthDate.month << ' ' << s.birthDate.year << '\n'
            << s.birthPlace.postalCode << '\n'
            << s.birthPlace.region << '\n'
            << s.birthPlace.district << '\n'
            << s.birthPlace.locality << '\n'
            << s.citizenship << '\n'
            << s.graduatedFrom << '\n'
            << s.graduationYear << '\n'
            << s.familyStatus << '\n'
            << s.address.postalCode << '\n'
            << s.address.region << '\n'
            << s.address.district << '\n'
            << s.address.locality << '\n'
            << s.education.institutionName << '\n'
            << s.education.department.institute << '\n'
            << s.education.department.faculty << '\n'
            << s.education.department.department << '\n'
            << s.education.educationLevel << '\n'
            << s.education.trainingDirection.code << '\n'
            << s.education.trainingDirection.name << '\n'
            << s.education.specialty.code << '\n'
            << s.education.specialty.name << '\n'
            << s.education.specialization.code << '\n'
            << s.education.specialization.name << '\n';
        current = current->next;
    }

    out.close();
}

void exitProgram() {
    saveDatabaseToFile("students_database.txt");
    cout << "Програма завершена. Дані збережено у файл 'students_database.txt'.\n";
}
