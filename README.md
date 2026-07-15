# Numerical Analysis and Custom Floating-Point Labs

This repository contains C implementations of foundational numerical analysis methods. The project is split into two modules:

## 1. Custom Floating-Point Simulator (/custom-float)

- finale.c: An interactive floating-point calculator implementing normalized base-10 scientific notation arithmetic.
- FLOTTANT.c: Implements the core normalization algorithm.
- SOMMEFL.c & DIFFL.c & MULFL.c & DIVFL.c: Arithmetic operators for normalized decimal floats.

## 2. Non-Linear Root-Finding Solvers (/root-finders)

- Bissection.c: Solves non-linear equations using bracketed interval halving.
- la Secante.c: Approximates roots using successive secant slopes.
- Newton-Raphson.c: Uses derivatives for rapid quadratic convergence.
- Point Fixe.c: Reformulates equations as g(x)=x to iterate to a root.

## 3. Academic Reports

- /docs/rapport analyse.pdf: Full computational lab report (written in French).
