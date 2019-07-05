#include <bits/stdc++.h>

/**
@Fecha: 05/07/2019
@Autor: Gabriel Mar Barrio
Regionals 2016 Latin America. Problem F: Farming Robot
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=752&page=show_problem&problem=5913
**/

using namespace std;

int main()
{
    int n; /** Cantidad de estaciones **/
    int c; /** Cantidad de comandos **/
    int s; /** Estacion de carga mas cercana a la zona devastada **/


    while(cin >> n >> c >> s){
        int x[c]; /** Lista de comandos **/

        int position = 1; /** El problema especifica que el robot siempre empieza en la estacion 1 **/
        int resultado = 0;

        if(s == 1){ /** Si la zona devastada es 1, ya estuvo 1 vez ahi ese dia (ya que ahi empieza )**/
            resultado ++;
        }

        for(int i = 0  ; i < c ; i++){ /** Vamos recibiendo los comandos **/
            cin >> x[i];
            if(x[i] == 1){ /** Si se mueve con forme a las manecillas del reloj **/
                position++;
                if(position > n){ /** Al ser un campo "circular" la ultima posicion conecta con la primera **/
                    position = position - n;
                }
                if(position == s){ /** Al llegar a la estacion S nuestro resultado aumenta **/
                    resultado++;
                }
            }else{ /** Si se mueve en contra de las manecillas del reloj **/
                position--;
                if(position < 1){ /** Al ser un campo "circular" la primera posicion conecta con la ultima**/
                    position = position + n;
                }
                if(position == s){ /** Al llegar a la estacion S nuestro resultado aumenta **/
                    resultado++;
                }
            }
        }
        cout << resultado << endl;
    }
    return 0;
}
