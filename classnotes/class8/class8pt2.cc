#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

//reads the same as  char string_int[]
int CharToInt(char *string_int, std::size_t size);

int main(int argc, char* argv[]) {
    std::cout << "Enter integer: " << std::endl;

    std::string string_int;
    std::cin >> string_int;

    int int_from_string = CharToInt(string_int.c_str(),std::strlen(string_int.c_str()));


    std::cout << "integer: " << string_int << std::endl;

    return 0;
}



int CharToInt(char *string_int, std::size_t size) {
    int result = 0; //have to zero out stack before running

    for(std::size_t i = 0; i < size; ++i) {
        result += static_cast<int>(string_int[size - i - 1] -'0') * std::pow(10, i);
        std::cout << "string_int[" << (size - i - 1) << "]: " << string_int[i] << std::endl;
    }

    return result;
}
