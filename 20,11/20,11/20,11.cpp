#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    FILE* file = std::fopen("text.txt", "r");
    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    char buffer[BUFSIZ]; 
    int maxLength = 0;

    while (std::fgets(buffer, BUFSIZ, file)) {
        int length = std::strlen(buffer);
        if (buffer[length - 1] == '\n') {
            length -= 1;
        }
        maxLength = (length > maxLength) ? length : maxLength;
    }

    std::fclose(file);

    if (maxLength > 0) {
        std::cout << "Length of the longest line in the file: " << maxLength << " characters." << std::endl;
    }
    else {
        std::cout << "The file is empty." << std::endl;
    }

    return 0;
}
