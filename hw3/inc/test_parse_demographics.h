// Copyright 2024
//
#ifndef HW3_INC_TEST_PARSE_DEMOGRAPHICS_H_
#define HW3_INC_TEST_PARSE_DEMOGRAPHICS_H_


#include <hw3_sol/inc/parse_demographics.h>

#include <cstddef>
#include <iostream>
#include <string>

// Generally useful constants
//
const std::size_t kDemRows = 3;
const std::size_t kDemDobSize = 3;


// Test 1 constants
//
// input
// {
//  {
//  "34A5",
//  "B", "3", "1", "02",
//  "E", "2", "W", "B"
//   }
// }
const std::size_t kTest1Rows = 1;
const std::size_t kTest1Cols[] = { 9 };
const std::string **kTest1Vals = new const std::string*[kTest1Rows] { // NOLINT
  new const std::string[kTest1Cols[0]] {
    "34A5",
      "B", "3", "1", "02",
      "E", "2", "W", "B"
  }
};
// expected output
// {
//  "34A5",
//  { "3", "1", "02" },
//  { "W", "B" }
// }
const std::size_t kExpect1Rows = kTest1Rows * kDemRows;
const std::size_t kExpect1Cols[kTest1Rows] = { 2 };
const std::string **kExpect1Vals = new const std::string*[kExpect1Rows] { // NOLINT
  new const std::string("34A5"),  // patient id
  new const std::string[kDemDobSize] {  // DoB
    "3", "1", "02"
  },
  new const std::string[kExpect1Cols[0]] {  // ethnicities
    "W", "B"
  },
};

// Test 2 constants
//
// input
// {
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
const std::size_t kTest2Rows = 3;
const std::size_t kTest2Cols[] = { 8, 10, 7 };
const std::string **kTest2Vals = new const std::string*[kTest2Rows] {
  new const std::string[kTest2Cols[0]] {
  "34A5",
    "E", "1", "B",
    "B", "3", "1", "02",
  },
  new const std::string[kTest2Cols[1]] {
  "5607",
    "B", "1", "1", "70",
    "E", "3", "P", "A", "H"
  },
  new const std::string[kTest2Cols[2]] {
  "4B56",
    "E", "0",
    "B", "10", "30", "98",
  }
};
// expected output
// {
//  "34A5",
//  { "3", "1", "02" },
//  "B",
//  "5607",
//  { "1", "1", "70" },
//  { "P", "A", "H" },
//  "4B56",
//  { "10", "30", "98" },
//  nullptr
// }
const std::size_t kExpect2Rows = kTest2Rows * kDemRows;
const std::size_t kExpect2Cols[kTest2Rows] = { 1, 3, 0 };
const std::string **kExpect2Vals = new const std::string*[kExpect2Rows] { // NOLINT
  // patient 1
  new const std::string("34A5"),  // patient id
  new const std::string[kDemDobSize] {  // DoB
    "3", "1", "02"
  },
  new const std::string("B"),  // ethnicities
  // patient 2
  new const std::string("5607"),  // patient id
  new const std::string[kDemDobSize] {  // DoB
    "1", "1", "70"
  },
  new const std::string[kExpect2Cols[1]] {  // ethnicities
    "P", "A", "H"
  },
  // patient 3
  new const std::string("4B56"),  // patient id
  new const std::string[kDemDobSize] {  // DoB
    "10", "30", "98"
  },
  nullptr,  // ethnicities
};


bool Equals(const std::size_t rows, const std::size_t eth_nums[],
            const std::string** expected, const std::string** actual);

bool IdsEqual(const std::size_t index, const std::string** expected,
              const std::string** actual);

bool DoBsEqual(const std::size_t index, const std::string** expected,
               const std::string** actual);

bool EthsEqual(const std::size_t index, const std::size_t eth_num,
               const std::string** expected, const std::string** actual);

void PrintTest(const std::size_t rows,
           const std::size_t cols[],
           const std::string** values);


void PrintExpected(const std::size_t patient_num,
           const std::size_t eth_nums[],
           const std::string** values);


void DeleteActual(const std::size_t patient_num, const std::size_t eth_nums[],
                  const std::string** values);

#endif  // HW3_INC_TEST_PARSE_DEMOGRAPHICS_H_
