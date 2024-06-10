// Copyright 2024 Kaylee Walz
#include <hw3/inc/parse_demographics.h>
#include <iostream>
#include <string>
#include <cstddef>
#include <vector>


const std::string** ParseDemographics(const std::size_t rows,
                                      const std::size_t cols[],
                                      const std::string** values) {
    std::vector<const std::string*> demographics_vector;

    for (std::size_t i = 0; i < rows; ++i) {
        demographics_vector.push_back(new std::string(values[i][0]));

        std::string* birthday;
        std::string* ethnicities;

        std::size_t col_index = 1;

        while (col_index < cols[i] &&
              std::string("BE").find(values[i][col_index].front())
         != std::string::npos) {
            switch (values[i][col_index].front()) {
                case 'B': {
                    birthday = new std::string[3];
                    ++col_index;
                    birthday[0] = values[i][col_index];
                    ++col_index;
                    birthday[1] = values[i][col_index];
                    ++col_index;
                    birthday[2] = values[i][col_index];
                    ++col_index;
                    break;
                }
                case 'E': {
                    ++col_index;
                    std::size_t num_eth = std::stoi(values[i][col_index]);
                    if (num_eth == 0) {
                        ethnicities = nullptr;
                    } else {
                         if (col_index + num_eth < cols[i]) {
                            ethnicities = new std::string[num_eth];
                            for (std::size_t k = 0; k < num_eth; ++k) {
                                ethnicities[k] = values[i][++col_index];
                            }
                        }
                    }
                    ++col_index;
                    break;
                }
            }
        }
        if (birthday != nullptr) {
            demographics_vector.push_back(birthday);
        } else {
            demographics_vector.push_back(new std::string[3]{ "", "", "" });
        }

        if (ethnicities != nullptr) {
            demographics_vector.push_back(ethnicities);
        } else {
            demographics_vector.push_back(nullptr);
        }
    }
    // Convert vector to array
    const std::string** demographics =
    new const std::string*[demographics_vector.size()];
    for (std::size_t i = 0; i < demographics_vector.size(); ++i) {
        demographics[i] = demographics_vector[i];
    }

    return demographics;
}

