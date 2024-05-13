//Copyright Kaylee CSCE240 2024
//



#include <iostream> 
#include <string>

int main() {
    std::string input; 

    std::cin >> input;
    std:: cout << input << std::endl;

    int patient_no = 0;
    std::cin >> patient_no;
    std::cout << patient_no << std::endl;


    for(int i = 0; i < patient_no; ++i){
        std::string patient_id; 
        std::cout << "<patient id =\"" << patient_id << "something here..." << std::endl; //???
        std::string input_2;
        for(int ii=0 ;ii<12; ++ii){
            std::cin >> input_2;
            // std::cout << ?????
        }
    }
    std::cout << "\t</demographic";//????

    return 0;
}//sudo apt install build-essential 