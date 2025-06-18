#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>


std::string readFileContent(const std::string& filename) {
    std::ifstream file(filename);
    std::string content, line;

    while (std::getline(file, line)) {
        content += line;
    }

    return content;
}


bool containsAllLetters(const std::string& text, const std::string& word) {
    std::set<char> requiredLetters(word.begin(), word.end());
    std::set<char> textLetters;

    for (char ch : text) {
        if (std::isalpha(ch)) {
            textLetters.insert(std::tolower(ch));
        }
    }

    for (char ch : requiredLetters) {
        if (textLetters.find(ch) == textLetters.end()) {
            return false;
        }
    }

    return true;
}


void processFile(const std::string& filename) {
    std::string content = readFileContent(filename);
    std::string targetWord = "while";

    bool result = containsAllLetters(content, targetWord);

    if (result) {
        std::cout << "File contains letters \"" << targetWord << "\".\n";
    }
    else {
        std::cout << "File DOSE NOT contains letters \"" << targetWord << "\".\n";
    }
}


int main() {
    std::string filename = "t.txt";  
    processFile(filename);
    return 0;
}
