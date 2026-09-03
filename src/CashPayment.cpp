#include <iostream>
using namespace std;

class CashPayment : public Payment {
private:
    double amountTendered;

public:
    CashPayment(double amountTendered)
        : amountTendered(amountTendered) {}

    bool pay(double amount) override {
        cout << "Cash payment required: Rs. " << amount << endl;
        cout << "Cash received: Rs. " << amountTendered << endl;

        if (amountTendered < amount) {
            cout << "Payment failed: insufficient cash." << endl;
            return false;
        }

        cout << "Payment successful." << endl;

        if (amountTendered > amount) {
            cout << "Change: Rs. " << amountTendered - amount << endl;
        }

        return true;
    }
};
