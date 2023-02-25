### SLAM十四讲 第三章课后习题

1. 验证旋转矩阵是正交矩阵。

写了一个随机生成旋转矩阵的[脚本](../program/det33)。

随机旋转矩阵生成的思路是随机生成一个单位长度的旋转轴 $\omega$ 和一个随机的角度 $\theta$，并且生成 $\omega$ 对应的skew-symmetric matrix  $[\omega] \in so(3)$ 。通过 $R = I + sin(\theta)*K + (1 - cos(\theta))*K^2 $，生成随机旋转矩阵。

*有观察到浮点运算导致的很小的非零值，也佐证了计算机在运算旋转矩阵在*

2. *寻找罗德里格斯公式的推导过程并理解它。

见[笔记](../notes/rigid-body-note.pdf)轴角部分。

3. 验证四元数旋转某个点后，结果是一个虚四元数（实部为零），所以仍然对应到一个三维空间点（式3.34）。

*Proof.* 假设有一个三维空间中的点 $p$，我们可以将其表示为实部为零的四元数：

$$ p = 0 + xi + yj + zk $$

为了用四元数 $q$ 旋转点 $p$，我们可以使用下面的公式：

$$ p' = qpq^{-1} $$

其中 $p'$ 是旋转后的点。由于 $p$ 的实部为零，我们可以看出 $p'$ 的实部也为零：

$$ \operatorname{Re}(p') = \operatorname{Re}(qpq^{-1}) = \operatorname{Re}(q)\operatorname{Re}(p)\operatorname{Re}(q^{-1}) = 0 $$

因此，$p'$ 是一个虚四元数，即三维空间中的向量。

4. 画表总结旋转矩阵、轴角、欧拉角、四元数的转换关系。

| 转换方式 | 旋转矩阵 $R$ | 旋转轴角 $(\theta, \boldsymbol{v})$ | 欧拉角 $(\phi, \theta, \psi)$ | 四元数 $q$ |
|:-------:|:-----------:|:--------------------------------:|:--------------------------:|:----------:|
| 旋转矩阵 |  $R$        |   $\theta = \cos^{-1}(\frac{\operatorname{tr}(R)-1}{2})$<br>$\boldsymbol{v} = \frac{1}{2\sin(\theta)}\begin{bmatrix} r_{32}-r_{23} \\ r_{13}-r_{31} \\ r_{21}-r_{12} \end{bmatrix}$ | 不唯一 |  $q = (r_{11}+r_{22}+r_{33}+1)^{\frac{1}{2}}+\frac{1}{2}\begin{bmatrix} r_{32}-r_{23} \\ r_{13}-r_{31} \\ r_{21}-r_{12} \end{bmatrix}$ |
| 旋转轴角 |  $R(\theta, \boldsymbol{v})$ |  $(\theta, \boldsymbol{v})$        | 不唯一 | $q = [\cos(\frac{\theta}{2}), \boldsymbol{v}\sin(\frac{\theta}{2})]$ |
| 欧拉角 | 不唯一 |  不唯一 | $(\phi, \theta, \psi)$ | 不唯一 |
| 四元数 | $R = \begin{bmatrix}1-2q_y^2-2q_z^2 & 2q_xq_y-2q_zq_w & 2q_xq_z+2q_yq_w \\ 2q_xq_y+2q_zq_w & 1-2q_x^2-2q_z^2 & 2q_yq_z-2q_xq_w \\ 2q_xq_z-2q_yq_w & 2q_yq_z+2q_xq_w & 1-2q_x^2-2q_y^2\end{bmatrix}$ | $(2\cos^{-1}(q_w),\frac{1}{\sqrt{1-q_w^2}}(q_x, q_y, q_z))$ | $(\operatorname{atan2}(2(q_wq_x+q_yq_z),1-2(q_x^2+q_y^2)),\sin^{-1}(2(q_wq_y-q_xq_z)),\operatorname{atan2}(2(q_wq_z+q_xq_y),1-2(q_y^2+q_z^2)))$ | $q$ |

*后续会更新到笔记里*

5. 假设我有一个大的Eigen 矩阵，我想把它的左上角 $3\times 3$ 的块取出来，然后赋值为
$I_{3\times 3}$。请编程实现此事。

[代码](../program/extract33)

6. *一般线程方程Ax = b 有哪几种做法？你能在Eigen 中实现吗？

[代码](../program/resolve_linear_f)
