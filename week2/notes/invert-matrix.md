# Matrix Inversion: Five Different Methods

Matrices have become a fundamental tool in many fields of computer science. For instance, in machine learning, matrices are utilized to represent training data and weights in neural networks. Similarly, in computer graphics, matrices are used to represent transformations of 3D objects. Additionally, in scientific computing, matrices are used to solve differential equations and simulate physical systems. Due to the widespread application of matrices, the efficient computation of matrix operations is crucial， and one of these involves calculating the inverse of the matrix. This blog will introduce eight different methods for computing the inverse of a matrix.

## Gaussian elimination approach

### Gaussian elimination

The most straightforward method for solving systems of linear equations is Gaussian elimination. This method involves three useful operations that yield an equivalent system of equations, which has the same solutions as the original system. These operations are as follows: 

1. Swap one equation for another. 

2. Add or subtract a multiple of one equation from another. 

3. Multiply an equation by a nonzero constant.

In Gaussian elimination, an augmented matrix is commonly used when solving a system of linear equations. The augmented matrix combines the coefficients of the variables with the constant terms of the equations, making it easier to perform row operations and ultimately solve the system.

When using Gaussian elimination to compute the inverse of a matrix, an augmented matrix is not needed. Instead, we can perform row operations directly on the matrix itself. It is worth noting that there is a variant of Gaussian elimination called the Gauss-Jordan method, which allows the solution to be read off directly from the matrix without back substitution. However, this method is computationally more expensive than the standard Gaussian elimination method, as it requires more row operations. Here is an example of the Gauss-Jordan method:

**Example** Find the inverse of the matrix $ A = \begin{bmatrix} 1 & 1 \\ 3 & -4 \end{bmatrix} $

**Solution** Suppose $A$ has an inverse, and it is

$$
B = 
\begin{bmatrix}
n_{11} & n_{12} \\ n_{21} & n_{22} 
\end{bmatrix}
$$

Then $AB = I_2 =  \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}$

It can be written as two systems,

$$
\begin{aligned}
1\times n_{11}+1\times n_{21} &= 1 &&& 1\times n_{12}+1\times n_{22} &&= 0 \\
3\times n_{11}-4\times n_{22} &= 0 &&& 3\times n_{12}-4\times n_{22} &&= 1 \\
\end{aligned}
$$

or in matrix form,

$$ 
\begin{bmatrix} 
~1 & 1 & \bigl| ~1~ \\ ~3 & -4 & \bigl| ~0~
\end{bmatrix}\text{ and }
\begin{bmatrix} 
~1 & 1 & \bigl| ~0~ \\ ~3 & -4 & \bigl| ~1~
\end{bmatrix}
$$

We can observe that the coefficient matrix for both matrices is the same. To simplify the process, we can group the two right-hand columns of the coefficient matrix into one augmented matrix as below.

$$
\begin{bmatrix} 
~1 & 1 & \bigl| ~1 & 0~\\
 ~3 & -4 & \bigl| ~0 & 1~
\end{bmatrix}
$$

by subject $3\times R_1 $ from $R_2$:

$$
\begin{bmatrix} 
~1 & 1 & \bigl| ~~~~1 & 0~ \\
 ~0 & -7 & \bigl| ~-3 & 1~
\end{bmatrix}
$$

and multiplying $R_2$ by $-\frac{1}{7}$ results in:

$$
\begin{bmatrix}
~1 & 1 & \bigl| ~1 & 0~ \\
 ~0 & 1 & \bigl| ~\frac{3}{7} & -\frac{1}{7}~
\end{bmatrix}
$$

at last, by subject $R_2$ from $R_1$:

$$
\begin{bmatrix}
~1 & 0 & \bigl| ~\frac{4}{7} & \frac{1}{7}~ \\
 ~0 & 1 & \bigl| ~\frac{3}{7} & -\frac{1}{7}~
\end{bmatrix}
$$

Therefore, the inverse of the matrix $A$ is $B = \begin{bmatrix} \frac{4}{7} & \frac{1}{7} \\ \frac{3}{7} & -\frac{1}{7} \end{bmatrix}$

### The LU Factorization

LU factorization is essentially the same as Gaussian elimination, but with some additional bookkeeping.

