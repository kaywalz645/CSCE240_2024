// Copyright 2024 Kaylee Walz
#include <hw4/inc/date.h>
#ifndef HW4_INC_DEMOGRAPHIC_H_
#define HW4_INC_DEMOGRAPHIC_H_


#include <istream>
#include <ostream>
#include <iostream>
#include <string>


class Demographic {
 public:
  Demographic();

  Demographic(const std::string& id,
              bool smoker,
              const std::string& ethnicity,
              const Date& dob);

  Demographic(const std::string* begin, const std::string* end);

  const std::string id() const;

  const Date dob() const;

  const std::string ethnicity() const;

  bool smoker() const;

  int weight() const;

  std::ostream* Extract(std::ostream* out) const;

  std::istream* Insert(std::istream* in);

 private:
  int weight_;
  bool smoker_;
  std::string ethnicity_;
  Date dob_;
  std::string id_;
};


std::istream& operator>>(std::istream& lhs, Demographic& rhs);

std::ostream& operator<<(std::ostream& lhs, const Demographic& rhs);

std::ostream& operator<<(std::ostream& lhs, const Date& rhs);
#endif  // HW4_INC_DEMOGRAPHIC_H_
