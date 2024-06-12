// Copyright 2024 CSCE 240 Programming Assignment 5
//
#include <hw5/inc/statistic_test.h>


namespace hw5 {

bool StatisticTest::TestDefaultConstructor(Statistic* default_test) {
  std::cout << "TESTING hw5::Statistic::Statistic() WITH hw5::Median"
    << std::endl;

  if (default_test->store_ == nullptr) {
    std::cout << "    PASSED" << std::endl;
    return true;
  }

  std::cout << "    EXPECTED: store_ == nullptr, ACTUAL: store_ == "
    << default_test->store_ << std::endl;
  return false;
}


bool StatisticTest::TestCollect(Statistic* collect_test) {
  std::cout << "TESTING hw5::Statistic::Collect(double) "
    << "WITH hw5::Median"
    << std::endl;

  bool passed = true;
  for (std::size_t i = 0; i < kTest2Size; ++i) {
    collect_test->Collect(kTest2Data[i]);

    if (collect_test->store_[i] != kTest2Data[i]) {
      passed = false;
      std::cout << "    EXPECECTED: hw5::Statistic::store_[" << i
        << "] == " << kTest2Data[i] << ", ACTUAL: " << collect_test->store_[i]
        << std::endl;
    }
  }

  if (passed)
    std::cout << "    PASSED" << std::endl;
  return passed;
}


bool StatisticTest::TestCopyConstructor(Statistic* expected) {
  std::cout << "TESTING hw5::Statistic::Statistic(const Statistic&) "
    << "WITH hw5::Median"
    << std::endl;

  // Dynamic "down casting" is generally a bad idea. The problem comes when a
  // parent is cast to a child class, but is not, in fact, an instance of that
  // child class. In this case, there is only one possible child.
  Median concrete_instance(*dynamic_cast<const Median*>(expected));
  Statistic *actual = &concrete_instance;

  if (expected->store_ == actual->store_) {
    std::cout << "    EXPECTED: deep copy, ACTUAL: shallow copy" << std::endl;
    return false;
  }

  if (Equals(*expected, *actual, kTest2Size)) {
    std::cout << "    PASSED" << std::endl;
    return true;
  }

  return false;
}


bool StatisticTest::TestAssignmentOperator(Statistic* expected) {
  std::cout << "TESTING hw5::Statistic::operator=(const Statistic&) "
    << "WITH hw5::Median"
    << std::endl;

  Median concrete_instance;
  Statistic *actual = &concrete_instance;
  *actual = *const_cast<const Statistic*>(expected);

  if (expected->store_ == actual->store_) {
    std::cout << "    EXPECTED: deep copy, ACTUAL: shallow copy" << std::endl;
    return false;
  }

  if (Equals(*expected, *actual, kTest2Size)) {
    std::cout << "    PASSED" << std::endl;
    return true;
  }

  return false;
}


const double* StatisticTest::store(const Median& child) {
  const Statistic* parent = &child;

  return parent->store_;
}


bool StatisticTest::Equals(const Statistic& expected,
                           const Statistic& actual,
                           std::size_t size) {
  bool passed = true;
  for (std::size_t i = 0; i < size; ++i) {
    if (expected.store_[i] != actual.store_[i]) {
      std::cout << "    EXPECTED: store_[" << i << "] == " << expected.store_[i]
        << ", Actual: " << actual.store_[i] << std::endl;
      passed = false;
    }
  }
  return passed;
}

}  // namespace hw5
