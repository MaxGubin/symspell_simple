#include "integer_compression.h"

namespace grammarly {


void BitWriter::put(uint32_t x) {

}

void compress(BitWriter& writer, std::span<uint32_t> integers) {
    for (const auto x: integers) {
        writer.put(x);
    }
}

} // namespace grammarly