#include <iostream>
#include <string>
using namespace std;

class UpiPayment : public Payment {
private:
    string upiId;

public:
    UpiPayment(string upiId)
        : upiId(upiId) {}

    bool pay(double amount) override {
        cout << "Processing UPI payment of Rs. " << amount << endl;
        cout << "UPI ID: " << upiId << endl;

        if (upiId == "fail") {
            cout << "Payment failed." << endl;
            return false;
        }

        cout << "Payment successful." << endl;
        return true;
    }
};
