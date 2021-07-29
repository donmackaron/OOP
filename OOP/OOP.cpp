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
        double dist() {
            return sqrt(x * x + y * y);
        }
        void show() {
            std::cout << "Координаты точки в 2Д мире\n" << "x: " << x << " y: " << y <<std::endl;
        }
        void getinfo() {
            show();
            std::cout << dist() << std::endl;
        }
};

class point3d : public point2d {
public:
    double z;
    void set(double x1, double y1, double z1) {
    point2d::set(x1, y1);
        z = z1;
    }
    double dist() {
        return sqrt(x * x + y * y + z * z);
    }
    void show() {
        std::cout << "Координаты точки в 2Д мире\n" << "x: " << x << " y: " << y <<  " z: " << z << std::endl;
    }
    void getinfo() {
        show();
        std::cout << dist() << std::endl;
    }
};

void OOP();
void nasled();

int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "choice\n";
    std::cout << "1. OOP\n";
    std::cout << "2. наследованиеn\n";
    int choice;
    std::cout << "enter choice\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        OOP();
    case 2:
        nasled();
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
    point2d a;
    a.set(3,4);
    a.getinfo();
    point3d b;
    b. set(3, 4, 10);
    b.getinfo();
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
