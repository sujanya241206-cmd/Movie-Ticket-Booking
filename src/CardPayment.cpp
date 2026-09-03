#include <iostream>
#include <string>
using namespace std;

class CardPayment : public Payment {
private:
    string cardNumber;
    string cardType;

public:
    CardPayment(string cardNumber, string cardType)
        : cardNumber(cardNumber), cardType(cardType) {}

    bool pay(double amount) override {
        cout << "Processing " << cardType
             << " payment of Rs. " << amount << endl;

        if (cardNumber == "fail") {
            cout << "Payment failed." << endl;
            return false;
        }

        cout << "Payment successful." << endl;
        return true;
    }
};
