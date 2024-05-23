// Copyright 2024 CSCE 240
//
#include <hw2/inc/parse_demographics.h>

#include <cstddef>
#include <iostream>
#include <string>


const std::string kValues[] = {  // NOLINT: guide says char** when global const
  "71RF",
  "3",
  "34A5",
    "S", "0", //4, 5
    "B", "3", "1", "02", //6, 7, 8, 9
    "W", "138", //10, 11
    "E", "2", "W", "B", //12, 13, 14, 15
  "4B56", //16
    "W", "121", //17. 18
    "B", "10", "30", "98", //19, 20, 21, 22
    "E", "0", //23, 24
    "S", "1",
  "5607",
    "B", "1", "1", "70",
    "W", "0",
    "S", "0",
    "E", "3", "P", "A", "H"
};
const std::size_t kValSize = sizeof(kValues)/sizeof(std::string);
const std::string kPatientIds[] = { "34A5", "5607" };  // NOLINT: see above
const std::size_t kPatientIdsSize = 2;
const char kEthnicityValues[][3] = { { 'W', 'B', '\0'}, { 'P', 'A', 'H' } };
const std::size_t kEthnicityValuesSizes[] = { 2, 3 };
const std::string kPatientMissingEthnicities = "4B56";  // NOLINT: see above


bool TestParseEthnicityValues();
bool TestParseEthnicityValuesEmpty();
bool TestParseEthnicityValuesNoId();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing ParseEthnicityValues" << std::endl;
  if (TestParseEthnicityValues()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  std::cout << "Testing ParseEthnicityValues With Empty Array" << std::endl;
  if (TestParseEthnicityValuesEmpty()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  std::cout << "Testing ParseEthnicityValues With Missing Patient" << std::endl;
  if (TestParseEthnicityValuesNoId()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  return passed;
}

bool TestParseEthnicityValues() {
  bool passed = true;
  const std::size_t kEthnicityValuesSize = 8;
  char ethnicity_values[kEthnicityValuesSize];

  for (std::size_t i = 0; i < kPatientIdsSize; ++i) {
    const int expected = kEthnicityValuesSizes[i];
    const int actual = ParseEthnicityValues(kPatientIds[i],
                                            kValues,
                                            kValSize,
                                            ethnicity_values);
    if (expected != actual) {
      std::cout << "  " << kPatientIds[i] << " "
        << "Expected Number of Ethnicity Values: " << expected
        << ", Actual: " << actual << std::endl;
      passed = false;
    }

    for (std::size_t ii = 0; ii < kEthnicityValuesSizes[i]; ++ii)
      if (kEthnicityValues[i][ii] != ethnicity_values[ii]) {
        std::cout << "  " << kPatientIds[i] << " "
          << "Expected ethnicity_values["<< ii << "]: "
          << kEthnicityValues[i][ii]
          << ", Actual: " << ethnicity_values[ii] << std::endl;
        passed = false;
      }
  }

  return passed;
}


bool TestParseEthnicityValuesEmpty() {
  bool passed = true;
  const std::size_t kEthnicityValuesSize = 1;
  char ethnicity_values[kEthnicityValuesSize];
  ParseErrors result;

  const int expected = 0;
  const int actual = ParseEthnicityValues(kPatientMissingEthnicities,
                                          kValues,
                                          kValSize,
                                          ethnicity_values,
                                          &result);
  if (expected != actual) {
    std::cout << "  " << kPatientMissingEthnicities
      << " Expected Number of Ethnicity Values: " << expected
      << ", Actual: " << actual << std::endl;
    passed = false;
  }

  if (result != ParseErrors::kNoEthnicities) {
    std::cout << "  Expected ParseError: kNoEthnicities, Actual: "
      << ::ToString(result) << std::endl;
    passed = false;
  }

  return passed;
}


bool TestParseEthnicityValuesNoId() {
  bool passed = true;
  const std::size_t kEthnicityValuesSize = 1;
  char ethnicity_values[kEthnicityValuesSize];
  ParseErrors result;

  ParseEthnicityValues("000", kValues, kValSize, ethnicity_values, &result);

  if (result != ParseErrors::kMissingPatient) {
    std::cout << "  Expected ParseError: kMissingPatient, Actual: "
      << ::ToString(result) << std::endl;
    passed = false;
  }

  return passed;
}
