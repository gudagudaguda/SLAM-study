#include <iostream>
#include <Eigen/Dense>

int main() {
  using namespace std;
  using namespace  Eigen;
  MatrixXd matrix = MatrixXd::Random(5, 5);
  MatrixXd I33 = MatrixXd::Identity(3, 3);
  cout << "matrix: \n" << matrix << endl;
  cout << "top 3 x 3 block: \n" <<  matrix.block<3, 3>(0, 0) << endl;
  // replace with a block of 3x3 identity matrix
  matrix.block<3, 3>(0, 0) = I33;
  cout << "matrix: \n" << matrix << endl;
  return 0;
}
