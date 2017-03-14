#ifndef StudentRecordPhysics_h
#define StudentRecordPhysics_h

#include "StudentRecord.h"

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

class StudentRecordPhysics : public StudentRecord{
 public:
  StudentRecordPhysics();
  ~StudentRecordPhysics();

  void print( std::ostream & out = std::cout ) const;

  bool input( std::istream & in );

  void compute_score(void) ;

  void clear(void);
};

#endif
