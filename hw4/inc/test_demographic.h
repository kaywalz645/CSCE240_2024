// Copyright 2024 CSCE 240
//
#ifndef HW4_INC_TEST_DATE_H_
#define HW4_INC_TEST_DATE_H_


#include <hw4/inc/date.h>
#include <hw4/inc/demographic.h>

#include <cstddef>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


// Used to collect demographic info to test Demographic class
struct TestDemographic {
  std::string id;
  Date dob;
  std::string ethnicity;
  int weight;
  bool smoker;
};

// conversion from Demographic to TestDemographic
const TestDemographic ToTestDemographic(const Demographic& demographic);


// constant test values
//
const std::string kTestArray[] = {
  "F0E1D",
  "S", "0",
  "B", "06", "08", "23",
  "W", "121",
  "E", "N"
};
const std::size_t kTestArraySize = sizeof(kTestArray)/sizeof(std::string);
const std::string kTestString = "F0E1D S 0 B 06 08 23 W 121 E N";
const std::string kExpectedString = "F0E1D 06-08-2023 N 121lbs is not smoker";
const TestDemographic kExpected{ "F0E1D", Date("06-08-23"), "N", 121, 0 };


// What follows is a class hierarchy of functors--class instances that behave
// like functions; that is, they overload the parenthesis operator

namespace demographic {

class Test {  // abstract parent
 public:
  virtual bool operator()() const = 0;
};


class TestRangeDemographic : public Test {  // concrete child
 public:
  TestRangeDemographic(const std::string* begin,
                       const std::string* end,
                       const TestDemographic& expected)
      : begin_(begin), end_(end), expected_(expected) {
    // empty
  }

  bool operator()() const;

 private:
  const std::string* begin_;
  const std::string* end_;
  TestDemographic expected_;
};


class TestExtractOperator : public Test {
 public:
  TestExtractOperator(const std::string* begin,
                      const std::string* end,
                      const std::string* expected)
    : begin_(begin), end_(end), expected_(expected) {
  }

  bool operator()() const;
 private:
  const std::string* begin_;
  const std::string* end_;
  const std::string* expected_;
};


class TestInsertOperator : public Test {
 public:
  TestInsertOperator(const std::string* input,
                     const TestDemographic* expected)
    : input_(input), expected_(expected) {
  }

  bool operator()() const;
 private:
  const std::string* input_;
  const TestDemographic* expected_;
};

}  // namespace demographic


// Utility functions for easier testing and feedback
bool operator==(const Demographic& rhs, const TestDemographic& lhs);
bool operator!=(const Demographic& rhs, const TestDemographic& lhs);

bool operator==(const TestDemographic& rhs, const Demographic& lhs);
bool operator!=(const TestDemographic& rhs, const Demographic& lhs);

bool operator==(const Date& rhs, const Date& lhs);

std::ostream& operator<<(std::ostream& lhs, const TestDemographic&);


#endif  // HW4_INC_TEST_DATE_H_