The basic idea behind LU factorization is to write a given matrix $A$ as the product of a lower triangular matrix $L$ and an upper triangular matrix $U$. That is,

$$A = LU$$

**Definition** an $m \times n$ matrix $L$ is *lower triangular* if its entries satisfy $l_{ij} = 0$ for $i < j$. Similarly, an $m \times n$ matrix $U$ is *upper triangular* if its entries satisfy $u_{ij} = 0$ for $i > j$.

**Example** Find the LU factorization of $A = \begin{bmatrix} 1 & 2 & -1 \\ 2 & 1 & -2 \\ -3 & 1 & 1 \end{bmatrix}$.

**Solution** Do Gaussian elimination first:

$$
\begin{align*}
\begin{bmatrix}
1 & 2 & -1 \\
2 & 1 & -2 \\
-3 & 1 & 1
\end{bmatrix}
&\xrightarrow[R_2 \leftarrow R_2 - 2R_1]{R_2 \leftarrow R_2 - 2R_1}
\begin{bmatrix}
1 & 2 & -1 \\
0 & -3 & 0 \\
-3 & 1 & 1
\end{bmatrix} \\
&\xrightarrow[R_3 \leftarrow R_3 + 3R_1]{R_3 \leftarrow R_3 + 3R_1}
\begin{bmatrix}
1 & 2 & -1 \\
0 & -3 & 0 \\
0 & 7 & -2
\end{bmatrix} \\
&\xrightarrow[R_3 \leftarrow R_3 + \frac{7}{3}R_2]{R_3 \leftarrow R_3 + \frac{7}{3}R_2}
\begin{bmatrix}
1 & 2 & -1 \\
0 & -3 & 0 \\
0 & 0 & -\frac{14}{3}
\end{bmatrix} = U
\end{align*}
$$

The lower triangular matrix $L$ is formed by placing $1$'s on the main diagonal and the multipliers used for elimination in the corresponding entries of the lower triangle.
That is,

$$
L = \begin{bmatrix}
1 & 0 & 0 \\
2 & 1 & 0 \\
-3 & -\frac{7}{3} & 1
\end{bmatrix}
$$

$L$ and $U$ satisfy that

$$
A = LU = \begin{bmatrix}
1 & 0 & 0 \\
2 & 1 & 0 \\
-3 & -\frac{7}{3} & 1
\end{bmatrix}
\begin{bmatrix}
1 & 2 & -1 \\
0 & -3 & 0 \\
0 & 0 & -\frac{14}{3}
\end{bmatrix}.
$$

After finding the LU factorization of matrix $A$, we can use it to compute the inverse of $A$ by extending the method as follows:

$$
\begin{align*}
\begin{bmatrix} A & I \end{bmatrix} &= \begin{bmatrix} L & 0 \\ 0 & I \end{bmatrix} \begin{bmatrix} U & A^{-1} \\ 0 & X \end{bmatrix} \\
&= \begin{bmatrix} LU & L(A^{-1}) \\ 0 & I \end{bmatrix} \begin{bmatrix} U & A^{-1} \\ 0 & X \end{bmatrix}
\end{align*}
$$

Since $LU = A$, we can simplify to:

$$
\begin{align*}
A^{-1} &= L(A^{-1})U \\
A^{-1} &= U^{-1}L^{-1} \\
A^{-1} &= \begin{bmatrix} 1 & 0 & 0 \\ -2 & 1 & 0 \\ \frac{7}{3} & \frac{1}{3} & 1 \end{bmatrix} \begin{bmatrix} 1 & -2 & 1 \\ 0 & -\frac{1}{3} & 0 \\ 0 & 0 & -\frac{3}{14} \end{bmatrix} \\
&= \begin{bmatrix} -\frac{1}{14} & \frac{3}{14} & \frac{2}{7} \\ \frac{2}{7} & \frac{1}{7} & \frac{2}{7} \\ -\frac{3}{14} & -\frac{1}{14} & \frac{1}{7} \end{bmatrix}
\end{align*}
$$

Therefore, the inverse of matrix $A$ is:

$$
A^{-1} = \begin{bmatrix} -\frac{1}{14} & \frac{3}{14} & \frac{2}{7} \\ \frac{2}{7} & \frac{1}{7} & \frac{2}{7} \\ -\frac{3}{14} & -\frac{1}{14} & \frac{1}{7} \end{bmatrix}
$$

