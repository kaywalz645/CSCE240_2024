// Copyright 2024 Kaylee Walz
#include <hw3/inc/parse_demographics.h>
#include <iostream>
#include <string>
#include <cstddef>
#include <vector>


const std::string** ParseDemographics(const std::size_t rows, 
                                      const std::size_t cols[],
                                      const std::string** values) {
    std::vector<const std::string*> demographics_vector; // Using a vector to manage memory easily

    for (std::size_t i = 0; i < rows; ++i) {
        // Add patient ID
        demographics_vector.push_back(new std::string(values[i][0]));
        std::cout << "---------NEW PATIENT: " << i << " ---------" << std::endl;

        for (std::size_t j = 1; j < cols[i]; ++j) {
            std::cout << "NEXT BOX: j: " << j << std::endl;
            switch (values[i][j].front()) {
                case 'B': {
                    std::cout << "Birthday Parse: j: " << j << std::endl;
                    std::string* birthday = new std::string[3];
                    if (j + 3 < cols[i]) { // Ensure there are enough elements
                        birthday[0] = values[i][++j];
                        birthday[1] = values[i][++j];
                        birthday[2] = values[i][++j];
                        demographics_vector.push_back(birthday);
                        std::cout << "hiiiiii " << j << std::endl;
                    } else {
                        std::cerr << "Error: Not enough elements for birthday" << std::endl;
                        delete[] birthday;
                    }
                    break;
                }
                case 'E': {
                    std::cout << "Ethnicities Parse: j: " << j << std::endl;
                    std::size_t n = std::stoi(values[i][++j]);
                    if (n == 0) {
                        demographics_vector.push_back(nullptr);
                    } else {
                         if (j + n < cols[i]) { // Ensure there are enough elements
                            std::string* ethnicities = new std::string[n];
                            for (std::size_t k = 0; k < n; ++k) {
                                ethnicities[k] = values[i][++j]; // Accessing the next element correctly
                            }
                            demographics_vector.push_back(ethnicities);
                        } else {
                            std::cerr << "Error: Not enough elements for ethnicities" << std::endl;
                        }
                    }
                    break;
                }
                default:
                    std::cerr << "Unexpected value type: " << values[i][j].front() << std::endl;
                    break;
            }
        }
    }

    // Convert vector to array
    const std::string** demographics = new const std::string*[demographics_vector.size()];
    for (std::size_t i = 0; i < demographics_vector.size(); ++i) {
        demographics[i] = demographics_vector[i];
    }

    return demographics;  
}


//  {
//  "34A5",
//  "B", "3", "1", "02",
//  "E", "2", "W", "B"
//   }
//  }
//   - or -
//  {
//  "34A5",
//     "E", "1", "B"
//     "B", "3", "1", "02",
//   }, {
//   "5607",
//     "B", "1", "1", "70",
//     "E", "3", "P", "A", "H"
//   }, {
//   "4B56",
//     "E", "0",
//     "B", "10", "30", "98",
//   }
// }