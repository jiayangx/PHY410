#ifndef StudentRecord_h
#define StudentRecord_h

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

class StudentRecord {
 public:
  StudentRecord();
  ~StudentRecord(){}

  std::string firstname() const;
  std::string lastname() const;
  float score() const;

  virtual void print ( std::ostream & out = std::cout ) const = 0;

  virtual bool input ( std::istream & in ) = 0;

  virtual void compute_score ( void ) = 0;

  bool operator>( StudentRecord const & right ) const;
  bool operator<( StudentRecord const & right ) const;
  bool operator>= (StudentRecord const & right ) const;
  bool operator<= (StudentRecord const & right ) const;

 protected:
  std::string firstname_;
  std::string lastname_;
  std::vector<float> scores_;
  float score_;

  void compute_average(void);
};

#endif
