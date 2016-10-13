/*
@date Octubre 2016
@author Carlos Almeraz, Edgar Ortiz

*/
#include <stdio.h>
#include <stdlib.h>

extern int push(int *stack, int pos);
extern int pop(int *stack, int pos);
extern int peek(int *stack, int pos);
extern void print(int *stack);

int main(void){
  int stack[5], pos = -1, opt = -1, val = 0, in = 0;
  printf("***BIENVENIDO AL STACK***\n");
  while (in == 0){
    printf("      ¿Que desea hacer?\n1) Insertar al Stack\n2) Sacar del Stack\n3) Ver el ultimo valor insertado\n4) Imprimir el Stack\n5) Salir\n$ ");
    scanf("%d",&opt);
    switch(opt){
      case 1:
        pos++;
        val=push(stack, pos);
        printf("\nSe ingreso el valor -> %d\n", val);
        break;
      case 2:
        val=pop(stack, pos);
        pos--;
        printf("\nSe saco el valor-> %d\n", val);
        break;
      case 3:
        val=peek(stack, pos);
        printf("\nEl ultimo valor agregado es -> %d\n", val);
        break;
      case 4:
        print(stack);
        break;
      case 5:
        in=1;
        break;
      default:
        printf("\nERROR... opcion invalida, vuelva a intentar...\n");
        break;
    }
  }
        return 0;
}
