#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "timeutil.h"

#if defined USE_CLOCK_GETTIME
double gethrtime_x86(void) {
  return (double)get_ns_time() /(double)1000000000llu;
}
#endif

unsigned long long get_ns_time() {
  struct timespec ts;

  if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
    errorExit("clock_gettime()");
  } 

  return (unsigned long long)ts.tv_sec*1000000000llu 
      + (unsigned long long)ts.tv_nsec;
}

volatile char *buf;

void allocateAndUseBuf(int mb) {

  buf = malloc(mb*1024*1024);

  if (buf == NULL) {
    errorExit("malloc()");
  }

  for (int i=0; i<mb*1024*1024; i++) { // Q2. why "buf[i] = ..."?
    buf[i] = i % 255;
  }
}

void errorExit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

