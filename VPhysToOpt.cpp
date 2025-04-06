#include "OptimizedGeometry.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: VPhysToOpt <directory_path>\n";
        return 1;
    }

    fs::path directory(argv[1]);
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "The specified directory does not exist or is not a directory.\n";
        return 1;
    }
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            fs::path filePath = entry.path();
            if (filePath.extension() == ".vphys") {
                std::string rawFile = filePath.string();
                fs::path optPath = filePath;
                optPath.replace_extension(".opt");
                std::string optFile = optPath.string();

                std::cout << "Processing " << rawFile << " -> " << optFile << std::endl;
                OptimizedGeometry geom;
                if (geom.CreateOptimizedFile(rawFile, optFile)) {
                    std::cout << "Successfully saved: " << optFile << std::endl;
                }
                else {
                    std::cerr << "Error converting " << rawFile << std::endl;
                }
            }
        }
    }

    return 0;
}
