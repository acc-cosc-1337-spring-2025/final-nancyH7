#include <iostream>
#include <random>
#include <vector>
#include <cassert>

class Roll {
private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;

public:
    Roll() : rng(std::random_device{}()), dist(1, 6) {}

    int rollDice() {
        return dist(rng) + dist(rng);
    }
};

class Shooter {
private:
    std::vector<Roll*> rolls; // Stores dynamically allocated Roll instances

public:
    ~Shooter() {
        // Clean up dynamically allocated memory
        for (auto roll : rolls) {
            delete roll;
        }
    }

    Roll* shoot() {
        Roll* roll = new Roll(); // Dynamically allocate Roll instance
        rolls.push_back(roll);   // Store in vector
        return roll;             // Return pointer to Roll instance
    }
};

void testShooter() {
    Shooter shooter;

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.shoot(); // Get a dynamically allocated Roll instance
        int result = roll->rollDice();
        assert(result >= 2 && result <= 12); // Ensure valid roll range
    }

    std::cout << "All shooter tests passed!\n";
}

int main() {
    testShooter();
    return 0;
}