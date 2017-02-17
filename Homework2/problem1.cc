#include <iostream>

int main(){
  
  float x1, y1, x2, y2, midpointx,midpointy, slope, xintercept, yintercept;
  std::cout << "Please enter x1 y1 x2 y2: ";
  std::cin >> x1 >> y1 >> x2 >> y2;
  midpointx=(x1+x2)/2;
  midpointy=(y1+y2)/2;
  if (x2==x1){
    std::cout << "Slope is undefined" <<'\n';
    std::cout << "y intercept is y-axis" <<'\n';
    std::cout << "The midpoint is: (" << midpointx << "," << midpointy << ")"<<'\n';
    std::cout << "And the line equation: x=" << x1 <<'\n'; }
  else {slope=(y2-y1)/(x2-x1);
  yintercept=y1-slope*x1;
  std::cout << "The midpoint is: (" << midpointx << "," << midpointy << ")"<< '\n';
  std::cout << "The slope is: " << slope << '\n';
  std::cout << "And the line equation: y=" << slope << "x+" << yintercept << '\n';}

  return 0;
}
  
    
