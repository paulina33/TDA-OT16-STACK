/*
@date Octubre 2016
@author Carlos Almeraz, Edgar Ortiz, Ana Paulina Salazar
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern int push(int *stack, int pos, float ValNum);
extern int pop(int *stack, int pos);
extern int peek(int *stack, int pos);
extern void print(int *stack);
/***************************************************************
 *               esta es la funcion principal,                 *
 *               la lee un caracter y dependiendo              *
 *               de su tipo y valor llama a las funciones      *
 *               y realiza la operacion necesaria.             *
 ***************************************************************/
int main(void)
{
  int stack[10], pos = -1, opt = -1, in = 0, k=0, j=0,l=0,m=0;
  char num[5];
  float  ValNum=0, val = 0, val1=0, suma=0, val2=0;
  
  
  while (in == 0)
    {
      printf(">>> ");
      scanf("%s", num);//leo el caracter
      ValNum= atof(num);//cambio el caracter a su valor en float
      k=num[0];//tomo el valor ascii de el caracter
      if((k>=48) && (k<=57))//if1 valoro si lo que me ingresa es un numero
	{
	  pos++;
	  push(stack, pos, ValNum);
	  printf("\nSe ingreso el valor -> %.2f\n", ValNum);
	}//cierro if 1
      else//else1 valoro que tipo de caracter es para saber que operacion se usa
	{
	  if(pos>0)
	    {
	      val= pop(stack, pos);
	      pos--;
	      val1=pop(stack, pos);
	      pos--;
	      printf("\nSe saco el valor-> %.1f\n", val);
	      printf("\nSe saco el valor2-> %.1f\n", val1);
	      switch(k){
	     
	      case 43:
		suma = val1+val;
		printf("suma %.2f\n", suma);
		pos++;
		val2=push(stack, pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;
	     
	      case 45:
		suma = val1-val;
		printf("Resta %.2f\n", suma);
		pos++;
		val2=push(stack, pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;
	     
	      case 47:
		suma = val1/val;
		printf("Division %.2f\n", suma);
		pos++;
		val2=push(stack, pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;

	      case 120:
		suma = val1*val;
		printf("Multiplicacion %.2f\n", suma);
		pos++;
		val2=push(stack, pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;
		case 37:
		  l=val1;
		  j=val;
		m = l%j;
		printf("Modulo %i\n", m);
		pos++;
		val2=push(stack, pos, m);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;	
	      default://si no es caracter val o numero se manda un mensaje de error
		printf("ERROR la opcion no es valida.favor de ingresar un numero o un caracter.");
		in=1;// se cambia el valor de la variable a validar en el ciclo para salir de el programa. 
		break;
	      }
	    }
	  
	}
    }    
  return 0;
    
}
