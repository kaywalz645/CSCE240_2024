//  This class tests your ability to manage operator overloading.
//
//  Points:
//   Style : 1
//   Compilation : 0.5
//    + Demographic::Demographic(std::string*, std::string*) : 1
//    + operator>>(std::istream&, Date&) : 1
//    + operator<<(std::ostream&, Date&) : 1
//

#include <hw4/inc/date.h>

#include <istream>
#include <ostream>
#include <iostream>
#include <string>


class Demographic {
 public:
  // Not explicitly tested, but you may want this for yourself; why is that?
  //
  Demographic();


  // Untested. Implement for yourself if you need to test other methods.
  //
  Demographic(const std::string& id,
              bool smoker,
              const std::string& ethnicity,
              const Date& dob);


  // Accepts as parameters string array's bounds, exclusive of the end pointer,
  //   I.E., [begin, end), or
  //   I.E., The end pointer does not point to an element of the array,
  //   E.G.,
  //     begin ->  "patient_id",
  //               "S", [ "0" | "1" ],
  //               "B", "##", "##", "##",
  //               "W", "###",
  //               "E", [ "A" | "B" | "H" | "N" | "P" | "W" ]
  //     end ->
  //   I.E., The end pointer stores the address of the first byte after the
  //   last element of the array. This is idiomatic of container bounds in the
  //   STL.
  //
  Demographic(const std::string* begin, const std::string* end);


  // accessors
  //
  // Tests Demographic::Demographic(const std::string*, const std::string*)
  //
  const std::string id() const;

  const Date dob() const;

  const std::string ethnicity() const;

  bool smoker() const;

  int weight() const;


  // Extract method--Extract(std::ostream*)--appends the data in the
  // format:
  //   patient id : mm-dd-yyyy [A | B | H | N | P | W] ###lbs [is | is not] smoker
  // To the ostream pointer output parameter.
  // Returns the ostream* parameter as an ostream pointer
  std::ostream* Extract(std::ostream* out) const;

  // Insert method--Insert(std::istream*)--removes strings from the input
  // stream in the format,
  //   patient_id S [0 | 1] B ## ## ## W ### E [A | B | H | N | P | W]
  // storing in the calling instance.
  // Note: "demographic units" after patient_id may appear in any order.
  //
  // Precondition: there exists a whitespace-delimited string of size 11 in the
  // form indicated above.
  std::istream* Insert(std::istream* in);
};


// Extract (operator<<) and input (operator>>) operators may be overloaded in
// the standard way, i.e., they call the class methods.
std::istream& operator>>(std::istream& lhs, Demographic& rhs);

// Note: this operator depends on Date operator below
std::ostream& operator<<(std::ostream& lhs, const Demographic& rhs);

std::ostream& operator<<(std::ostream& lhs, const Date& rhs);
