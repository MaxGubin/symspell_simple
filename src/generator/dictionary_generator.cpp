#include "string_mutator.h"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>
#include <unordered_map>



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

using temp_indexT = std::unordered_map<std::string, std::vector<size_t>>;
temp_indexT CreateTempIndex(const std::vector<std::string>& word_list, int num_delete) {
    temp_indexT index;
    size_t n = 0;
    for(const auto & word: word_list) {
        auto mutator_string_call = [&index, n] (std::string_view str) {
            auto [iter_pos, new_key] = index.insert({std::string(str), std::vector<size_t>()});
            if (new_key || n != iter_pos->second.back()) {
                iter_pos->second.push_back(n);
            }
        };
        grammarly::mutate_by_deletion(word, num_delete, mutator_string_call);
        ++n;
    }
    return index;
}

void CreateMappableStrings() {

}

void CreateMappableIndex() {

}

} // namespace

void GenerateDictionary(const std::string& infile, const std::string& outfile) {
    auto input_strings = LoadWordsFromFile(infile);
    std::sort(std::begin(input_strings), std::end(input_strings));
    const auto temp_index = CreateTempIndex(input_strings, 2);

    std::ofstream 

}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "input_vocabulary output_dictionary" << std::endl; 
        return -1;
    }
    std::string input_path(argv[1]);
    std::string output_path(argv[2]);
    if (input_path.empty()) {
        std::cerr << "Input file is not specified" << std::endl;
    }
    GenerateDictionary(input_path, output_path);
}