# 🏦 Bank Management System (Python Version)

This enhanced console-based banking system was ported from a legacy C++ version. The Python version applies software design principles to create a robust, modular, and testable solution.

---

## 🔧 Features & Enhancements

- ✅ Ported from C++ to Python
- ✅ Object-Oriented Design (OOP)
- ✅ Strategy Pattern for transactions
- ✅ Logging with timestamps (`logger_config.py`)
- ✅ Unit testing with Python’s `unittest` module
📸 **[View UML Diagram – UML_BankSystem.png](https://1drv.ms/i/c/c7d4b73524dc22bd/ESyulRAVMglHuN1czhHy1D0BxyHNbVTyrbY4onP0ZL-BQw?e=WQHjqu)**

---

## 📂 Project Structure

| File | Description |
|------|-------------|
| [`main.py`](./main.py) | Console menu and program entry point |
| [`account.py`](./account.py) | Account class and core data structure |
| [`bank.py`](./bank.py) | Manages account operations via `BankManager` |
| [`transaction.py`](./transaction.py) | Strategy Pattern for Deposit/Withdraw logic |
| [`logger_config.py`](./logger_config.py) | Logging setup using Python's `logging` module |
| [`tests/`](./tests/) | Unit tests for all components |
| [`UML_BankSystem.png`](./UML_BankSystem.png) | UML diagram as a PNG image |
| [`bank_system.puml`](./bank_system.puml) | UML diagram source in PlantUML format |
| [`bankManagement.cpp`](./bankManagement.cpp) | Original C++ version for comparison |

---

## 🚀 How to Run

Make sure Python 3 is installed.

```bash
cd Artifact1_BankSystem
python main.py
```
