// Copyright 2024 Kaylee
#include <iostream>
#include <string>
int main() {
    // std::string input; 
    
    // std::cin >> input;
    // std::cout << input << std::endl;


    std::cout << "<?xml version=\"1.0\"encoding=\"UTF-8\"?>";
    std::string demographics_id;
    std::cin >> demographics_id;
    std::cout << "\n<demographics id=\"" << demographics_id << "\">" << std::endl;
    int numOfPatients = 0;
    std::cin >> numOfPatients;

    // Patient Data
    std::string patientID;
    int birthMonth, birthDay, birthYear;
    std::string weight;
    int smoker;
    std::string ethnicity;

    // Identifiers
    std::string birthDateID = "B";
    std::string weightID = "W";
    std::string smokerID = "S";
    std::string ethnicityID = "E";


    for(int i = 0; i < numOfPatients; ++i){
        std::cin >> patientID;
        std::cout << "\t<patient id=\"" << patientID << "\">" << std::endl;
        std::string temp;
        std::cin >> temp;
        for(int ii = 0; i < 4; ++ii){
            if(temp == birthDateID){
                for(int iii = 0; i < 3; ++iii){
                    std::cin >> birthMonth;
                    std::cin >> birthDay;
                    std::cin >> birthYear;
                    std::cout << "<birthday>\n\t\t<month>" << birthMonth << "</month>\n\t\t" << birthYear
                    
                }
            }
// <patient id="FFFFF">
//     <birthday>
//       <month>3</month>
//       <day>1</day>
//       <year>2002</year>
//     </birthday>
//     <weight>144</weight>
//     <ethnicities>
//       <ethnicity id="N">American or Alaskan Native</ethnicity>
//     </ethnicities>
//   </patient>
            else if(temp == weightID){
                std::cin >> weight;
                std::cout << "<weight>" << weight << "</weight";
            }
            else if(temp == smokerID){
                std::cin >> smoker;
                if(smoker = 1){
                    std::cout << "<smoker />";
                }
            }
            else if(temp == ethnicityID){
                std::cin >> ethnicity;
            }
        }
    }
    return 0;
}
