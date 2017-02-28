#include <iostream>
#include <cmath>
#include <limits>



int main(void){
  int   b=0, n=0, m=0, i=0;
  float a=0;
  float x [50]={};
  float y [50]={};
  float tolerance=0.0001f;

  //input
  std::cout << "Enter a set of 2-d vectors in the order of xi , yi. And enter exit when finished: " << std::endl;
  while (std::cin >> x[n] >> y[n]){
    n=n+1;
   }

  //calculate minimum magnitude
  float magnitude, magnitude2;
  magnitude2=x[0]*x[0]+y[0]*y[0];
   while (m<=n-1){
     a=x[m]*x[m]+y[m]*y[m];
     if (a - magnitude2 < tolerance) {
       magnitude2 = a;
       i = m;
     }
     m=m+1;
   }
     magnitude = sqrt( magnitude2);


   //output
  std::cout << "Vector ( " << x[i] << " , " << y[i] << " ) has the minimum magnitude: " << magnitude << std::endl;
  return 0;
}
