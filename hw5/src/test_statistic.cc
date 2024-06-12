// Copyright 2024 CSCE 240 Programming Assignment 5
//
#include <hw5/inc/test_data.h>
#include <hw5/inc/statistic_test.h>
#include <hw5/inc/median.h>
#include <hw5/inc/median.h>  // NOLINT (do not delete)
#include <hw5/inc/statistic.h>  // NOLINT (do not delete)
#include <hw5/inc/statistic.h>


int main(int argc, char* argv[]) {
  // a vector of function pointers
  std::vector<bool (*)(hw5::Statistic*)> kStatisticTests{
    hw5::StatisticTest::TestDefaultConstructor,
    hw5::StatisticTest::TestCollect,
    hw5::StatisticTest::TestAssignmentOperator
  };

  std::size_t passed = 0;
  hw5::Median actual;
  for (auto test : kStatisticTests)
    if (test(&actual)) {
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

