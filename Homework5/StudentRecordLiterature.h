#ifndef StudentRecordLiterature_h
#define StudentRecordLiterature_h

#include "StudentRecord.h"

class StudentRecordLiterature : public StudentRecord {

 public:

  StudentRecordLiterature();
  ~StudentRecordLiterature();

   void print( std::ostream & out = std::cout ) const;

   bool input( std::istream & in );

   void compute_score(void);

   void clear(void);
};


#endif
