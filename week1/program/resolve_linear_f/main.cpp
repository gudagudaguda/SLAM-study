#include <iostream>
#include <Eigen/Dense>

int main()
{
    using namespace std;
    using namespace Eigen;
    MatrixXd A = MatrixXd::Random(3, 3);
    A = A * A.transpose(); // A*A^T是半正定矩阵

    // 随机生成3x1的三维向量b
   VectorXd b = VectorXd::Random(3);

    //直接求逆 计算成本高
    VectorXd x = A.inverse() * b;
    cout << "Directly solve: " << x.transpose() << endl;

    // QR分解
    x << A.colPivHouseholderQr().solve(b);
    cout << "QR decomposition: " << x.transpose() << endl;

    // LU分解
    x << A.lu().solve(b);
    cout << "LU decomposition: " << x.transpose() << endl;

    // Cholesky分解 必须是正定矩阵
    LLT<MatrixXd> lltOfA(A);
    x << lltOfA.solve(b);
    cout << "Cholesky decomposition: " << x.transpose() << endl;

    //高斯消元法
    x << A.partialPivLu().solve(b);
    cout << "Gaussian elimination: " << x.transpose() << endl;

    // 雅可比迭代法
    int maxIter = 50000;
    double eps = 1e-6;
    x.setZero();
    VectorXd xNext = x;
    for (int iter = 0; iter < maxIter; iter++) {
        for (int i = 0; i < A.rows(); i++) {
            double sum = 0.0;
            for (int j = 0; j < A.cols(); j++) {
                if (j != i) {
                    sum += A(i, j) * x(j);
                }
            }
            xNext(i) = (b(i) - sum) / A(i, i);
        }
        double norm = (xNext - x).norm();
        if (norm < eps) {
            x = xNext;
            cout << "Iter: " << iter << ", ";
            break;
        }
        x = xNext;
    }
    cout << "Jacobi iteration: " << x.transpose() << endl;

    // 高斯-赛德尔迭代法
    maxIter = 100;
    eps = 1e-6;
    x.setZero();
    xNext = x;
    for (int iter = 0; iter < maxIter; iter++) {
        for (int i = 0; i < A.rows(); i++) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; j++) {
                sum1 += A(i, j) * xNext(j);
            }
            for (int j = i + 1; j < A.cols(); j++) {
                sum2 += A(i, j) * x(j);
            }
            xNext(i) = (b(i) - sum1 - sum2) / A(i, i);
        }
        double norm = (xNext - x).norm();
        if (norm < eps) {
            x = xNext;
            cout << "Iter: " << iter << ", ";
            break;
        }
        x = xNext;
    }
    cout << "Gauss-Seidel iteration: " << x.transpose() << endl;

    maxIter = 100;
    eps = 1e-6;
    double omega = 1.2; // 松弛因子
    x.setZero();
    xNext = x;
    for (int iter = 0; iter < maxIter; iter++) {
        for (int i = 0; i < A.rows(); i++) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; j++) {
                sum1 += A(i, j) * xNext(j);
            }
            for (int j = i + 1; j < A.cols(); j++) {
                sum2 += A(i, j) * x(j);
            }
            xNext(i) = (1.0 - omega) * x(i) + (omega / A(i, i)) * (b(i) - sum1 - sum2);
        }
        double norm = (xNext - x).norm();
        if (norm < eps) {
            x = xNext;
            cout << "Iter: " << iter << ", ";
            break;
        }
        x = xNext;
    }
    cout << "SOR method: " << x.transpose() << endl;

    // 共轭梯度法
    x.setZero();
    x = A.selfadjointView<Upper>().ldlt().solve(b);
    cout << "Cholesky decomposition: " << x.transpose() << endl;

    return 0;
}

