#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(3, 3);
    A = A * A.transpose(); // A*A^T是半正定矩阵

    // 随机生成3x1的三维向量b
    Eigen::VectorXd b = Eigen::VectorXd::Random(3);

    //直接求逆 计算成本高
    Eigen::VectorXd x = A.inverse() * b;

    // QR分解
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

    // LU分解
    Eigen::VectorXd x = A.lu().solve(b);

    // Cholesky分解 必须是正定矩阵
    Eigen::LLT<Eigen::MatrixXd> lltOfA(A);
    Eigen::VectorXd x = lltOfA.solve(b);

    std::cout << "The solution is:\n" << x << std::endl;

    return 0;
}

