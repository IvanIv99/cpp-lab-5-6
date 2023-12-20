#include "FlatClass.h"
#include <iomanip>

int main() {
    Flat::flats[0].edit_flat();
    Flat::flats[0].print_flat();

    double average_cost = Flat::avg_cost(75);
    std::cout << "Средняя стоимость всех квартир площадью больше 75 м^2 составляет: "
              << std::fixed << std::setprecision(0) << average_cost << std::endl;

    Flat* sorted_flats = Flat::sorted_flats();
    std::cout << "Квартиры отсортированные по стоимости с человека: " << std::endl;
    for (int i = 0; i < Flat::num_flats; ++i) {
        sorted_flats[i].print_flat();
    }
    delete[] sorted_flats;

    double average_cost_floor = Flat::avg_cost_floor(4);
    std::cout << "Средняя стоимость квартир на 4-ом этаже составляет: "
              << std::fixed << std::setprecision(0) << average_cost_floor << std::endl;

    return 0;
}