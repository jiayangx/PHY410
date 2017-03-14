#include "StudentRecordPhysics.h"

StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics(){};

void StudentRecordPhysics::print( std::ostream & out ) const {
  out << "Physics score: " << lastname_ << "," << firstname_
      << ", homework: " << scores_[0] << ", lab: " << scores_[1]
      << ", average: " << score() << std::endl;
}

void StudentRecordPhysics::compute_score(void)  {
  if (scores_.size() == 0){return;}
  score_ = 0.;
  float iscore = 0.;
  for (unsigned int i=0; i < scores_.size(); ++i){
    if (i ==0){
      iscore = 0.8 * scores_[i];
      score_ += iscore;}
    else {
      iscore = 0.2 * scores_[i];
      score_ += iscore;
    }
  }
  score_ /= scores_.size();
}
      

bool StudentRecordPhysics::input( std::istream & in) {
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

void StudentRecordPhysics::clear (void){
  for (unsigned int j=0; j < scores_.size(); ++j){
    scores_.erase(scores_.begin());
  }
}
