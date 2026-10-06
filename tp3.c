/*
Programa para calcular el Indice de Masa Corporal (IMC) del usuario.
Solicita peso en kilogramos y altura en metros.
Luego aplica la fórmula: IMC = peso / (altura * altura).
Finalmente muestra el resultado numérico junto con una tabla de referencia
para que el usuario pueda interpretar su IMC, e indica en qué categoría se encuentra.
*/

#include <stdio.h>

int main(void)
{
	int peso = 0;
	float altura = 0;
	float indice = 0;

	printf("Ingrese su peso (kg): \n");
	scanf ("%d",&peso);

	printf("Ingrese su altura (m): \n");
	scanf ("%f",&altura);

	indice = peso/(altura*altura);

	printf("Su índice de masa corporal es: %.2f\n", indice);
	printf("\n");
	printf("  Índice:    <18.5     |   Condición: Bajo peso\n");
	printf("  Índice: 18.5 a 24.9  |   Condición: Normal\n");
	printf("  Índice: 25.0 a 29.9  |   Condición: Sobrepeso\n");
	printf("  Índice:     >=30     |   Condición: Obesidad\n");

	if (indice < 18.5)
		printf("Usted se encuentra en: Bajo peso\n");
	else if (indice < 25.0)
		printf("Usted se encuentra en: Normal\n");
	else if (indice < 30.0)
		printf("Usted se encuentra en: Sobrepeso\n");
	else
		printf("Usted se encuentra en: Obesidad\n");
    
}
