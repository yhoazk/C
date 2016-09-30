#include <stdio.h>

#define MALLSC_OFFST 0x11
#define REQMEM_OFFST 0x2B
#define REMMEM_OFFST 0x42
#define GIVPTR_OFFST 0x5B


#define TRUE 1
#define FALSE 0

typedef  unsigned short UNIT16;
/*
 * char* <- RO
 * char[] <- RW
 * */
char msg_template[] = "|Malloc Success: FALSE | Requested Memory: 00000 | Remain Memory: 00000 | Given Pointer: 0x00000000|";
                    //|Malloc Success: TRUE  | Requested Memory: 00000 | Remain Memory: 00000 | Given Pointer: 0x00000000|";
char msg_false[] = "FALSE";
char msg_true[]  = "TRUE ";
char decodeAsciiHex[] = "0123456789ABCDEF";

/*char* msg_reqMem;
char* msg_remMem;
char* msg_givptr;*/
/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/




void fill_template(int succ, UNIT16 req, UNIT16 rem, long* gvptr)
{
    char* currMsg;
    char* MsgOffstPtr;
    int i = 5;
    char base10_rq[5];
    char base10_rm[5];
    
    base10_rq[4] = (req - (req % 10000))/10000;
    base10_rm[4] = (rem - (rem % 10000))/10000;
    
    req -= (req % 10000);
    rem -= (rem % 10000);
    base10_rq[3] = (req - (rem % 1000))/1000;
    base10_rm[3] = (rem - (rem % 1000))/1000;

    req -= (req % 1000);
    rem -= (rem % 1000);
    base10_rq[2] = (req - (rem % 100))/100;
    base10_rm[2] =  (rem - (rem % 100))/100;

    req -= (req % 100);
    rem -= (rem % 100);
    base10_rq[1] =  (req - (rem % 10))/10;
    base10_rm[1] =  (rem - (rem % 10))/10;

    req -= (req % 10);
    rem -= (rem % 10);
    //base10_rq[0] =  (req - (rem % 10000))/10000;
    base10_rq[0] = req;
    base10_rm[0] = rem;
//    base10_rm[0] =  (rem - (rem % 10000))/10000;

    currMsg = (succ == FALSE)? msg_false : msg_true;
    // Copy the message to the buffer
    MsgOffstPtr = &msg_template[MALLSC_OFFST]; // move to the poss of the msg
    for(i=0; i < 5; i++ ){
       msg_template[MALLSC_OFFST+i] = *currMsg++;
       msg_template[REQMEM_OFFST+i] = decodeAsciiHex[] 
       msg_template[REMMEM_OFFST+i] = 
    }
    
    /* print the requested memory info */


}




int main(){
    fill_template(TRUE, 84, 45688, 0xDEADBEEF);
    printf("\n");
    printf(msg_template);
    fill_template(FALSE, 84, 45688, 0xDEADBEEF);
    printf("\n");
    printf(msg_template);
    return 0;
    return 0;
}
