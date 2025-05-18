#include <iostream>
#include <vector>
#include <ctime>

// RollOutcome enumeration for game outcomes
enum class RollOutcome { natural, craps, seven_out, notpoint };

// Die class for rolling a single die
class Die {
public:
    Die() { std::srand(std::time(0)); } // Seed random number generator
    int roll() { return (std::rand() % 6) + 1; } // Random number from 1 to 6
};

// Roll class to manage a roll of two dice
class Roll {
private:
    int rolled_value;
public:
    Roll(Die& die1, Die& die2) { 
        rolled_value = die1.roll() + die2.roll();
    }
    int get_rolled_value() const { return rolled_value; }
};

// Shooter class to handle rolling dice
class Shooter {
private:
    std::vector<int> rolled_values;
    Die die1, die2;
public:
    Roll* throw_die() {
        Roll* roll = new Roll(die1, die2);
        rolled_values.push_back(roll->get_rolled_value());
        return roll;
    }
    void display_rolled_values() const {
        std::cout << "Rolled values: ";
        for (int val : rolled_values) std::cout << val << " ";
        std::cout << std::endl;
    }
};

// ComeOutPhase class to determine initial roll outcomes
class ComeOutPhase {
public:
    RollOutcome get_outcome(int rolled_value) {
        if (rolled_value == 7 || rolled_value == 11) return RollOutcome::natural;
        else if (rolled_value == 2 || rolled_value == 3 || rolled_value == 12) return RollOutcome::craps;
        return RollOutcome::notpoint;
    }
};

// PointPhase class to handle rolling in the point phase
class PointPhase {
private:
    int point;
public:
    PointPhase(int init_point) : point(init_point) {}

    RollOutcome get_outcome(int rolled_value) {
        if (rolled_value == 7) return RollOutcome::seven_out;
        else if (rolled_value == point) return RollOutcome::natural;
        return RollOutcome::notpoint;
    }
};