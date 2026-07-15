\# 🧮 Numerical Analysis \& Custom Floating-Point Arithmetic in C



This repository contains low-level C implementations of foundational numerical analysis methods. The project explores the physical limitations of machine precision by building a custom base-10 floating-point emulator from scratch, alongside a comparative analysis of non-linear root-finding algorithms.



\## 📂 Repository Structure



```text

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

