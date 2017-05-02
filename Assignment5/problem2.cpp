#include <iostream>
using namespace std;

#include "linalg.hpp"
using namespace cpt;

int main()
{


    double m1 = 12, m2 = 16;

    // Matrix with masses as the diagonal elements
    Matrix<double,2> M(5, 5);
    M(0,0) = m2;
    M(1,1) = m1;
    M(2,2) = m1;
    M(3,3) = m1;
    M(4,4) = m2;
    cout << "M =\n" << M;


    Matrix<double,2> Minv(5,5);
    inverse(M, Minv);
    cout << "Minv=" << endl << Minv << endl;

    // "Spring" constants affecting each mass
    double k1 = 1.0, k2 = 1.1;
    double Lagrange[5][5] = {
      {   k2,    -k2,       0     ,  0,   0  },
      {   -k2,   k1+k2,  -k1,   0,    0    },
      {   0,      -k1,       2*k1,   -k1,    0     },
      {   0,      0,      -k1,    k1+k2,    -k2  },
      {   0,      0,     0,    -k2,     k2}
    };
    Matrix<double,2> K(5, 5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            K(i,j) = Lagrange[i][j];
    cout << "K =\n" << K;




    // Solve with generalized eigenvector solution
    Matrix<double,1> eigenvalues = solve_eigen_generalized(K, M, true);

    cout << "Eigenvalues =\n" << eigenvalues << endl
         << "Eigenvectors =\n" << K;


}
