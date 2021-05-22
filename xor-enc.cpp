/* 
    xor-enc for encryption
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fin, *fout;
    char p, c;
    std::string key;
    int i = 0;

    fin = fopen(argv[1], "rb");
    fout = fopen(argv[2], "wb");
    
    if(fin == NULL || fout == NULL){
        std::cout << "File not found" << std::endl;
        exit(0);
    }
    
    std::cin >> key;

    while(!feof(fin)){
        p = getc(fin);
        c = p ^ key[i];
        putc(c, fout);
        i = i + 1 %key.length();
    }

    fcloseall();
}
