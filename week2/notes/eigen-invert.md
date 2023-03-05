# How Eigen Computes Matrix Inverses: A Comprehensive Guide

You may have some prior knowledge on matrix and solve linear equations. But have you ever wondered how modern software libraries solve complex equations with ease? One such library, Eigen, employs matrix inverses to tackle even the toughest problems. In this blog post, we'll explore the ins and outs of Eigen's matrix inverse capabilities and how it handles various situations. Get ready to dive deep into the world of numerical optimization!

## Quick Recap

Before we get into the details of Eigen's implementation, let's briefly review the basics of matrix.

## Eigen's `inverse()` Function

Eigen is a C++ template library for linear algebra that provides a wide range of matrix and vector operations, including matrix inversion. The `inverse()` function in Eigen is used to compute the inverse of a matrix, and its implementation depends on the size and structure of the matrix.

### Small Fixed-Size Matrices

For matrices of size up to 4x4, Eigen uses a method based on cofactors to compute the inverse. This involves computing the determinant of the matrix and then taking the adjugate (transpose of the matrix of cofactors) divided by the determinant. Here's an example of how this is implemented in Eigen:

```c++
template<typename Derived>
Eigen::Matrix<typename Derived::Scalar, Derived::ColsAtCompileTime, Derived::RowsAtCompileTime>
MatrixBase<Derived>::inverse() const
{
  EIGEN_STATIC_ASSERT_FIXED_SIZE(Derived)
  typedef typename internal::traits<Derived>::Scalar Scalar;
  const int size = RowsAtCompileTime;

  // Compute the determinant
  Scalar det = Determinant<Derived>::run(derived());

  // Compute the adjugate
  Eigen::Matrix<Scalar,size,size> adj;
  adj = internal::adjoint<Derived>(derived());

  // Compute the inverse
  return adj / det;
}
```

### General Square Matrices

For general square matrices, Eigen uses a method based on LU decomposition to compute the inverse. This involves decomposing the matrix into a lower-triangular matrix and an upper-triangular matrix, and then solving a series of linear systems to compute the inverse. Here's an example of how this is implemented in Eigen:

```c++
template<typename Derived>
typename Eigen::internal::plain_matrix_type<typename Derived::Scalar, Derived::ColsAtCompileTime, Derived::RowsAtCompileTime>::type
MatrixBase<Derived>::inverse() const
{
  EIGEN_STATIC_ASSERT((internal::is_same<typename Derived::Scalar, typename internal::traits<Derived>::Scalar>::value),
    YOU_MIXED_DIFFERENT_NUMERIC_TYPES__YOU_NEED_TO_USE_THE_CAST_METHOD_OF_MATRIXBASE_TO_CAST_NUMERIC_TYPES_EXPLICITLY)
  typename internal::plain_matrix_type<Scalar, ColsAtCompileTime, RowsAtCompileTime>::type tmp(m_evaluator.rows(), m_evaluator.cols());
  internal::inverse_impl<Derived>::run(m_evaluator.derived(), tmp);
  return tmp;
}
```
In this case, Eigen uses the internal::inverse_impl template class to handle the actual computation of the inverse. This class selects the appropriate method based on the size and structure of the matrix, and is implemented separately for different decomposition methods (e.g. PartialPivLU, FullPivLU, etc.).

### Non-Square Matrices

For non-square matrices (i.e. rectangular matrices), Eigen uses a method based on the QR decomposition to compute the pseudoinverse (which is a generalization of the inverse for non-square matrices). This involves decomposing the matrix into an orthogonal matrix and an upper-triangular matrix, and then taking the pseudoinverse of the upper-triangular matrix. Here's an example of how this is implemented in Eigen:

```c++
template<typename Derived>
typename Eigen::internal::plain_matrix_type<typename Derived::Scalar, Derived::ColsAtCompileTime, Derived::RowsAtCompileTime>::type
MatrixBase<Derived>::inverse() const
{
  EIGEN_STATIC_ASSERT((NumColsAtCompileTime == RowsAtCompileTime),
    THIS_METHOD_IS_ONLY_FOR_MATRICES__USE_NORMAL_EQUIVALENCE_INSTEAD)
  typename internal::plain_matrix_type<Scalar, ColsAtCompileTime, RowsAtCompileTime>::type tmp(m_evaluator.rows(), m_evaluator.cols());
  internal::inverse_impl<Derived>::run(m_evaluator.derived(), tmp);
  return tmp;
}
```
