### Configuration Space

#### Degrees of freedom

**C-space**: The space of all *configurations*.

**Degrees of freedom(dof)**: The dimension of the C-space; i.e., the minmum number of real numbers needed to represent the configuration.


$N$ = $\#$ of bodies, including ground

$J$ = $\#$ of joints

$m$ = 6 for spatial bodies, 3 for planar

**Grublers formula** (all constraints are **independent**)
$$
\begin{align*}
\text{dof} &= \text{rigid body freedoms} - \text{joint constraints} \\
&= m(N-1) - \sum\limits_{i=1}^{J}c_{i} \\
&= m(N-1) - \sum\limits_{i=1}^{J}(m-f_{i}) \\
&= m(N-1-J) + \sum\limits_{i=1}^{J}f_{i} . \\
\end{align*}
$$

#### constraints

**holonomic constraints**: constraints on configuration

**nonhlolnomic constraints**: constraints on velocity

**Pfaffian constraints**: $A(\theta)\dot{\theta} = 0$