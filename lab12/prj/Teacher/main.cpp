#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <filesystem>
#include <algorithm>
#include "ModulesRadomska.h"

using namespace std;
namespace fs = std::filesystem;

void setupConsole() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}

void displayHeader() {
    cout << "═══════════════════════════════════════════════════════════════════\n";
    cout << "     🎓 Лабораторна робота №12 | Студент: Радомська Діана КН-24    \n";
    cout << "     📐 Тема: Розрахунок об'єму куба за довжиною грані             \n";
    cout << "═══════════════════════════════════════════════════════════════════\n\n";
}

void createErrorReport(const string& fileName, const string& reason) {
    ofstream errorFile(fileName);
    for (int soundCount = 0; soundCount < 100; soundCount++) cout << '\a';

    errorFile << "╔═══════════════════════════════════════════════════════════════╗\n"
              << "║                    🚨 КРИТИЧНА ПОМИЛКА 🚨                    ║\n"
              << "╠═══════════════════════════════════════════════════════════════╣\n"
              << "║ Опис помилки: " << reason << endl
              << "║ Рекомендація: Перевірте структуру папок проекту!              ║\n"
              << "╚═══════════════════════════════════════════════════════════════╝\n";
    errorFile.close();
}

bool validatePath() {
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    string currentPath = exePath;
    string expectedPath = "\\lab12\\prj\\";

    string pathLower = currentPath, expectedLower = expectedPath;
    transform(pathLower.begin(), pathLower.end(), pathLower.begin(), ::tolower);
    transform(expectedLower.begin(), expectedLower.end(), expectedLower.begin(), ::tolower);

    if (pathLower.find(expectedLower) == string::npos) {
        createErrorReport("TestResults.txt", "main.cpp має бути у каталозі \\lab12\\prj\\");
        cout << "🔴 КРИТИЧНА ПОМИЛКА! Детальна інформація у файлі TestResults.txt\n";
        return false;
    }
    return true;
}

int getTestCount() {
    int count;
    cout << "📝 Введіть кількість тестових випадків: ";
    cin >> count;

    if (cin.fail() || count <= 0) {
        cout << "❌ Помилка! Некоректна кількість тестів. Натисніть Enter...";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return -1;
    }
    return count;
}

void writeFileHeader(ofstream& file) {
    file << "╔═══════════════════════════════════════════════════════════════════════════════╗\n"
         << "║                      ЗВІТ ПРО ТЕСТУВАННЯ КЛАСУ КУБА                           ║\n"
         << "║                   Виконавець: Радомська Діана, група КН-24                    ║\n"
         << "╠═══════╦══════════════╦══════════════════════╦══════════════════════╦══════════╣\n"
         << "║ № п/п ║ Грань куба   ║ Очікуваний об'єм     ║ Розрахований об'єм   ║ Оцінка   ║\n"
         << "╠═══════╬══════════════╬══════════════════════╬══════════════════════╬══════════╣\n";
}

void writeFileFooter(ofstream& file) {
    file << "╚═══════╩══════════════╩══════════════════════╩══════════════════════╩══════════╝\n"
         << "\n📊 Підсумок тестування завершено " << __DATE__ << " о " << __TIME__ << "\n";
}

bool processTestCase(int testNum, ofstream& resultFile) {
    float sideLength, expectedVol;

    cout << "\n🔸 Тестовий випадок #" << testNum << "\n";
    cout << "   Довжина грані куба (a): ";
    cin >> sideLength;
    cout << "   Очікуваний об'єм (a³): ";
    cin >> expectedVol;

    if (cin.fail()) {
        cout << "⚠️ Некоректні дані! Завершення програми...";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return false;
    }

    ClassLab12_Radomska cubeObject(sideLength);
    float actualVol = cubeObject.getVolume();
    bool testPassed = (fabs(actualVol - expectedVol) < 0.0001);
    string status = testPassed ? "УСПІХ" : "ПОМИЛКА";

    resultFile << "║ " << setw(5) << right << testNum
               << " ║ " << setw(12) << left << fixed << setprecision(3) << sideLength
               << " ║ " << setw(20) << left << fixed << setprecision(6) << expectedVol
               << " ║ " << setw(20) << left << fixed << setprecision(6) << actualVol
               << " ║ " << setw(8) << left << status << "  ║\n";

    return true;
}

void displayFooter() {
    cout << "\n═══════════════════════════════════════════════════════════════════\n"
         << "     💾 Результати збережено у файл TestResults.txt                \n"
         << "     🎯 Тестування завершено успішно!                              \n"
         << "═══════════════════════════════════════════════════════════════════\n";
}

int main() {
    setupConsole();
    displayHeader();

    if (!validatePath()) return 0;

    int testCount = getTestCount();
    if (testCount == -1) return 1;

    ofstream outputFile("TestResults.txt");
    if (!outputFile) {
        cerr << "💾 Помилка створення файлу TestResults.txt" << endl;
        cout << "Натисніть Enter для завершення...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    writeFileHeader(outputFile);

    for (int i = 1; i <= testCount; i++) {
        if (!processTestCase(i, outputFile)) {
            outputFile.close();
            return 1;
        }
    }

    writeFileFooter(outputFile);
    outputFile.close();

    displayFooter();

    cout << "Натисніть Enter для завершення...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    return 0;
}
