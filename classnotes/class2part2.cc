

#include <iostream>
#include <string> 


int main(int argc, char* argv[]){
    // array of unknown size of character strings
    //argc >> argument count
    double input;
    std::cout << "enter your values";
    std::cin >> input;

    
    double guess = 0.5 * input;

    double root = input / guess;

    guess = 0.5*(guess + root);

    root = input / guess;

    std::cout << "root: " << root << std::endl;
}
