//Copyright 2024 Kaylee Walz
#include <hw4/inc/date.h>

//  This class tests your ability to manage operator overloading and iterating
//  over arrays via pointer (pointer arithmetic).
//
//  Points:
//   Style : 1
//   Compilation : 0.5
//    + Date::Date(std::string&) : 1
//    + Date::Date(std::string*, std::string*) : 1
//    + Date::operator-(Date&) 
//      && Date::operator-(std::string&) : 1, using Date::Date(std::string&)
//    + operator-(std::string&, Date&) : 1
//
//   Bonus:
//     Implicit conversion to std::string: 1, using Date::Date(std::string&)
//

#include <cassert>
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>



  // Not explicitly tested, but you may want this for yourself; why is that?
  //
  Date::Date(){
    //empty
  }


  // Not explicity tested; implement for yourself if you need for Demographics
  //
  Date::Date(const std::string& month,
       const std::string& day,
       const std::string& year) : month_(month), day_(day), year_(year) {
    // empty
  }


  // Accepts as parameters a string array's bounds, exclusive of the end
  // pointer,
  //   I.E., The two pointer represent [begin, end),
  //   I.E., The end pointer does not point to an element of the array,
  //   E.G.,
  //     begin ->  "mm",
  //               "dd",
  //               [ "yy" | "yyyy" ],
  //     end ->
  //   I.E., The end pointer stores the address of the first byte after the
  //   last element of the array. This is idiomatic of container bounds in the
  //   STL.
  //
  Date::Date(const std::string* begin, const std::string* end) {
    if (end - begin == 3) {
        month_ = *(begin);
        day_ = *(begin + 1);
        year_ = *(begin + 2);
    } else {
        throw std::invalid_argument("Invalid range for date components");
    }
  }


  // The parameter date is of the form
  //   mm/dd/yy or mm/dd/yyyy
  //            or
  //   mm-dd-yy or mm-dd-yyyy
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

  // Not explicitly tested; used to test Date constructors
  const std::string& Date::month() const {
    return month_;
  }
  const std::string& Date::day() const {
    return day_;
  }
  const std::string& Date::year() const {
    return year_;
  }


  // Tested in a single test; both must pass for credit.
  // Calculates the number of whole years between the calling class and the
  // parameters class: years = begin_date - end_date; may be negative.
  //
  int Date::operator-(const Date& end_date) {
    return std::stoi(year_) - std::stoi(end_date.year_);
  }
  // The parameter end_date is of the form
  //   mm/dd/yy or mm/dd/yyyy
  //            or
  //   mm-dd-yy or mm-dd-yyyy
  int Date::operator-(const std::string& end_date) {
     Date temp(end_date);
    return *this - temp;
  }


// The parameter begin_date is of the form
//   mm/dd/yy or mm/dd/yyyy
//            or
//   mm-dd-yy or mm-dd-yyyy
int operator-(const std::string& begin_date, const Date& end_date) {
    Date temp(begin_date);
    return temp - end_date;
}
