// Copyright 2024 CSCE240
//
#include <hw4/inc/test_date.h>


int main(int argc, char* argv[]) {
  // read-only test cases (these are called functors--classes that behave like
  // functions)
  const date::TestStringDate kTest1(kTestString1, kTestArray);
  const date::TestArrayDate kTest2(kTestArray);
  const date::TestMethodDifference kTest3(kTestString1,
                                          kTestString2,
                                          kTestDiff_1_2);
  const date::TestFunctionDifference kTest4(kTestString1,
                                      kTestString3,
                                      kTestDiff_1_3);

  // dynamic array of tests
  std::vector<const date::Test*> tests{ &kTest1, &kTest2, &kTest3, &kTest4 };

  // command line arg test number
  const std::size_t kTestArg = 1;

  // if no arg given, run all tests
  int test = argc == 2 ? std::atoi(argv[kTestArg]) : 4;

  if (test < 4) {
    if ( (*(tests.at(test)))() )
      return 0;
    return 1;
  }

  const std::size_t kTotalTests = 4;
  std::size_t tests_passed = 0;
  for (std::size_t i = 0; i < kTotalTests; ++i) {
    if ( (*(tests.at(i)))() )
      ++tests_passed;

    std::cout << std::endl;
  }

  std::cout << "Passed " <<  tests_passed << " of " << kTotalTests
    << " total tests." << std::endl;

  return tests_passed == kTotalTests;
}


namespace date {

bool TestStringDate::operator()() const {
  std::cout << "Testing Date::Date(const std::string&)" << std::endl;

  Date actual(input_);

  if (expected_ == actual) {
    std::cout << "  PASSED" << std::endl;
    return true;
  }

  std::cout << "    Expected: " << expected_ << ", Actual: " << actual
    << std::endl;

  return false;
}


bool TestArrayDate::operator()() const {
  std::cout << "Testing Date::Date(const std::string*, const std::string*)"
    << std::endl;

  Date actual(input_, input_ + 3);

  if (input_ == actual) {
    std::cout << "  PASSED" << std::endl;
    return true;
  }

  std::cout << "  Expected: " << input_ << ", Actual: " << actual << std::endl;

  return false;
}


bool TestMethodDifference::operator()() const {
  std::cout << "Testing Date::operator-(const Date&)" << std::endl;

  bool passed = true;

  int actual = Date(lhs_) - Date(rhs_);
  if (expected_ != actual) {
    passed = false;

    std:: cout << "  " << lhs_ << " - " << rhs_ << " Expected: " << expected_
      << ", Actual: " << actual << std::endl;
  }

  actual = Date(rhs_) - lhs_;
  if (-expected_ != actual) {
    passed = false;

    std:: cout << "  " << rhs_ << " - " << lhs_ << " Expected: " << -expected_
      << ", Actual: " << actual << std::endl;
  }

  if (passed)
    std::cout << "  PASSED" << std::endl;

  return passed;
}


bool TestFunctionDifference::operator()() const {
  std::cout << "Testing Date::operator-(const Date&)" << std::endl;

  bool passed = true;

  int actual = lhs_ - Date(rhs_);
  if (expected_ != actual) {
    passed = false;

    std:: cout << "  " << lhs_ << " - " << rhs_ << " Expected: " << expected_
      << ", Actual: " << actual << std::endl;
  }

  actual = rhs_ - Date(lhs_);
  if (-expected_ != actual) {
    passed = false;

    std:: cout << "  " << rhs_ << " - " << lhs_ << " Expected: " << -expected_
      << ", Actual: " << actual << std::endl;
  }

  if (passed)
    std::cout << "  PASSED" << std::endl;

  return passed;
}

}  // end namespace date


bool operator==(const Date& lhs, const std::string* rhs) {
  return lhs.year() == rhs[2] && lhs.month() == rhs[1] && lhs.day() == rhs[0];
}


bool operator!=(const Date& lhs, const std::string* rhs) {
  return !(lhs == rhs);
}


bool operator==(const std::string* lhs, const Date& rhs) {
  return lhs[0] == rhs.month() && lhs[1] == rhs.day() && lhs[2] == rhs.year();
}


bool operator!=(const std::string* lhs, const Date& rhs) {
  return !(lhs == rhs);
}


std::ostream& operator<<(std::ostream& lhs, const Date& rhs) {
  return lhs << rhs.month() << '-' << rhs.day() << '-' << rhs.year();
}


std::ostream& operator<<(std::ostream& lhs, const std::string* rhs) {
  // if you can read this, you are a
  // https://youtu.be/i6l8MFdTaPE?si=Jp7IM39xjSPe9RID
  return lhs << *(rhs) << '-' << *(rhs + 1) << '-' << *(rhs + 2);
}

