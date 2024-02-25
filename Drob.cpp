#include <iostream>
#include <cmath>

class Fraction {
    private:
    int numerator;
    int denominator;

    // Функция для вычисления НОД (наибольшего общего делителя)
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public:
    Fraction(double value) {
        const double EPSILON = 1e-6; // точность для сравнения с плавающей запятой
        int sign = (value < 0) ? -1 : 1;
        value = std::abs(value);

        double wholePart;
        double fractionalPart = modf(value, &wholePart);

        numerator = static_cast<int>(fractionalPart * 1000000);
        denominator = 1000000;

        // Сокращаем дробь
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        numerator += static_cast<int>(wholePart * 1000000);
        numerator *= sign;
    }

    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    double value;
    std::cout << "Vvedite znachenie double: ";
    std::cin >> value;

    Fraction fraction(value);
    std::cout << "Drobnoe predstavlenie: ";
    fraction.print();

    return 0;
}