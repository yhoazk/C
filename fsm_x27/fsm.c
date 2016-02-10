/**  TEST STUFF START **/
#include <stdio.h>
/**  TEST STUFF END **/



/*
The implementation should meet the following parameters:
ECU ID = 0x60
Tester ID = 0xF0
Both answers, positive and negative, shall be supported
Time in between bytes for the ECU answer, P1 = 1ms
Time in between Tester command and the beginning of the ECU
answer, P2 = 5ms
Service seed shall be totally random and shall not be the same.
Implement the XTEA cipher algorithm of 64-bits with a key of 128-bits 3 rounds

 * */


/*****************/
/** Crypto stuff **/





/** CRC stuff **/

/** RandomSeed  stuff **/
/* Pool of entropy */
static unsigned int pui32RndEntropy[16];

static unsigned int ui32RndIndex = 0;
/* Entropy added my api user*/
void RandomAddEntropy(unsigned int ui32Entropy)
{
    //
    // Add this byte to the entropy pool.
    //
    ((unsigned char *)pui32RndEntropy)[ui32RndIndex] = ui32Entropy & 0xff;

    //
    // Increment to the next byte of the entropy pool.
    //
    ui32RndIndex = (ui32RndIndex + 1) & 63;
}


/* Get the random Seed */


unsigned int getRndSeed(void){
    unsigned int ui32A, ui32B, ui32C, ui32D, ui32Temp, ui32Idx;

    //
    // Initialize the digest.
    //
    ui32A = 0x67452301;
    ui32B = 0xefcdab89;
    ui32C = 0x98badcfe;
    ui32D = 0x10325476;

    //
    // Perform the first round of operations.
    //
#define F(a, b, c, d, k, s)                                                   \
    {                                                                         \
        ui32Temp = a + (d ^ (b & (c ^ d))) + pui32RndEntropy[k];         \
        a = (ui32Temp << s) | (ui32Temp >> (32 - s));                         \
    }
    for(ui32Idx = 0; ui32Idx < 16; ui32Idx += 4)
    {
        F(ui32A, ui32B, ui32C, ui32D, ui32Idx + 0, 3);
        F(ui32D, ui32A, ui32B, ui32C, ui32Idx + 1, 7);
        F(ui32C, ui32D, ui32A, ui32B, ui32Idx + 2, 11);
        F(ui32B, ui32C, ui32D, ui32A, ui32Idx + 3, 19);
    }

    //
    // Perform the second round of operations.
    //
#define G(a, b, c, d, k, s)                                                   \
    {                                                                         \
        ui32Temp = (a + ((b & c) | (b & d) | (c & d)) +                       \
                    pui32RndEntropy[k] + 0x5a827999);                    \
        a = (ui32Temp << s) | (ui32Temp >> (32 - s));                         \
    }
    for(ui32Idx = 0; ui32Idx < 4; ui32Idx++)
    {
        G(ui32A, ui32B, ui32C, ui32D, ui32Idx + 0, 3);
        G(ui32D, ui32A, ui32B, ui32C, ui32Idx + 4, 5);
        G(ui32C, ui32D, ui32A, ui32B, ui32Idx + 8, 9);
        G(ui32B, ui32C, ui32D, ui32A, ui32Idx + 12, 13);
    }

    //
    // Perform the third round of operations.
    //
#define H(a, b, c, d, k, s)                                            \
    {                                                                  \
        ui32Temp = a + (b ^ c ^ d) + pui32RndEntropy[k] + 0x6ed9eba1; \
        a = (ui32Temp << s) | (ui32Temp >> (32 - s));                      \
    }
    for(ui32Idx = 0; ui32Idx < 4; ui32Idx += 2)
    {
        H(ui32A, ui32B, ui32C, ui32D, ui32Idx + 0, 3);
        H(ui32D, ui32A, ui32B, ui32C, ui32Idx + 8, 9);
        H(ui32C, ui32D, ui32A, ui32B, ui32Idx + 4, 11);
        H(ui32B, ui32C, ui32D, ui32A, ui32Idx + 12, 15);

        if(ui32Idx == 2)
        {
            ui32Idx -= 3;
        }
    }

    //
    // Use the first word of the resulting digest as the random number seed.
    //
    return(ui32A + 0x67452301); 
    
}



/******** FSM STUFF START *********/


#define ECU_ID (0x60)
#define TESTER_ID (0xF0)


typedef enum STATES_t{
    IDLE = 'A',
    CHECK_IF_HEADER,
    HEADER_FORMAT,
    HEADER_TGT,
    HEADER_SRC,
    CHECK_IF_SID,
    GET_DATA_BYTES,
    GET_KEY,
    CHECK_SUM,
    WAIT_5MS,
    SEND
}STATES;

STATES ui32ProcessFSM( unsigned char ubMessage){
    static STATES currentState = CHECK_IF_HEADER;
    static STATES nextState = IDLE;

    switch(currentState){
        default:
        case CHECK_IF_HEADER:
            if(ubMessage == 82){
                nextState = HEADER_FORMAT;
                printf("Header Correct\n");
            }
            else{
                printf("Idle\n");
            }
            break;
        case HEADER_FORMAT:
            if(ubMessage == ECU_ID){
                nextState = HEADER_TGT;
                printf("ECU_ID Correct\n");
            }
            break;
        case HEADER_TGT:
            if(ubMessage == TESTER_ID){
                nextState = HEADER_SRC;
                printf("TESTER_ID Correct\n");
            }
            break;
        case HEADER_SRC:
            if(ubMessage == 27){
                nextState = CHECK_IF_SID;
                printf("Header Correct\n");
            }
            break;
        case CHECK_IF_SID:
            if(ubMessage == 1){
                nextState = CHECK_SUM;
                printf("Header Correct\n");
            }
            break;
        case GET_DATA_BYTES:
            if(ubMessage == 82){
                nextState = HEADER_FORMAT;
                printf("Header Correct\n");
            }
            break;
        case GET_KEY:
            if(ubMessage == 82){
                nextState = HEADER_FORMAT;
                printf("Header Correct\n");
            }
            break;
        case CHECK_SUM:
            if(ubMessage == 82){
                nextState = SEND;
                printf("Header Correct\n");
            }
            break;
        case WAIT_5MS:
            break;
        case SEND:
            break;
    }
    currentState = nextState;
    return currentState;
}


/******** FSM STUFF END *********/


/**  TEST MAIN START **/

int main(){
    unsigned char input = 0;
    STATES state = IDLE;
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    RandomAddEntropy(getRndSeed());
    printf("%x\n", getRndSeed());
    
    printf("Testing FSM\n ");

    while(state != SEND){
    input = getchar();
    (void) getchar(); // cosume the intro char
        state = ui32ProcessFSM(input);
        printf("State:%c\n", state);
    }

    return 0;
}
/**  TEST MAIN END **/
