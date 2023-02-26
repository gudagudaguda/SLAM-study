#include <iostream>
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>

#define MATRIX_SIZE 100
int main()
{
    using namespace std;
    using namespace Eigen;
    clock_t time_stt;
    MatrixXd A = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    A = A * A.transpose(); // A*A^T是半正定矩阵

    // 随机生成3x1的三维向量b
   VectorXd b = VectorXd::Random(MATRIX_SIZE);

    //直接求逆 计算成本高
    time_stt = clock();
    VectorXd x = A.inverse() * b;
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "Directly solve: " << x.transpose() << endl;

    // QR分解
    time_stt = clock();
    x << A.colPivHouseholderQr().solve(b);
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "QR decomposition: " << x.transpose() << endl;

    // LU分解
    time_stt = clock();
    x << A.lu().solve(b);
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "LU decomposition: " << x.transpose() << endl;

    // Cholesky分解 必须是正定矩阵
    time_stt = clock();
    LLT<MatrixXd> lltOfA(A);
    x << lltOfA.solve(b);
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "Cholesky decomposition: " << x.transpose() << endl;

    //高斯消元法
    time_stt = clock();
    x << A.partialPivLu().solve(b);
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "Gaussian elimination: " << x.transpose() << endl;

    // 雅可比迭代法
    time_stt = clock();
    JacobiSVD<MatrixXd> jacobi(A, ComputeThinU | ComputeThinV);
    x << jacobi.solve(b);
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "Jacobi iteration: " << x.transpose() << endl;

//    // 高斯-赛德尔迭代法 n太大时手搓的for loop很难收敛
//    time_stt = clock();
//    int maxIter = 100000;
//    double eps = 1e-10;
//    x.setZero();
//    VectorXd xNext = x;
//    for (int iter = 0; iter < maxIter; iter++) {
//        for (int i = 0; i < A.rows(); i++) {
//            double sum1 = 0.0;
//            double sum2 = 0.0;
//            for (int j = 0; j < i; j++) {
//                sum1 += A(i, j) * xNext(j);
//            }
//            for (int j = i + 1; j < A.cols(); j++) {
//                sum2 += A(i, j) * x(j);
//            }
//            xNext(i) = (b(i) - sum1 - sum2) / A(i, i);
//        }
//        double norm = (xNext - x).norm();
//        if (norm < eps) {
//            x = xNext;
//            cout << "Iter: " << iter << ", ";
//            break;
//        }
//        x = xNext;
//    }
//    cout << "Time consumed: "
//         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
//         << "Gauss-Seidel iteration: " << x.transpose() << endl;

//    time_stt = clock();
//    maxIter = 100000;
//    eps = 1e-10;
//    double omega = 1.5;
//    x.setZero();
//    xNext = x;
//    for (int iter = 0; iter < maxIter; iter++) {
//        for (int i = 0; i < A.rows(); i++) {
//            double sum1 = 0.0;
//            double sum2 = 0.0;
//            for (int j = 0; j < i; j++) {
//                sum1 += A(i, j) * xNext(j);
//            }
//            for (int j = i + 1; j < A.cols(); j++) {
//                sum2 += A(i, j) * x(j);
//            }
//            xNext(i) = (1.0 - omega) * x(i) + (omega / A(i, i)) * (b(i) - sum1 - sum2);
//        }
//        double norm = (xNext - x).norm();
//        if (norm < eps) {
//            x = xNext;
//            cout << "Iter: " << iter << ", ";
//            break;
//        }
//        x = xNext;
//    }
//    cout << "Time consumed: "
//         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
//         << "SOR method: " << x.transpose() << endl;

    // 共轭梯度法
    time_stt = clock();
    ConjugateGradient<MatrixXd> cg;
    x = cg.compute(A).solve(b);
    cout << "Time consumed: "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms, "
         << "Conjugate gradient: " << x.transpose() << endl;

    return 0;
}

