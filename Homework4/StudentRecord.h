#ifndef StudentRecord_h
#define StudentRecord_h

#include <string>
#include <iostream>
#include <istream>


class StudentRecord {
 public:
  StudentRecord (std::string ix=0, std::string iy=0, float iz=0. );
  ~StudentRecord();
 bool input (std::istream & in);
 void print() const;
 float z() const;
 std::string x() const;
 std::string y() const;
 StudentRecord & operator/=( StudentRecord const & right );

 private:
  std::string ln_;
  std::string fn_;
  float s_;
  
};

  #endif
