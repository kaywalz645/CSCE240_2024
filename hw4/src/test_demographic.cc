// Copyright 2024 CSCE240
//
#include <hw4/inc/test_demographic.h>


int main(int argc, char* argv[]) {
  // read-only test cases (these are called functors--classes that behave like
  // functions)
  const demographic::TestRangeDemographic kTest1(kTestArray,
                                                 kTestArray + kTestArraySize,
                                                 kExpected);
  const demographic::TestExtractOperator kTest2(kTestArray,
                                                kTestArray + kTestArraySize,
                                                &kExpectedString);
  const demographic::TestInsertOperator kTest3(&kTestString, &kExpected);

  // dynamic array of tests
  std::vector<const demographic::Test*> tests{ &kTest1, &kTest2, &kTest3 };

  // command line arg test number
  const std::size_t kTestArg(1), kTotalTests(3);

  // if no arg given, run all tests
  std::size_t test = argc == 2 ? std::atoi(argv[kTestArg]) : kTotalTests;

  if (test < kTotalTests) {
    if ( (*(tests.at(test)))() )
      return 0;
    return 1;
  }

  std::size_t tests_passed = 0;
  for (std::size_t i = 0; i < kTotalTests && i < tests.size(); ++i) {
    if ( (*(tests.at(i)))() )
      ++tests_passed;

    std::cout << std::endl;
  }

  std::cout << "Passed " <<  tests_passed << " of " << kTotalTests
    << " total tests." << std::endl;

  return tests_passed == kTotalTests;
}


bool demographic::TestRangeDemographic::operator()() const {
  std::cout << "Testing Demographic::Demographic(const std::string*, "
            << "const std::string*)" << std::endl;

  Demographic actual(begin_, end_);

  if (expected_ == actual) {
    std::cout << "  PASSED" << std::endl;
    return true;
  }

  std::cout << "    Expected: " << expected_ << ", Actual: "
    << ToTestDemographic(actual) << std::endl;

  return false;
}


bool demographic::TestExtractOperator::operator()() const {
  std::cout << "Testing operator<<(std::ostream&, const Demographic&)"
            << std::endl;

  Demographic actual(begin_, end_);

  std::stringstream sout;

  sout << actual;

  if (*expected_ == sout.str()) {
    std::cout << "  PASSED" << std::endl;
    return true;
  }

  std::cout << "    Expected: " << *expected_ << std::endl
            << "      Actual: " << sout.str() << std::endl;

  return false;
}


bool demographic::TestInsertOperator::operator()() const {
  std::cout << "Testing operator>>(std::istream&, Demographic&)" << std::endl;
  Demographic actual;
  std::stringstream sin(*input_);

  sin >> actual;

  if (*expected_ == actual) {
    std::cout << "  PASSED" << std::endl;
    return true;
  }

  std::cout << "    Expected: " << *expected_ << std::endl
            << "      Actual: " << ToTestDemographic(actual) << std::endl;
  return false;
}


const TestDemographic ToTestDemographic(const Demographic& demographic) {
  return {
    demographic.id(),
    demographic.dob(), demographic.ethnicity(), demographic.weight(),
    demographic.smoker()
  };
}


bool operator==(const Demographic& lhs, const TestDemographic& rhs) {
  return lhs.id() == rhs.id && lhs.dob() == rhs.dob
    && lhs.ethnicity() == rhs.ethnicity && lhs.weight() == rhs.weight
    && lhs.smoker() == rhs.smoker;
}


bool operator!=(const Demographic& lhs, const TestDemographic& rhs) {
  return !(lhs == rhs);
}


bool operator==(const TestDemographic& lhs, const Demographic& rhs) {
  return rhs == lhs;
}


bool operator!=(const TestDemographic& lhs, const Demographic& rhs) {
  return !(lhs == rhs);
}


bool operator==(const Date& lhs, const Date& rhs) {
  return lhs.year() == rhs.year() && lhs.month() == rhs.month()
    && lhs.day() == rhs.day();
}


std::ostream& operator<<(std::ostream& lhs, const TestDemographic& rhs) {
  return lhs << rhs.id << " : " << rhs.dob << ' ' << rhs.ethnicity << ' '
    << rhs.weight << ' ' << std::boolalpha << rhs.smoker;
}
