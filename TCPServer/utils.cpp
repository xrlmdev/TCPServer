#include "main.h"

void toUpperCase(std::string& sSource) {
    for (char& c : sSource) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (uc >= 0xE0 && uc <= 0xFF) {
            c = uc - 0x20;
        }
        else if (uc == 0xB8) {
            c = 0xA8;
        }
        else {
            c = toupper(uc);
        }
    }
}