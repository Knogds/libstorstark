
#include "helper.h"

/* erase bits from .. to */
void erasebits_range(int hi, int lo, volatile unsigned int *n)
{
    while(hi >= lo)
        *n &= ~(1<<lo++);
}

