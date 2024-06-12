// Copyright 2024 Kaylee Walz
#include <hw4/inc/date.h>

#include <cassert>
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>



  Date::Date() {
    // empty
  }

  Date::Date(const std::string& month,
       const std::string& day,
       const std::string& year): month_(month), day_(day), year_(year)  {
    // empty
  }

  Date::Date(const std::string* begin, const std::string* end) {
    if (end - begin == 3) {
        month_ = *(begin);
        day_ = *(begin + 1);
        year_ = *(begin + 2);
    } else {
        throw std::invalid_argument("Invalid range for date components");
    }
  }

    Date::Date(const std::string& date) {
        parseDate(date);
    }

    void Date::parseDate(const std::string& date) {
    char delimiter = (date.find('/') != std::string::npos) ? '/' : '-';
    std::istringstream iss(date);
    std::getline(iss, month_, delimiter);
    std::getline(iss, day_, delimiter);
    std::getline(iss, year_, delimiter);
    }

  const std::string& Date::month() const {
    return month_;
  }
  const std::string& Date::day() const {
    return day_;
  }
  const std::string& Date::year() const {
    return year_;
  }

  int Date::operator-(const Date& end_date) {
    return std::stoi(year_) - std::stoi(end_date.year_);
  }

  int Date::operator-(const std::string& end_date) {
     Date temp(end_date);
    return *this - temp;
  }

int operator-(const std::string& begin_date, const Date& end_date) {
    Date temp(begin_date);
    return temp - end_date;
}

std::string Date::to_string() const {
  return day_ + "-" + month_ + "-" + year_;
}
