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
#ifndef HW4_INC_DATE_H
#define HW4_INC_DATE_H

#include <istream>
#include <ostream>
#include <string>


class Date {
 public:

  Date();

  Date(const std::string& month,
       const std::string& day,
       const std::string& year);


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
  Date(const std::string* begin, const std::string* end);


  // The parameter date is of the form
  //   mm/dd/yy or mm/dd/yyyy
  //            or
  //   mm-dd-yy or mm-dd-yyyy
  explicit Date(const std::string& date);


  // Not explicitly tested; used to test Date constructors
  const std::string& month() const;
  const std::string& day() const;
  const std::string& year() const;


  // Tested in a single test; both must pass for credit.
  // Calculates the number of whole years between the calling class and the
  // parameters class: years = begin_date - end_date; may be negative.
  //
  int operator-(const Date& end_date);
  // The parameter end_date is of the form
  //   mm/dd/yy or mm/dd/yyyy
  //            or
  //   mm-dd-yy or mm-dd-yyyy
  int operator-(const std::string& end_date);

  private:
    std::string month_;
    std::string day_;
    std::string year_;

    void parseDate(const std::string& date);

};


// The parameter begin_date is of the form
//   mm/dd/yy or mm/dd/yyyy
//            or
//   mm-dd-yy or mm-dd-yyyy
int operator-(const std::string& begin_date, const Date& end_date);
#endif //Date