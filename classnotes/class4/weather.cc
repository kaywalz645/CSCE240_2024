#include <weather.h>

#include <iostream>

int main (int argc, char* argv[]) {
    std::cout << "Wind Chill is " << CalcWindChill(2.0, 4.7) << std::endl;

    return 0;
}

double CalcWindChill(double, double) {
    return 0.0;
}