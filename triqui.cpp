#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
//Esta libreria cstdlib lo que hace es permitir usar dos funciciones:
//srand(), que con un parametro como time(0) hace que la semilla sea diferente en cada ejecucion
//rand() que genera un numero entre 0 y RAND_MAX (32767).
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
    return 0;
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
        tablero(tablero1);
    } while (turno <= 0 || turno >= 9 && tablero1[turno]!='O' || tablero1[turno]!= 'X'); //este bucle se hara hasta que el jugador ingrese un numero valido
}
void turnocomputadora (char simbolo,char tablero1[9]) {
    srand(time(0));
    cout << "--> Respuesta de la computadora" << endl;
    bool colocado=false;
    while (!colocado) {
        int turno = 1 + rand() % 9;
        if(tablero1[turno]==' ') {
            tablero1[turno]=simbolo;
            colocado = true;
        }
    }
    tablero(tablero1);
}
bool victoria(char simbolo, char simbolo2, char tablero[9]) {
    //HUMANO
    if((tablero[0]=='X' && tablero[1]=='X' && tablero[2]=='X') || ((tablero[3]=='X' && tablero[4]=='X' && tablero[5]=='X') || (tablero[6]=='X' && tablero[7]=='X' && tablero[8]=='X'))) {
        cout << "<--------------- GANASTE ---------------->" << endl;
        cout << endl;
        return true;
    }
    if((tablero[0]=='X' && tablero[3]=='X' && tablero[6]=='X') || ((tablero[1]=='X' && tablero[4]=='X' && tablero[7]=='X') || (tablero[2]=='X' && tablero[5]=='X' && tablero[8]=='X'))) {
        cout << "<--------------- GANASTE ---------------->" << endl;
        cout << endl;
        return true;
    }
    if (tablero[0]=='X' && tablero[4]=='X' && tablero[8]=='X' || (tablero[2]=='X' && tablero[4]=='X' && tablero[6]=='X')) {
        cout << "<--------------- GANASTE ---------------->" << endl;
        cout << endl;
        return true;
    }

    //COMPUTADORA
    if((tablero[0]=='O' && tablero[1]=='O' && tablero[2]=='O') || ((tablero[3]=='O' && tablero[4]=='O' && tablero[5]=='O') || (tablero[6]=='O' && tablero[7]=='O' && tablero[8]=='O'))) {
        cout << "<--------------- PERDISTE ---------------->" << endl;
        cout << endl;
        return true;
    }
    if((tablero[0]=='O' && tablero[3]=='O' && tablero[6]=='O') || ((tablero[1]=='O' && tablero[4]=='O' && tablero[7]=='O') || (tablero[2]=='O' && tablero[5]=='O' && tablero[8]=='O'))) {
        cout << "<--------------- PERDISTE ---------------->" << endl;
        cout << endl;
        return true;
    }
    if (tablero[0]=='O' && tablero[4]=='O' && tablero[8]=='O' || (tablero[2]=='O' && tablero[4]=='O' && tablero[6]=='O')) {
        cout << "<--------------- PERDISTE ---------------->" << endl;
        cout << endl;
        return true;
    }
    return false;
}
void jugar(char tablero1[9], char simbolo1, char simbolo2){
    int estrategia=dado();
    if (estrategia==1) {
        do {
            turnojugador(simbolo1,tablero1);
            turnocomputadora(simbolo2,tablero1);

        }while (!victoria(simbolo1, simbolo2, tablero1));
    }
}

int main() {
//Establecemos la semilla que cambia con cada ejecucion:
    char tablero1[9]= {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//Se crean variables que generen numeros del 1 al 6
    int num1=1+rand()%6;
    int num2=1+rand()%6;
//Los simbolos del jugador y de la computadora
    char simbolo1='X';
    char simbolo2='O';
    int k;
//INICIO JUEGO CON FUNCION DEL DADO
    do {
        if (k == 1) {
            for (int i = 0;i < 9; i++){
                tablero1[i] = ' ';
            }
        }
        jugar(tablero1, simbolo1, simbolo2);
        cout << "Quieres seguir jugado?" << endl;
        cout << endl;
        cout << "SI = 1   |   NO = 0";
        cout << endl;
        cin >> k;
    } while (k==1);

    cout <<endl;
return 0;
}