//url repositorio https://github.com/jln07hml/bmi-calculator/tree/tp8
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int cuantas_piezas(int);
int rectificable(float, float);
int rechazada(float, float);
void cargar_piezas(float *, int);
int contar(int (*)(float, float), float, float *, int);
float* reserva_memoria(int);
void segregar(int (*)(float, float), float, float *, int, float *);
void mostrar_piezas(char *, float *, int);

int main (void) {

    float diametros[TAM] = {0};
    int n;
    float max = 12;  
    float min = 10; 

    n = cuantas_piezas(TAM);

    cargar_piezas(diametros, n);

    int n_rectificar = contar(rectificable, max, diametros, n);

    float *p_rectificables = reserva_memoria(n_rectificar);

    segregar(rectificable, max, diametros, n, p_rectificables);

    int n_rechazar = contar(rechazada, min, diametros, n);

    float *p_rechazadas = reserva_memoria(n_rechazar);

    segregar(rechazada, min, diametros, n, p_rechazadas);

    mostrar_piezas("rectificables", p_rectificables, n_rectificar);

    mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);

    return 0;
}

int cuantas_piezas(int max) {
    int n;
    do {
        printf("Cuántas piezas ingresará? \n");
        scanf("%d", &n);
    } while (n < 0 || n > max);
    return n;
}
float* reserva_memoria(int n){
    float* mem;
    mem = malloc(n * (sizeof(float)));
    if (mem == NULL){
        exit(1);
    }
    return mem;
}
void cargar_piezas (float* diametros, int n){
    for (int i = 0; i < n; i++){
        do{
            printf("Ingrese diámetro de pieza %d: \n", (i+1));
            scanf("%f", (diametros + i));
        }while (0 > *(diametros + i));
    }
}

int rectificable(float diametro, float valor) {
    if (diametro > valor)
    return 1;
    else
    return 0;
}

int rechazada(float diametro, float valor) {
    if (diametro < valor)
    return 1;
    else
    return 0;
}

int  contar(int (*criterio)(float, float), float valor, float * diametros, int n){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if (criterio(*(diametros + i), valor)){
        cont = cont + 1;
        }
    }
    return (cont);
}

void segregar(int (*criterio)(float, float), float valor, float * diametros, int n, float * q){
    int j = 0;
    for (int i = 0; i < n; i++){
        if (criterio(*(diametros + i), valor)){
            *(q+j) = *(diametros+i);
            j++;
        }
    }
}

void mostrar_piezas(char * criterio, float * p, int n){
    printf("Piezas %s: \n", criterio);
    for (int i = 0; i < n; i++){
        printf("Diámetro: %.2f \n", *(p+i));
    }
    free (p); 
    // libero memoria ya que es lo que se debe hacer, es la ultima función del main y el main no se puede tocar
}