#include <iostream>
using namespace std;

void krat(int a, int b);
template<typename T>
class drob {
public:
    T x; T y;
    drob() {
        x = 1; y = 2;
    };
    drob(T x, T y) {
        this->x = x;
        if (y == 0) {
            cout << "error";
        }
        else {
            this->y = y;
        }
    };
    drob(const drob& a) {
        x = a.x;
        y = a.y;
    };
    ~drob() { }
    void add(const drob& a);
    void min(const drob& a);
    void mno(const drob& a);
    void get_drob() {
        cout << x << "/" << y;
    }
    friend drob operator +(drob const& a, drob const& b) {
        drob c;
        T i = a.y * b.y;
        T x = (i / a.y) * a.x;
        T y = (i / b.y) * b.x;
        c.x = x + y;
        c.y = i;
        return c;
    }
    drob& operator =(drob const& a) {
        x = a.x;
        y = a.y;
        return *this;
    }
    friend ostream& operator <<(ostream& a, const drob& b) {
        a <<"Drob:"<< b.x << "/" << b.y << endl;
        return a;
    }
    friend istream& operator >>(istream& a, drob& b) {
        a >> b.x >> b.y;
        return a;
    }
};
template<typename T> void drob<T>::add(const drob& a) {
    cout << x << "/" << y << "+" << a.x << "/" << a.y << "=";
    if (y == a.y) {
        x += a.x;
        cout << x << "/" << y << endl;
    }
    else {
        T i = y * a.y;
        T c = (i / y) * x;
        T d = (i / a.y) * a.x;
        x = c + d;
        y = i;
        cout << x << "/" << y << endl;
    }
}
template<typename T> void drob<T>::min(const drob& a) {
    cout << x << "/" << y << "-" << a.x << "/" << a.y << "=";
    if (y == a.y) {
        x -= a.x;
        cout << x << "/" << y << endl;
    }
    else {
        T i = y * a.y;
        T c = (i / y) * x;
        T d = (i / a.y) * a.x;
        x = c - d;
        y = i;
        cout << x << "/" << y << endl;
    }
}
template<typename T> void drob<T>::mno(const drob& a) {
    cout << x << "/" << y << "*" << a.x << "/" << a.y << "=";
    x *= a.x;
    y *= a.y;
    cout << x << "/" << y << endl;
}
int main() {
    drob<int> x;
    drob<double> y(2.333, 3.222);
    cout << x << y;
    drob<float> z;
    cin>> z;
    cout << z;
    return 0;
}