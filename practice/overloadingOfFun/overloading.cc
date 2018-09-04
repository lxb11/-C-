#include <iostream>
using  namespace std;

class Complex
{
public:
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void print()
    {
        cout << "(" << a << "+" << b << "i)" << endl;
    }

    //声明外部的全局函数为友元
    friend Complex addComplex(Complex& c1, Complex& c2);
#if 0
    friend Complex operator+(Complex& c1, Complex& c2);
    friend Complex operator-(Complex& c1, Complex& c2);
#endif
    Complex operator+(Complex& another)
    {
        Complex temp(this->a + another.a, this->b + another.b);
        return temp;
    }

    Complex operator-(Complex& another)
    {
        Complex temp(this->a - another.a, this->b - another.b);
        return temp;
    }

private:
    int a;//实数部分
    int b;//虚数部分
};

//全局函数提供一各加法
Complex addComplex(Complex& c1, Complex& c2)
{
    Complex temp(c1.a + c2.a, c1.b + c2.b);
    return temp;
}

#if 0
//全局提供一个+号操作符重载
Complex operator+(Complex& c1, Complex& c2)
{
    Complex temp(c1.a + c2.a, c1.b + c2.b);
    return temp;
}

Complex operator-(Complex& c1, Complex& c2)
{
    Complex temp(c1.a - c2.a, c1.b - c2.b);
    return temp;
}
#endif

int main()
{
    Complex c1(10, 20);
    Complex c2(20, 40);
    c1.print();

    Complex c3 = addComplex(c1, c2);
    c3.print();

    Complex c4 = c1.operator+(c2);
    c4.print();
    
    Complex c5 = c1 + c2;//operator+(c1, c2);//正常一般的操作符+支持全剧调用方式，和全局函数
    //的调用方式，和成员函数的调用方式.
    //如果c1有成员函数operator+函数，c1.operator+(c2);
    c5.print();

    Complex c6 = c1 - c2;
    c6.print();

    return 0;
}

