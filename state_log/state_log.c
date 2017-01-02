#include <stdio.h>
/*
 * Program intended to log the change of states and its count
 * and store them in an array for debugging with the shit datalizer
 * */
/* returns 1 on sucess 0 otherwise */
#define STATE_TABS (20)

typedef enum 
{
    STATE_NULL,
    STATE_A = 'a',
    STATE_B,
    STATE_C,
    STATE_D,
    STATE_E,
    STATE_F,
    STATE_G
}states_log;

typedef struct 
{
    unsigned int state;
    unsigned int count;
} state_log_t;

/* Queue related states */
unsigned int queue_head;


state_log_t state_queue[STATE_TABS];
/*Get the last state logged (head of queue)*/
states_log get_currentStateLog(void)
{
    return ((states_log)state_queue[queue_head].state);
}

states_log get_lastStateLog(void)
{
    return ((states_log)state_queue[queue_head-1].state);
}
/* increments the count of cycles registered for this state 
 * increments the head 
 * */
int increment_stateCount(void)
{
    state_queue[queue_head].count++;
    return 1;
}
/* Return the count of changed states loged */
int get_stateCount()
{
    return state_queue[queue_head].count;
}


int log_state(states_log s)
{
    states_log ls = get_currentStateLog();
    if(ls == s)
    {
        increment_stateCount();
    }
    else
    {
            queue_head++;
            state_queue[queue_head].state = s;
            state_queue[queue_head].count++;
    }
}



void printStates(){
    int i;
    for(i = 0; i < 20; i++)
    {
        printf("State: %c   Count: %i\n", state_queue[i].state,  state_queue[i].count);
    }
}


int main(void){
   char c;
   while(1)
   {
    c = getchar();
    printf(":%c:",c);
    if(EOF == c )
    {
        break;
    }
    if("\n" == c)
    {
        continue;
    }
    log_state(c);
   }
   printStates(); 
   return 0;
}

