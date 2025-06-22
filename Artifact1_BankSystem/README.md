# 🏦 Bank Management System (Python Version)

This enhanced console-based banking system was ported from a legacy C++ version. The Python version applies software design principles to create a robust, modular, and testable solution.

---

## 🔧 Features & Enhancements

- ✅ Ported from C++ to Python
- ✅ Object-Oriented Design (OOP)
- ✅ Strategy Pattern for transactions
- ✅ Logging with timestamps (`logger_config.py`)
- ✅ Unit testing with Python’s `unittest` module
- ✅ UML diagram provided in PlantUML format (`bank_system.puml`)

---

## 📂 Project Structure

| File | Description |
|------|-------------|
| `main.py` | Console menu and program entry point |
| `account.py` | Account class and core data structure |
| `bank.py` | Manages account operations through `BankManager` |
| `transaction.py` | Implements Strategy Pattern (Deposit & Withdraw) |
| `logger_config.py` | Logging configuration |
| `tests/` | Unit tests for account, bank, and transactions |
| `bankManagement.cpp` | Original C++ version for comparison |
| `bank_system.puml` | UML class diagram (viewable via PlantUML) |

---

## 🚀 How to Run

Make sure Python 3 is installed.

'''bash
cd Artifact1_BankSystem
python main.py
'''

---
