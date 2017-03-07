#include <iostream>
#include "StudentRecord.h"
#include <string>
#include <vector>
#include <fstream>

void print_value (std::vector<StudentRecord> *idname);{
  idname->size();
  int j=0;
  std::string lna, fna;
  std::cin >> j;
  if (j > idname){
    std::cout << "Invalid input!" << std::endl;
    else {
      for (unsigned int i=0; i < idname->size(); i++ ){
	if (j==i){
	  lna=ln_;
	  fna=fn_;
	  std::cout << lna << "," << fna << "," << s_ << std::endl;
	}
	else {}
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

  print_value( &p_vector);
  return 0;
}
