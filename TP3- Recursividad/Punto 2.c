
//2. Calcular la potencia de un número en forma recursiva.

int main()
{
    int num;
    int pot;

    printf("Ingrese el numeor que desea elevar");
    scanf("%i", &num);
    printf("Ingrese la potencia deseada");
    scanf("%i", &pot);
    int i = pot;


    int rta = calcularPotencia(num, pot, 0); // Llamo a la funcion

    printf("%i", rta);

    return 0;
}


int calcularPotencia(int num, int pot, int vuelta)
{

    int rta;

    if (pot == vuelta)  // condicion de corte
    {
        // Que la cantidad de vueltas sea igual a la potencia

        rta = 1;// solucion trivial
    }
    else
    {

        rta =  num * calcularPotencia(num, pot, vuelta + 1); // llamado recursivo
        // acercamiento al corte

    }

    return rta;
}
