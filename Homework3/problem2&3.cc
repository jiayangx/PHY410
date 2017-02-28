#include <iostream>
#include <cmath>
#include <typeinfo>

unsigned long int factorial (unsigned long int i=1){
  unsigned long int n;
  n=i;
  while (i>1){
    n=n*(i-1);
    i=i-1;}
  return n;}
unsigned long int Stirling (unsigned long int i=1){
  return exp(i*log(i)-i);}

int main (void){ 
  unsigned long int i;
  std::cout << "Please enter a nonnegative integer: " << std::endl;
  std::cin >> i;
  if (i==0) {std::cout << i << "! = 1" << std::endl;}
  else if (i<=20){
      std::cout << i << "! = " << factorial(i) << std::endl;}
  else
     {std::cout << i << "! = " << Stirling(i) << " (Used Stirling approximation)" << std::endl;}
  return 0;
}
  
  
