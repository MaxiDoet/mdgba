#include <stdint.h>
#include <stdio.h>

#include "system.h"

void r4300_step()
{
    cpu.pc += 4;
}