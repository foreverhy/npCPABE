#ifndef VERIHY_HEX 
#define VERIHY_HEX

#include <sstream>
#include <string>

class Hex {
    static const std::string lut;
  public:
    static std::string encode(const std::string &input) {
        size_t len = input.size();
        std::string out;
        out.reserve(len << 1);
        for (size_t i = 0; i < len; ++i) {
            char c = input[i];
            out.push_back(lut[c >> 4]);
            out.push_back(lut[c & 15]);
        }
        return out;
    }

    static std::string decode(const std::string &input) {
        std::string out;    
        size_t len = input.length();
        out.reserve(len >> 1);
        for (size_t i = 0; i < len; i += 2) {
            unsigned v = 0;
            char a = input[i], b = input[i + 1];
            v += (a > '9') ? (a - 'a' + 10) : (a - '0');
            v <<= 4;
            v += (b > '9') ? (b - 'a' + 10) : (b - '0');
            out.push_back(v);
        }
        return out;
    }

};
const std::string Hex::lut = "0123456789abcdef";

#endif
