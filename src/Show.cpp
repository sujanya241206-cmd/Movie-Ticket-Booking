#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie;
class Screen;
class ShowSeat;

class Show {
private:
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat*> showSeats;

public:
    Show(Movie* movie, Screen* screen, string startTime)
        : movie(movie), screen(screen), startTime(startTime) {}

    Movie* getMovie() {
        return movie;
    }

    Screen* getScreen() {
        return screen;
    }

    string getStartTime() {
        return startTime;
    }

    void addShowSeat(ShowSeat* showSeat) {
        showSeats.push_back(showSeat);
    }

    vector<ShowSeat*> getShowSeats() {
        return showSeats;
    }
};