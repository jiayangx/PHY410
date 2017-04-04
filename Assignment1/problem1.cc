#include <iostream>
#include <cmath>

const int n = 9;

double r[n] = {0.033, 0.25675, 0.483, 0.63, 0.88, 1.067, 1.4, 1.7, 2.0};
double v[n] = {230, -151.25, 253.3, 200, 214, 623.3, 500, 960, 810};

int main (void) {
  double s_x = 0, s_y = 0, s_xx = 0, s_xy = 0;

  if (n<2) {
    std::cout << "Error! Need at least two data points!" << std::endl;
    return 0;
  }

  for (int i = 0; i<n; i++) {
    s_x += r[i];
    s_y += v[i];
    s_xx += r[i] * r[i];
    s_xy += r[i] * v[i];
  }

  std::cout << s_x << " " << s_y << " " << s_xx << " " << s_xy << std::endl;

  double denom = n * s_xx - s_x * s_x;

  if ( fabs(denom) < 0.000001) {
    std::cout << "Error! Denominator is zero!" << std::endl;
    return 0;
  }

  double a = (s_xx * s_y - s_x * s_xy) / denom;
  double b = (n * s_xy - s_x * s_y) / denom;

  std::cout << denom << " " << a << " " << b << std::endl;

  double sum = 0;
  for (int i=0; i<n; i++) {
    double v_of_r_i = a + b * r[i];
    double error = v[i] - v_of_r_i;
    sum += error * error;
  }

  double sigma = (n>2) ? sqrt (sum / (n-2)) : 0;

  double sigma_a = sqrt(sigma * sigma * s_xx / denom);
  double sigma_b = sqrt(sigma * sigma * n / denom);

  std::cout.precision(4);
  std::cout << " Least-squares fit of " << n << " data points\n"
	    << " Hubble's constant slope   b = " << b
	    << " +- " << sigma_b << " km/Mpc\n"
	    << " Intercept with r axis    a = " << a
	    << " +- " << sigma_a << " km/s\n"
	    << " Estimated v error bar sigma = " << sigma << " km/s" << std::endl;

}
  