## Partition method

The partition (or escalator) method is a recursive method used to compute the inverse of a square matrix. The method is based on the fact that if the inverse of a square matrix $A_n$ of order $n$ is known, then the inverse of the matrix $A_{n+1}$ can be obtained by adding the $(n+1)^{th}$ row and $(n+1)^{th}$ column to $A_n$. To apply the method, we partition our matrix into four smaller submatrices.

### The Partition Method for Matrix Inversion
<!--TODO reform this subsection-->
The motivation for the method of inversion by partitioning is the fact that smaller matrices are easier to invert than larger ones. With this method, it is possible to invert a matrix by computing the inverses of two smaller matrices and performing some matrix multiplication and addition. Two different sets of equations will be developed which will each give the inverse.

Let $D$ be the inverse of the matrix $A$. Partition $A$ between a pair of rows and corresponding columns. Also partition $D$ and $I$ similarly. The product $HD$ can then be written as:

$$
\begin{bmatrix}
H_{11} & H_{12} \\
H_{21} & H_{22}
\end{bmatrix}
\begin{bmatrix}
D_{11} & D_{12} \\
D_{21} & D_{22}
\end{bmatrix} =
\begin{bmatrix}
I_{11} & I_{12} \\
I_{21} & I_{22}
\end{bmatrix}
$$

Performing the matrix multiplication results in the following equality:

$$
\begin{aligned}
H_{11}D_{11} + H_{12}D_{21} &= I_{11} \\
H_{11}D_{12} + H_{12}D_{22} &= I_{12} \\
H_{21}D_{11} + H_{22}D_{21} &= I_{21} \\
H_{21}D_{12} + H_{22}D_{22} &= I_{22} \\
\end{aligned}
$$

In order for the two matrices to be identical, the corresponding submatrices must be equal. That is, the following matrix equations must hold:

$$
\begin{aligned}
H_{11}D_{11} + H_{12}D_{21} &= I_{11} \\
H_{11}D_{12} + H_{12}D_{22} &= I_{12} \\
H_{21}D_{11} + H_{22}D_{21} &= I_{21} \\
H_{21}D_{12} + H_{22}D_{22} &= I_{22} \\
\end{aligned}
$$

where $H$ is a $k \times k$ matrix and $k$ is the size of the partitioned matrices. 



### The inversion by Bordering

Let

$$ 
A_{n+1} = 
\begin{bmatrix} 
a_{11} & a_{12} & \cdots & a_{1n} \\ 
a_{21} & a_{22} & \cdots & a_{2n} \\ 
\vdots & \vdots & \ddots & \vdots \\ 
a_{n1} & a_{n2} & \cdots & a_{nn} \\ 
a_{n+1,1} & a_{n+1,2} & \cdots & a_{n+1,n} \end{bmatrix} 
= \begin{bmatrix} 

A_n  B_n \\
C_n  d 

\end{bmatrix} $$

<!-- FOR LINE DO NOT DISPLAY -->
with 

$$ A_n = 
\begin{bmatrix} 
a_{11} & a_{12} & \cdots & a_{1n} \\
 a_{21} & a_{22} & \cdots & a_{2n} \\ 
 \vdots & \vdots & \ddots & \vdots \\ 
 a_{n1} & a_{n2} & \cdots & a_{nn} 
\end{bmatrix} , 
B_{n\times 1} = 
\begin{bmatrix}
 a_{1,n+1} \\ a_{2,n+1} \\ \vdots \\ a_{n,n+1} 
 \end{bmatrix} ,
 \\
C_{1\times n} = 
\begin{bmatrix} 
a_{n+1,1} & a_{n+1,2} & \cdots & a_{n+1,n} 
\end{bmatrix} , d = a_{n+1,n+1} $$


We can calculate the inverse of matrix $A_n$ using the classical adjoint or Gauss-Jordan method. Once we have the inverse of matrix $A_n$ we can compute the inverse of the other submatrices of matrix $A_{n+1}$ using the following formulas.

$$ A_{n+1} = \begin{bmatrix} A & B \\ C & d \end{bmatrix} $$

