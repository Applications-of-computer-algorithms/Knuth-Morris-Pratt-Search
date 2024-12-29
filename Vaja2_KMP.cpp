// KMP Algorithm
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

// Global output file stream
ofstream out;

/**
 * Reads the entire content of a text file and returns it as a string.
 * If the file cannot be opened, returns an empty string.
 */
string readInputText(const string& filePath) {
    ifstream input(filePath);
    stringstream sstream;

    if (!input.is_open()) {
        return string();
    }

    sstream << input.rdbuf();
    return sstream.str();
}

//  Writes the contents of the KMP "next" array (failure function) to the output file
void outputKMPNextArray(vector<int> kmpNext) {
    for (int i = 0; i < kmpNext.size(); i++) {
        out << kmpNext[i] << ' ';
    }
    out << endl;
}

// Executes the Knuth-Morris-Pratt (KMP) algorithm for string pattern matching.
void KMP(const string& text, const string& pattern) {
    vector<int> kmpNext(pattern.size(), 0);

    // Build the KMP "next" array (failure function)
    kmpNext[0] = -1; // Convention: -1 for the first index
    kmpNext[1] = 0;

    for (unsigned int i = 2; i < kmpNext.size(); i++) {
        for (unsigned int j = 1; j < i; j++) {
            string prefix = pattern.substr(0, i - j);
            string suffix = pattern.substr(j, i - j);

            if (prefix == suffix) {
                kmpNext[i] = prefix.length(); // Set prefix length in the failure function
                break;
            }
        }
    }

    // Output the "next" array
    outputKMPNextArray(kmpNext);

    // Search for pattern in the text
    int patternIndex = 0;           // Index in the pattern
    int textIndex = 0;              // Index in the text
    int matchStartIndex = 0;        // Starting index of a match in the text
    string comparisonStr = "";      // Used to build the current matching substring

    while ((textIndex + pattern.length()) < text.length()) {
        // If characters match, continue building the match
        if (text[textIndex + patternIndex] == pattern[patternIndex]) {
            if (patternIndex == 0) {
                matchStartIndex = textIndex;    // Save the starting index of the match
            }
            comparisonStr += text[textIndex + patternIndex];
            patternIndex++;

            // If the full pattern matches, output the starting index
            if (comparisonStr == pattern) {
                out << matchStartIndex << ' ';
                comparisonStr = "";             // Reset comparison string
                patternIndex = 0;               // Reset pattern index
                textIndex += pattern.length();  // Skip ahead in the text
            }
        }
        else {
            // If mismatch, adjust textIndex and reset patternIndex using the "next" array
            textIndex += patternIndex - kmpNext[patternIndex];
            patternIndex = 0;
            comparisonStr = "";                 // Reset comparison string
        }
    }
}

int main(int argc, const char* const argv[]) {
    // Ensure the program is called with exactly two arguments (pattern and file path)
    if (argc != 3) {
        return -1;
    }

    string text = readInputText(argv[2]);   // Read the text from the file
    string pattern = argv[1];               // The pattern to search for
    out.open("out.txt");                    // Open the output file

    if (!out) {
        return -2; 
    }

    KMP(text, pattern); 
    return 0;
}