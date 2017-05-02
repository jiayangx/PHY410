#include <cmath>
#include <iostream>
using namespace std;
 
#include "linalg.hpp"
using namespace cpt;
 
int main()
{
    double v0 = 10.0,
           r = 1;
 
    Matrix<double,2> v(7, 1);       // column vector with 3 rows
    v[0][0] = v0;

    cout << " v = \n" << v << endl;
    cout << "v.dim1 = " << v.dim1() << endl;
 
    Matrix<double,2> R(7, 7);       // 3x3 resistance matrix
      R[0][0] = r;              // set components using slicing notation
      R[0][4] = r; 
      R[0][5] = -2*r;
    //   R(0,0) = r;
    //   R(0,2) = 3*r;
    //   R(0,5) = r;
    //   R(0,6) = -2*r;
 
    R[1][0] = -2*r;
    R[1][2] = 2*r;
    R[1][5] = -r;
    R[1][6] = -r;
 
    R(2,1) = -r;               // or use subscripting notation
    R(2,2) = r;
    R(2,3) = r;
    R(2,6) = r;

    R(3,3) = 2*r;
    R(3,4) = 2*r;           
    R(3,5) = -r;
    R(3,6) = -r;

    R(4,0) = 2*r;
    R(4,2) = r;              
    R(4,4) = -r;
    R(4,5) = 4*r;
    R(4,6) = -r;

    R(5,0) = -r;               
    R(5,1) = r;
    R(5,4) = r;
    R(5,5) = r;

    R(6,0) = -r;
    R(6,2) = -2*r;              
    R(6,3) = -r;            
    R(6,5) = -r;
    R(6,6) = 4*r;

    cout << " R = \n" << R << std::endl;
    cout << " R.dim1 = " << R.dim1() << endl;
    cout << " R.dim2 = " << R.dim2() << endl;
 
    // the solve_Gauss_Jordan replaces R by R^-1 and v by i
    // so save the original R and copy v into a vector i
    Matrix<double,2> R_save(R), i(v);
 
    solve_Gauss_Jordan(R, i);
    
 
    // find all currents
    cout << " i_1 = " << i[0] << '\n'
         << " i_2 = " << i[1] << '\n'
         << " i_3 = " << i[2] << '\n'
         << " i_4 = " << i[3] << '\n'
         << " i_5 = " << i[4] << '\n'
         << " i_6 = " << i[5] << '\n'
         << " i_7 = " << i[6] << '\n'
         << " i_8 = " << i[2] - i[6] << '\n'
         << " i_9 = " << i[6] - i[3] << '\n'
         << " i_10 = " << i[2] + i[0] + i[5] - i[6] << '\n'
         << " i_11 = " << i[0] + i[5] << '\n'
         << " i_12 = " << i[4] - i[5]<< '\n'
         << " i = i_1 + i_2 + i_3 = " << i[0] + i[1] + i[2] << '\n'
      //  << " or i = i_9 + i_10 + i_12 = " << i[0] + i[2] - i[3] + i[4] << '\n'
         << endl;
 
    // see whether LU decomposition gives the same answer
    //    i = v;
    //   solve_LU_decompose(R_save, i);
    //       cout << " i_1 = " << i[0] << '\n'
	  //       << " i_2 = " << i[1] << '\n'
    //      << " i_3 = " << i[2] << '\n'
    //        << " i_4 = " << i[3] << '\n'
	      //      << " i_5 = " << i[4] << '\n'
    //        << " i_6 = " << i[5] << '\n'
	      //        << " i_7 = " << i[6] << '\n'
    //        << " i_8 = " << i[2] - i[6] << '\n'
    //       << " i_9 = " << i[6] - i[3] << '\n'
    //        << " i_10 = " << i[2] + i[3] + i[5] - i[6] << '\n'
    //        << " i_11 = " << i[3] + i[5] << '\n'
    //       << " i_12 = " << i[4] - i[5]<< '\n'
  //       << " i = i_1 + i_2 + i_3 = " << i[0] + i[1] + i[2] << '\n'
  //       << endl;
}
