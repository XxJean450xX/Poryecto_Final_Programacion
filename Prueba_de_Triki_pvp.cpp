#include <iostream>
#include <cstdlib>
using namespace std;

void board(string x[3][3]){
    for (int i = 0; i < 3; i++) {
    // Bucle para recorrer las columnas
        for (int j = 0; j < 3; j++) {
            cout << x[i][j] << ""; // Imprimir el valor de cada elemento
        }
        cout << endl; // Saltar a la siguiente línea después de imprimir cada fila
    }
}

int main()
{
    int contador_play = 9;
    int play;
    int turno;
    string Tablero[3][3] = {
        { "___|", "___|", "___"},
        { "___|", "___|", "___"},
        { "   |", "   |", "   "}
    };
    board(Tablero);
    cout << "Turno" << endl;
    cin >> turno;
    for (int e = 0; e < contador_play; e++){
        cout << "Ingresa tu jugada: " << endl;
    
        switch (turno)
        {
            case 1:
                cin >> play;
                switch (play){
                    case 1:
                        if (Tablero[0][0] == "_X_|" || Tablero[0][0] == "_O_|"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[0][0] = "_X_|";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 2:
                        if (Tablero[0][1] == "_X_|" || Tablero[0][0] == "_O_|"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[0][1] = "_X_|";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 3:
                        if (Tablero[0][2] == "_X_" || Tablero[0][0] == "_O_|"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[0][2] = "_X_";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 4:
                        if (Tablero[1][0] == "_X_|" || Tablero[0][0] == "_O_|"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[1][0] = "_X_|";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 5:
                        if (Tablero[1][1] == "_X_|" || Tablero[0][0] == "_O_|"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[1][1] = "_X_|";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 6:
                        if (Tablero[1][2] == "_X_" || Tablero[0][0] == "_O_|"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[1][2] = "_X_";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 7:
                        if (Tablero[2][0] == " X |" || Tablero[0][0] == " O |"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[2][0] = " X |";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 8:
                        if (Tablero[2][1] == " X |" || Tablero[0][0] == " O |"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[2][1] = " X |";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    case 9:
                        if (Tablero[2][2] == " X " || Tablero[0][0] == " O |"){
                            cout << "Esta ocupada esta jugada" << endl;
                            cout << endl;
                            contador_play++;
                        }
                        else{
                            Tablero[2][2] = " X ";
                            board(Tablero);
                            turno++;
                        }
                        break;
                    default:
                        cout << "No exite esa jugada" << endl;
                        cout << endl;
                        contador_play++;
                        break;
                    }
                        break;
            case 2:
                cin >> play;
                switch (play){
                case 1:
                    if (Tablero[0][0] == "_X_|" || Tablero[0][0] == "_O_|"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[0][0] = "_O_|";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 2:
                    if (Tablero[0][1] == "_X_|" || Tablero[0][0] == "_O_|"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[0][1] = "_O_|";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 3:
                    if (Tablero[0][2] == "_X_" || Tablero[0][0] == "_O_|"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[0][2] = "_O_";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 4:
                    if (Tablero[1][0] == "_X_|" || Tablero[0][0] == "_O_|"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[1][0] = "_O_|";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 5:
                    if (Tablero[1][1] == "_X_|" || Tablero[0][0] == "_O_|"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[1][1] = "_O_|";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 6:
                    if (Tablero[1][2] == "_X_" || Tablero[0][0] == "_O_|"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[1][2] = "_O_";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 7:
                    if (Tablero[2][0] == " X |" || Tablero[0][0] == " O |"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[2][0] = " O |";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 8:
                    if (Tablero[2][1] == " X |" || Tablero[0][0] == " O |"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[2][1] = " O |";
                        board(Tablero);
                        turno--;
                    }
                    break;
                case 9:
                    if (Tablero[2][2] == " X " || Tablero[0][0] == " O |"){
                        cout << "Esta ocupada esta jugada" << endl;
                        cout << endl;
                        contador_play++;
                    }
                    else{
                        Tablero[2][2] = " O ";
                        board(Tablero);
                        turno--;
                    }
                    break;
                default:
                    cout << "No exite esa jugada" << endl;
                    cout << endl;
                    contador_play++;
                    break;
                    }
                    break;
        }
    }
    return 0;
}
