#include <iostream>

using namespace std;

int NOD(int a, int b) {
    int r;
    if (b > a) std::swap(a,b);
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int NOK(int a, int b) {
    return a * b / NOD(a, b);
}

class RationalNumber {
private:
    int m_numerator;
    int m_denominator;

    void Red() {
        int n = NOD(this->m_numerator, this->m_denominator);
         
        this->m_numerator = this->m_numerator / n;
        this->m_denominator = this->m_denominator / n;
    }
public:
    friend RationalNumber RationalY(const RationalNumber& element);
    friend double Y(const RationalNumber& element);
    friend ostream& operator<< (ostream& out, const RationalNumber& element);
    friend istream& operator>> (istream& in, RationalNumber& element);

    RationalNumber() {
        m_numerator = 1;
        m_denominator = 2;

    }
    RationalNumber(int numerator, int denominator) {
        m_numerator = numerator;
        m_denominator = denominator;
        
        Red();
    }
    
    RationalNumber(double numerator) {
        m_numerator = numerator*10;
        m_denominator = 10;
        
        Red();
    }
    
    RationalNumber operator+ (const RationalNumber& element) {
        double k1, k2;
        RationalNumber S;
        S.m_denominator = this->m_denominator * element.m_denominator;
        k1 = S.m_denominator / element.m_denominator;
        k2 = S.m_denominator / this->m_denominator;
        S.m_numerator = k2*this->m_numerator + k1*element.m_numerator;

        S.Red();
        return S;
    }
    
    RationalNumber operator* (const RationalNumber& element) {
        RationalNumber C;
        C.m_denominator = this->m_denominator * element.m_denominator;
        C.m_numerator = this->m_numerator * element.m_numerator;
        
        C.Red();
        return C;
    }
    
    RationalNumber operator/ (const RationalNumber& element) {
        RationalNumber D;
        D.m_denominator = this->m_denominator * element.m_numerator;
        D.m_numerator = this->m_numerator * element.m_denominator;
        D.Red();
        
        return D;
    }
};

RationalNumber RationalY(const RationalNumber& element) {
    RationalNumber a = 2;
    RationalNumber b = 1.3;
    RationalNumber res = a * element + b / element;
    
    res.Red();
    return res;
}

double Y(const RationalNumber& element) {
    double deistv = (double)element.m_numerator / element.m_denominator;
    
    return 2 * deistv + 1.3 / deistv;
}


void CreateTable() {
    for (int i = -10; i <= 10; i++) {
        if (i != 0) {
            RationalNumber r = (double)i/10;
            cout << "x= " << (double)i/10 << "    \t y = " << RationalY(r) << "   \t  y1 = " << Y(r) << endl;
        }
    }
}

ostream& operator<< (ostream& out, const RationalNumber& element) {
    out << element.m_numerator << "/" << element.m_denominator;
 
    return out;
}

istream& operator>> (istream& in, RationalNumber& element) {
    cout << "Введите числитель: ";
    in >> element.m_numerator;
    cout << "Введите знаменатель: ";
    in >> element.m_denominator;
    
    element.Red();
    return in;
}

int main() {
    setlocale(LC_ALL, "Russian");

    CreateTable();
    
    return 0;

}
