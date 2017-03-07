#include <iostream>
#include "StudentRecord.h"
#include <string>
#include <vector>
#include <fstream>

void calculate_average ( std::vector<StudentRecord> *idname) {
  float average = 0. ;
  for (unsigned int i = 0; i < idname->size(); i++ ){
    (*idname)[i].print();
    average += (*idname)[i].z();
  }
  average /= idname->size();
  std::cout << "The average is " << average << std::endl;
}


int main (int argc, char **argv) {
  std::ifstream inputfile ( "records.txt");
  std::vector<StudentRecord> p_vector;

  bool valid = true;
  while (valid) {
    StudentRecord p1;
    valid = p1.input( inputfile );
    if (not valid)
      break;
    std::cout << "You input:" << std::endl;
    p1.print();
    p_vector.push_back(p1);
  }

  calculate_average( &p_vector);
  return 0;
}
