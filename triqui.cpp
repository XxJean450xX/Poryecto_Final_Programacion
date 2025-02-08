#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
//Esta libreria cstdlib lo que hace es permitir usar dos funciciones:
//srand(), que con un parametro como time(0) hace que la semilla sea diferente en cada ejecucion
//rand() que genera un numero entre 0 y RAND_MAX (32767)
int dado() {
    srand (time(0));
    int num=1+rand()%6;
    int num2=1+rand()%6;
    //LANZAMIENTO DEL DADO: Se crean variables que generen numeros del 1 al 6
        int z;
        cout << "Lance el dado escribiendo el numero 1: ";
        cin >> z;
        cout << endl;
        cout << "<---------------RESULTADOS---------------->" << endl;
        cout << endl;
        //
        cout << "--> El resultado de su tirada es de: " << num2 << endl;
        cout << "--> El resultado de la maquina es de: " << num << endl;
        cout << endl;
        //Dependiendo de los numeros escogidos se determinara quien empieza primero
if (num == num2) { //Si se existe un empate entonces se repitira en bucle el proceso de dados
    do {
        cout << "Ha salido empate, volviendo a tirar..." << endl;
        cout << "<---------------RESULTADOS---------------->" << endl;
        cout << endl;
        //
        num=1+rand()%6;
        num2=1+rand()%6;

        cout << "--> El resultado de su tirada es de " << num << endl;
        cout << "--> El resultado de la maquina es de " << num2 << endl;
        cout << endl;
        if(num2 > num) {
            //
            cout<<"Su numero es mayor, por lo tanto usted juega primero" <<endl;
            cout << endl;
            return 1;
        }
        if(num2 < num) {
            //
            cout  << "Su numero es menor, por lo tanto usted juega segundo" <<endl;
            cout << endl;
            return 0;
        }
    }while (num==num2);
}
    if(num2 > num) { //Detectamos cual es el ganador del turno (USUARIO)
        //
        cout << "Su numero es mayor, por lo tanto usted juega primero" <<endl;
        cout << endl;
        return 1;
    }
    if (num > num2) { //Detectamos cual es el ganador del turno (BOT)
        cout << "Su numero es menor, por lo tanto usted juega segundo" <<endl;
        cout << endl;
        return 0;
    }
}

//La funcion recibe como parametro un array siempre
void tablero(char lugares[9]){
    cout <<"     |     |     "<<endl;
    cout <<"  "<<lugares[0]<<"  |  "<<lugares[1]<<"  |  "<<lugares[2]<<"  "<<endl;
    cout <<"-----------------"<<endl;
    cout <<"     |     |     "<<endl;
    cout <<"  "<<lugares[3]<<"  |  "<<lugares[4]<<"  |  "<<lugares[5]<<"  "<<endl;
    cout <<"-----------------"<<endl;
    cout <<"     |     |     "<<endl;
    cout <<"  "<<lugares[6]<<"  |  "<<lugares[7]<<"  |  "<<lugares[8]<<"  "<<endl;
 cout <<endl;
}

//La función revisa cada posibilidad de victoria a partir de condicionales
bool victoria(char simbolo, char tablero[9]) {

    if(tablero[0]==simbolo && tablero[1]==simbolo && tablero[2]==simbolo) return true; //Filas
    if(tablero[3]==simbolo && tablero[4]==simbolo && tablero[5]==simbolo) return true; //Filas
    if(tablero[6]==simbolo && tablero[7]==simbolo && tablero[8]==simbolo) return true; //Filas

    if(tablero[0]==simbolo && tablero[3]==simbolo && tablero[6]==simbolo) return true; //Columnas
    if(tablero[1]==simbolo && tablero[4]==simbolo && tablero[7]==simbolo) return true; //Columnas
    if(tablero[2]==simbolo && tablero[5]==simbolo && tablero[8]==simbolo) return true; //Columnas

    if(tablero[0]==simbolo && tablero[4]==simbolo && tablero[8]==simbolo) return true; //Diagonales
    if(tablero[2]==simbolo && tablero[4]==simbolo && tablero[6]==simbolo) return true; //Diagonales

    //Al retornar falso, significa que no existe ninguna victoria
    return false;
}

