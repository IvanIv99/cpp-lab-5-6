#include <algorithm>
#include "FlatClass.h"

Flat::Flat(): rooms(0), area(0), cost(0), population(0), floor(0) {}

Flat::Flat(int rooms, int area, int cost, int population, int floor)
        : rooms(rooms), area(area), cost(cost), population(population), floor(floor) {}

Flat::Flat(const Flat &other)
        : rooms(other.rooms), area(other.area), cost(other.cost), population(other.population), floor(other.floor) {}

Flat::~Flat() {}

double Flat::avg_cost(int N) {
    double total_cost = 0;
    int count = 0, flat_price;
    for (int i = 0; i < num_flats; ++i) {
        Flat& flat = flats[i];
        if (flat.area > N) {
            flat_price = flat.cost * flat.area;
            total_cost += flat_price;
            count++;
        }
    }
    return total_cost / count;
}

Flat* Flat::sorted_flats() {
    Flat* sorted_flats = new Flat[num_flats];
    for (int i = 0; i < num_flats; ++i) {
        sorted_flats[i] = flats[i];
    }
    std::sort(sorted_flats, sorted_flats + num_flats, [](const Flat &a, const Flat &b) {
        return (a.cost / a.population) < (b.cost / b.population);
    });
    return sorted_flats;
}

double Flat::avg_cost_floor(int N) {
    double total_cost = 0;
    int count = 0, flat_price;
    for (int i = 0; i < num_flats; ++i) {
        Flat& flat = flats[i];
        if (flat.floor == N) {
            flat_price = flat.cost * flat.area;
            total_cost += flat_price;
            count++;
        }
    }
    return total_cost / count;
}

void Flat::print_flat() const {
    std::cout << "Количество комнат: " << rooms << ", Площадь квартиры: " << area << ", Стоимость за м^2: " << cost
              << ", Количество проживающих: " << population << ", Этаж: " << floor << std::endl;
}

void Flat::edit_flat() {
    std::cout << "Введите новые значения:" << std::endl;
    std::cout << "Количество комнат: ";
    std::cin >> rooms;
    std::cout << "Площадь квартиры: ";
    std::cin >> area;
    std::cout << "Стоимость за м^2: ";
    std::cin >> cost;
    std::cout << "Количество проживающих: ";
    std::cin >> population;
    std::cout << "Этаж: ";
    std::cin >> floor;
}

Flat Flat::flats[] = {
        Flat(2, 75, 20000, 3, 2),
        Flat(3, 110, 25000, 2, 4),
        Flat(4, 150, 35000, 1, 7),
        Flat(5, 200, 50000, 4, 3),
        Flat(1, 45, 15000, 1, 6),

};

const int Flat::num_flats = sizeof(flats) / sizeof(flats[0]);