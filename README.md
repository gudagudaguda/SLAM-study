# 中天的SLAM学习之路

## TOC
[第一周](#第一周)

### 第一周

- **明确接下来学习的内容**

*前五周学习数学基础，后三周学习SLAM技术的同时通过* $\stackrel{\textit{魔改}}{\textit{实践}}$ ORB-SLAM2巩固。

*前三周*： $\stackrel{\textit{rigid-body kinamatics}}{\textit{刚体运动学}}$ 和 $\stackrel{\textit{Lie groups}}{\textit{李群}}$

*第四周*： $\stackrel{\textit{image processing}}{\textit{图像处理}}$

*第五周*： $\stackrel{\textit{nonlinear optimization}}{\textit{非线性优化}}$

*第六周 &第七周(前半)*： $\stackrel{\textit{visual odometry}}{\textit{视觉里程计}}$

*第七周(后半) &第八周*： $\textit{后端}（\stackrel{\textit{filters and optimization }}{\textit{滤波器和优化方法}）}$

*同时每周保持代码练习*

*前三周：C++ Primer，每天一章*

*第四&五周：OpenCV，之前学过的C++库(Eigen, Sophus, Ceres, g2o)*

*第六~八周：ORB-SLAM2源码*

- **学习刚体运动学 —— 如何表示刚体的 $\stackrel{\text{position and orientation}}{\textbf{位姿}}$**

- - $\stackrel{\text{rotation matrix}}{\text{旋转矩阵}}$ ( $=$ DCM)

- - $\stackrel{\text{euler angle}}{\text{欧拉角}} $

- **学习Eigen —— 用于矩阵、向量运算的C++模板库**