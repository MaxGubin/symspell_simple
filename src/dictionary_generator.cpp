#include <algorithm>

#include <fstream>
#include <string>
#include <string_view>
#include <vector>



namespace {
std::vector<std::string> LoadWordsFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    assert(file.is_open());
    std::vector<std::string> result;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.front() != '#') {
            result.emplace_back(std::move(line));
        }
    }
    return result;
}

} // namespace

void GenerateDictionary(const std::string& infile, const std::string& outfile) {
    auto input_strings = LoadWordsFromFile(infile);
    std::sort(std::begin(input_strings), std::end(input_strings));
}