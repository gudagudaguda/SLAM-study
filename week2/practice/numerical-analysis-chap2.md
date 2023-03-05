### 2.1 Exercises
1. Use Gaussian elimination to solve the systems:

$$
\begin{aligned}
(a) \quad & 2x - 3y = 2 \quad & (b) \quad & x + 2y = -1 \quad & (c) \quad & -x + y = 2 \\
          & 5x - 6y = 8         &       & 2x + 3y = 1          &       & 3x + 4y = 15
\end{aligned}

$$

**Solution**

(a) 
$$
\begin{bmatrix}
2 & -3 &\bigl|& 2 \\
5 & -6 &\bigl|& 8
\end{bmatrix}
\sim
\begin{bmatrix}
1 & -\frac{3}{2} &\bigl|& 1 \\
5 & -6 &\bigl|& 8
\end{bmatrix}
\sim
\begin{bmatrix}
1 & -\frac{3}{2} &\bigl|& 1 \\
0 & \frac{3}{2} &\bigl|& 3
\end{bmatrix}
\sim
\begin{bmatrix}
1 & -\frac{3}{2} &\bigl|& 1 \\
0 & 1 &\bigl|& 2
\end{bmatrix}
\sim
\begin{bmatrix}
1 & 0 &\bigl|& 4 \\
0 & 1 &\bigl|& 2
\end{bmatrix}
$$

So, $x = 4$ and $y = 2$.

Same method for (b) $x = 5$ and $y = -3$ and (c) $x = 1$ and $y = 3$.

3. Solve by back substitution:

$$
\begin{aligned}
(a) \quad  3x - 4y + 5z &= 2 \quad & (b) \quad  x - 2y + z &= 2 \\
           3y - 4z &= -1           &           4y - 3z &= 1 \\
           5z &= 5                 &           -3z &= 3
\end{aligned}
$$

**Solution**


(a) 
$$
\begin{aligned}
5z = 5 \quad &\Rightarrow \quad z = 1 \\
3y - 4z = -1 \quad \Rightarrow \quad 3y - 4 = -1 \quad \Rightarrow \quad 3y = 3 \quad &\Rightarrow \quad y = 1 \\
3x - 4y + 5z = 2 \quad \Rightarrow \quad 3x - 4 + 5 = 2 \quad \Rightarrow \quad 3x = 1 \quad &\Rightarrow \quad x = \frac{1}{3}
\end{aligned}
$$

Therefore, $x = \frac{1}{3}$, $y = 1$ and $z = 1$.

Same method for (b) $x = 2$, $y = -0.5$ and $z = -1$.

4. Solve the tableau form

(a) $\begin{bmatrix} 3 & -4 & -2 & | & 3 \\ 6 & -6 & 1 & | & 2 \\ -3 & 8 & 2 & | & -1 \end{bmatrix}$

(b) $\begin{bmatrix} 2 & 1 & -1 & | & 2 \\ 6 & 2 & -2 & | & 8 \\ 4 & 6 & -3 & | & 5 \end{bmatrix}$

**Solution**

(a) 
$$
\begin{bmatrix} 3 & -4 & -2 & | & 3 \\ 6 & -6 & 1 & | & 2 \\ -3 & 8 & 2 & | & -1 \end{bmatrix}
\sim
\begin{bmatrix} 1 & -\frac{4}{3} & -\frac{2}{3} & | & 1 \\ 6 & -6 & 1 & | & 2 \\ -3 & 8 & 2 & | & -1 \end{bmatrix}
\sim
\begin{bmatrix} 1 & -\frac{4}{3} & -\frac{2}{3} & | & 1 \\ 0 & 1 & -\frac{5}{2} & | & -2 \\ -3 & 8 & 2 & | & -1 \end{bmatrix}
\sim \\
\begin{bmatrix} 1 & -\frac{4}{3} & -\frac{2}{3} & | & 1 \\ 0 & 1 & -\frac{5}{2} & | & -2 \\ 0 & 1 & 0 & | & \frac{1}{2} \end{bmatrix}
\sim
\begin{bmatrix} 1 & 0 & 0 & | & 1 \\ 0 & 1 & 0 & | & \frac{1}{2} \\ 0 & 0 & 1 & | & -1 \end{bmatrix}
$$

5. Use the approximate operation count $2\frac{n^3}{3}$ for Gaussian elimination to estimate how much longer it takes to solve $n$ equations in $n$ unknowns if $n$ is tripled.

**Solution**
Assuming the approximate operation count $2n^3/3$ for Gaussian elimination, if n is tripled (i.e. multiplied by 3), then the number of operations required for Gaussian elimination will increase by a factor of $27$ (i.e. $3^3$).

Therefore, the time it takes to solve $n$ equations in $n$ unknowns using Gaussian elimination will increase significantly as $n$ becomes larger.

<!--TODO restructure in katex-->
6. Assume that your computer completes a 5000 equation back substitution in 0.005 seconds. Use the approximate operation counts n2 for back substitution and 2n3/3 for elimination to estimate how long it will take to do a complete Gaussian elimination of this size. Round your answer to the nearest second

7. Assume that a given computer requires 0.002 seconds to complete back substitution on a 4000 × 4000 upper triangular matrix equation. Estimate the time needed to solve a general system of 9000 equations in 9000 unknowns. Round your answer to the nearest second.