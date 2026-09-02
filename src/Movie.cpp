#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string language;
    int duration;

public:
    Movie(string title, string language, int duration)
        : title(title), language(language), duration(duration) {}

    string getTitle() {
        return title;
    }

    string getLanguage() {
        return language;
    }

    int getDuration() {
        return duration;
    }
};