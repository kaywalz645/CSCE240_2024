#include <iostream>

//learning derefrencing pointers
//creating int and doubles; using pointers to manipulate values

int main(int argc, char* argv[]) {
    std::cout << "some pointers" << std::endl;

    //pointer
    void *dyn_void;
    int *dyn_int;
    double *dyn_dbl;
    char *dyn_char = nullptr;

    //values
    int auto_int = 17;
    double auto_dbl = 3.14159;
    char auto_char = 'X';

    //changing pointer dyn's to the address of the auto's 
    //(pointer stores addresses(duh))
    dyn_int = &auto_int;
    dyn_dbl = &auto_dbl;
    dyn_char = &auto_char;

    std::cout << "dyn_int" << dyn_int << std::endl;
    std::cout << "dyn_dbl" << dyn_dbl << std::endl;
    std::cout << "dyn_char" << dyn_char << std::endl; 

    //char being weird so we stopped using it
    *dyn_int += 1;
    *dyn_dbl += 1;


    std::cout << "*dyn_int" << dyn_int << std::endl;
    std::cout << "*dyn_dbl" << dyn_dbl << std::endl;

    dyn_int = new int(29);
    dyn_dbl = new double(3.34159);

    //creating the int without deleting it would be a memory leak
    delete dyn_int;
    dyn_int = new int(1024); 



    return 0;
}