// Copyright 2024 Kaylee Walz
#include <hw4/inc/demographic.h>


#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>

Demographic::Demographic() : weight_(0),
                            smoker_(false),
                            ethnicity_(""),
                            dob_(),
                            id_("") {
    // empty
}


Demographic::Demographic(
                const std::string& id,
                bool smoker,
                const std::string& ethnicity,
                const Date& dob)
    : id_(id), smoker_(smoker), ethnicity_(ethnicity), dob_(dob), weight_(0) {
    // empty
}

Demographic::Demographic(const std::string* begin, const std::string* end) {
    if (begin == end) {
        throw std::invalid_argument("Array cannot be empty");
    }
    const std::string* it = begin;
    while (it != end) {
        if (*it == "S") {
            smoker_ = (*(++it) == "1");
        } else if (*it == "E") {
            ethnicity_ = *(++it);
        } else if (*it == "B") {
            std::string day = *(++it);
            std::string month = *(++it);
            std::string year = *(++it);
            dob_ = Date(day, month, year);
        } else if (*it == "W") {
            weight_ = std::stoi(*(++it));
        } else {
          id_ = *it;
        }
        ++it;
    }
}

const std::string Demographic::id() const {
    return id_;
  }

const Date Demographic::dob() const {
    return dob_;
  }

  const std::string Demographic::ethnicity() const {
    return ethnicity_;
  }

  bool Demographic::smoker() const {
    return smoker_;
  }

  int Demographic::weight() const {
    return weight_;
  }

  std::ostream* Demographic::Extract(std::ostream* out) const {
    *out << id_ << " : " << dob_.to_string() << " " <<
    ethnicity_ << " " << weight_ << "lbs "
         << (smoker_ ? "is" : "is not") << " smoker";
    return out;
}

std::istream* Demographic::Insert(std::istream* in) {
    std::string patient_id, smoker_flag, ethnicity_code, date_code, weight_code;
    *in >> patient_id >> smoker_flag;
    id_ = patient_id;
    smoker_ = (smoker_flag == "1");

    while (*in >> date_code) {
        if (date_code == "B") {
            std::string day, month, year;
            *in >> day >> month >> year;
            dob_ = Date(day, month, year);
        } else if (date_code == "W") {
            *in >> weight_;
        } else if (date_code == "E") {
            *in >> ethnicity_code;
            ethnicity_ = ethnicity_code;
        }
    }
    return in;
}

std::istream& operator>>(std::istream& lhs, Demographic& rhs) {
    return *rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const Demographic& rhs) {
    return *rhs.Extract(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const Date& rhs) {
    lhs << rhs.to_string();
    return lhs;
}
