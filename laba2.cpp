#include <iostream>
using namespace std;

void krat(int a, int b);
class drob {
public:
    int x; int y;
    drob() {//констукторы:
        x = 1; y = 2;
    };//по умолчанию
    drob(int x, int y) {
       this -> x = x;
        if (y == 0) {
            cout << "error";
        }
        else {
            this -> y = y;
        }
    };//с параметрами 
    drob(const drob& a) {
        x = a.x;
        y = a.y;
    };// копирование
    ~drob() { }// деструктор
    void add(const drob& a);//добавление дробей
    void min(const drob& a);//вычитание
    void mno(const drob& a);//умножение
    void get_drob() {
        krat(x, y);
    }//вывод дроби
};
void drob::add(const drob& a) {
    cout << x << "/" << y << "+" << a.x << "/" << a.y << "=";
    if (y == a.y) {
        x += a.x;
        krat(x, y);
    }
    else {
        int i = y * a.y;
        int c = (i / y) * x;
        int d = (i / a.y) * a.x;
        x = c + d;
        y = i;
        krat(x, y);
    }
}
void drob::min(const drob& a) {
    cout << x << "/" << y << "-" << a.x << "/" << a.y << "=";
    if (y == a.y) {
        x -= a.x;
        krat(x, y);
    }
    else {
        int i = y * a.y;
        int c = (i / y) * x;
        int d = (i / a.y) * a.x;
        x = c - d;
        y = i;
        krat(x, y);
    }
}
void drob::mno(const drob& a) {
    cout << x << "/" << y << "*" << a.x << "/" << a.y << "=";
    x *= a.x;
    y *= a.y;
    krat(x, y);
}
class fulldrob : public drob
{
public:
    int c;
    fulldrob() {
        c = 1;
        drob();
    }
    fulldrob(int c, int x, int y) {
        this->c = c;
        this->x = x;
        this->y = y;
    }
    fulldrob(const fulldrob& a): drob(a) {
        c = a.c;
    }
    void get() {
        cout << c << "." << x << "/" << y << endl;
    }
};
int main() {
    drob x;
    x.get_drob();
    drob y(4, 5);
    y.get_drob();
    drob z(y);
    z.get_drob();
    x.min(y);
    y.add(z);
    z.mno(x);
    fulldrob a;
    a.get();
    fulldrob b(1,2,3);
    b.get();
    fulldrob c(b);
    c.get();
    return 0;
}
void krat(int a, int b) {
    int min = (a < b) ? a : b;
    if (a == b) {
        a = 1;
        b = 1;
        cout << "1" << endl;
    }
    else if (a % b == 0) {
        cout << a / b << endl;
    }
    else {
        for (int i = min; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            }
        }
        cout << a << "/" << b << endl;
    }
}