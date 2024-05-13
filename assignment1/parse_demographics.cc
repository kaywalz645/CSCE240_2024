// Copyright 2024 Kaylee
#include <iostream>
#include <string>
int main() {
    std::string inputLine;
    std::cout << "<demographics>\n";

    // Read until end of input
    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) continue;  // Skip empty lines

        std::cout << "\t<patient>\n";

        // Parse patient data
        String patientID;

        int birthMonth, birthDay, birthYear, weight, smoker;
        std::string ethnicity;

        std::sscanf(inputLine.c_str(), "patient id %d B %d %d %d W %d S %d E", 
            &patientID, &birthMonth, &birthDay, &birthYear, &weight, &smoker);

        std::cout << "\t\t<patient_id>" << patientID << "</patient_id>\n";
        std::cout << "\t\t<birth_date>" << birthMonth << "/" << birthDay << "/" << birthYear << "</birth_date>\n";
        std::cout << "\t\t<weight>" << weight << " lbs</weight>\n";
        std::cout << "\t\t<smoker>" << (smoker == 1 ? "smoker" : "non-smoker") << "</smoker>\n";
        std::cout << "\t\t<ethnicities>\n";

        // Read and output ethnicities
        while (std::cin >> inputLine && inputLine != "...") {
            std::cout << "\t\t\t<ethnicity>" << inputLine << "</ethnicity>\n";
        }

        std::cout << "\t\t</ethnicities>\n";
        std::cout << "\t</patient>\n";
    }

    std::cout << "</demographics>\n";

    return 0;

}
