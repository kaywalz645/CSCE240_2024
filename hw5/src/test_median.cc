// Copyright 2024 CSCE 240 Programming Assignment 5
//

#include <hw5/inc/test_data.h>
#include <hw5/inc/statistic_test.h>
#include <hw5/inc/median.h>
#include <hw5/inc/statistic.h>
#include <vector>


bool TestMedianCopyConstructor(hw5::Median*);
bool TestMedianCalculateMethod(hw5::Median*);


int main(int argc, char* argv[]) {
  const std::vector<bool (*)(hw5::Median*)> kMedianTests{
    TestMedianCopyConstructor,
    TestMedianCalculateMethod
  };

  int passed = 0;
  
  hw5::Median expected;
  for (auto test : kMedianTests)
    if (test(&expected)) {
      ++passed;
      std::cout << std::endl;
    } else {
      std::cout << std::endl
        <<  "TESTS ARE, NECESSARILY, CUMMULATIVE.\n" <<  "    " << passed
        << " of 3 tests PASSED." << std::endl;
      return 1;
    }

  return 0;
}


bool TestMedianCopyConstructor(hw5::Median* expected) {
  if (!hw5::StatisticTest::TestCollect(expected))
    return false;
  std::cout << "TESTING hw5::Median::Median(const Median)" << std::endl;


  hw5::Median actual(*expected);  // COPY CONSTRUCTOR

  // access to read-only memory, e.g., why it is bad to have friends
  const double* expected_store = hw5::StatisticTest::store(*expected);
  const double* actual_store = hw5::StatisticTest::store(actual);

  if (expected_store == actual_store) {
    std::cout << "    EXPECTED: deep copy, ACTUAL: shallow copy" << std::endl;
    return false;
  }

  if (hw5::StatisticTest::Equals(*expected, actual, kTest2Size)) {
    std::cout << "    PASSED" << std::endl;
    return true;
  }

  return false;
}


bool TestMedianCalculateMethod(hw5::Median* calculator) {
  std::cout << "TESTING hw5::Median::Caculate(void)" << std::endl;

  double actual = calculator->Calculate();

  if (kTest2Expected == actual) {
    std::cout << "    PASSED" << std::endl;
    return true;
  }

  std::cout << "    EXPECTED: median == " << kTest2Expected << ", ACTUAL: "
    << actual << std::endl;

  return false;
}


bool TestMedianDefaultConstructor(hw5::Median* expected) {
  std::cout << "TESTING hw5::Median::Median()" << std::endl;

  const double *store = hw5::StatisticTest::store(*expected);
  if (store == nullptr) {
    std::cout << "    PASSED" << std::endl;
    return true;
  }

  std::cout << "    Expected: store_ == nullptr, Actual: " << store
    << std::endl;

  return false;
}
