#include "GIE_Private.h"
#include "stdTypes.h"
void GIE_Enable()
{
	SREG |=(1<<7);
	}
void GIE_Disable()
{
	SREG &=~(1<<7);
}



