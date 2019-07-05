#include <bits/stdc++.h>

/**

@Fecha: 05/07/2019
@Autor: Gabriel Mar Barrio
Regionals 2016 Latin America. Problem A: Assigning Teams
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5908

**/

using namespace std;

int main()
{
    int playersSkills[4]; /** A, B, C and D**/
    int resultado = INT_MAX; /** Como queremos buscar la menor posible diferencia, incializamos nuestro resultado en un numero muy grande **/
    int temp;

    while(cin >> playersSkills[0] >> playersSkills[1] >> playersSkills[2] >> playersSkills[3]){
        temp = 0;
        resultado = INT_MAX;

        /** Al ser un problema bastante sencillo, intentamos con todas las posibles combinaciones y nos quedamos con la diferencia mas pequeña **/

        temp = abs( (playersSkills[0] + playersSkills[1]) - (playersSkills[2] + playersSkills[3]) );
        if(temp < resultado){
            resultado = temp;
        }

        temp = abs( (playersSkills[0] + playersSkills[1]) - (playersSkills[2] + playersSkills[3]) );
        if(temp < resultado){
            resultado = temp;
        }

        temp = abs( (playersSkills[0] + playersSkills[3]) - (playersSkills[2] + playersSkills[1]) );
        if(temp < resultado){
            resultado = temp;
        }

        cout << resultado << endl;
    }
    return 0;

}
