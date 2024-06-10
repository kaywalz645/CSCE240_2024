// Copyright 2024 CSCE 240
//
#ifndef HW4_INC_TEST_DATE_H_
#define HW4_INC_TEST_DATE_H_


#include <hw4/inc/date.h>

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>


// constants to test Date class
//
const std::string kTestString1 = "06-08-24";
const std::string kTestString2 = "06-08-23";  // exactly 1 year from date 1
const int kTestDiff_1_2 = 1;  // 1 - 2
const std::string kTestString3 = "12-13-27";  // ~3.5 = 3 years from date 1
const int kTestDiff_1_3 = -3;  // 1 - 3

const std::size_t kTestArraySize = 3;
const std::string* kTestArray = new std::string[3] { "06", "08", "24" };


// What follows is a class hierarchy of functors--class instances that behave
// like functions; that is, they overload the parenthesis operator and not much
// else

namespace date {  // using a namespace here because Test class(es) will exist
                  // for Person's test as well

class Test {  // abstract parent
 public:
  virtual bool operator()() const = 0;
};


class TestStringDate : public Test {  // concrete child
 public:
  TestStringDate(const std::string& input, const std::string* expected)
      : input_(input), expected_(expected) {
    // empty
  }

  bool operator()() const;

 private:
  std::string input_;
  const std::string* expected_;
};


class TestArrayDate : public Test {  // concrete child
 public:
  explicit TestArrayDate(const std::string* input) : input_(input) {
    // empty
  }

  bool operator()() const;

 private:
  const std::string* input_;
};


class TestDifference : public Test {  // abstract child
 public:
  TestDifference(const std::string& lhs, const std::string& rhs, int expected)
      : lhs_(lhs), rhs_(rhs), expected_(expected) {
    // empty
  }

  virtual bool operator()() const = 0;

 protected:
  std::string lhs_;
  std::string rhs_;
  int expected_;
};

class TestMethodDifference : public TestDifference {  // concrete "grandchild"
 public:
  using TestDifference::TestDifference;

  bool operator()() const;
};

class TestFunctionDifference : public TestDifference {  // concrete "grandchild"
 public:
  using TestDifference::TestDifference;

  bool operator()() const;
};

}  // end namespace date


// Utility functions for easier testing and feedback
bool operator==(const Date& rhs, const std::string* lhs);
bool operator!=(const Date& rhs, const std::string* lhs);

bool operator==(const std::string* lhs, const Date& rhs);
bool operator!=(const std::string* lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& lhs, const std::string* rhs);
std::ostream& operator<<(std::ostream& lhs, const Date& rhs);


#endif  // HW4_INC_TEST_DATE_H_
