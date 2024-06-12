// Copyright 2024 CSCE Programming Assignment 5
//
#ifndef _HW5_INC_STATISTIC_TEST_H_
#define _HW5_INC_STATISTIC_TEST_H_


#include <hw5/inc/median.h>
#include <hw5/inc/statistic.h>
#include <hw5/inc/test_data.h>

#include <cstddef>
#include <iostream>
#include <vector>


namespace hw5 {

// A class used to test the internal memory managed by Statistic class.
//
// All methods must be static so that static addresses may later be stored in
// function pointers.
//
class StatisticTest {
 public:
  static bool TestDefaultConstructor(Statistic*);
  static bool TestCollect(Statistic*);
  static bool TestCopyConstructor(Statistic*);
  static bool TestAssignmentOperator(Statistic*);

  static const double* store(const Median&);

  static bool Equals(const Statistic&, const Statistic&, std::size_t size);
};

}  // namespace hw5


void LoadStatistic(const double*, std::size_t, hw5::Statistic*);
bool TestMedianCalculate(const hw5::Statistic&, double);


#endif  // _HW5_INC_STATISTIC_TEST_H_
