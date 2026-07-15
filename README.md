#  Numerical Analysis & Custom Floating-Point Arithmetic in C

This repository contains low-level C implementations of foundational numerical analysis methods. The project explores the physical limitations of machine precision by building a custom base-10 floating-point emulator from scratch, alongside a comparative mathematical analysis of non-linear root-finding algorithms.

##  Repository Structure

    numerical-analysis-labs/
    ├── custom-float/
    │   ├── FLOTTANT.c         # Core mantissa/exponent normalizer
    │   ├── SOMMEFL.c          # Floating-point addition
    │   ├── DIFFL.c            # Floating-point subtraction
    │   ├── MULFL.c            # Floating-point multiplication
    │   ├── DIVFL.c            # Floating-point division
    │   └── finale.c           # Interactive calculator program
    ├── root-finders/
    │   ├── Bissection.c       # Interval halving method
    │   ├── la Sécante.c       # Secant approximation method
    │   ├── Newton-Raphson.c   # Derivative-based solver
    │   └── Point Fixe.c       # Fixed-point iteration
    ├── docs/
    │   ├── rapport analyse.pdf  # Full computational lab report (Français)
    │   └── rapport analyse.docx # Original report document
    └── README.md


##  Part 1: Custom Floating-Point Simulator (`/custom-float`)

Modern hardware uses the IEEE 754 binary standard for floating-point arithmetic. This module circumvents native hardware to manually emulate floating-point arithmetic in base-10, demonstrating concepts like mantissa shifting, exponent alignment, and catastrophic cancellation.

### Mathematical Data Structure
Numbers are represented using a custom `FLOT` struct:
$$x = m \times 10^e$$
Where the mantissa $m$ is strictly normalized such that $0.1 \le |m| < 1.0$, and $e$ is the integer exponent.

##  Part 2: Non-Linear Root-Finding Solvers (`/root-finders`)

This module compares four classic numerical algorithms to find the roots of the transcendental equation:
$$f(x) = 2\sin(x) - x = 0$$

### 1. Bisection Method (`Bissection.c`)
This method relies on the **Intermediate Value Theorem**. If a continuous function $f(x)$ changes sign over an interval $[a, b]$, at least one root must exist within that interval.
* **Iteration:** The interval is halved at each step by calculating the midpoint $x_{mid} = \frac{a + b}{2}$. 
* **Convergence:** **Linear**. The method is slow but unconditionally guaranteed to converge. The maximum absolute error after $n$ iterations is bounded by:
  $$\epsilon_n \le \frac{b-a}{2^n}$$

### 2. Newton-Raphson Method (`Newton-Raphson.c`)
An open method derived from the first-order Taylor series expansion. It computes the tangent line at the current guess $x_n$ to formulate the next guess.
* **Iteration Formula:** $$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$$
* **Applied to our function:** Since $f(x) = 2\sin(x) - x$, the exact analytical derivative is $f'(x) = 2\cos(x) - 1$.
* **Convergence:** **Quadratic**. The number of accurate decimal places roughly doubles with each iteration.

### 3. Secant Method (`la Sécante.c`)
The Secant method uses a finite-difference approximation of the derivative based on two successive points to avoid calculating the analytical derivative:
$$f'(x_n) \approx \frac{f(x_n) - f(x_{n-1})}{x_n - x_{n-1}}$$
* **Iteration Formula:** Substituting this into Newton's formula yields:
  $$x_{n+1} = x_n - f(x_n) \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$$
* **Convergence:** **Superlinear**. Its convergence rate relies on the Golden Ratio, with an order of convergence $p \approx 1.618$.

### 4. Fixed-Point Iteration (`Point Fixe.c`)
This method reformulates the target equation $f(x) = 0$ into an equivalent algebraic form $x = g(x)$. For our equation, we extract $x$ to define the helper function:
$$g(x) = 2\sin(x)$$
* **Iteration Formula:** $$x_{n+1} = g(x_n)$$
* **Convergence:** **Linear**, governed by the *Contraction Mapping Theorem*. The sequence converges only if $|g'(x)| < 1$ near the root. 

##  Compilation and Execution Guide

This code is written in standard C and requires the GCC compiler. You must link the math library using the `-lm` flag on Linux/macOS systems.

**To compile the Root-Finding Solvers:**
```bash
cd root-finders
gcc Newton-Raphson.c -o newton.exe -lm
./newton.exe
