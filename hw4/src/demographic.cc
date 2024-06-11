//Copyright 2024 Kaylee Walz
#include <hw4/inc/demographic.h>


#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>

Demographic::Demographic() {
    //empty
}


Demographic::Demographic(
                const std::string& id,
                bool smoker,
                const std::string& ethnicity,
                const Date& dob) {
    //empty
    }

 Demographic::Demographic(const std::string* begin, const std::string* end) {
    // this is where you should declare where the demographics are
    // like the ethnicities is at index 3, etc...
 }
 
  const std::string Demographic::id() const{
    return id_;
  }

  const Date Demographic::dob() const{
    return dob_;
  }

  const std::string Demographic::ethnicity() const{
    return ethnicity_;
  }

  bool Demographic::smoker() const{
    return smoker_;
  }

  int Demographic::weight() const{
    return weight_;
  }