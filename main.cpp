#include <iostream>
#include <vector>

struct Cake {
    int weight;
    int value;
};

int maxDuffelBagValue(const std::vector<Cake> &cakes, int max_capacity) {
    int higher_value = 0;
    std::vector<int> capacities(max_capacity + 1, 0);
    for (int current_capacity = 1; current_capacity <= max_capacity; current_capacity++) {
        for (const auto &cake : cakes) {
            if (cake.weight <= current_capacity) {
                int higher_cake_value = (cake.value + capacities[current_capacity - cake.weight]);
                if (higher_cake_value > higher_value) {
                    higher_value = higher_cake_value;
                }
            }
        }
        capacities[current_capacity] = higher_value;
        std::cout << "higher_value of capacity " << current_capacity << " = " << higher_value << std::endl;
    }
    return higher_value;
}

int main() {
    std::vector<Cake> cakes{{7, 160}, {3, 90}, {2, 15}};
    int result = maxDuffelBagValue(cakes, 20);
    std::cout << "Result = " << result << std::endl;
    return EXIT_SUCCESS;
}