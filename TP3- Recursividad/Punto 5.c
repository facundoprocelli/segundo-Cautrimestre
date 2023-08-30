#include <stdio.h>
#include <stdlib.h>


/*
5. Determinar en forma recursiva si un arreglo es capicúa.
*/

int main()
{

    int arreglo[5] = {1,3,2,3,1};

    confirmarCapicua(arreglo, 5, 0, 4);
    return 0;
}




void confirmarCapicua(int arreglo[], int validos, int i, int k) {
    if (i >= k) { // 1° condicion de salida, que los dos indices sean iguals o uno mayor a otro
        printf("Es capicua");

    }
     else if (arreglo[i] != arreglo[k]){
      // 2° condicion de slaida, que los elelemntos sean diferentes
        printf("No es capicua");
    } else {
        confirmarCapicua(arreglo, validos, i + 1, k - 1); // llamado recursivo
                                            // acercamiento a ambas salidas
    }
}



// por que el codigo este no funciona correctamente

/*
void confirmarCapicua(int arreglo[], int validos, int i, int k){

if ( i >= k && arreglo[i] == arreglo[k] ){


// Para que salga de la funcion, lo que tiene que
    pasar es que los indices sean iguales, lo cual si sucede quere decir que es capicua
    y tambien que los valores sean diferentes, por lo tanto si sucede no es capicua


        printf(" es capicua");
} else{
        printf(" no Es capicua");
    confirmarCapicua( arreglo, validos, i + 1, k - 1);

}

}

*/





