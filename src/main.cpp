#include <iostream>
#include <cassert>

// Enum to define possible roll outcomes
enum class RollOutcome {
    natural,    // 7 or 11 (ComeOutPhase)
    craps,      // 2, 3, or 12 (ComeOutPhase)
    point,      // Any other (ComeOutPhase) or matching point (PointPhase)
    seven_out,  // 7 rolled in PointPhase
    nopoint     // Any roll except point and 7 in PointPhase
};

// Abstract base class
class Phase {
public:
    virtual RollOutcome getOutcome(int rolled_value) const = 0; // Pure virtual method
    virtual ~Phase() = default; // Virtual destructor
};

// Derived ComeOutPhase class
class ComeOutPhase : public Phase {
public:
    RollOutcome getOutcome(int rolled_value) const override {
        if (rolled_value == 7 || rolled_value == 11) return RollOutcome::natural;
        else if (rolled_value == 2 || rolled_value == 3 || rolled_value == 12) return RollOutcome::craps;
        else return RollOutcome::point;
    }
};

// Derived PointPhase class
class PointPhase : public Phase {
private:
    int point; // Stores the point value

public:
    explicit PointPhase(int point_value) : point(point_value) {}

    RollOutcome getOutcome(int rolled_value) const override {
        if (rolled_value == point) return RollOutcome::point;
        else if (rolled_value == 7) return RollOutcome::seven_out;
        else return RollOutcome::nopoint;
    }
};

// Test function for ComeOutPhase
void testComeOutPhase() {
    ComeOutPhase phase;
    assert(phase.getOutcome(7) == RollOutcome::natural);
    assert(phase.getOutcome(11) == RollOutcome::natural);
    assert(phase.getOutcome(2) == RollOutcome::craps);
    assert(phase.getOutcome(3) == RollOutcome::craps);
    assert(phase.getOutcome(12) == RollOutcome::craps);
    assert(phase.getOutcome(4) == RollOutcome::point);
    assert(phase.getOutcome(10) == RollOutcome::point);
    std::cout << "ComeOutPhase tests passed!\n";
}

// Test function for PointPhase
void testPointPhase() {
    PointPhase phase(5); // Set point value to 5
    assert(phase.getOutcome(5) == RollOutcome::point);
    assert(phase.getOutcome(7) == RollOutcome::seven_out);
    assert(phase.getOutcome(4) == RollOutcome::nopoint);
    assert(phase.getOutcome(9) == RollOutcome::nopoint);
    std::cout << "PointPhase tests passed!\n";
}

int main() {
    testComeOutPhase();
    testPointPhase();
    return 0;
}