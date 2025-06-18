#include <iostream>
#include <string>
#include <set>

bool containsAllLetters_iterative(const std::string& input, const std::string& word) {
    std::set<char> lettersToFind(word.begin(), word.end());
    std::set<char> found;

    for (size_t i = 0; i < input.length(); ++i) {
        char ch = std::tolower(input[i]);
        if (lettersToFind.count(ch)) {
            found.insert(ch);
        }
    }

    return found == lettersToFind;
}

std::string replaceWhileWithStars_iterative(const std::string& input) {
    std::string result;
    std::string target = "while";
    size_t i = 0;

    while (i < input.length()) {
        if (input.substr(i, target.length()) == target) {
            result += "***";
            i += target.length();
        }
        else {
            result += input[i];
            ++i;
        }
    }

    return result;
}

int main() {
    std::string testString;

    std::cout << "input string: ";
    std::getline(std::cin, testString);

    std::string keyword = "while";

    // task1
    bool hasAllLetters = containsAllLetters_iterative(testString, keyword);
    std::cout << "Includes all letters from 'while' \"" << keyword << "\": "
        << (hasAllLetters ? "yes" : "no") << std::endl;

    // task2
    std::string replaced = replaceWhileWithStars_iterative(testString);
    std::cout << "after replacement: " << replaced << std::endl;

    return 0;
}
