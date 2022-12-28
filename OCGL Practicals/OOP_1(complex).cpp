#include<iostream>
using namespace std;

class Complex
{
public:
    float real, img;
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex operator +(Complex &c2);
    Complex operator *(Complex &c2);
    friend istream &operator >> (istream &in, Complex &c2);
    friend ostream &operator << (ostream &out, Complex &c2);
};

Complex Complex :: operator+ (Complex &c2)
{
    Complex temp;
    temp.real = real + c2.real;
    temp.img = img + c2.img;
    return temp;
}

Complex Complex :: operator* (Complex &c2)
{
    Complex temp;
    temp.real = (real*c2.real)-(img*c2.img);
    temp.img = (real*c2.img)+(img*c2.real);
    return temp;
}

istream &operator >> (istream &in, Complex &c1)
{
    cout << "Enter real and imaginary part of the complex number :";
    in >> c1.real >> c1.img;
    return in;
}

ostream &operator << (ostream &out, Complex &c2)
{
    out << c2.real << "+" << c2.img << "i" << endl;
    return out;
}

int main()
{
    Complex c1, c2, c3;
    cin >> c1 >> c2;
    c3 = c1 + c2;
    cout << "\nThe sum is : " << c3;
    c3 = c1 * c2;
    cout << "The product is : " << c3;
    return 0;
}

/*
	Enter real and imaginary part of the complex number :5 10
	Enter real and imaginary part of the complex number :10 20

	The sum is : 15+30i
	The product is : -150+200i
*/