#include "my_ntohl.h"

uint32_t my_ntohl(uint32_t n){
        uint32_t n1,n2,n3,n4;

        n1 = (n & 0xFF000000) >> 24;
        n2 = (n & 0x00FF0000) >> 8;
        n3 = (n & 0x0000FF00) << 8;
        n4 = (n & 0x000000FF) << 24;

        return n1 | n2 | n3 | n4;
}

