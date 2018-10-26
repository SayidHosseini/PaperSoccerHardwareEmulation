#include "stack.h"

STACK_TYPE _stack[NUMBER_OF_STACKS][MAX_NUMBER_OF_ELEMENTS];

int _headIndex[NUMBER_OF_STACKS] = {0};
int _stackSize[NUMBER_OF_STACKS];
int _stackCounter = 0;

int sInit(int stackSize)
{
	_stackSize[_stackCounter] = stackSize;
	_stackCounter++;
	return (_stackCounter - 1);
}

void sPush(STACK_TYPE data, int stackID)
{
	if (_headIndex[stackID] < _stackSize[stackID])
		_stack[stackID][_headIndex[stackID]++] = data;
}

STACK_TYPE sPop(int stackID)
{
	if (_headIndex >= 0)
		return _stack[stackID][--_headIndex[stackID]];
}