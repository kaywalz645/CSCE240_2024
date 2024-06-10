// Copyright 2024 Kaylee Walz
#ifndef HW3_INC_PARSE_DEMOGRAPHICS_H_
#define HW3_INC_PARSE_DEMOGRAPHICS_H_

#include <cstddef>
#include <string>

const std::string** ParseDemographics(const std::size_t rows,
                                      const std::size_t cols[],
                                      const std::string** values);
#endif  // HW3_INC_PARSE_DEMOGRAPHICS_H_
