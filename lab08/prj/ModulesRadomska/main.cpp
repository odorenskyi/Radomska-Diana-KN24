#include <cmath>
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <random>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <map>
#include <stack>
#include <vector>

using namespace std;

void developer_information() {
    std::cout << "Радомська Діана ©, Усі права захищені." << std::endl;
}

double s_calculation(double x, double y, double z) {
    if (x - y <= 0) {
        return NAN; // Повертаємо NaN, якщо логарифм невизначений
    }

    double numerator = z + 2 * pow(y, 2);
    double denominator = log(x - y);
    double sqrt_term = sqrt(M_PI * x);

    return (numerator / denominator) + sqrt_term;
}

void deposit_calculation(double deposit, int months) {

    if (months != 6 && months != 12) {
        cout << "Некоректний термін депозиту!\n";
        return;
    }

    double rate = (months == 6) ? 0.16 : 0.18;
    double interest = deposit * rate * (months / 12.0);

    cout << "Сума виплат відсотків: " << interest << " грн\n";
    cout << "Загальна сума після строку дії: " << deposit + interest << " грн\n";
}

// Функція для задачі 9.2: визначення максимального балу Бофорта
void g_calculation(double max_speed) {

    // Масиви для визначення балу Бофорта та опису дії вітру
    double thresholds[] = {0.3, 1.5, 9.4, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6, 100.0};
    string descriptions[] = {
        "Відсутність вітру. Дим піднімається прямо. Листя дерев нерухомі.",
        "Дим «пливе». Флюгер не обертається.",
        "Рух повітря відчувається обличчям. Шелестить листя. Флюгер обертається.",
        "Тріпоче листя, хитаються дрібні гілки. Майорять прапори.",
        "Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу.",
        "Хитаються великі гілки. На воді з'являються хвилі.",
        "Хитаються великі гілки.",
        "Хитаються невеликі стовбури дерев. На морі здіймаються хвилі, піна.",
        "Ламаються гілки дерев. Важко йти проти вітру.",
        "Невеликі руйнування. Зриває покрівлі, руйнує димарі.",
        "Значні руйнування. Дерева вириваються з корінням.",
        "Великі руйнування.",
        "Призводить до спустошень."
    };

    // Визначення балу Бофорта
    int beaufort_scale = 0;
    for (int i = 0; i < 12; i++) {
        if (max_speed <= thresholds[i]) {
            beaufort_scale = i;
            break;
        }
    }

    // Виведення результату
    cout << "Найбільша зафіксована сила вітру за шкалою Бофорта: " << beaufort_scale << " балів\n";
    cout << "Дія вітру: " << descriptions[beaufort_scale] << endl;
}

// Функція для задачі 9.3: підрахунок двійкових 0 або 1
void f_calculation(unsigned int N) {

    if (N > 9008000) {
        cout << "Число виходить за дозволений діапазон!\n";
        return;
    }

    bitset<24> binary(N);
    bool D13 = binary[13];

    int count = (D13 == 0) ? (24 - binary.count()) : binary.count();

    cout << "Результат: " << count << endl;
}
// Функція для задачі 10.1
void task_10_1(const std::string& input_filename, const std::string& output_filename) {
    // Відкриття вихідного файлу для запису
    std::ofstream outfile(output_filename);
    if (!outfile.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити вихідний файл '" << output_filename << "' для запису." << std::endl;
        return;
    }

    // 1. Запис авторської інформації
    outfile << "  Авторська інформація:\n";
    outfile << "  Ім'я та прізвище: Діана Радомська\n";
    outfile << "  Установа/організація: ЦНТУ\n";
    outfile << "  Місто: Кропивницький\n";
    outfile << "  Країна: Україна\n";
    outfile << "  Рік розробки: 2025\n\n";

    // 2. Генерація та запис випадкового числа
    std::srand(std::time(nullptr)); // Ініціалізація генератора випадкових чисел
    int random_number = std::rand() % (100 - 10 + 1) + 10; // Випадкове число від 10 до 100
    outfile << "Випадкове число (від 10 до 100): " << random_number << "\n\n";

    // 3. Перевірка пунктуації тексту вірша
    // Очікуваний текст вірша (авторський оригінал)
    const std::vector<std::string> original_poem_lines = {
        "Як парость виноградної лози, плекайте мову.",
        "Пильно й ненастанно політь бур'ян.",
        "Чистіша від сльози вона хай буде.",
        "Вірно і слухняно нехай вона щоразу служить вам,",
        "Хоч і живе своїм живим життям."
    };

    // Читання тексту з вхідного файлу
    std::ifstream infile(input_filename);
    std::vector<std::string> input_poem_lines;
    std::string current_line;
    bool file_read_error = false;

    if (infile.is_open()) {
        while (std::getline(infile, current_line)) {
            // Можна додати обрізку пробілів на кінцях рядка, якщо потрібно
            // current_line.erase(0, current_line.find_first_not_of(" \t\n\r\f\v"));
            // current_line.erase(current_line.find_last_not_of(" \t\n\r\f\v") + 1);
            input_poem_lines.push_back(current_line);
        }
        infile.close();
         // Видалення можливого порожнього останнього рядка, якщо файл закінчується символом нового рядка
        if (!input_poem_lines.empty() && input_poem_lines.back().empty()) {
             input_poem_lines.pop_back();
        }
    } else {
        std::cerr << "Помилка: Не вдалося відкрити вхідний файл '" << input_filename << "' для читання." << std::endl;
        file_read_error = true;
    }

    // Порівняння та запис повідомлення про пунктуацію
    outfile << "Повідомлення про пунктуацію:\n";
    if (file_read_error) {
        outfile << "  Не вдалося прочитати вхідний файл для перевірки пунктуації.\n";
    } else if (input_poem_lines == original_poem_lines) {
        outfile << "  Текст віршу із вхідного файла НЕ має пунктуаційних помилок (відповідно до авторського оригіналу).\n";
    } else {
        outfile << "  Текст віршу із вхідного файла МАЄ пунктуаційні помилки або відрізняється від оригіналу.\n";
    }

    outfile.close();
    std::cout << "Завдання 10.1 виконано. Результати записано у файл: " << output_filename << std::endl;
}

//10.2
void task_10_2(const std::string& filename) {
    // Вхідний текстовий файл
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису!" << std::endl;
        return;
    }

    // Додавання англійської абетки у верхньому регістрі
    file << "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

    // Додавання дати й часу дозапису інформації
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    file << "Дата і час дозапису: " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "\n";

    file.close();
}

//10.3
void task_10_3(double x, double y, double z, unsigned int b, const std::string& filename) {
    // Open output file for appending
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл '" << filename << "' для запису." << std::endl;
        return;
    }

    // Write the result of s_calculation with arguments x, y, z
    double result = s_calculation(x, y, z);
    file << "Результат функції s_calculation(" << x << ", " << y << ", " << z << ") = ";
    if (std::isnan(result)) {
        file << "невизначено (ділення на нуль або від'ємний підкореневий вираз)" << std::endl;
    } else {
        file << result << std::endl;
    }

    // Write number b in binary code
    file << "Число " << b << " у двійковому коді: " << std::bitset<32>(b) << std::endl;

    file.close();
    std::cout << "Завдання 10.3 виконано. Результати дописано у файл: " << filename << std::endl;
}
