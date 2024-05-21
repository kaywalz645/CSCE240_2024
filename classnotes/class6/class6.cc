//stoi 

#include <cstddef>
#include <iostream>
#include <ctime>

std::size_t Min(double data[], std::size_t size); //declaration for c++ :)

std::size_t Max(const double data[], std::size_t size); //declaration for c++ :)


int main (int agrc, char* argv[]){
    std::srand(std::time(nullptr));
    std::cout << "Process some arrays!" << std::endl;

    const std::size_t kSize = 10;
    int int_array[kSize];
     //here v
    for(int i = 0; i < kSize; ++i){ //compiler will complain bc this int i is signed and kSize is not signed 
        int_array[i] = std:: rand() % 100;
        std::cout << int_array[i] << std::endl;
    }
    return;
}

std::size_t Max(const double data[], std::size_t size){ //const data is read only data, you do not want to change consts
    int max = 0; //cant look up the value of an array(c++ is not introspective like java)
                 //so you have to give the size to the function 
                 //this is why we include this -> (std::size_t size)
                    
    for (std::size_t i = 0; i < size; ++i){
        if(data[max] < data[i]){ //compares the index of the largest value(assuming the largest value is in index 0)
            max = i;             // with the values of the rest of the indexes and if the later index is larger then i is now the index of the max value
        }
    }
}


// different example, didn't feel like making 
// another file for such a small example


// #include <cstddef>
// #include <iostream>
// int main (int agrc, char* argv[]){

//     std::cout << "errors in size" << std::endl;
//     const std::size_t kSize = 10;
//     int int_array[kSize];

//     for(std::size_t i = 0; i < kSize; ++i){
//         int_array[i] = i + 1;
//         std::cout << "int_array[" << i << "]:" << int_array[i] << std::endl;
//     }
// }