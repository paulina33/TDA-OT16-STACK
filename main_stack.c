/*
@date Octubre 2016
@author Carlos Almeraz, Edgar Ortiz, Ana Paulina Salazar
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tam 10

extern int push(int *stack, int pos, float ValNum);
extern int pop(int *stack, int pos);
extern int peek(int *stack, int pos);
extern void print(int *stack);
void motor(int *stack, int *pos, float val1, float val, char num[], int k, int *in);

/***************************************************************
 *               esta es la funcion principal,                 *
 *               la lee un caracter y dependiendo              *
 *               de su tipo y valor llama a las funciones      *
 *               y realiza la operacion necesaria.             *
 ***************************************************************/
int main(void)
{
  int stack[tam], pos = -1, in = 0, k=0;
  char num[5];
  float  ValNum=0, val = 0, val1=0;
  
  printf("Bienvenido a la calculadora favor de inicializar con el numero que quiere calcular. Una vez introducidos los dos o mas numeros a utilizar, ingrese un caractrer permitido \n 1)mas \n 2)-\n 3)porcentaje\n 4)x\n 5)/\n");
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
	  //printf("%i pos1 \n",pos);
	}//cierro if 1
      else//else1 valoro que tipo de caracter es para saber que operacion se usa
	{
	  if(pos>0)
	    {
	      val= pop(stack, pos);
	      pos--;
	      val1=pop(stack, pos);
	      // pos--;
	      printf("\nSe saco el valor-> %.1f\n", val);
	      printf("\nSe saco el valor2-> %.1f\n", val1);
	      motor(stack,  &pos,  val1, val, num, k, &in);
	      //printf("%i pos1 \n",pos);
	      //print(stack);
	    }
	  else 
	    {	   
	      //print(stack); 
printf(" no hay suficientes valores para hacer una operacion\n");
	    }	
}
      if(pos>=tam)
	{
	in=1;   
	printf("Favor de no ingresar mas de 10 valores seguidos.\n");
	} 
      //print(stack);
}    
  return 0;
    
}
void motor(int *stack, int *pos, float val1, float val, char num[], int k, int *in)
{
  int j=0,l=0,m=0;
  float val2, suma=0;
switch(k){
 case 43:	
	suma = val1+val;
		printf("suma %.2f\n", suma);
		*pos++;
		val2=push(stack, *pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;
	     
	      case 45:
		suma = val1-val;
		printf("Resta %.2f\n", suma);
		*pos++;
		val2=push(stack, *pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;
	     
	      case 47:
		suma = val1/val;
		printf("Division %.2f\n", suma);
		*pos++;
		val2=push(stack, *pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;

	      case 120:
		suma = val1*val;
		printf("Multiplicacion %.2f\n", suma);
		*pos++;
		val2=push(stack, *pos, suma);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;
		case 37:
		  l=val1;
		  j=val;
		m = l%j;
		printf("Modulo %i\n", m);
		*pos++;
		val2=push(stack, *pos, m);
		printf("\nSe ingreso el valor -> %.2f\n", val2);
		break;	
	      default://si no es caracter val o numero se manda un mensaje de error
		printf("ERROR la opcion no es valida.favor de ingresar un numero o un caracter.");
		*in=1;// se cambia el valor de la variable a validar en el ciclo para salir de el programa. 
		break;
		}
}
