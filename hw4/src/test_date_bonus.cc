// Copyright 2024 CSCE240
//


#include <hw4/inc/date.h>

#include <cstddef>
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
  std::cout << "Testing implicit conversion/comparison to std::string\n"
    << "    Good job on compilation, +0.5 bonus points." << std::endl;

  const std::string kExpected = "06-08-1999";
  const Date kTestDate(kExpected);

  const std::string kActual = kExpected;

  if (kExpected == kActual && kExpected == static_cast<std::string>(kTestDate)) {
    std::cout << "    Passed! +0.5 points" << std::endl;

    return 0;
  }

  std::cout << "    Expected: " << kExpected << std::endl
    << "    Actual: " << kActual << std::endl;

  return 1;
}

