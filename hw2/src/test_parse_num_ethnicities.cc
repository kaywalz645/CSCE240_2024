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
    "S", "0",
    "B", "3", "1", "02",
    "W", "138",
    "E", "2", "W", "B",
  "4B56",
    "W", "121",
    "B", "10", "30", "98",
    "E", "0",
    "S", "1",
  "5607",
    "B", "1", "1", "70",
    "W", "0",
    "S", "0",
    "E", "3", "P", "A", "H"
};
const std::size_t kValSize = sizeof(kValues)/sizeof(std::string);
const std::string kPatientIds[] = { "34A5", "4B56", "5607" };  // NOLINT: see ^
const std::size_t kPatientIdsSize = 3;
const int kEthnicityNums[] = { 2, 0, 3 };
const char* kPatientNoId = "4B56";


bool TestParseNumEthnicities();
bool TestParseNumEthnicitiesEmpty();
bool TestParseNumEthnicitiesNoId();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing ParseNumEthnicities" << std::endl;
  if (TestParseNumEthnicities()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  std::cout << "Testing ParseNumEthnicities With Empty Array" << std::endl;
  if (TestParseNumEthnicitiesEmpty()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  std::cout << "Testing ParseNumEthnicities With Missing Patient" << std::endl;
  if (TestParseNumEthnicitiesNoId()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  return passed;
}

bool TestParseNumEthnicities() {  // true when correct number of students parsed
  bool passed = true;
  for (std::size_t i = 0; i < kPatientIdsSize; ++i) {
    const int expected = kEthnicityNums[i];
    const int actual = ParseNumEthnicities(kPatientIds[i], kValues, kValSize);
    if (expected != actual) {
      std::cout << "  " << kPatientIds[i] << "-"
        << "Expected Number of Ethnicities: " << expected
        << ", Actual: " << actual << std::endl;
      passed = false;
    }
  }

  return passed;
}


bool TestParseNumEthnicitiesEmpty() {  // true when return is 0 and result is
  bool passed = true;                  //   ParseErrors::kNoEthnicities
  ParseErrors result;
  const std::size_t expected = 0;
  const std::size_t actual = ParseNumEthnicities(kPatientNoId,
                                                 kValues,
                                                 kValSize,
                                                 &result);
  if (expected != actual) {
    std::cout << "  " << kPatientNoId << "-Expected Number of Ethnicities: "
      << expected << ", Actual: " << actual << std::endl;
    passed = false;
  }

  if (result != ParseErrors::kNoEthnicities) {
    std::cout << "  " << kPatientNoId
      << "-Expected ParseError: kNoEthnicities Actual: " << ::ToString(result)
      << std::endl;
    passed = false;
  }

  return passed;
}


bool TestParseNumEthnicitiesNoId() {  // true when result is
  bool passed = true;                 //   ParseErrors::kMissingPatient
  ParseErrors result;
  ParseNumEthnicities("000", kValues, kValSize, &result);

  if (result != ParseErrors::kMissingPatient) {
    std::cout << "  000-Expected ParseError: kMissingPatient, Actual: "
      << ::ToString(result) << std::endl;
    passed = false;
  }

  return passed;
}
