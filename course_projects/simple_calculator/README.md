# 🧮 Simple C++ Command-Line Calculator

A basic command-line expression evaluator built in C++. This project demonstrates manual parsing and calculation logic for arithmetic expressions, supporting the standard order of operations (PEMDAS/BODMAS) and parentheses.

## ✨ Features

  * **Order of Operations (PEMDAS/BODMAS):** Correctly evaluates expressions following the standard hierarchy: Parentheses (`()`), Exponents (`^`), Multiplication (`*`), Division (`/`), Addition (`+`), and Subtraction (`-`).
  * **Integer Arithmetic:** Performs calculations using integer operands.
  * **Error Handling:** Includes checks for invalid characters and division by zero.
  * **Tokenization:** Manual argument parsing (tokenization) implemented in the `arg_parse` function, separating numbers and operators.

## 🚀 Getting Started

These instructions will get you a copy of the project up and running on your local machine.

### Prerequisites

You will need a C++ compiler that supports the C++ standard (e.g., GCC, Clang).

### Building the Project

1.  **Clone the repository:**

    ```bash
    git clone [your-repo-link]
    cd [your-repo-name]
    ```

2.  **Compile the source code:**
    Assuming your main file is named `calculator.cpp`:

    ```bash
    g++ calculator.cpp -o calculator
    ```

### Usage

Run the compiled executable from your terminal. The program will prompt you to enter an expression.

```bash
./calculator
```

#### Example

```
Please enter your formula, it must not contain space!
(10+2)*3^2/6
54
```

## 📐 Supported Operators

| Operator | Function | Precedence Order |
| :--- | :--- | :--- |
| `()` | Grouping (Parentheses) | Highest |
| `^` | Exponentiation (Power) | High |
| `*`, `/` | Multiplication, Division | Medium |
| `+`, `-` | Addition, Subtraction | Lowest |

## 💡 Implementation Details

The core of the calculator is its recursive approach to solving the expression:

1.  **`main` $\rightarrow$ `arg_parse`:** The input string is broken down into a sequence of numbers (operands) and operator characters (stored as their ASCII values) in a `std::vector<int>`.
2.  **`main` $\rightarrow$ `basic_calculate`:** This function initiates the calculation sequence, starting with:
      * **`bracket`:** Solves all nested expressions enclosed in parentheses recursively by calling `basic_calculate` on sub-expressions.
      * **Operator Order:** Once parentheses are resolved, the `basic_calculate` function sweeps through the expression in three distinct passes to respect operator precedence:
        1.  Exponents (`^`)
        2.  Multiplication and Division (`*`, `/`)
        3.  Addition and Subtraction (`+`, `-`)
            After each operation, the vector is modified (`erase` and `insert`) to replace the sub-expression with the calculated result, effectively reducing the expression until only a single result remains.
