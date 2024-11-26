#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Function to check if a string belongs to L1
bool isInL1(const string& str) {
    if (str.length() < 4) return false;
    return str.substr(0, 2) == str.substr(str.length() - 2, 2);
}

// Function to check if a string belongs to L2
bool isInL2(const string& str) {
    regex pattern("^a[a|b]*b$");
    return regex_match(str, pattern);
}

// Union of L1 and L2
bool isInUnion(const string& str) {
    return isInL1(str) || isInL2(str);
}

// Intersection of L1 and L2
bool isInIntersection(const string& str) {
    return isInL1(str) && isInL2(str);
}

// Concatenation of L1 and L2
bool isInConcatenation(const string& str) {
    // Divide the string into two parts and check
    for (size_t i = 1; i < str.length(); ++i) {
        string part1 = str.substr(0, i);
        string part2 = str.substr(i);
        if (isInL1(part1) && isInL2(part2)) {
            return true;
        }
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    cout << "Belongs to L1: " << (isInL1(input) ? "Yes" : "No") << endl;
    cout << "Belongs to L2: " << (isInL2(input) ? "Yes" : "No") << endl;
    cout << "Belongs to L1 ? L2 (Union): " << (isInUnion(input) ? "Yes" : "No") << endl;
    cout << "Belongs to L1 n L2 (Intersection): " << (isInIntersection(input) ? "Yes" : "No") << endl;
    cout << "Belongs to L1 L2 (Concatenation): " << (isInConcatenation(input) ? "Yes" : "No") << endl;

    return 0;
}