$$ A_{-1,n+1} = \begin{bmatrix} X \\ Y \\ Z \\ t \end{bmatrix} $$

$$ t = (d-C A_{-1} B)^{-1} $$

$$ Y = -A_{-1} B t $$

$$ Z = -C A_{-1}^t $$

$$ X = A_{-1}(I-BZ) $$

For a more thorough explanation, please check out this excellent [article](https://www.math.uwaterloo.ca/~hwolkowi/matrixcookbook.pdf) about the partition method. Now, let's take a look at an example.

$$ A_3 = \begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & 4 \\ 5 & 6 & 1 \end{bmatrix} = \begin{bmatrix} A & B \\ C & d \end{bmatrix} = \begin{bmatrix} \begin{matrix} 1 & 2 \\ 0 & 1 \end{matrix} & \begin{matrix} 3 \\ 4 \end{matrix} \\ \begin{matrix} 5 & 6 \end{matrix} & 1 \end{bmatrix} $$

$$ A = \begin{bmatrix} 1 & 2 \\ 0 & 1 \end{bmatrix} $$

$$ B = \begin{bmatrix} 3 \\ 4 \end{bmatrix} $$

$$ C = \begin{bmatrix} 5 & 6 \end{bmatrix} $$

$$ d = 1 $$


Finally, putting everything together, we have the inverse matrix for the matrix $A^3$.

$$
A^{-1}_3 = \begin{bmatrix} -11.5 & 8 & 2.5 \ 10 & -7 & -2 \ -2.5 & 2 & 0.5 \end{bmatrix}
$$

For our implementation, we follow the same procedure as in our example. First, we compute the inverse of the submatrix $A$, using the classical adjoint method. Next, we solve the equation for each element of the inverse matrix $A^{-1}_n+1$ using the formulas given above.

## Iterative Methods

### Jacobi Method

**Definition** The $n \times n$ matrix $A = (a_{ij})$ is ***strictly diagonally dominant*** if, for each $1 \leq i \leq n$, $|a_{ii}| > \sum\limits_{j \neq i} |a_{ij}|$. In other words, each main diagonal entry dominates its row in the sense that it is greater in magnitude than the sum of magnitudes of the remainder of the entries in its row.

**Theorem** If the $n \times n$ matrix $A$ is strictly diagonally dominant, then:
1. $A$ is a nonsingular matrix, and
2. for every vector $b$ and every starting guess, the Jacobi Method applied to $Ax=b$ converges to the (unique) solution.

## Example
Let's consider the following $3 \times 3$ matrix $A$:
$$ 
A = 
\begin{bmatrix} 
4 & 1 & 1 \\ 1 & 4 & 1 \\ 1 & 1 & 4 
\end{bmatrix} 
$$

---
split outline
<!--Break to two articles Outline-->

# The Pitfalls of Inversing Matrix

Linear equations and matrix operations are fundamental concepts in mathematics and science. One common method of solving linear equations is by using matrix inverses. However, this approach can lead to accuracy problems and numerical instability. In this blog post, we'll explore why using matrix inverses to solve linear equations should be avoided and alternative methods for solving linear equations.

## The Problems with Using Matrix Inverses to Solve Linear Equations

Using matrix inverses to solve linear equations can be inaccurate. Even small errors in matrix inversion can lead to large errors in the solution. Additionally, there can be numerical stability issues when using matrix inverses, particularly with ill-conditioned matrices.

## Alternative Methods for Solving Linear Equations

LU decomposition and QR decomposition are alternative methods for solving linear equations. These methods work by decomposing a matrix into simpler components that are easier to work with. Compared to using matrix inverses, these alternative methods are more accurate and less susceptible to numerical instability.

## Analyzing the Complexity and Accuracy of Matrix Operations

Mathematical methods such as Big O notation and condition number can be used to analyze the complexity and accuracy of matrix operations. Understanding these concepts is essential for improving the accuracy and efficiency of linear algebra operations.

## Conclusion

Using matrix inverses to solve linear equations can lead to accuracy problems and numerical instability. It is important to understand alternative methods such as LU decomposition and QR decomposition, and to analyze the complexity and accuracy of matrix operations. By doing so, we can improve our work in linear algebra and ensure more accurate results.

So next time you encounter a linear equation, remember to think twice before reaching for the inverse matrix.
