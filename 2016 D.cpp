#include <bits/stdc++.h>

/**

@Fecha: 05/07/2019
@Autor: Gabriel Mar Barrio
Regionals 2016 Latin America. Problem D: Dating On-Line
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5911

Breve explicacion: El problema nos brinda una serie de actividades con una calificacion, la cual puede ser como un diagrama radial de muchas maneras.
Nosotros debemos de encontrar el area mas grande de todas las areas posibles.
El problema se puede simplificar en dividir el diagrama radial en muchos triangulos pequeños, de los cuales conocemos 2 lados y un angulo (360/N), suficiente
informacion para conocer su area (mediante 1/2abSinC). Para saber cual es la manera en acomodarlos que nos dara mas area, tenemos que intentar hacer los triangulos mas grandes posibles,
en otras palabras, hacer triangulos con los lados mas grandes posibles (no queremos hacer un triangulo con el lado mas grande y el mas pequeño).
Para lograr esto podemos acomodar el arreglo de tal manera que los mas pequeños esten en los extremos y los mas grandes en el medio (el mas pequeño en el primer lugar,
el segundo mas pequeño en el ultimo, el tercero en el segundo, el cuarto en el penultimo... el mas grande en el centro.)
Al tener el arreglo ordenado de esta manera solo tenemos aplicar N veces la formula : 1/2abSinC 'a' siendo la ith casilla, 'b' la casilla i+1th y 'C' siendo 360/N. Asi solo tenemos que
ir sumando el area de todos los triangulos y podremos conocer la posible area mayor.

**/

using namespace std;

int main()
{

    int n; /** Cantidad de actividades **/
    while(cin >> n){
        double result = 0;
        int s[n]; /** Lista de actividades **/
        for(int i = 0 ; i < n ; i++){
            cin >> s[i];
        }

        /** Ordenamos el arreglo de menor a mayor **/
        sort(s,s+(sizeof(s)/sizeof(s[0])));

        int arr[n]; /** Arreglo "dummy" **/
        int middle = ceil((double)n/2.0); /** Encontramos el centro del arreglo **/


        {
            int i,j;
            for(i = 0 , j = 0 ; i < middle ; i++){
                arr[i] = s[j];
                j++;
                /** Al hacer 2 acciones por iteracion, si N es impar y estamos en la ultima iteracion no queremos que se ejecute la segunda accion **/
                if(middle == i+1 && (n%2 != 0)){
                    continue;
                }
                arr[n-1-i] = s[j];
                j++;
            }
        }

        double angle = 360/(double)n; /** Obtenemos nuestro angulo **/
        /** Por la naturaleza de los diagramas radiales, el ultimo lugar del arreglo hace un triangulo con el primero **/
        /** La funcion sin recibe radianes, asi que tenemos que convertirlos a grados (atan(1)*4=pi)**/
        result = arr[0]*arr[n-1]*sin(angle*atan(1)*4/180)/2;

        /** Vamos sacando las areas de todos los triangulos restantes **/
        for(int i = 0 ; i < n-1 ; i++){
            result = result + arr[i]*arr[i+1]*sin(angle*atan(1)*4/180)/2;
        }

        /** El problema nos pide 3 decimales redondeados, de eso se encargan las siguientes 2 lineas **/
        cout << fixed;
        cout << setprecision(3);

        cout << result << endl;
    }

    return 0;
}
