#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <filesystem>

void print_help() {
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
}

int main(int argc, char* argv[]) {
   std::string input_file;
   std::string output_file;

   for (int i = 1; i < argc; i++) {
       std::string arg = argv[i];

       if (arg == "-h" || arg == "--help") {
           print_help();
           return 0;
       } else if (arg == "-o" || arg == "--output") {
           if (i + 1 >= argc) {
               std::cerr << "error: " << arg << " requires a file argument\n";
               return 1;
           }

           output_file = argv[++i];
       } else if (!arg.empty() && arg[0] == '-') {
           std::cerr << "error: unknown option '" << arg << "'\n";
           return 1;
       } else {
           if (!input_file.empty()) {
               std::cerr << "error: multiple input files are not supported\n";
               return 1;
           }

           input_file = arg;
       }
   }

   if (input_file.empty()) {
       print_help();
       return 1;
   }

   std::error_code ec;

   if (!std::filesystem::exists(input_file, ec)) {
       if (ec) {
           std::cerr << "error: cannot check '" << input_file << "': " << ec.message() << "\n";
       } else {
           std::cerr << "error: '" << input_file << "' does not exist\n";
       }

       return 1;
   }

   std::ifstream in(input_file);
   if (!in) {
       std::cerr << "error: cannot open '" << input_file << "'\n";
       return 1;
    }

   return 0;
}
