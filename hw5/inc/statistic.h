#include <cstddef>

// Create the abstract class. It must implement the following methods, provide
// a pure virtual method for its child Median, use the private
// hw5::Statistic::store_ member to manage memory, and maintain friend class
// hw5::StatisticTest declaration.
//
// Points:
//   - Styled Header: 0.5 POINTS
//   - Styled Source: 0.5 POINTS
//   - Compilation (make bin/statistic.o): 0.5 POINTS
//   - Compilation against tests (make test-statistic): 0.5 POINTS
//   - Default Constructor: 1.0 POINTS
//   - Copy Constructor: 0.0 POINTS (tested using hw5::Median)
//   - Destructor: 1.0 POINTS (tested via valgrind and a lack of segfaults)
//   - Collect Method: 1.0 POINTS
//   - Assignment operator: 1.0 POINTS
//

class Statistic {
 public:
  // Default Constructor : 1.0 POINTS
  //
  Statistic();

  // Copy Constructor
  //   Must be tested using Median; you may and often must call parent
  //   constructors and methods from child constructors and methods.
  Statistic(const Statistic&);


  // Destructor : 1.0 POINTS
  //
  virtual ~Statistic();


  // Assignment Operator : 1.0 POINTS
  //
  Statistic& operator=(const Statistic&);


  // Collect Method: 1.0 POINTS
  //   Extends collection of stored values. It may allocate memory or increase
  //   memory allocation as required to append the parameter to the
  //   hw5::Statistic::store_ class member.
  void Collect(double);


  // To be implemented by some concrete child class, i.e., hw5::Median
  virtual double Calculate() const = 0;


 private:
  // dynamic array of doubles on which child classes will perform statistic
  // calculations
  //
  double *store_;  // do not delete, rename, or move to non-private scope


  // you may add others as necessary

 public:
  // Used by test software, do not delete, leave in public section of class
  //
  friend class StatisticTest;
};
