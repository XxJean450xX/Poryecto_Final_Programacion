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
if (num == num2) {
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
    if(num2 > num) {
        //
        cout << "Su numero es mayor, por lo tanto usted juega primero" <<endl;
        cout << endl;
        return 1;
    }
    if (num > num2) {
        cout << "Su numero es menor, por lo tanto usted juega segundo" <<endl;
        cout << endl;
        return 0;
    }
    //aca quite el return 0
}
void tablero(char lugares[9]){ //la funcion recibe como parametro una matriz siempre
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
//esta funcion determinara el turno del jugador con una matriz cambiante
void turnojugador (char simbolo1,char tablero1[9]){
    int turno;
    do {
        cout << "--> Ingrese un numero del 1 al 9 para marcar su casilla: ";
        cin >> turno;
        //Se decrementa 'turno' porque el vector empieza a contar desde 0
        turno--;
        //Verificar que la casilla ingresada esta vacia
        if(tablero1[turno]==' ') {

            tablero1[turno]=simbolo1;
            //Si la condicion es verdadera se sale del bucle
            break;
        }
        //Despues de cada accion se mostrara como quedo reflejada la misma en el tablero
        tablero(tablero1);
    } while (turno <= 0 || turno >= 9 && tablero1[turno]!='O' || tablero1[turno]!= 'X');
    //este bucle se hara hasta que el jugador ingrese un numero valido y una posicion valida
}

bool victoria(char simbolo, char tablero[9]) {

    if(tablero[0]==simbolo && tablero[1]==simbolo && tablero[2]==simbolo) { //Filas
        cout << "1"<< endl;
        return true;
    }
    if(tablero[3]==simbolo && tablero[4]==simbolo && tablero[5]==simbolo) { //Filas
        cout << "2"<< endl;
        return true;
    }
    if(tablero[6]==simbolo && tablero[7]==simbolo && tablero[8]==simbolo) { //Filas
        cout << "3"<< endl;
        return true;
    }
    if(tablero[0]==simbolo && tablero[3]==simbolo && tablero[6]==simbolo) { //Filas
        cout << "4"<< endl;
        return true;
    }
    if(tablero[1]==simbolo && tablero[4]==simbolo && tablero[7]==simbolo) { //Filas
        cout << "5"<< endl;
        return true;
    }
    if(tablero[2]==simbolo && tablero[5]==simbolo && tablero[8]==simbolo) { //Filas
        cout << "6"<< endl;
        return true;
    }
    if(tablero[0]==simbolo && tablero[4]==simbolo && tablero[8]==simbolo) { //Filas
        cout << "7"<< endl;
        return true;
    }
    if(tablero[2]==simbolo && tablero[4]==simbolo && tablero[6]==simbolo) { //Filas
        cout << "8"<< endl;
        return true;
    }

    //Al retornar falso, significa que la condicion en el while de "jugar" es verdadera y seguira con la ejecucion
    return false;
}

bool mejormov(char tablero1[9], char simbolo1, char simbolo2) {
    for (int i = 0; i < 9; i++) {
        if (tablero1[i] == ' ') {
            tablero1[i] = simbolo1; //simulación de la jugada
            if (victoria(simbolo1, tablero1)) { //revisar si la jugada da victoria
                tablero1[i] = simbolo2;
                return true;
            }
            tablero1[i] = ' ';//Restaurar la casilla
        }
    }
    return false;
}

void turnocomputadora (char simbolo1, char simbolo2, char tablero1[9], int z) {

    cout << "--> Respuesta de la computadora" << endl;
    if (mejormov(tablero1, simbolo2, simbolo2)) {
        tablero(tablero1);
        return;
    }
    if (mejormov(tablero1, simbolo2, simbolo1)) {
        tablero(tablero1);
        return;
    }

    srand(time(0));
    bool colocado=false;
    while (!colocado) {
        int turno = 1 + rand() % 9;
        if(tablero1[turno]==' ') {
            tablero1[turno]=simbolo2;
            colocado = true;
        }
    }
    tablero(tablero1);
    return;
}
void jugar(char tablero1[9], char simbolo1, char simbolo2, int z){
    //almacenar el resultado en la variable "estrategia"
    int estrategia=dado();
    //Si retorno el valor de 1 es porque el jugador juega primero
    if (estrategia==1) {
        do {
            turnojugador(simbolo1,tablero1);
            turnocomputadora(simbolo1, simbolo2,tablero1, z);
        }while (!victoria(simbolo1, tablero1) || !victoria(simbolo2, tablero1));
    }
    //Si retorno el valor de 0 es porque la computadora juega primero
    else if (estrategia == 0 ) {
        do {
            turnocomputadora(simbolo1, simbolo2,tablero1, z);
            turnojugador(simbolo1,tablero1);
        } while (!victoria(simbolo1, tablero1) || !victoria(simbolo2, tablero1));
    }
}

int main() {
//Establecemos la semilla que cambia con cada ejecucion:
    char tablero1[9]= {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//Los simbolos del jugador y de la computadora
    char simbolo1='X';
    char simbolo2='O';
    int k;
    int z = 0; //Ayuda a guardar la cordenada de la posible victoria para la computadora
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
    } while (k==1);

    cout <<endl;
return 0;
}