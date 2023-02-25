#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

Matrix3d randomRotation() {
    Vector3d axis = Vector3d::Random().normalized();

    double angle = MatrixXd::Random(1, 1)(0, 0) * 2.0 * M_PI;

    Matrix3d K;
    K << 0.0, -axis(2), axis(1),
            axis(2), 0.0, -axis(0),
            -axis(1), axis(0), 0.0;
    Matrix3d R = Matrix3d::Identity() + sin(angle) * K + (1.0 - cos(angle)) * K * K;

    return R;
}


int main() {
    Matrix3d matrix_33 = randomRotation();
    Vector3d a = matrix_33.col(0);
    Vector3d b = matrix_33.col(1);
    Vector3d c = matrix_33.col(2);
    cout << "matrix_33 = " << endl << matrix_33 << endl;
    cout << "matrix_33 * matrix_33.transpose() = " << endl << matrix_33 * matrix_33.transpose() << endl;
    cout << "det " << a.transpose() * b.cross(c) << endl;
    return 0;
}
