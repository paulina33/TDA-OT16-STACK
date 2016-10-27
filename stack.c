#include <stdio.h>
#include <stdlib.h>
/*************************************
 *  Esta funciones agregan al estack *
 *  retiran de el stack              *
 *   eliminan elementos del stack    *
 **********************************/

int push (int * stack, int pos, float ValNum){
  stack[pos] = ValNum;
  printf("satack %i\n", stack[pos]);
  return ValNum;
}

int pop (int * stack, int pos){
  int val = stack[pos];
  stack[pos] = -9999;
  return val;
}

int peek (int * stack, int pos){
  int val = stack[pos];
  return val;
}

void print (int * stack){
  int i;
  for(i=4; i>=0; i--){
    if(stack[i] == -9999)
      printf("\n[   ]");
    else
      printf("\n[ %d  ]\n",stack[i]);
  }
}
