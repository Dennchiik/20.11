#include <iostream>
#include <string>
#include <algorithm>

int countWordOccurrences(const std::string& text, const std::string& word) {
    size_t pos = 0;
    int count = 0;
    std::string lowerText = text;
    std::string lowerWord = word;

    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    while ((pos = lowerText.find(lowerWord, pos)) != std::string::npos) {
        count++;
        pos += lowerWord.length();
    }

    return count;
}

int main() {
    std::string wordToFind;

    std::cout << "Enter the word to find in the file (only lowercase letters): ";
    std::cin >> wordToFind;

    std::cout << "Enter the content of the file (terminate input with Ctrl+D in Unix-like systems or Ctrl+Z in Windows):\n";

    std::string text;
    std::string line;
    while (std::getline(std::cin, line)) {
        text += line + "\n";
    }

    int occurrences = countWordOccurrences(text, wordToFind);
    std::cout << "The word '" << wordToFind << "' appears " << occurrences << " times in the entered text." << std::endl;

    return 0;
}
