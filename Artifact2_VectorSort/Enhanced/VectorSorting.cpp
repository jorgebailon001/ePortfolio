//============================================================================
// Name        : VectorSorting.cpp
// Author      : Jorge Bailon
// Version     : 1.0
// Copyright   : Copyright � 2017 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>
#include <stack>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information using console (std::in)
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) {
    cout << "Loading CSV file " << csvPath << endl;

    // Define a vector data structure to hold a collection of bids.
    vector<Bid> bids;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bids.push_back(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

// FIXME (2a): Implement the quick sort logic over bid.title

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */
int partition(vector<Bid>& bids, int begin, int end) {
    //set low and high equal to begin and end
    int low = begin;
    int high = end;

    // Calculate the middle point
    int middlePoint = begin + (end - begin) / 2;

    // pick the middle element as pivot point
    string pivot = bids[middlePoint].title;

    // while not done 
    bool done = false;
    while (!done) {

        // keep incrementing low index while bids[low] < bids[pivot]
        while (bids[low].title < pivot) {
            low++;
        }

        // keep decrementing high index while bids[pivot] < bids[high]
        while (pivot < bids[high].title) {
            high--;
        }

        /* If there are zero or one elements remaining,
            all bids are partitioned. Return high */
            // else swap the low and high bids (built in vector method)
                 // move low and high closer ++low, --hig
        if (low >= high) {
            done = true;
        }
        else {
            // Swap the low and high bids
            swap(bids[low], bids[high]);
            // moving low and high closer 
            low++;
            high--;
        }
    }

    return high;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */
void quickSort(vector<Bid>& bids, int begin, int end) {
    //set mid equal to 0
    if (begin >= end) {
        return;
    }

    /* Base case: If there are 1 or zero bids to sort,
     partition is already sorted otherwise if begin is greater
     than or equal to end then return*/

     /* Partition bids into low and high such that
      midpoint is location of last element in low */
    int mid = partition(bids, begin, end);

    // recursively sort low partition (begin to mid)
    quickSort(bids, begin, mid);

    // recursively sort high partition (mid+1 to end)
    quickSort(bids, mid + 1, end);
}

// FIXME (1a): Implement the selection sort logic over bid.title

/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */
void selectionSort(vector<Bid>& bids) {
    int size = bids.size(); // Getting the number of bids in the vector
    int min; // To hold the index of the minimum element

    //Outer loop to move through each element of the vector
    for (int pos = 0; pos < size - 1; pos++) {
        min = pos; // Set the current position as minimum 

        // Inner loop to find the minimum element in the unsorted section of the vector
        for (int i = pos + 1; i < size; i++) {
            // If the current element's title is less than the current minimum's title, update min
            if (bids[i].title < bids[min].title) {
                min = i;
            }
        }

        // After finding the minimum element, swap it with the first unsorted element if they are not the same 
        if (min != pos) {
            swap(bids[pos], bids[min]);
        }
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */

std::vector<Bid> copyBids(const std::vector<Bid>& source) {
    return std::vector<Bid>(source); // vector's copy constructor performs deep copy
}

int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    std::stack<std::vector<Bid>> undoStack;
    std::stack<std::vector<Bid>> redoStack;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  5. Undo Last Sort" << endl;
        cout << "  6. Redo Last Sort" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            bids = loadBids(csvPath);

            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 2:
            // Loop and display the bids read
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

            // FIXME (1b): Invoke the selection sort and report timing results
        case 3:
            undoStack.push(copyBids(bids)); // Save current state before sorting
            while (!redoStack.empty()) redoStack.pop(); // Clear redo history

            ticks = clock(); // Captures the start time
            selectionSort(bids);
            ticks = clock() - ticks;

            cout << bids.size() << " bids sorted." << endl;
            cout << "Selection Sort time: " << ticks << " clock ticks" << endl;
            cout << "Selection Sort time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds " << " seconds" << endl;

            break;

            // FIXME (2b): Invoke the quick sort and report timing results
        case 4:
            undoStack.push(copyBids(bids));
            while (!redoStack.empty()) redoStack.pop();

            ticks = clock();
            quickSort(bids, 0, bids.size() - 1);
            ticks = clock() - ticks;

            cout << bids.size() << " bids sorted using quick sort" << endl;
            cout << "Time: " << ticks << " clock ticks" << endl;
            cout << "Time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 5:
            if (!undoStack.empty()) {
                redoStack.push(copyBids(bids)); // Save current state for redo
                bids = undoStack.top();
                undoStack.pop();
                cout << "Undo successful." << endl;
            }
            else {
                cout << "Nothing to undo." << endl;
            }
            break;

        case 6:
            if (!redoStack.empty()) {
                undoStack.push(copyBids(bids));
                bids = redoStack.top();
                redoStack.pop();
                cout << "Redo successful." << endl;
            }
            else {
                cout << "Nothing to redo." << endl;
            }
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}