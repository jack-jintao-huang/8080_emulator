#include "emulator.h"

/*
Condition Code based functions
*/
int parity(int x)
{
	int i;
    int size = 8;
	int p = 0;
	x = (x & ((1<<size)-1));
	for (i=0; i<size; i++)
	{
		if (x & 0x1) p++;
		x = x >> 1;
	}
	return (0 == (p & 0x1));
}
void set8080ConditionCodes(uint16_t answer, State8080 *state){
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = parity(answer&0xff);
}
/*
Initialize 8080 emulator.
*/
State8080* init8080(void)
{
    State8080* state = calloc(1,sizeof(State8080));
	state->memory = malloc(0x10000);  //16K
	return state;
}
int emulate8080Op(State8080* state){
    return 0;
}




int main()
{
    return 0;
}