#include "StudentRecordHistory.h"

StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory(){};

void StudentRecordHistory::print( std::ostream & out ) const {
  out << "History score: " << lastname_ << "," << firstname_
      << ", exam1: " << scores_[0] << ", exam2: " << scores_[1]
      << ", average: " << score() << std::endl;
}

void StudentRecordHistory::compute_score (void){
  if (scores_.size() == 0){return;}
  score_= 0.;
  float a = 0., b = 0., c = 0.;
  for (unsigned int i=0; i < scores_.size(); ++i){
    a = scores_[i];
    if (a > b){
      c = b;
      b = a;
    }
  }
  score_= 0.6*b+0.4*c;
}


bool StudentRecordHistory::input( std::istream & in) {
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  std::getline( in, line, ',');
  scores_.push_back( std::atof( line.c_str() ) );
  std::getline( in, line );
  scores_.push_back( std::atof( line.c_str() ) );
  if ( line == "")
    return false;
    else {
      compute_score();
      return true;
    }
}

void StudentRecordHistory::clear (void){
  for (unsigned int j=0; j < scores_.size(); ++j){
    scores_.erase(scores_.begin());
  }
}