//La función ejecuta el turno del jugador
int turnojugador (char simbolo1,char tablero1[9]){
    int turno; //Almacenamiento de la pocicion donde quiere jugar el usuario
    do {
        cout << "--> Ingrese un numero del 1 al 9 para marcar su casilla: ";
        cin >> turno;
        turno--; //Se decrementa 'turno' porque el vector empieza a contar desde 0

        if(tablero1[turno]==' ') { //Verificar que la casilla ingresada esta vacia

            tablero1[turno]=simbolo1;
            tablero(tablero1);

            break; //Si la condicion es verdadera se sale del bucle
        }
        //Despues de cada accion se mostrara como quedo reflejada la misma en el tablero
        tablero(tablero1);

    } while (turno <= 0 || turno >= 9 || tablero1[turno]=='O' || tablero1[turno]== 'X'); //este bucle se hara hasta que el jugador ingrese un numero valido y una posicion valida

    return 0;
}

//La funcion recorre el tablero buscando la jugada que pueda generar una victoria haciendo una simulacion, si detecta una victoria ejecutara esa jugada como la mejor posible
bool mejormov(char tablero1[9], char simbolo1, char simbolo2) {
    for (int i = 0; i < 9; i++) { //Recorrer array

        if (tablero1[i] == ' ') {//Verificar si esta libre la casilla
            tablero1[i] = simbolo1; //Simulación de la jugada
            if (victoria(simbolo1, tablero1)) { //Revisar si la jugada da victoria
                tablero1[i] = simbolo2;//Confirma la jugada con el signo que se desea ingresar
                return true;//Retorna verdadero para que detecte que esa jugada es verdaderamente la mejor
            }
            tablero1[i] = ' ';//Restaurar la casilla si no es la jugada ganadora
        }
    }
    return false;
}

//La funcion ejecutara el turno de la computadora, permite que la jugadora detecte cuando ganar, cuando puede ganar el usuario y si no existe ninguna de esas jugadas, jugar aleatoria
int turnocomputadora (char simbolo1, char simbolo2, char tablero1[9]) {

    srand(time(0));
    cout << "--> Respuesta de la computadora" << endl;
    if (mejormov(tablero1, simbolo2, simbolo2)) { //Busca la jugada ganadora verificando si puede ganar
        tablero(tablero1); //Imprimimos el tablero para ver la jugada ejecutada
        return 1;
    }
    if (mejormov(tablero1, simbolo1, simbolo2)) {
        //Busca la jugada ganadora del usuario verificando si puede ganar y completando la jugada, pero con el signo del usuario, para asi bloquearlo
        tablero(tablero1); //Imprimimos el tablero para ver la jugada ejecutada
        return 0;
    }
    if ((tablero1[0] == simbolo1 || tablero1[2] == simbolo1 || tablero1[6] == simbolo1 || tablero1[8] == simbolo1) && (tablero1[4] == ' ')) { //Verifica si el jugador inicio con un esquina para hacer la mejor jugada en esta apartura, la cual seria en marcar la casilla del centro
        tablero1[4] = simbolo2; //Marcar casilla del centro
        tablero(tablero1);
        return 0;
    }
    if ((tablero1[4] == simbolo1) && (tablero1[0] == ' ' || tablero1[2] == ' ' || tablero1[6] == ' ' || tablero1[8] == ' ')) { //Verifica si el jugador inicio en el centro, para hacer las mejores jugadas por las esquinas
        int esquina; //Variable para esquina aleatoria
        while (tablero1[0] == ' ' || tablero1[2] == ' ' || tablero1[6] == ' ' || tablero1[8] == ' ') { //Repetira hasta que se genere una jugada valida en las esquinas
            esquina = 1 + rand() % 4;//Esquina random
            switch (esquina) { //Apartir de la esquina random, la esquina que corresponde
                case 1:
                    if (tablero1[0] == ' ') { //Verificar si esa casilla es valida
                        tablero1[0] = simbolo2;
                    } else {
                        break; //Cerrar Swicth si no es valida la casilla
                    }

                    tablero(tablero1);
                    return 0;
                case 2:
                    if (tablero1[2] == ' ') {//Verificar si esa casilla es valida
                        tablero1[2] = simbolo2;
                    }
                    else {
                        break; //Cerrar Swicth si no es valida la casilla
                    }

                    tablero(tablero1);
                    return 0;
                case 3:
                    if (tablero1[6] == ' ') {//Verificar si esa casilla es valida
                        tablero1[6] = simbolo2;
                    }
                    else {
                        break; //Cerrar Swicth si no es valida la casilla
                    }

                    tablero(tablero1);
                    return 0;
                case 4:
                    if (tablero1[8] == ' ') {//Verificar si esa casilla es valida
                        tablero1[8] = simbolo2;
                    }
                    else {
                        break; //Cerrar Swicth si no es valida la casilla
                    }

                    tablero(tablero1);
                    return 0;
            }
        }
    }

    bool colocado=false;
    while (!colocado) {
        int turno = 1 + rand() % 9;
        if(tablero1[turno]==' ') {
            tablero1[turno]=simbolo2;
            colocado = true;
        }
    }
    tablero(tablero1);
    return 0;
}

