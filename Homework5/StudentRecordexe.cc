#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordHistory.h"
#include "StudentRecordLiterature.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

float calculate_average( std::vector<StudentRecord> const * records ){
  float average=0.;

  
  if ( records->size() > 0 ) {
    for( StudentRecord const & record: *records ) {
      average += record.score();
    }
    average /= records->size();
  }
  return average; 
}

int main(int argc, char * argv[]){

  if ( argc < 2 ) {
    std::cout << "Usage: " << argv[0] << " filename.txt" << std::endl;
    return 0;
  }
  std::ifstream fin( argv[1] );

  StudentRecord record;
  std::vector<StudentRecord> records;
  while( record.input(fin) ) {
    records.push_back(record);
    std::cout << "Added record: ";
    record.print();
  }

  std::cout << "Average : " << compute_score( &records ) << std::endl;
}
