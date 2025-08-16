#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

// === Reversal method required by the assignment ===
// Reads from inFile, reverses ALL characters, writes to outFile.
bool reverseFile(const std::string& inFile, const std::string& outFile) {
    std::ifstream in(inFile, std::ios::binary);
    if (!in) return false;

    std::ostringstream buf;
    buf << in.rdbuf();                 // read whole file
    std::string data = buf.str();

    std::reverse(data.begin(), data.end());

    std::ofstream out(outFile, std::ios::binary);
    if (!out) return false;
    out << data;
    return true;
}

int main() {
    const std::string inFile  = "CSC450_CT5_mod5.txt";
    const std::string outFile = "CSC450-mod5-reverse.txt";

    // 1) get a line from the user and append it
    std::cout << "Enter a line to append: ";
    std::string line;
    std::getline(std::cin, line);

    std::ofstream appender(inFile, std::ios::app);
    if (!appender) { std::cerr << "Cannot open " << inFile << " for appending.\n"; return 1; }
    appender << line << '\n';
    appender.close();

    // 2) call the reversal method (meets the requirement)
    if (!reverseFile(inFile, outFile)) {
        std::cerr << "Failed to reverse and write output file.\n";
        return 1;
    }

    std::cout << "Appended to " << inFile
              << " and wrote reversed chars to " << outFile << ".\n";
    return 0;
}
