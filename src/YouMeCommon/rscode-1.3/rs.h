/*
 * rs.h
 *
 *  Created on: Sep 14, 2017
 *      Author: root
 */

#ifndef LIB_RS_H_
#define LIB_RS_H_

#include "fec.h"

// input:
// code, generated by fec_new() function from fec.h
// data[0....k-1 ], points to original data
// size, data length
//
// output:
// data[k....n-1], points to generated redundant data
//
// info:
// the function will always succeed,except malloc fail.if malloc fail,it will call exit()
void rs_encode(void *code,char *data[],int size); 


// input:
// data[0.....n-1] points to original data and redundate data,in right order
// if data[i] is missing ,set poniter data[i] to 0 (point it to null)
//
// outout:
// data[0.....k-1] will point to the recovered original data.
//
// info:
// return zero on success
// if the number of no-zero pointers is less than k,the function will fail and return non-zero
//
// advanced info:
// 1. rs_decode wont malloc memory for those zero pointers in data[0.....k-1]. instead it will re-use the memory of other non-zero pointers (and let data[0.....k-1] point to those memory).
// 2. if the input data[0.....n-1] contains x non-zero pointers,after called rs_decode,there will still be exactly x non-zero poninters in data[0.....n-1],just the order may change.
int rs_decode(void *code,char *data[],int size);


void rs_encode2(int k,int n,char *data[],int size);

int rs_decode2(int k,int n,char *data[],int size);





#endif /* LIB_RS_H_ */
