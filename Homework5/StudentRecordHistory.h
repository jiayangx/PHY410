#ifndef StudentRecordHistory_h
#define StudentRecordHistory_h

#include "StudentRecord.h"

class StudentRecordHistory : public StudentRecord {

 public:

  StudentRecordHistory();
  ~StudentRecordHistory();

  std::string firstname() const;
  std::string lastname() const;

  void print( std::ostream & out = std::cout ) const;

  bool input( std::istream & in );

  void compute_score(void);

  void clear(void);
};

#endif
