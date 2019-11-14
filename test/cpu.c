

#include <stdio.h>
int main(int argc,char * argv[]){
    union endian_union {
        int int_placeholder;
        char char_placeholder;
    } e_u;
    e_u.int_placeholder = 1;
    if (1 == e_u.char_placeholder){
        printf("a\n");
    }
    else{
        printf("b\n");
    }
     
    return 0;
}


