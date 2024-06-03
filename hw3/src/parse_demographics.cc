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
        std::cout << "---------NEW PATIENT: " << i << " ---------" << std::endl;

        demographics_vector.push_back(new std::string(values[i][0])); 
    
        std::vector<std::string> dob;
        std::vector<std::string> ethnicities;

        std::size_t col_index = 1; //starts at the next index hopefully

        while(col_index < cols[i] && std::string("BE").find(values[i][col_index].front())
         != std::string::npos) {
            switch (values[i][col_index].front()) {
                case 'B': {
                    std::cout << "Birthday Parse: j: " << col_index << std::endl;
                    std::string* birthday = new std::string[3];
                        ++col_index; //move to month
                        birthday[0] = values[i][col_index];
                        ++col_index; //move to date
                        birthday[1] = values[i][col_index];
                        ++col_index; //move to year
                        birthday[2] = values[i][col_index];
                        demographics_vector.push_back(birthday);
                        ++col_index; //move to E 
                    break;
                }
                case 'E': {
                    ++col_index; //move to number of E
                    std::cout << "Ethnicities Parse: j: " << col_index << std::endl;
                    std::size_t num_eth = std::stoi(values[i][col_index]); //parse num of e
                    if (num_eth == 0) {
                        demographics_vector.push_back(nullptr);
                    } else {
                         if (col_index + num_eth < cols[i]) { // Ensure there are enough elements
                            std::string* ethnicities = new std::string[num_eth];
                            for (std::size_t k = 0; k < num_eth; ++k) {
                                ethnicities[k] = values[i][++col_index]; //for each ethnicity save value
                            }
                            demographics_vector.push_back(ethnicities); //after finished save
                        } else {
                            std::cerr << "Error: Not enough elements for ethnicities" << std::endl;
                        }
                    }
                    ++col_index; //move to next value like E or ID
                    break;
                }
                default: {
                    std::cerr << "Unexpected value type: " << values[i][col_index].front() << std::endl;
                    break;
                }
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