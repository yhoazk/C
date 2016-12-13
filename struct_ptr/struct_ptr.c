#include <stdio.h>


typedef struct {
    unsigned bit0 : 1;
    unsigned bit1 : 1;
    unsigned bit2 : 1;
    unsigned bit3 : 1;
    unsigned bit4 : 1;
    unsigned bit5 : 1;
    unsigned bit6 : 1;
    unsigned bit7 : 1;
    unsigned nibble0 : 4;
    unsigned nibble1 : 4;
    unsigned char0 : 8;
    unsigned char1 : 8;
    unsigned int1 : 32;
} test;

test myStruct = { 1,1,1,1,0,0,0,0, 0x7, 0xe, 0xFE, 0xFA, 0xDEADBEEF };


void printStructByRef(test* s){
    printf("-------------------------------\n");
    printf("unsigned bit0 :1-> %x\n", s->bit0);
    printf("unsigned bit1 :1-> %x\n", s->bit1);
    printf("unsigned bit2 :1-> %x\n", s->bit2);
    printf("unsigned bit3 :1-> %x\n", s->bit3);
    printf("unsigned bit4 :1-> %x\n", s->bit4);
    printf("unsigned bit5 :1-> %x\n", s->bit5);
    printf("unsigned bit6 :1-> %x\n", s->bit6);
    printf("unsigned bit7 :1-> %x\n", s->bit7);
    printf("unsigned nibble0 :4-> %x\n", s->nibble0);
    printf("unsigned nibble1:4 -> %x\n", s->nibble1);
    printf("unsigned char0  :8-> %x\n", s->char0);
    printf("unsigned char1  :8-> %x\n", s->char1);
    printf("unsigned int1 :32-> %x\n", s->int1);
}



int main(){
    printf("asdasds\n");

    printf("unsigned bit0 :1-> %x\n", myStruct.bit0);
    printf("unsigned bit1 :1-> %x\n", myStruct.bit1);
    printf("unsigned bit2 :1-> %x\n", myStruct.bit2);
    printf("unsigned bit3 :1-> %x\n", myStruct.bit3);
    printf("unsigned bit4 :1-> %x\n", myStruct.bit4);
    printf("unsigned bit5 :1-> %x\n", myStruct.bit5);
    printf("unsigned bit6 :1-> %x\n", myStruct.bit6);
    printf("unsigned bit7 :1-> %x\n", myStruct.bit7);
    printf("unsigned nibble0 -> %x\n: 4", myStruct.nibble0);
    printf("unsigned nibble1 -> %x\n: 4", myStruct.nibble1);
    printf("unsigned char0  -> %x\n", myStruct.char0);
    printf("unsigned char1  -> %x\n", myStruct.char1);
    printf("unsigned int1 :3-> %x\n", myStruct.int1);
    
    printStructByRef(&myStruct);
    return 0;
}
