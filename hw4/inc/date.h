// Copyright 2024 Kaylee Walz
#ifndef HW4_INC_DATE_H_
#define HW4_INC_DATE_H_

#include <istream>
#include <ostream>
#include <string>


class Date {
 public:
     Date();

     Date(const std::string& month,
       const std::string& day,
       const std::string& year);


     Date(const std::string* begin, const std::string* end);


     explicit Date(const std::string& date);

     const std::string& month() const;
     const std::string& day() const;
     const std::string& year() const;


     int operator-(const Date& end_date);
     int operator-(const std::string& end_date);

 private:
     std::string month_;
     std::string day_;
     std::string year_;

    void parseDate(const std::string& date);
};

int operator-(const std::string& begin_date, const Date& end_date);

#endif  // HW4_INC_DATE_H_
