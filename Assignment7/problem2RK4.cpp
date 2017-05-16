#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "nonlin.hpp"
#include "diffeq.hpp"

using namespace std;
using namespace cpt;

class LorenzFunction {
public : 
  LorenzFunction( double isigma=0, double ibeta = 0, double irho = 0 ) :
    sigma( isigma ),beta(ibeta),rho(irho)
  {
  }
       

protected :                     
 
  double sigma;                 
  double beta;                   
  double rho;               
  
};
  


class LorenzDiffEq : public LorenzFunction {
public : 

  LorenzDiffEq( double sigma = 0, double beta=0, double rho = 0 ) : 
    LorenzFunction( sigma, beta, rho ) {}

  Matrix<double,1> operator()( Matrix<double,1> const & p) const {
    double x = p[0], y = p[1], z = p[2];
    
    Matrix<double,1> out(3);
    out[0] = sigma * (p[1] - p[0]);
    out[1] = p[0] * (rho - p[2]) - p[1];
    out[2] = p[0] * p[1] - beta * p[2];

    return out;
  }

};



int main() {

  clock_t tStart = clock();

  double sigma = 10.0;
  double beta = 9/3;
  double rho = 28.0;
  

					   
  //* Set initial position
  double x = 1;
  double y = 1;        
  double z = 1;



  double tau = 0.05;



  LorenzDiffEq lorenzDiffEq( sigma, beta, rho);



  double accuracy = 1e-6;

  //* Take one backward step to start Verlet

  Matrix<double,1> xv(3);
  xv[0] = x;
  xv[1] = y;
  xv[2] = z;
 



  //* Loop over desired number of steps with given time step
  //    and numerical method
  int nStep = 10000;


  bool plotTrajectory = true; // plot Poincare and trajectory if true.
                              // plot only Poincare if false.



  std::vector<double> x_plot;
  std::vector<double> y_plot;
  std::vector<double> z_plot;
  double dt_min = tau;
  double dt_max = tau;
  int iStep;
  for( iStep=0; iStep<nStep; iStep++ ) {  




    //* Record angle and time for plotting
    if ( plotTrajectory ) {
      x_plot.push_back( xv[0] );
      y_plot.push_back( xv[1] );
      z_plot.push_back( xv[2] );

    }
    


    cpt::RK4_step(xv,tau,lorenzDiffEq);

  }
    
    


  //* Print out the plotting variables
  int i;
  if ( plotTrajectory ) {
    ofstream plotOut("LorenzRK4_plot.txt");
    for( i=0; i< x_plot.size(); i++ ) {
      plotOut << x_plot[i] << " "  << y_plot[i] << " " << z_plot[i] << endl;
    }
    plotOut.close();
  }



  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

  return 0;

}
