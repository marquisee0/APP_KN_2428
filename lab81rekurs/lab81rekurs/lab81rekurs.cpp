#include <iostream>
#include <string>
#include <set>
#include <cctype>

void collectLettersRecursive(const std::string& input, std::set<char>& found, size_t index, const std::set<char>& target) {
    if (index >= input.length()) return;

    char ch = std::tolower(input[index]);
    if (target.count(ch)) {
        found.insert(ch);
    }

    collectLettersRecursive(input, found, index + 1, target);
}

bool containsAllLetters_recursive(const std::string& input, const std::string& word) {
    std::set<char> requiredLetters(word.begin(), word.end());
    std::set<char> foundLetters;

    collectLettersRecursive(input, foundLetters, 0, requiredLetters);

    return foundLetters == requiredLetters;
}

std::string replaceWhileWithStars_recursive(const std::string& input, const std::string& target, size_t index = 0) {
    if (index >= input.length()) return "";

    if (input.substr(index, target.length()) == target) {
        return "***" + replaceWhileWithStars_recursive(input, target, index + target.length());
    }
    else {
        return input[index] + replaceWhileWithStars_recursive(input, target, index + 1);
    }
}

int main() {
    std::string testString;
    std::cout << "Input string: ";
    std::getline(std::cin, testString);

    std::string keyword = "while";

    // task1
    bool hasAllLetters = containsAllLetters_recursive(testString, keyword);
    std::cout << "Includes all letters? \"" << keyword << "\": "
        << (hasAllLetters ? "Yes" : "No") << std::endl;

    // task2
    std::string replaced = replaceWhileWithStars_recursive(testString, keyword);
    std::cout << "Changed string: " << replaced << std::endl;

    return 0;
}
