#ifndef INTEGER_COMPRESSION
#define INTEGER_COMPRESSION

#include <cstdint>
#include <span>
#include <>

namespace grammarly {

class BitReader {
public:
};

class BitWriter {
public:
    void put(uint32_t x);
private:
    std::back_insert_terator 
};
// 
void compress(BitWriter&, std::span<uint32_t> integers);


}  // namespace grammarly


#endif // INTEGER_COMPRESSION