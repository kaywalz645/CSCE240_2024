// Copyright 2024 CSCE Programming Assignment 5
//
#ifndef _HW5_INC_TEST_DATA_H_
#define _HW5_INC_TEST_DATA_H_


#include <cstddef>


const std::size_t kTest1Size = 5;
const double kTest1Data[kTest1Size] = {
  34, 54, 99, 102, 43
};
const double kTest1Expected = 54;


const std::size_t kTest2Size = 6;
const double kTest2Data[kTest2Size] = {
  34, 55, 99, 102, 22, 43
};
const double kTest2Expected = 49;

#endif  // _HW5_INC_TEST_DATA_H_
