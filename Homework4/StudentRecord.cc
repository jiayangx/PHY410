#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "StudentRecord.h"


StudentRecord::StudentRecord (std::string ix, std::string iy, float iz) {
  ln_=ix;
  fn_=iy;
  s_=iz;
}

StudentRecord::~StudentRecord(){}


bool StudentRecord::input (std::istream & in ) {
  std::string line;
  std::getline ( in, line, ',');
  ln_=line;
  std::getline ( in, line, ',');
  fn_=line;
  std::getline (in, line);
  s_=std::atof ( line.c_str() );
  if (line == "")
    return false;
  else
    {return true;}
}
  
void StudentRecord::print() const {
  std::cout << ln_ << "," << fn_ << "," << s_ << std::endl;
}
float StudentRecord::z() const {return s_;}
std::string StudentRecord::x() const { return ln_;}
std::string StudentRecord::y() const { return fn_;}

StudentRecord & StudentRecord::operator/=( StudentRecord const & right) {
  s_/= right.s_;
  return *this;
}
