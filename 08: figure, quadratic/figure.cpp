#include <cmath>
#include <cstdio>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <functional>
#include <string>
#include <iostream>

class Figure
{
    double a;
public:
    Figure() {};
    virtual ~Figure() {};
    virtual double get_square() const { return a * a; };
};

class Rectangle: Figure
{
    double a, b;
public:
    Rectangle (double aa, double bb): a(aa), b(bb) {};
    static Rectangle *make (const std::string &str) {
        double aa, bb;
        sscanf(str.c_str(), "%lf %lf", &aa, &bb);
        return new Rectangle(aa, bb);
    }
    virtual double get_square() const override { return a * b; };
};

class Square: Figure
{
    double a;
public:
    Square (double aa): a(aa) {};
    static Square *make (const std::string &str) {
        double aa;
        sscanf(str.c_str(), "%lf", &aa);
        return new Square(aa);
    }
    virtual double get_square() const override { return a * a; };
};

class Circle: Figure
{
    double r;
public:
    Circle (double rr): r(rr) {};
    static Circle *make (const std::string &str) {
        double rr;
        sscanf(str.c_str(), "%lf", &rr);
        return new Circle(rr);
    }
    virtual double get_square() const override { 
        constexpr double pi = 4 * atan(1); 
        return pi * r * r; 
    };
};

class Fabric 
{
public:
    std::map <std::string, std::function <Figure*(std::string)> > mapa 
    {
        {"C", Circle::make},
        {"R", Rectangle::make},
        {"S", Square::make},
    };
    Fabric() {}
    ~Fabric() {}
    std::unique_ptr<Figure> create_obj(std::string name, const std::string params) {
        std::unique_ptr<Figure> cur_fig = static_cast<std::unique_ptr<Figure>>(mapa[name](params));
        return cur_fig;
    }
};

static Fabric& factory_instance()
{
    static Fabric f;
    return f;
}

int main()
{
    std::vector <std::unique_ptr<Figure> > figures;

    std::string str;
    while (std::getline(std::cin, str)) {
        std::unique_ptr<Figure> cur_fig = factory_instance().create_obj(std::string(1, str[0]), 
                str.substr(2));
        figures.push_back(std::move(cur_fig));
    }

    std::stable_sort (figures.begin(), figures.end(), 
            [] (auto &&a, auto &&b) { return a->get_square() < b->get_square(); } );

    for (const auto &fig: figures) {
        std::cout << fig->get_square() << std::endl;
    }
}