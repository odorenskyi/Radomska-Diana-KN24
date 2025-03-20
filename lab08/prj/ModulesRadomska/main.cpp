#include <cmath>

double s_calculation(double x, double y, double z) {
    if (x - y <= 0) {
        return NAN; // Повертаємо NaN, якщо логарифм невизначений
    }

    double numerator = z + 2 * pow(y, 2);
    double denominator = log(x - y);
    double sqrt_term = sqrt(M_PI * x);

    return (numerator / denominator) + sqrt_term;
}

