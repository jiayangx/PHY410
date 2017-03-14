#include "StudentRecord.h"
#include<vector>

StudentRecord::StudentRecord(){}

std::string StudentRecord::firstname() const {return firstname_;}
std::string StudentRecord::lastname() const {return lastname_;}
float StudentRecord::score() const {return score_;}

void StudentRecord::print ( std::ostream & out ) const  { 
  out << lastname() << "," << firstname() << "," << score() << std::endl;
}

bool StudentRecord::input ( std::istream & in ) {
  std::string line;
  std::getline( in, line, ',');
  firstname_ = line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline(in, line);
  score_ = std::atof( line.c_str() );
  if ( line == "") 
    return false;
  else
    return true;
}

bool StudentRecord::operator>( StudentRecord const & right ) const {
  return this->score() > right.score();
};

bool StudentRecord::operator>=( StudentRecord const & right ) const {
  return this->score() >= right.score();
};

bool StudentRecord::operator<( StudentRecord const & right ) const {
  return this->score() < right.score();
};

bool StudentRecord::operator<=( StudentRecord const & right ) const {
  return this->score() <= right.score();
};

void StudentRecord::compute_score(void) {

  if ( scores_.size() == 0 ) {
    return ;
  }

  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    double iscore = scores_[i];
    score_ += iscore;
  }
  score_ /= scores_.size();

}
