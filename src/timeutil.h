#ifndef __NSTIME_H__
#define __NSTIME_H__

#if defined USE_CLOCK_GETTIME
double gethrtime_x86(void);
unsigned long long get_ns_time();
#endif
void errorExit(char *msg);
void allocateAndUseBuf(int mb);

#endif
