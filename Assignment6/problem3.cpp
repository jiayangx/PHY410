#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "nonlin.hpp"
using namespace cpt;

double f(Matrix<double,1>& p, Matrix<double,1>& x, Matrix<double,1>& y, int s) {
      double a = p[0], b = p[1], c = p[2];
      double fe = 0.0;
      for (int i = 0; i < s; i++ ) {
	fe += ( y[i] - a*x[i]*x[i] - b*x[i] - c) * ( y[i] - a*x[i]*x[i] - b*x[i] - c);
      };
      return fe;
    }

void df(Matrix<double,1>& p, Matrix<double,1>& dp,  Matrix<double,1>& x, Matrix<double,1>& y, int s ) {
      double a = p[0], b = p[1], c = p[2];
      dp[0] = 0.0;
      dp[1] = 0.0;
      dp[2] = 0.0;
      for (int i = 0; i < s; i++ ) {
	dp[0] += -2*x[i]*x[i]*( y[i] - a*x[i]*x[i] - b*x[i] - c);
      };
      for (int i = 0; i < s; i++ ) {
	dp[1] += -2*x[i]*( y[i] - a*x[i]*x[i] - b*x[i] - c);
      };
      for (int i = 0; i < s; i++ ) {
	dp[2] += -2*( y[i] - a*x[i]*x[i] - b*x[i] - c);
      };
      return;
    }

int main()
{
  using namespace std; 


    // data downloaded from http://neic.usgs.gov/neis/epic/epic_global.html
    const string co2_data("co2_mm_mlo.txt");

    cout << " CO2 data " << endl;

    vector<double> x_values, y_values;

    // read the data file
    ifstream data_file(co2_data.c_str());
    if (data_file.fail()) {
        cerr << "cannot open " << co2_data << endl;
        exit(EXIT_FAILURE);
    } else
      cout << " reading data file: " << co2_data << endl;
    string line; 
    int j = 0; 
    while (getline(data_file, line)) {
        if (line.c_str()[0] != '#') {    
          stringstream sline(line);
          int year=0,month=0,days=-1;
          double date=0., average = 0., interp = 0., trend = 0.;
          sline >> year >> month >> date >> average >> interp >> trend >> days;
	  x_values.push_back( date );
	  y_values.push_back( interp );
          ++j; 
        }
    }

    data_file.close();


    cpt::Matrix<double,1> xvec(x_values.size());
    cpt::Matrix<double,1> yvec(x_values.size());
    cpt::Matrix<double,1> sigma(x_values.size());


    for ( unsigned int i = 0; i < x_values.size(); i++ ) {
      xvec[i] = x_values[i];
      yvec[i] = y_values[i];
      sigma[i] = 0.001; //sqrt(y_values[i]);
    }


    Matrix<double,1> p(3);
    Matrix<double,1> dp(3);
    cin >> p[0] >> p[1] >> p[2];
    cout << " Enter desired accuracy: ";
    double gtol;
    cin >> gtol;
    double f_min;
    int iterations;
    int s = x_values.size();
    double fa = 0;
    double dfa = 0;

    fa = f(p, xvec, yvec, s);
    dfa = df(p, dp, xvec, yvec, s);



    
    minimize_BFGS(p, gtol, iterations, f_min, f, df);
    cout << " f(" << p[0] << ", " << p[1] << ", " << p[2] << ")  "<< f_min
	 << " in " << iterations << " iterations" << endl;

}
