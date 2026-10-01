#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char* argv[]) {
    std::string input_file;

    if (argc < 2) {
        std::cout << "mylang <input> [-o <output>]\n\n";

        std::cout << "Options:\n";
        std::cout
            << " "
            << std::left << std::setw(24)
            << "-o, --output <file>"
            << "Write output to a file\n";

        std::cout
            << " "
            << std::left << std::setw(24)
            << "-h, --help"
            << "Show this help message\n";

        return 1;
    }

    return 0;
}