//La funcion inicia el juego, lanza el dado, y empieza un bucle entre el jugador y la maquina hasta que el contador "z" detecte que ya non hay jugadas
void jugar(char tablero1[9], char simbolo1, char simbolo2, int z){

    int estrategia=dado(); //Almacenar el resultado en la variable "estrategia" para indicar quien inicia
    while (z < 9) {
        switch (estrategia){ //Indica a partir de "estrategia" quien iniciara el juego y como se intercalara
            case 1://USUARIO
                turnojugador(simbolo1,tablero1);

                if (victoria(simbolo1, tablero1)) {
                    cout << "----- GANASTE ----->" << endl;
                    return;
                }
                estrategia--;
                z++;
                if (z > 8) {
                    break;
                }

            case 0://COMPUTADOR

                if (turnocomputadora(simbolo1, simbolo2,tablero1) == 1){ //Indica cuando el Computador completo el 3 en raya
                    cout << "<----- PERDISTE ----->" << endl;
                    return;
                }
                estrategia++;
                z++;
                if (z > 8) {
                    break;
                }
        }
    }
    tablero(tablero1);
    cout << "<----- EMPATE ----->" << endl;
}

int main() {
    char tablero1[9]= {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; //Almacena el tablero del juego

    //Los simbolos del jugador y de la computadora
    char simbolo1='X';
    char simbolo2='O';

    int k; //Ayuda a indicar si el usuario quiere seguir jugando
    int z = 0; //Contador de cantidad de jugadas

    //INICIO JUEGO CON FUNCION DEL DADO
    do {
        //ejecucion de la funcion principal "jugar"
        jugar(tablero1, simbolo1, simbolo2, z);

        //Al terminar la ejecucion se presenta el siguiente mensaje:
        cout << "Quieres seguir jugando?" << endl;
        cout << endl;
        cout << "SI = 1   |   NO = 0";
        cout << endl;
        cin >> k;

        //Si el usuario desea seguir jugando entonces se recorre un bucle que limpiara el tablero
        if (k == 1) {
            for (int i = 0;i < 9; i++){
                tablero1[i] = ' ';
            }
        }
    } while (k==1); //A partir de el valor de "k" se continuara el bucle (el juego) o se acabara (el juego)

    cout <<endl;
    return 0;
}