#ifndef _md64_r4300_h
#define _md64_r4300_h

typedef struct r4300_t {
    uint64_t gpr[32];
    
    /* Special Register */
    uint64_t pc;
    uint64_t hi;
    uint64_t lo;
} r4300_t;

void r4300_step();

#endif