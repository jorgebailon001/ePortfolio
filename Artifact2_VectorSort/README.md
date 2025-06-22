# 📊 Artifact 2: Vector Sorting Program (C++)

This project demonstrates algorithm development and data structure manipulation using C++. Originally created for CS 300, the program reads bid data from a CSV file and applies **Selection Sort** and **Quick Sort** to organize the data. 

For the capstone enhancement, an **Undo/Redo system** using stack data structures was integrated to allow users to reverse and reapply sorting actions — making the sorting experience more interactive and educational.

---

## ✨ Features & Enhancements

| Feature                                | Description                                                                 |
|----------------------------------------|-----------------------------------------------------------------------------|
| ✅ Original C++ sorting logic           | Implements Quick Sort and Selection Sort over bid data                     |
| 🧠 Data structuring with `vector<Bid>` | Encapsulates bid data with C++ structures and containers                   |
| ⏱ Timing benchmarks                    | Tracks runtime of sorting algorithms using clock ticks                     |
| 🆕 **Undo/Redo Sort**                  | Allows reverting sort operations via stack-based state history             |
| 🧪 Manual & automated testing ready    | Logic is console-driven and testable with standard input scenarios         |

---

## 📁 Project Structure

Artifact2_VectorSort/

├── [**Enhanced/**](./Enhanced)  
│   ├── [VectorSorting.cpp](./Enhanced/VectorSorting.cpp) ← Enhanced version with stack-based Undo/Redo system  
│   ├── [CSVparser.cpp](./Enhanced/CSVparser.cpp), [CSVparser.hpp](./Enhanced/CSVparser.hpp) ← CSV parsing library for loading bid data  
│   └── [eBid_Monthly_Sales.csv](./Enhanced/eBid_Monthly_Sales.csv) ← Sample dataset of bids used for sorting  
│  
└── [**Original/**](./Original)  
    └── [VectorSorting_Original.cpp](./Original/VectorSorting_Original.cpp) ← Original version before enhancement with no Undo/Redo logic

---

## 🖥 How to Run

> **Pre-requisites:** Visual Studio or any C++ compiler with C++11+ support

```bash
# Compile (Linux/Mac or with Developer Command Prompt on Windows)
g++ VectorSorting.cpp CSVparser.cpp -o VectorSortApp

# Run
./VectorSortApp
