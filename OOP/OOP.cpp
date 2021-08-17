// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


class depozit {
private:
    std::string name;
    double money;
    double stavka;
    int years;
    double dep(double m, double r, int t) {
        double res = m;
        for (int i = 0; i < t; i++) {
            res = res * (1 + (r / 100));
        }
        return res;
    }
    void showtable(bool style = false) {
        std::cout << "| name  \t" << "| money\t" << "| time\t";
        if (style) {
            std::cout << "| sum\t" << "| time\t";
        }
            std::cout << "| % \t" << "| value |\n";
    }
    void showdata(double m, int t) {
        std::cout << "| " << name << "  \t";
        std::cout << "| " << money << "\t";
        std::cout << "| " << years << "\t";
        std::cout << "| " << m << "\t";
        std::cout << "| " << years - t << "\t";
        std::cout << "| " << stavka << "\t";
        std::cout << "| " << result(m,t) << " \n";
        std::cout << std::endl;
    }
    void showdata() {
        std::cout << "| " << name << "\t";
        std::cout << "| " << money << "\t";
        std::cout << "| " << years << "\t";
        std::cout << "| " << stavka << "\t";
        std::cout << "| " << result() << " \n";
        std::cout << std::endl;
    }
    double result() {
        return dep(money, stavka, years);
    }
    double result(double m, int t) {
        double m1, m2;
        m1 = dep(money, stavka, years);
        if (t > years) {
            return m1;
        }
        else {
            m2 = dep(m, stavka, years - t);
            return m1 + m2;
        }
    }
public:
    void setall(std::string n , double m , double r, int t) {
        name = n;
        money = m;
        stavka = r;
        years = t;
    }
    void show(double m, int t) {
        showtable(true);
        showdata(m,t);
    }
    void show(double m) {
        showdata(m, 1);
    }
    void show() {
        showtable();
        showdata();
    }
    depozit(std::string n ="anonim", double m=0, double s=0, int y=0) {
        setall(n, m, s, y);
        //show();
    }
    depozit operator+(int t) {
        depozit tmp;
        tmp.setall(name, money, stavka, years + t);
        return tmp;
    }
    depozit operator+(double m) {
        depozit tmp;
        tmp.setall(name, money + m, stavka, years);
        return tmp;
    }
    depozit operator*(double x) {
        depozit tmp;
        tmp.setall(name, money, stavka + x, years);
        return tmp;
    }
    double operator!() {
        return result();
    }
    double operator-(depozit tmp) {
        return result() - !tmp;
    }
};

class point2d {
    public :
        double x;
        double y;
        void set(double x1, double y1) {
            x = x1;
            y = y1;
        }
       virtual double dist() {
            return sqrt(x * x + y * y);
        }
       void show() {
            std::cout << "Координаты точки в 2Д мире\n" << "x: " << x << " y: " << y <<std::endl;
        }
        virtual void getinfo() {
            show();
            std::cout << dist() << std::endl;
        }
        point2d(double x1, double y1) {
            set(x1, y1);
            getinfo();
        }
};

class point3d : public point2d {
public:
    using point2d::set;
    double z;
    void set(double x1, double y1, double z1) {
    set(x1, y1);
        z = z1;
    }
    double dist() {
        return sqrt(x * x + y * y + z * z);
    }
    void show() {
        std::cout << "Координаты точки в 3Д мире\n" << "x: " << x << " y: " << y <<  " z: " << z << std::endl;
    }
    point3d(double x1, double y1, double z1) : point2d( x1,  y1) {
        set(x1, y1, z1);
        getinfo();
    }
    
};

class base {
public:
    double pi;
    double s2;
    double s3;
    double size;
    std::string name;
    virtual double volum() = 0;
    virtual double area() = 0;
    void set(double l, std::string figure) {
        size = l;
        name = figure;
    }
    void show() {
        std::cout << "Данные фигуры: " << name << std::endl;
        std::cout << "объём: " << volum() << std::endl;
        std::cout << "площадь: " << area() << std::endl;
    }
    base(double l, std::string figure) {
        pi = 3.14;
        s2 = sqrt(2);
        s3 = sqrt(3);
        set(l, figure);
        
    }
};

