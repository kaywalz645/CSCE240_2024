// Copyright 2024 Kaylee Walz

#ifndef HW2_INC_PARSE_DEMOGRAPHICS_H_
#define HW2_INC_PARSE_DEMOGRAPHICS_H_
#include <cstddef>
#include <string>

// Describes any exceptional execution paths of the following functions, or the
// lack thereof (kNoErrors)
enum class ParseErrors {
  kNoErrors,
  kNoPatients,
  kNoEthnicities,
  kMissingPatient
};

// Translates the above enum values into strings for printing
//
inline const std::string ToString(const ParseErrors& error) {
  switch (error) {
    case ParseErrors::kNoErrors:
      return "kNoErrors";
    case ParseErrors::kNoPatients:
      return "kNoPatients";
    case ParseErrors::kNoEthnicities:
      return "kNoEthnicities";
    case ParseErrors::kMissingPatient:
     return "kMissingPatient";
    default:
      // not possible with enum
      return std::string();
  }
}

// Returns the number of patients found in the string array parameter values[]
// as specified by the input format in hw2.pdf.
//
//   + Precondition: size parameter is no larger than the number of elements in
//                   values[] parameter
//   + Postcondition: when output parameter errors is not nullptr, it will
//                    contain:
//       * kNoErrors : when execution is normal
//       * kNoPatients : when number of patients is 0
//   + Returns: unsigned integral value of number of patients
//
std::size_t ParseNumPatients(const std::string values[],
                             std::size_t size,
                             ParseErrors* errors = nullptr);


// Returns the number of ethnicities date for a patient specified by string id
// parameter found in the string array parameter.
//
//   + Precondition: size parameter is no larger than the number of elements in
//                   values[] parameter
//   + Postcondition: when output parameter errors is not nullptr, it will
//                    contain:
//     * kNoErrors
//     * kNoPatients when number of patients is 0
//     * kNoEthnicities when there are none given
//     * kMissing patient if patient id is not found
//   + Returns: an unsigned integral value representing the number of
//     ethnicities for a patient specified by the patient_id paramter
std::size_t ParseNumEthnicities(const std::string& patient_id,
                                const std::string values[],
                                std::size_t size,
                                ParseErrors* errors = nullptr);


// Returns the ethnicity values for a patient, given the patient's patient_id.
//
//   + Preconditions:
//       * size parameter is no larger than the number of elements in values
//       * ethnicity_values output parameter is large enough to hold all
//         ethnicities for the specified patient id
//   + Postconditions:
//       * Output parameter ethnicity_values contains the ethnicity values for
//         the patient specified by the patient_id parameter
//       * When if output parameter errors is not nullptr, it will contain
//         - kNoErrors : when execution normal
//         - kNoPatients : when number of patients is 0
//         - kMissingPatient : patient if patient id is not found
//         - kNoEthnicities : when no ethnicities are found
//   + Returns:
//       * An unsigned integral value representing the number of ethnicity
//         values copied into the output parameter ethnicity_values,
//       * A 0 if there are no patients, ethnicities, or the specified patient
//         id does not exist.
std::size_t ParseEthnicityValues(const std::string& patient_id,
                                 const std::string values[],
                                 std::size_t size,
                                 char ethnicity_values[],
                                 ParseErrors* errors = nullptr);
#endif //HW2_INC_PARSE_DEMOGRAPHICS_H_
