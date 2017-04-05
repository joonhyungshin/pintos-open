#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

/* Fixed point arithmetics. */
typedef int fixed_point_t;

/* FP_F and FP_Q should sum up to 31. */
#define FP_P 17
#define FP_Q 14
#define FP_F (1<<FP_Q)

#define INT_TO_FP(N) ((N) * FP_F)
#define FP_ROUND_ZERO(X) ((X) / FP_F)
#define FP_ROUND_NEAR(X) ((X) >= 0 ? ((X) + FP_F / 2) / FP_F   \
                          : ((X) - FP_F / 2) / FP_F)
#define FP_ADD(X, Y) ((X) + (Y))
#define FP_SUB(X, Y) ((X) - (Y))
#define FP_ADD_INT(X, N) ((X) + (N) * FP_F)
#define FP_SUB_INT(X, N) ((X) - (N) * FP_F)
#define FP_MUL(X, Y) (((int64_t) (X)) * (Y) / FP_F)
#define FP_MUL_INT(X, N) ((X) * (N))
#define FP_DIV(X, Y) (((int64_t) (X)) * FP_F / (Y))
#define FP_DIV_INT(X, N) ((X) / (N))

#endif /* threads/fixed-point.h */