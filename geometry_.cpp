// geometry_.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


struct MyPoint
{
    MyPoint(double a, double b)
    {
        x = a;
        y = b;
    }
    MyPoint() {}
    double x;
    double y;
};

struct Vector
{
    Vector(double a, double b)
    {
        dir_x = a;
        dir_y = b;
    }
    Vector() {}

    double dir_x;
    double dir_y;
};

struct Line
{
    MyPoint p;
    Vector dir;

    Line() {}
    Line(const MyPoint& a, const Vector& b)
    {
        p = a;
        dir = b;
    }
};

bool intersect(const Line& l1, const Line& l2, MyPoint& intersection_point) {
    const MyPoint p1 = l1.p;
    const MyPoint p2 = l2.p;
    const Vector n1 = l1.dir;
    const Vector n2 = l2.dir;
    double u = (p1.y * n2.dir_x + n2.dir_y * p2.x - p2.y * n2.dir_x - n2.dir_y * p1.x) /
        (n1.dir_x * n2.dir_y - n1.dir_y * n2.dir_x);
    double v = (p1.x + n1.dir_x * u - p2.x) / n2.dir_x;

    intersection_point.x = p1.x + n1.dir_x * u;
    intersection_point.y = p1.y + n1.dir_y * u;

    return u > 0 && v > 0;
}

void intersection_line_circle(double r, double a, double b, double c)
{

    double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b) + 0.001)
        cout << "no points" << endl;
    else if (abs(c * c - r * r * (a * a + b * b)) < 0.001) {
        puts("1 point");
        cout << x0 << ' ' << y0 << '\n';
    }
    else {
        double d = r * r - c * c / (a * a + b * b);
        double mult = sqrt(d / (a * a + b * b));
        double ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
        puts("2 points");
        cout << "Points of intersection line and circle" << endl;
        cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
    }
}

//
int main(int argc, char* argv[]) {

    MyPoint p1(1, 1), p2(0, 2);
    Vector dir1(0, 1), dir2(1, 0);
    Line l1(p1, dir1);
    Line l2(p2, dir2);
    MyPoint intersection_point;
    if (intersect(l1, l2, intersection_point))
    {
        std::cout << "Lines intersect in [" << intersection_point.x << ", " << intersection_point.y << "]" << std::endl;
    }
    else
    {
        std::cout << "Lines do not intersect" << std::endl;
    }
    int r = 1; //dlya kola
    int a = 2; //dlya pryamoi
    int b = -1;
    int c = 1;
    intersection_line_circle(r, a, b, c);
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
