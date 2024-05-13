// Copyright 2024 Kaylee
#include <iostream>
#include <string>
int main() {
    std::cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    std::string demographics_id;
    std::cin >> demographics_id;
    std::cout << "\n<demographics id=\""
    << demographics_id << "\">" << std::endl;
    int numOfPatients = 0;
    std::cin >> numOfPatients;
    std::cout << numOfPatients << std::endl;

    // Patient Data
    std::string patientID;
    int birthMonth, birthDay, birthYear;
    std::string weight;
    int smoker;
    int ethnicity;

    // Identifiers
    std::string birthDateID = "B";
    std::string weightID = "W";
    std::string smokerID = "S";
    std::string ethnicityID = "E";


    for (int i = 0; i < numOfPatients; ++i) {
        std::cin >> patientID;
        std::cout << "\t<patient id=\"" << patientID << "\">" << std::endl;
        for (int ii = 0; ii < 4; ++ii) {
            std::string temp;
            std::cin >> temp;
            if (temp == birthDateID) {
                    std::cin >> birthMonth;
                    std::cin >> birthDay;
                    std::cin >> birthYear;
                    if (birthYear > 24) {
                        birthYear += 1900;
                    } else if (birthYear <= 24) {
                        birthYear += 2000;
                    }
                    std::cout << "\t<birthday>\n\t\t<month>" << birthMonth
                    << "</month>\n\t\t<day>" << birthDay <<
                    "</day>\n\t\t<year>" << birthYear <<
                    "</year>\n\t</birthday>" << std::endl;
            } else if (temp == weightID) {
                std::cin >> weight;
                std::cout << "\t<weight>" << weight << "</weight>" << std::endl;
            } else if (temp == smokerID) {
                std::cin >> smoker;
                if (smoker == 1) {
                    std::cout << "\t<smoker />" << std::endl;
                }
            } else if (temp == ethnicityID) {
                std::cin >> ethnicity;
                std::cout << "\t<ethnicities>" << std::endl;
                for (int iv = 0; iv < ethnicity; ++iv) {
                    std::string t;
                    std::cin >> t;
                    if (t == "N") {
                        std::cout << "\t<ethnicity id=\""<< t <<
                        "\">American or Alaskan Native</ethnicity>"
                        << std::endl;
                    } else if (t == "A") {
                        std::cout << "\t<ethnicity id=\""<< t <<
                        "\">Asian</ethnicity>" << std::endl;
                    } else if (t == "B") {
                        std::cout << "\t<ethnicity id=\""<< t <<
                        "\">African American</ethnicity>" << std::endl;
                    } else if (t == "H") {
                        std::cout << "\t<ethnicity id=\""<< t <<
                        "\">Hispanic</ethnicity>" << std::endl;
                    } else if (t == "P") {
                        std::cout << "\t<ethnicity id=\""<< t <<
                        "\">Native Islander</ethnicity>" << std::endl;
                    } else if (t == "W") {
                        std::cout << "\t<ethnicity id=\""<< t <<
                        "\">White</ethnicity>" << std::endl;
                    }
                }
                std::cout << "\t</ethnicities>" << std::endl;
            }
        }
        std::cout << "\t</patient>" << std::endl;
    }
    std::cout << "\n</demographics>" << std::endl;
    return 0;
}
