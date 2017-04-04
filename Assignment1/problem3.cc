#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// ---------------- declare global variables ----------------

string url("http://dark.dark-cosmology.dk/~tamarad/SN/");
string data_file_name("Davis07_R07_WV07.dat");
//string data_file_name("error1.dat");
//string data_file_name("error2.dat");
//string data_file_name("error3.dat");
//string data_file_name("error4.dat");

vector<double>               // C++ std template vector type
  z_data,                    // redshift - column 2 in data file
  mu_data,                   // distance modulus - column 3
  mu_err_data,               // error in distance modulus - column 4
  zl_data,
  mul_data,
  mul_err_data,
  zh_data,
  muh_data,
  muh_err_data;

// ---------------- function declarations ----------------

void read_data();            // opens and reads the data file

void chi_square_fit(         // makes a linear chi-square fit
  const vector<double>& x,   // vector of x values - input
  const vector<double>& y,   // vector of y values - input
  const vector<double>& err, // vector of y error values - input
  double& a,                 // fitted intercept - output
  double& b,                 // fitted slope - output
  double& sigma_a,           // estimated error in intercept - output
  double& sigma_b,           // estimated error in slope - output
  double& chi_square         // minimized value of chi-square sum - output
);

// ---------------- function definitions ----------------

int main() {

  cout << " Chi-square fit of supernova data to a straight line\n"
       << " Reference: " << url << endl;

  read_data();

  int n = z_data.size();

  for (int i = 0; i < n; i++) {
    if (z_data[i] < 0.5) {
      zl_data.push_back(z_data[i]);
      mul_data.push_back(mu_data[i]);
      mul_err_data.push_back(mu_err_data[i]);
    }
    else {
      zh_data.push_back(z_data[i]);
      muh_data.push_back(mu_data[i]);
      muh_err_data.push_back(mu_err_data[i]);
    }
  }
  
  double sep = 0.5;
  //  int n = z_data.size();
  int nl = zl_data.size();
  int nh = zh_data.size();
  vector<double> logz_data(n);
  vector<double> logzl_data(nl);
  vector<double> logzh_data(nh);

  //for (int i = 0; i<n; i++)
  //{cout << z_data[i] << endl;}


  //  for (int i = 0; i <nl; i++){
  //  cout << zl_data[i] << endl;}
  
  cout << nl << endl
       << nh << endl;
  
    for (int i = 0; i < nl; i++)
      logzl_data[i] = log10(zl_data[i]);   // to use mu = a + b log_10(z)

  for (int i = 0; i < nh; i++)
    logzh_data[i] = log10(zh_data[i]);

  double interceptl, intercepth, slopel, slopeh, interceptl_err, intercepth_err, slopel_err, slopeh_err, chisqrl, chisqrh;
  chi_square_fit(logzl_data, mul_data, mul_err_data,
                 interceptl, slopel, interceptl_err, slopel_err, chisqrl);
  chi_square_fit(logzh_data, muh_data, muh_err_data,
                 intercepth, slopeh, intercepth_err, slopeh_err, chisqrh);

  cout.precision(4);
  cout << " slope of low redshift = " << slopel << " +- " << slopel_err << "\n"
       << " intercept of low redshift= " << interceptl << " +- " << interceptl_err << "\n"
       << " chi-square/d.o.f of low redshift= " << chisqrl / (nl - 2) << endl;

  cout << " slope of high redshift = " << slopeh << " +- " << slopeh_err << "\n"
       << " intercept of high redshift= " << intercepth << " +- " << intercepth_err << "\n"
       << " chi-square/d.o.f of high redshift= " << chisqrh / (nh - 2) << endl;
}

void read_data() {

  // create an input file stream object and open the data file
  ifstream data_file(data_file_name.c_str());
  if (data_file.fail())
    cerr << "sorry, cannot open " << data_file_name << endl;

  // read the data file one line at a time
  string line;                         // string object to hold current line
  while (getline(data_file, line)) {   // std::getline defined in <string>

    if (line[0] == ';')                // skip lines starting with semicolon
      continue;

    string SN;                         // name of supernova in column 1
    double z, mu, mu_err;              // columns 2, 3, 4
    istringstream is(line);            // string stream object to read line
    is >> SN >> z >> mu >> mu_err;     // read successive column entries

    if (is.fail()) {                   // if a read error occurs
      cerr << "error reading line: "
           << line << endl;            // print an error message
      continue;
    }

    // store the data values in the data vectors
    z_data.push_back(z);
    mu_data.push_back(mu);
    mu_err_data.push_back(mu_err);
  }

  cout << " read " << z_data.size() << " data values" << endl;

  data_file.close();
}

void chi_square_fit(         // makes a linear chi-square fit
  const vector<double>& x,   // vector of x values - input
  const vector<double>& y,   // vector of y values - input
  const vector<double>& err, // vector of y error values - input
  double& a,                 // fitted intercept - output
  double& b,                 // fitted slope - output
  double& sigma_a,           // estimated error in intercept - output
  double& sigma_b,           // estimated error in slope - output
  double& chi_square)        // minimized value of chi-square sum - output
{
  int n = x.size();

  assert(n >= 2);

  double S = 0, S_x = 0, S_y = 0;
  for (int i = 0; i < n; i++) {
    assert ( fabs(err[i]) >= 0.000001 );
    S += 1 / err[i] / err[i];
    S_x += x[i] / err[i] / err[i];
    S_y += y[i] / err[i] / err[i];
  }

  vector<double> t(n);
  for (int i = 0; i < n; i++)
    t[i] = (x[i] - S_x/S) / err[i];

  double S_tt = 0;
  for (int i = 0; i < n; i++)
    S_tt += t[i] * t[i];

  b = 0;
  for (int i = 0; i < n; i++)
    b += t[i] * y[i] / err[i];
  assert( fabs(S_tt) > 0.00001);
  b /= S_tt;

  assert( fabs(S) > 0.00001);
  a = (S_y - S_x * b) / S;
  sigma_a = sqrt((1 + S_x * S_x / S / S_tt) / S);
  sigma_b = sqrt(1 / S_tt);

  chi_square = 0;
  for (int i = 0; i < n; i++) {
    double diff = (y[i] - a - b * x[i]) / err[i];
    chi_square += diff * diff;
  }
}
