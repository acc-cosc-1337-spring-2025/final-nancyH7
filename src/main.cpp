#include <iostream>
#include <random>
#include <cassert>

class Die {
private:
    std::mt19937 rng;  // random number generator
    std::uniform_int_distribution<int> dist; // Uniform distribution between 1 and 6

public:
    // Constructor to seed RNG with a random device for true randomness
    Die() : rng(std::random_device{}()), dist(1, 6) {}

    // Roll the die and return a random value between 1 and 6
    int roll() {
        return dist(rng);
    }
};

void testDie() {
    Die die;
    
    for (int i = 0; i < 10; ++i) {
        int result = die.roll();
        assert(result >= 1 && result <= 6); // Ensure roll is within valid range
    }

    std::cout << "All die rolls passed the test!\n";
}

int main() {
    testDie();
    return 0;
}