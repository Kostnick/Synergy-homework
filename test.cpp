#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>

/*

    ќ„≈Ќ№ ¬ј∆Ќќ : ќшибка в коде из-за устаревшей версии с++ (нужна от c++ 17 и  выше)

    »звин€юсь, что мне потребовалось так много попыток

*/


class Fraction {
public:
    Fraction(const int num = 0, const int den = 1);
    Fraction(const Fraction& other) = default;
    ~Fraction() = default;
    std::string toString() const;
    int chisl;
    int znam;
    Fraction& operator+=(int a);
    friend bool operator==(const Fraction& left, const Fraction& rigth);
    friend const Fraction operator+(const Fraction& left, const Fraction& rigth);

private:
    void reduce();

private:
    int _numeratotr;
    int _denomenator;
};

Fraction::Fraction(const int num, const int den) {
    if (den == 0) {
        throw std::invalid_argument("denomenator can't be zero");
    }

    _numeratotr = num;
    _denomenator = den;

    reduce();
}

std::string Fraction::toString() const {
    if (_numeratotr == 0) {
        return "0";
    }

    if (_denomenator == 1) {
        return std::to_string(_numeratotr);
    }

    return std::to_string(_numeratotr) + "/" + std::to_string(_denomenator);
}

void Fraction::reduce() {
    auto gcd = std::gcd(std::abs(_numeratotr), _denomenator);

    if (gcd != 1) {
        _numeratotr /= gcd;
        _denomenator /= gcd;
    }
}




Fraction& Fraction::operator+=(int a) {
    this->chisl += a * this->znam;
    return *this;
}

bool operator==(const Fraction& left, const Fraction& rigth) {
    if (left.chisl == rigth.chisl && left.znam == rigth.znam)
        return true;
    else
        return false;


}

const Fraction operator+(const Fraction& left, const Fraction& rigth) {
    Fraction drob; 
    if (left.znam == rigth.znam) {
        drob.znam = left.znam; 
        drob.chisl = left.chisl + rigth.chisl; 
    }
    else { 
        drob.znam = left.znam * rigth.znam; 
        drob.chisl = rigth.chisl * left.znam + left.chisl * rigth.znam; 
    }
    return drob; 
}

int main() {
    Fraction a(0, 10);
    Fraction b(2, 5);
    std::cout << a.toString() << " " << b.toString() << " " << (a == b) << "\n";

    a += 2;
    Fraction c(40, 20);
    std::cout << a.toString() << " " << c.toString() << " " << (a == c) << "\n";

    auto d = a + b;
    std::cout << d.toString() << " " << "\n";
}