// Copyright 2024 CSCE 240
//
#include <hw2/inc/parse_demographics.h>

#include <cstddef>
#include <iostream>
#include <string>


const std::string kValues[] = {  //NOLINT: guide says char** when global const,
  "71RF",                        //        but I want std::strings for testing
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
const std::size_t kSize = sizeof(kValues)/sizeof(std::string);
const std::size_t kPatientNum = 3;

const std::string kEmptyValues[] = {  // NOLINT: see above
  "83ZK",
  "0"
};
const std::size_t kEmptySize = 2;

bool TestParseNumPatients(std::size_t expected);
bool TestParseNumNoPatients();

int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing ParseNumPatients" << std::endl;
  if (TestParseNumPatients(kPatientNum)) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  std::cout << "Testing ParseNumPatients With Empty Array" << std::endl;
  if (TestParseNumNoPatients()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;  // exit with failure
  }

  return passed;
}


bool TestParseNumPatients(std::size_t expected) {  // true when correct number
  bool passed = true;                              // of patients parsed
  std::size_t actual = ParseNumPatients(kValues, kSize);
  if (expected != actual) {
    std::cout << "  Expected Number of Patients: " << expected << ", Actual: "
        << actual << std::endl;
    passed = false;
  }

  return passed;
}


bool TestParseNumNoPatients() {  // true when return val is -1 for size is 0
  bool passed = true;
  const int expected = 0;
  ParseErrors result;

  int actual = ParseNumPatients(kEmptyValues, kEmptySize, &result);

  if (expected != actual) {
    std::cout << "  Expected Number of Patients: " << expected << ", Actual: "
        << actual << std::endl;
    passed = false;
  }

  if (result != ParseErrors::kNoPatients) {
    std::cout << "  Expected ParseError: kNoPatients Actual: "
      << ::ToString(result) << std::endl;
    passed = false;
  }

  return passed;
}
