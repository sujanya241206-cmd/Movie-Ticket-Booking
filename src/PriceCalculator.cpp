#include <iostream>
#include <string>
using namespace std;

class PriceCalculator {
private:
    static const int SILVER_PRICE = 150;
    static const int GOLD_PRICE = 250;
    static const int PLATINUM_PRICE = 400;

public:
    int calculatePrice(string seatType) {
        if (seatType == "SILVER") {
            return SILVER_PRICE;
        }
        else if (seatType == "GOLD") {
            return GOLD_PRICE;
        }
        else if (seatType == "PLATINUM") {
            return PLATINUM_PRICE;
        }

        return 0;
    }

    // Compile-time polymorphism: function overloading.
    int calculatePrice(int silverSeats, int goldSeats, int platinumSeats) {
        return silverSeats * SILVER_PRICE
             + goldSeats * GOLD_PRICE
             + platinumSeats * PLATINUM_PRICE;
    }
};
