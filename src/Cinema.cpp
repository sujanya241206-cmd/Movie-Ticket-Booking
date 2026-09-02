#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Screen;

class Cinema {
private:
    string name;
    vector<Screen*> screens;

public:
    Cinema(string name)
        : name(name) {}

    string getName() {
        return name;
    }

    void addScreen(Screen* screen) {
        screens.push_back(screen);
    }

    vector<Screen*> getScreens() {
        return screens;
    }
};