class qube : public base {
public:
    qube(double l) : base(l, "куб") {
        show();
    }
    double volum() {
        return size *size*size;
    }
    double area() {
        return 6 * size * size;
    }
};

class sphere : public base {
public:
    sphere(double l) :base(l, "Сфера") {
        show();
    }
    double volum() {
        return (4 * pi * size * size * size) / 3;
    }
    double area() {
        return 4 * pi * size * size;
    }
};

class tetraeder : public base {
public:
    tetraeder(double l) : base(l, "тетраедер") {
        show();
    }
    double volum() {
        return ( s2 * size * size * size) / 12;
    }
    double area() {
        return s3 * size * size;
    }
};

class Base {
public:
    std::string name;
    virtual void show() {
        std::cout << "class Base" << name << std::endl;
    }
};

class alpha : public Base {
public:
    void show() {
        std::cout << "class alpha" << name << std::endl;
    }
    void names() {
        name = " names alpha";
        show();
    }
};

class beta : public Base {
public:
    void show() {
        std::cout << "class beta" << name << std::endl;
    }
};

class swapster {
public:
    std::string name;
    swapster(std::string txt) {
        name = txt;
    }
    void show() {
        std::cout << "name class" << name<<std::endl;
    }
    void swap(swapster &obj) {
        std::cout << "before swap" << std::endl;
        show();
        obj.show();
        std::string txt;
        txt = obj.name;
        obj.name = name;
        name = txt;
        std::cout << "after swap" << std::endl;
        show();
        obj.show();
    }
};

void OOP();
void nasled();
void figure();
void reference();
void swaping();

int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "choice\n";
    std::cout << "1. OOP\n";
    std::cout << "2. наследование\n";
    std::cout << "3. Площадь фигуры\n";
    std::cout << "4. ССылка\n";
    std::cout << "5. Обмен данными между объектами\n";
    int choice;
    std::cout << "enter choice\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        OOP();
        break;
    case 2:
        nasled();
        break;

    case 3:
        figure();
        break;
    case 4:
        reference();
        break;
    case 5:
        swaping();
        break;
    default :
        break;
    }
}

void OOP() {
    depozit creator("lolkek", 100, 10, 5);
    std::cout << "creator\n";
    creator.show();
    depozit fellow;
    fellow = creator + 2;
    std::cout << "fellow\n";
    fellow.show();
    fellow = creator + 100.1;
    std::cout << "fellow\n";
    fellow.show();
    std::cout << "fellow\n";
    ((creator + 25.0) * 4).show();
    std::cout << "fellow\n";
    fellow.show();
    std::cout << "creator\n";
    creator.show();
    creator = creator + 2;
    std::cout << "creator\n";
    creator.show();
    std::cout << "creator\n";
    ((creator + 5.0) * 2).show();
    std::cout << "creator\n";
    creator.show();
    double dif = fellow - creator;
    double diff = creator - fellow;
    std::cout << dif << " " << diff;
    std::cout << std::endl;
}

void nasled() {
    point2d a(3,4);
    
    point3d b(3, 4, 10);
    
    point2d c(2, 5);
}

void figure() {
    qube cube(10);
    sphere sph(10);
    tetraeder tet(10);

}

void reference() {
    Base obj;
    alpha obja;
    beta objB;
    obj.name = " Base";
    obj.show();
    obja.name = " alpha";
    obja.show();
    objB.name = " Beta";
    objB.show();
    Base& ref = obj;
    Base& ref1 = obja;
    Base& ref2 = objB;
    obj.name = " Base1";
    obja.name = " alpha1";
    objB.name = " Beta1";
    ref.show();
    ref1.show();
    ref2.show();
    obj = obja;
    obj.show();
    obja.names();
    
}

void swaping() {
    swapster A("red");
    swapster B("Green");
    A.show();
    B.show();
    A.swap(B);
    A.show();
    B.show();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
