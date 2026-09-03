#include <iostream>
using namespace std;

// Abstraction: Payment defines a common interface for all payment methods.
class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual ~Payment() {}
};
