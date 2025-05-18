#include <iostream>
#include <random>
#include <cassert>

class Roll {
private:
    std::mt19937 rng;  // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist; // Uniform distribution for a six-sided die

public:
    // Constructor to seed RNG
    Roll() : rng(std::random_device{}()), dist(1, 6) {}

    // Roll two dice and return the sum
    int rollDice() {
        return dist(rng) + dist(rng);
    }
};

void testRoll() {
    Roll roll;
    
    for (int i = 0; i < 10; ++i) {
        int result = roll.rollDice();
        assert(result >= 2 && result <= 12); // Validate result is in correct range
    }

    std::cout << "All dice rolls passed the test!\n";
}

int main() {
    testRoll();
    return 0;
}