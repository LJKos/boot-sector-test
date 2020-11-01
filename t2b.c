#include <stdio.h>
#include <stdint.h>

uint8_t get_bin(int c) {
    switch (c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
            
        default: return 16;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("%s <src.txt> <dest.bin>\n", argv[0]);
        return 0;
    }
    
    FILE *fpin = fopen(argv[1], "r");
    if (!fpin) {
        return 1;
    }
    FILE *fpout = fopen(argv[2], "w");
    if (!fpout) {
        fclose(fpin);
        return 1;
    }
    
    int c = fgetc(fpin);
    uint8_t b = 0;
    uint8_t byte = 0;
    while (c != EOF) {
        b = get_bin(c);
        
        if (b < 16) {
            byte = b << 4;
        } else {
            c = fgetc(fpin);
            continue;
        }
        
        c = fgetc(fpin);
        b = get_bin(c);
        
        if (b < 16 && c != EOF) {
            byte |= b;
        } else {
            continue;
        }
        
        printf("%02x\n", byte);
        fwrite(&byte, 1, 1, fpout);
        byte = 0;
        c = fgetc(fpin);
    }
    
    fclose(fpin);
    fclose(fpout);
    
    return 0;
}
