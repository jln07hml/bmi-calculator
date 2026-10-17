#include <stdlib.h>
#include <stdio.h>
#define Tam 5
#define ValMáx 999999999
void main(void)
{
    int codigos[Tam];
    int precios[Tam];
    for (int i = 0; i < Tam; i++)
    {
        do
        {
            printf("Ingrese Codigo de Producto N %d: ", (i + 1));
            scanf("%d", &codigos[i]);
            if (codigos[i] > ValMáx || codigos[i] < 1)
            printf ("Codigo de Producto N %d RECHAZADO, repitalo ",(i+1));
        } while (codigos[i] > ValMáx || codigos[i] < 1);      
    }
    for (int j = 0; j < Tam; j++)
    {
        do
        {
            printf("Ingrese Precio del Producto N %d: ", (j + 1));
            scanf("%d", &precios[j]);
            if (precios[j] < 0)
            printf("Precio del Producto N %d RECHAZADO, repitalo ", (j + 1));
        } while (precios[j] < 0);        
    }
    for (int i = 0; i < Tam; i++)
    {
        printf("Codigo de Producto N%d: %d\n", (i+1), codigos[i]);     
    }
    for (int j = 0; j < Tam; j++)
    {
        printf("Precio del Producto N%d: %d\n", (j+1), precios[j]);
    }
    for (int i = 0; i < Tam; i++)
    {
        printf("Codigo de Producto Caro N%d: %d\n", (i+1), codigos[i]);     
    }
    for (int j = 0; j < Tam; j++)
    {
        printf("Precio del Producto Barato N%d: %d\n", (j+1), precios[j]);
    }
    int menor_p = precios [0];
    int mayor_p = precios [0];
    int menor_c = codigos [0];
    int mayor_c = codigos [0];
     for (int i = 0; i < Tam; i++)
    {   
        if (menor_p > precios [i]){
            menor_p = precios [i];
            menor_c = codigos [i];
        }    
    }
    for (int j = 0; j < Tam; j++)
    {
        if (mayor_p < precios [j]){
            mayor_p = precios [j];
            mayor_c = codigos [j];
        } 
    }
        
    printf("Producto caro precio: %d, codigo: %d \n", mayor_p, mayor_c); 
    printf("Producto barato precio: %d, codigo: %d \n", menor_p, menor_c); 
}