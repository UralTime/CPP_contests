#include <cstdio>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <functional>
#include <string>
#include <sstream>
#include <iostream>

class Fabric 
{
    std::map <std::string, std::function <Figure*(std::string)> > mapa 
    {
        {"C", Circle::make},
        {"R", Rectangle::make},
        {"S", Square::make},
    };
public:
    Fabric() {}
    ~Fabric() {}
    std::unique_ptr<Figure> create_obj(const std::string &str) {
        std::istringstream input(str);
        std::string name, params;
        input >> name;
        std::getline(input, params);
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
        std::unique_ptr<Figure> cur_fig = factory_instance().create_obj(str);
        figures.push_back(std::move(cur_fig));
    }

    std::stable_sort (figures.begin(), figures.end(), 
            [] (auto &&a, auto &&b) { return a->get_square() < b->get_square(); } );

    for (const auto &fig: figures) {
        std::cout << fig->to_string() << std::endl;
    }
}