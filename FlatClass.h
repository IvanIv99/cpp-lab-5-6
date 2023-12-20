#include <iostream>

class Flat {
public:
    int rooms;
    int area;
    int cost;
    int population;
    int floor;

    Flat();
    Flat(int rooms, int area, int cost, int population, int floor);
    Flat(const Flat &other);
    ~Flat();

    static double avg_cost(int N);
    static Flat* sorted_flats();
    static double avg_cost_floor(int N);

    void print_flat() const;
    void edit_flat();

    static Flat flats[];
    static const int num_flats;
};
