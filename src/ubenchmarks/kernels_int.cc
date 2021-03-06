/*******************************************************************************
 * Copyright (C) 2018 Tiago R. Muck <tmuck@uci.edu>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#include "kernels.h"
#include "kernels_macros.h"


void vitamins_bm_low_ilp_cache_bad_int_limited(int *workbuffer, int workbufferS, int *out, int numIterations){
	int i = 0;
	for(i = 0; i < numIterations; ++i){
		workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)] += _vitamins_bm_low_ilp_int(0);
	}
}

void vitamins_bm_low_ilp_cache_good_int_limited(int *workbuffer, int workbufferS, int *out, int numIterations){
	int i = 0;
	for(i = 0; i < numIterations; ++i){
		*out += _vitamins_bm_low_ilp_int(0);
	}
}	


void vitamins_bm_low_ilp_cache_bad_int(int *workbuffer, int workbufferS, int *out){
    vitamins_bm_low_ilp_cache_bad_int_limited(workbuffer, workbufferS, out,512);
}

void vitamins_bm_low_ilp_cache_good_int(int *workbuffer, int workbufferS, int *out){
	vitamins_bm_low_ilp_cache_good_int_limited(workbuffer, workbufferS, out,512);
}

#define vitamins_bm_branches_cond(var, c) ((var) == (c))   

void vitamins_bm_branches_limited(int *workbuffer, int workbufferS, int *out, int numIterations){
    int ix,i;
    for(ix=0;ix<numIterations;++ix){//remove ix and use i derectly to get the weird results
        i = ix % 50;
        if(vitamins_bm_branches_cond(i, 1)) *out += 37;
        else if(vitamins_bm_branches_cond(i, 2)) *out += 41;
        else if(vitamins_bm_branches_cond(i, 46)) *out += 46;
        else if(vitamins_bm_branches_cond(i, numIterations-2)) *out += 47;
        else if(vitamins_bm_branches_cond(i, 48)) *out += 48;
        else if(vitamins_bm_branches_cond(i, 13)) *out += 13;
        else if(vitamins_bm_branches_cond(i, 14)) *out += 3;
        else if(vitamins_bm_branches_cond(i, 15)) *out += 15;
        else if(vitamins_bm_branches_cond(i, 16)) *out += 16;
        else if(vitamins_bm_branches_cond(i, numIterations-1)) *out += 17;
        else if(vitamins_bm_branches_cond(i, 22)) *out += 22;
        else if(vitamins_bm_branches_cond(i, 23)) *out += 23;
        else if(vitamins_bm_branches_cond(i, 24)) *out += 24;
        else if(vitamins_bm_branches_cond(i, 25)) *out += 35;
        else if(vitamins_bm_branches_cond(i, 26)) *out += 26;
        else if(vitamins_bm_branches_cond(i, 27)) *out += 27;
        else if(vitamins_bm_branches_cond(i, 28)) *out += 28;
        else if(vitamins_bm_branches_cond(i, 29)) *out += 29;
        else if(vitamins_bm_branches_cond(i, 49)) *out += 49;
        else if(vitamins_bm_branches_cond(i, 50)) *out += 50;
        else if(vitamins_bm_branches_cond(i, 18)) *out += 18;
        else if(vitamins_bm_branches_cond(i, 19)) *out += 19;
        else if(vitamins_bm_branches_cond(i, 20)) *out += 20;
        else if(vitamins_bm_branches_cond(i, 3)) *out += 14;
        else if(vitamins_bm_branches_cond(i, 4)) *out += 4;
        else if(vitamins_bm_branches_cond(i, 5)) *out += 5;
        else if(vitamins_bm_branches_cond(i, 6)) *out += 6;
        else if(vitamins_bm_branches_cond(i, 7)) *out += 7;
        else if(vitamins_bm_branches_cond(i, 8)) *out += 8;
        else if(vitamins_bm_branches_cond(i, 9)) *out += 9;
        else if(vitamins_bm_branches_cond(i, 10)) *out += 10;
        else if(vitamins_bm_branches_cond(i, 11)) *out += 11;
        else if(vitamins_bm_branches_cond(i, 12)) *out += 12;
        else if(vitamins_bm_branches_cond(i, 30)) *out += 30;
        else if(vitamins_bm_branches_cond(i, 31)) *out += 31;
        else if(vitamins_bm_branches_cond(i, 32)) *out += 32;
        else if(vitamins_bm_branches_cond(i, 33)) *out += 33;
        else if(vitamins_bm_branches_cond(i, 34)) *out += 34;
        else if(vitamins_bm_branches_cond(i, 35)) *out += 25;
        else if(vitamins_bm_branches_cond(i, 36)) *out += 36;
        else if(vitamins_bm_branches_cond(i, 37)) *out += 1;
        else if(vitamins_bm_branches_cond(i, 38)) *out += 38;
        else if(vitamins_bm_branches_cond(i, 39)) *out += 39;
        else if(vitamins_bm_branches_cond(i, numIterations-3)) *out += 40;
        else if(vitamins_bm_branches_cond(i, 41)) *out += 2;
        else if(vitamins_bm_branches_cond(i, 42)) *out += 42;
        else if(vitamins_bm_branches_cond(i, 43)) *out += 43;
        else if(vitamins_bm_branches_cond(i, 44)) *out += 44;
        else if(vitamins_bm_branches_cond(i, 45)) *out += 45;
        else if(vitamins_bm_branches_cond(i, 21)) *out += 21;
        else *out *= 2;
    }
}

void vitamins_bm_branches_deep_limited(int *workbuffer, int workbufferS, int *out, int numIterations){
    int ix,i;
    for(ix=0;ix<numIterations;++ix){//remove ix and use i derectly to get the weird results
        i = ix % 50;
        if(vitamins_bm_branches_cond(i, 1)) *out += 37;
        else if(vitamins_bm_branches_cond(i, 2)) *out += 41;
        else if(vitamins_bm_branches_cond(i, 46)) *out += 46;
        if(vitamins_bm_branches_cond(i, numIterations-2)) *out += 47;
        else if(vitamins_bm_branches_cond(i, 48)) *out += 48;
        else if(vitamins_bm_branches_cond(i, 13)) *out += 13;
        else if(vitamins_bm_branches_cond(i, 14)) *out += 3;
        if(vitamins_bm_branches_cond(i, 15)) *out += 15;
        else if(vitamins_bm_branches_cond(i, 16)) *out += 16;
        else if(vitamins_bm_branches_cond(i, numIterations-1)) *out += 17;
        else if(vitamins_bm_branches_cond(i, 22)) *out += 22;
        if(vitamins_bm_branches_cond(i, 23)) *out += 23;
        else if(vitamins_bm_branches_cond(i, 24)) *out += 24;
        else if(vitamins_bm_branches_cond(i, 25)) *out += 35;
        else if(vitamins_bm_branches_cond(i, 26)) *out += 26;
        if(vitamins_bm_branches_cond(i, 27)) *out += 27;
        else if(vitamins_bm_branches_cond(i, 28)) *out += 28;
        else if(vitamins_bm_branches_cond(i, 29)) *out += 29;
        else if(vitamins_bm_branches_cond(i, 49)) *out += 49;
        if(vitamins_bm_branches_cond(i, 50)) *out += 50;
        else if(vitamins_bm_branches_cond(i, 18)) *out += 18;
        else if(vitamins_bm_branches_cond(i, 19)) *out += 19;
        else if(vitamins_bm_branches_cond(i, 20)) *out += 20;
        if(vitamins_bm_branches_cond(i, 3)) *out += 14;
        else if(vitamins_bm_branches_cond(i, 4)) *out += 4;
        else if(vitamins_bm_branches_cond(i, 5)) *out += 5;
        else if(vitamins_bm_branches_cond(i, 6)) *out += 6;
        else if(vitamins_bm_branches_cond(i, 7)) *out += 7;
        else if(vitamins_bm_branches_cond(i, 8)) *out += 8;
        else if(vitamins_bm_branches_cond(i, 9)) *out += 9;
        if(vitamins_bm_branches_cond(i, 10)) *out += 10;
        else if(vitamins_bm_branches_cond(i, 11)) *out += 11;
        else if(vitamins_bm_branches_cond(i, 12)) *out += 12;
        else if(vitamins_bm_branches_cond(i, 30)) *out += 30;
        else if(vitamins_bm_branches_cond(i, 31)) *out += 31;
        if(vitamins_bm_branches_cond(i, 32)) *out += 32;
        else if(vitamins_bm_branches_cond(i, 33)) *out += 33;
        else if(vitamins_bm_branches_cond(i, 34)) *out += 34;
        else if(vitamins_bm_branches_cond(i, 35)) *out += 25;
        else if(vitamins_bm_branches_cond(i, 36)) *out += 36;
        if(vitamins_bm_branches_cond(i, 37)) *out += 1;
        else if(vitamins_bm_branches_cond(i, 38)) *out += 38;
        else if(vitamins_bm_branches_cond(i, 39)) *out += 39;
        else if(vitamins_bm_branches_cond(i, numIterations-3)) *out += 40;
        else if(vitamins_bm_branches_cond(i, 41)) *out += 2;
        else if(vitamins_bm_branches_cond(i, 42)) *out += 42;
        if(vitamins_bm_branches_cond(i, 43)) *out += 43;
        else if(vitamins_bm_branches_cond(i, 44)) *out += 44;
        else if(vitamins_bm_branches_cond(i, 45)) *out += 45;
        else if(vitamins_bm_branches_cond(i, 21)) *out += 21;
        else *out *= 2;
    }
}

void vitamins_bm_branches(int *workbuffer, int workbufferS, int *out){
    vitamins_bm_branches_limited(workbuffer, workbufferS, out,2048);
}

void vitamins_bm_branches_deep(int *workbuffer, int workbufferS, int *out){
    vitamins_bm_branches_deep_limited(workbuffer, workbufferS, out,1024);
}


#define _vitamins_bm_high_ilp_int_good_cache \
    int *f0 = (int*)&(workbuffer[0]);\
    int *f1 = (int*)&(workbuffer[1]);\
    int *f2 = (int*)&(workbuffer[2]);\
    int *f3 = (int*)&(workbuffer[3]);\
    int *f4 = (int*)&(workbuffer[4]);\
    int *f5 = (int*)&(workbuffer[5]);\
    int *f6 = (int*)&(workbuffer[6]);\
    int *f7 = (int*)&(workbuffer[7]);\
       	for(i = 0; i < numIterations; ++i){
    

#define _vitamins_bm_high_ilp_int_bad_cache \
    volatile int *f0 = 0;\
    volatile int *f1 = 0;\
    volatile int *f2 = 0;\
    volatile int *f3 = 0;\
    volatile int *f4 = 0;\
    volatile int *f5 = 0;\
    volatile int *f6 = 0;\
    volatile int *f7 = 0;\
    for(i = 0; i < numIterations; ++i){\
        f0 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f1 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f2 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f3 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f4 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f5 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f6 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);\
        f7 = &(workbuffer[vitamins_bm_mem_rnd_idx(workbufferS)]);



void vitamins_bm_high_ilp_cache_good_int_limited(int *workbuffer, int workbufferS, int *out, int numIterations){
    _vitamins_bm_high_ilp_int_begin
    _vitamins_bm_high_ilp_int_good_cache
    _vitamins_bm_high_ilp_end
}

void vitamins_bm_high_ilp_cache_bad_int_limited(int *workbuffer, int workbufferS, int *out, int numIterations){
    _vitamins_bm_high_ilp_int_begin
    _vitamins_bm_high_ilp_int_bad_cache
    _vitamins_bm_high_ilp_end
}

void vitamins_bm_high_ilp_cache_good_int(int *workbuffer, int workbufferS, int *out){
    vitamins_bm_high_ilp_cache_good_int_limited(workbuffer, workbufferS, out,2048);
}

void vitamins_bm_high_ilp_cache_bad_int(int *workbuffer, int workbufferS, int *out){
    vitamins_bm_high_ilp_cache_bad_int_limited(workbuffer, workbufferS, out,256);
}


static inline unsigned int _squareroot(unsigned int a_nInput)
{
    unsigned int op  = a_nInput;
    unsigned int res = 0;
    unsigned int one = 1uL << ((sizeof(int)*8)-2); // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for uint32_t type


    // "one" starts at the highest power of four <= than the argument.
    while (one > op)
    {
        one >>= 2;
    }

    while (one != 0)
    {
        if (op >= res + one)
        {
            op = op - (res + one);
            res = res +  2 * one;
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

#include <cstdio>

static void inline matrix_mult_acc(int *acc, int *c, int *a, int *b, const int rows, const int cols){
    for (int i=0; i < rows; i+=16)//do 1/16 here to reduce the overall rt while keeping cache issue
        for(int j=0; j < cols; j+=64)//do 1/64 here to reduce the overall rt while keeping cache issue
            for(int k=0; k < cols; ++k)
                c[(rows*i)+j] += a[(rows*i)+k]*b[(rows*k)+j];
    for (int i=0; i < rows; ++i)
        for(int j=0; j < cols; ++j)
            *acc += c[(rows*i)+j];
}


void vitamins_bm_matrix_mult_limited(int *workbuffer, int workbufferS, int *out,int numIterations){
    int matrixBufferSize = workbufferS / 3;
    int matrixSize = _squareroot(matrixBufferSize);
    if(matrixSize > 512) matrixSize = 512;//too big will fuck things up
    int *matrixABuffer = workbuffer;
    int *matrixBBuffer = &(workbuffer[matrixBufferSize]);
    int *matrixCBuffer = &(workbuffer[matrixBufferSize*2]);

    for(int i = 0; i < numIterations; ++i)
        matrix_mult_acc(out,matrixCBuffer,matrixABuffer,matrixBBuffer,matrixSize,matrixSize);

}
