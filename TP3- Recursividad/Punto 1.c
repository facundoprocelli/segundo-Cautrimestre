
//1. Calcular el factorial de un número en forma recursiva. 

int main()
{
    int num;

    printf("Ingrese el numeor que desea conocer el factorial");
    scanf("%i", &num);

    int rta =  calcularFactorial(num); // Llamo a la funcion 

    printf("%i", rta);// imprimo resultado
    return 0;
}


int calcularFactorial(int num) {

int rta;
if (num == 0) { // Condicion de corte

    rta = 1; // respuesta trivial
} else {

    rta = num * calcularFactorial(num - 1); // llamo de forma recursiva
                                // acercamiento al corte
}
return rta;
}
