// Copyright 2024 CSCE 240
//
#include <hw3_sol/inc/test_parse_demographics.h>


int main(int argc, char* argv[]) {
  if (std::atoi(argv[1]) == 1) {
    std::cout << "RUNNING TEST 1" << std::endl;

    std::cout << "INPUT:" << std::endl;
    PrintTest(kTest1Rows, kTest1Cols, kTest1Vals);

    std::cout << "EXPECTED OUTPUT:" << std::endl;
    PrintExpected(kTest1Rows, kExpect1Cols, kExpect1Vals);

    const std::string** actual =  ParseDemographics(kTest1Rows,
                                                    kTest1Cols,
                                                    kTest1Vals);

    std::cout << "RESULTS:" << std::endl;
    bool passed = Equals(kTest1Rows, kExpect1Cols, kExpect1Vals, actual);

    if (argc == 3) {
      std::cout << "ATTEMPTING TO DELETE RETURNED MEMORY" << std::endl;
      DeleteActual(kTest1Rows, kExpect1Cols, actual);
    }

    return passed ? 0 : 1;
  }

  if (std::atoi(argv[1]) == 2) {
    std::cout << "RUNNING TEST 2" << std::endl;

    std::cout << "INPUT:" << std::endl;
    PrintTest(kTest2Rows, kTest2Cols, kTest2Vals);

    std::cout << "EXPECTED OUTPUT:" << std::endl;
    PrintExpected(kTest2Rows, kExpect2Cols, kExpect2Vals);
    const std::string** actual = ParseDemographics(kTest2Rows,
                                                   kTest2Cols,
                                                   kTest2Vals);

    std::cout << "RESULTS:" << std::endl;
    bool passed = Equals(kTest2Rows, kExpect2Cols, kExpect2Vals, actual);

    if (argc == 3) {
      std::cout << "ATTEMPTING TO DELETE RETURNED MEMORY" << std::endl;
      DeleteActual(kTest2Rows, kExpect2Cols, actual);
    }

    return passed ? 0 : 1;
  }

  return 2;
}

bool Equals(const std::size_t patients, const std::size_t eth_nums[],
            const std::string** expected, const std::string** actual) {
  const std::size_t kDemBirthOff = 1;
  const std::size_t kDemEthOff = 2;

  if (!actual) {
    std::cerr << "  Expected: array of strings, string arrays, and nullptrs\n"
      << "  Actual: nullptr" << std::endl;
    return false;
  }

  bool passed = true;

  for (std::size_t i = 0; i < patients; ++i) {
    std::cout << " Testing Patient Index " << i << std::endl;
    passed = IdsEqual(i * kDemRows, expected, actual) && passed;

    passed = DoBsEqual(i * kDemRows + kDemBirthOff, expected, actual) && passed;

    passed = EthsEqual(i * kDemRows + kDemEthOff, eth_nums[i], expected, actual)
      && passed;
  }

  if (passed)
    std::cout << "  PASSED" << std::endl;
  else
    std::cout << "  FAILED" << std::endl;

  return passed;
}


bool IdsEqual(const std::size_t index, const std::string** expected,
              const std::string** actual) {
  // id present
  if (!actual[index]) {
    std::cout << "  Expected Id: " << expected[index]
      << "\n  Actual Id: nullptr" << std::endl;
    return false;
  }

  // id correct
  if (*actual[index] != *expected[index]) {
    std::cout << "  Expected Id: " << *expected[index]
      << "\n  Actual Id: " << *actual[index] << std::endl;
    return false;
  }

  return true;
}


bool DoBsEqual(const std::size_t index, const std::string** expected,
               const std::string** actual) {
    // dob present
    if (!actual[index]) {
      std::cout << "  Expected DoB: 3 element array\n"
        << "  Actual Id: nullptr" << std::endl;
      return false;
    }

    // dob correct
    const char *parts[kDemDobSize] = { "month", "day", "year" };
    bool passed = true;
    for (std::size_t ii = 0; ii < kDemDobSize; ++ii) {
      if (expected[index][ii] != actual[index][ii]) {
        std::cout << "  Expected DoB " << parts[ii] << ": " <<
        expected[index][ii] << "\n  Actual DoB " << parts[ii] << ": "
          << actual[index][ii] << std::endl;
        passed = false;
      }
    }

  return passed;
}


bool EthsEqual(const std::size_t index, const std::size_t eth_num,
               const std::string** expected, const std::string** actual) {
  // ethnicities nullptr if count is 0
  if (eth_num == 0) {
    if (actual[index]) {
      std::cout << "  Expected Ethnicities: nullptr\n  Actual: not null"
        << std::endl;

      return false;
    }
    return true;
  }

  // one ethnicity
  if (eth_num == 1) {
    if (*expected[index] != *actual[index]) {
      std::cout << "  Expected Ethnicities: " << *expected[index]
        << "  Actual: "  << *actual[index] << std::endl;

      return false;
    }
    return true;
  }

  // multiple ethnicities
  bool passed = true;
  for (std::size_t i = 0; i < eth_num; ++i) {
    if (expected[index][i] != actual[index][i]) {
      std::cout << "  Expected Ethnicity: " << expected[index][i]
        << "  Actual Ethnicity " << actual[index][i] << std::endl;
      passed = false;
    }
  }
  return passed;
}


void PrintTest(const std::size_t rows,
           const std::size_t cols[],
           const std::string** values) {
  std::cout << "{" << std::endl;
  for (std::size_t i = 0; i < rows; ++i) {
    std::cout << "  { ";
    for (std::size_t ii = 0; ii < cols[i]; ++ii) {
      std::cout << values[i][ii] << ' ';
    }
    std::cout << "}" << std::endl;
  }
  std::cout << "}" << std::endl;
}

void PrintExpected(const std::size_t patient_num,
                          const std::size_t eth_nums[],
                          const std::string** values) {
  const std::size_t kDoB = 1;
  const std::size_t kEthnicity = 2;
  std::cout << "{" << std::endl;
  for (std::size_t i = 0; i < patient_num; ++i) {
    std::cout << "  -> " << *values[i * kDemRows] << std::endl;

    std::cout << "  { ";
    for (std::size_t ii = 0; ii < kDemDobSize; ++ii)
      std::cout << values[i * kDemRows + kDoB][ii] << " ";
    std::cout << "}" << std::endl;

    if (eth_nums[i] == 0) {
      std::cout << "  nullptr" << std::endl;
    } else if (eth_nums[i] == 1) {
      std::cout << "  -> " << *values[i * kDemRows + kEthnicity] << std::endl;
    } else if (eth_nums[i] > 1) {
      std::cout << "  { ";
      for (std::size_t ii = 0; ii < eth_nums[i]; ++ii)
        std::cout << values[i * kDemRows + kEthnicity][ii] << " ";

      std::cout << "}" << std::endl;
    }
  }
  std::cout << "}" << std::endl;
}

void DeleteActual(const std::size_t patient_num, const std::size_t eth_nums[],
                  const std::string** values) {
  const std::size_t kDoB = 1;
  const std::size_t kEthnicity = 2;

  for (std::size_t i = 0; i < patient_num; ++i) {
    delete values[i * kDemRows];

    delete [] values[i * kDemRows + kDoB];

    if (eth_nums[i] == 1)
      delete values[i * kDemRows + kEthnicity];
    else if (eth_nums[i] > 1)
      delete [] values[i * kDemRows + kEthnicity];
  }

  delete [] values;
}
