#include <cstddef>
#include <string>


// Accepts the necessary parameters to describe a multi-dimensional array of the
// type described in hw3/inc/test_parse_demographics.h
//
//  {
//  "34A5",
//  "B", "3", "1", "02",
//  "E", "2", "W", "B"
//   }
//  }
//   - or -
//  {
//  "34A5",
//     "E", "1", "B"
//     "B", "3", "1", "02",
//   }, {
//   "5607",
//     "B", "1", "1", "70",
//     "E", "3", "P", "A", "H"
//   }, {
//   "4B56",
//     "E", "0",
//     "B", "10", "30", "98",
//   }
// }
//
// Returns a const pointer to a two dimensional array of the type described in
// hw3/inc/test_parse_demographics.h
//
//  {
//   "34A5",
//   { "3", "1", "02" },
//   { "W", "B" }
//  }
//   - or -
//  {
//   "34A5",
//   { "3", "1", "02" },
//   "B",
//   "5607",
//   { "1", "1", "70" },
//   { "P", "A", "H" },
//   "4B56",
//   { "10", "30", "98" },
//   nullptr
//  }
//
//  A const pointer can be achieved as follows, given
//  std::string** eg;
//  const std::string** const_eg = const_cast<const std::string**>(eg);
//
const std::string** ParseDemographics(const std::size_t rows,
                                      const std::size_t cols[],
                                      const std::string** values);
