#include <cmath>
#include <iostream>
#include <bitset>

using namespace std;

double s_calculation(double x, double y, double z) {
    if (x - y <= 0) {
        return NAN; // Повертаємо NaN, якщо логарифм невизначений
    }

    double numerator = z + 2 * pow(y, 2);
    double denominator = log(x - y);
    double sqrt_term = sqrt(M_PI * x);

    return (numerator / denominator) + sqrt_term;
}

void deposit_calculation() {
    double deposit;
    int months;

    cout << "Введіть суму депозиту: ";
    cin >> deposit;
    cout << "Введіть кількість місяців (6 або 12): ";
    cin >> months;

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
void g_calculation() {
    double max_speed;

    cout << "Введіть максимальну швидкість вітру (м/с): ";
    cin >> max_speed;

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
void f_calculation() {
    unsigned int N;

    cout << "Введіть натуральне число N (0 - 9008000): ";
    cin >> N;

    if (N > 9008000) {
        cout << "Число виходить за дозволений діапазон!\n";
        return;
    }

    bitset<24> binary(N);
    bool D13 = binary[13];

    int count = (D13 == 0) ? (24 - binary.count()) : binary.count();

    cout << "Результат: " << count << endl;
}

