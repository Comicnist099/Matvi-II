#include <iostream> 
#include <string> 
#include <string.h> 
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;
struct punto {
	bool sección;
	float CoorX, CoorY, p;
	punto* prev, * next;
}*origen, * aux;

int numeroFilas;
int numeroColumnas;
int numeroFilas1;
int numeroColumnas1;

char numeroFilasChar[100] = "";
char numeroColumnasChar[100] = "";
char numeroFilasChar1[100] = "";
char numeroColumnasChar1[100] = "";
int repetidor = 0;
char opc;
int vector;
int contador;
float PI = 3.14159265;
char valorIngresado[50];
char EnteroChar[100], xhChar[100], yhChar[100], zhChar[100];
char enteroI_1Char[100], iI_1Char[100], jI_1Char[100], kI_1Char[100];
char enteroI_1Char2[100], iI_1Char2[100], jI_1Char2[100], kI_1Char2[100];
int Entero;




/////////////////////////////////////////
double xh = 0;
double yh = 0;
double zh = 0;
double ResultadoH = 0;

int enteroI_1 = 0;
int iI_1 = 0;
int jI_1 = 0;
int kI_1 = 0;

int enteroI_2 = 0;
int iI_2 = 0;
int jI_2 = 0;
int kI_2 = 0;

int REsultado1_1 = 0;
int REsultado1_2 = 0;
int REsultado1_3 = 0;
int REsultado1_4 = 0;

int REsultado2_1 = 0;
int REsultado2_2 = 0;
int REsultado2_3 = 0;
int REsultado2_4 = 0;

int REsultado3_1 = 0;
int REsultado3_2 = 0;
int REsultado3_3 = 0;
int REsultado3_4 = 0;

int REsultado4_1 = 0;
int REsultado4_2 = 0;
int REsultado4_3 = 0;
int REsultado4_4 = 0;
//////////////////////////////////////
void MultiplicacionDeMatrices(int, int, int);
void SumaRestaDeMatrices();
void ObtencionDeMatrices1(int, int);
void ObtencionDeMatrices2(int, int);
void ImpresionDeMatrices1(int, int);
void ImpresionDeMatrices2(int, int);
void ObtencionDeMatricesTrasladadas(int, int, float, float, float);
void ConvertirMatriz1EnMatriz2(int, int);
void ConvertirMatrizResultanteEnMatriz2(int, int);
void MultiplicacionDeMatrices2(int, int, int);
void ObtencionDeMatricesRotadas(int, int, int, char);
void ObtencionDeMatricesEscaladas(int, int, float, float, float);
float ValidacionFracciones(char[]);


bool flag = false;
void Validacion(char  x[100]) {
	int length = strlen(x);
	for (int i = 0; i < length; i++) {
		if ((x[i] > 57 || x[i] < 48)) {
			flag = false;
		}
		else {
			flag = true;
		}
	}
	if (flag == false) {
		cout << "No se pueden poner letras" << endl;
		system("pause");
	}
}


struct Movimientos
{
	char opcion[100];
	char rotacion[100];
	float filas1[100];
	float filas2[100];
	float filas3[100];
}Instrucciones[1];

struct Matriz1
{
	float filas1[11];

}Estructura1[11];

struct Matriz2
{
	float filas2[11];

}Estructura2[11];

struct MatrizResultante
{
	float filasResultantes[11];

}EstructuraResultante[11];

void main()
{
	do
	{
		cout << "\t\t BIENVENIDO \n\n";

		cout << "\t\t ¿Que desea hacer?" << endl;
		cout << "\t\t a)Suma de matrices" << endl;
		cout << "\t\t b)Resta de matrices" << endl;
		cout << "\t\t c)Multiplicacion de matrices" << endl;
		cout << "\t\t d)Multiplicacion de matriz por magnitud" << endl;
		cout << "\t\t e)Matriz compuesta" << endl;
		cout << "\t\t f)Matriz por vector" << endl;
		cout << "\t\t g)Normalización de un vector" << endl;
		cout << "\t\t h)Inverso de cuaternion" << endl;
		cout << "\t\t i)Suma de cuaterniones" << endl;
		cout << "\t\t j)Resta de cuaterniones" << endl;
		cout << "\t\t k)Multiplicación de cuaterniones" << endl;
		cout << "\t\t l)Bresehamm" << endl;
		cout << "\t\t m)Salir" << endl;

		cin >> opc;
		system("cls");

		switch (opc)
		{
		case 'A':
		case 'a':
#pragma region SUMA_MATRICES
			SumaRestaDeMatrices();
			if (flag) {
				cout << "Suma de matrices: " << endl;
				for (int i = 0; i < numeroFilas; i++) {
					for (int j = 0; j < numeroColumnas; j++) {
						Estructura1[i].filas1[j] = Estructura1[i].filas1[j] + Estructura2[i].filas2[j];
						cout<<" \t\t"<< Estructura1[i].filas1[j];

					}
					cout << endl;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			repetidor = 1;
#pragma endregion
			break;

		case'B':
		case'b':
#pragma region RESTA_MATRICES
			SumaRestaDeMatrices();
			if (flag) {
				cout << "Resta de matrices: " << endl;
				for (int i = 0; i < numeroFilas; i++) {
					for (int j = 0; j < numeroColumnas; j++) {
						Estructura1[i].filas1[j] = Estructura1[i].filas1[j] - Estructura2[i].filas2[j];
						cout<<"\t\t"<< Estructura1[i].filas1[j];
					}
					cout << endl;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
			repetidor = 1;
#pragma endregion
			break;

		case 'C':
		case 'c':
#pragma region MULTIPLICACION_MATRICES 
			cout << "***ADVERTENCIA se esta multiplicando de la manera: (Matriz1)(Matriz2)***" << endl << endl;
			cout << "Introduzca la cantidad de Filas y columnas de la matriz 1" << endl << "Filas: ";
			cin >> numeroFilasChar;
			Validacion(numeroFilasChar);
			if (flag) {
				cout << "Columnas: ";
				cin >> numeroColumnasChar;
				Validacion(numeroColumnasChar);
			}
			system("cls");
			if (flag) {
				numeroFilas = atoi(numeroFilasChar);

				numeroColumnas = atoi(numeroColumnasChar);


				cout << "***ADVERTENCIA se esta multiplicando de la manera: (Matriz1)(Matriz2)***" << endl << endl;
				cout << "Introduzca la cantidad de Filas y columnas de la matriz 2" << endl << "Filas: ";
				cin >> numeroFilasChar1;
				Validacion(numeroFilasChar1);
				if (flag) {
					cout << "Columnas: ";
					cin >> numeroColumnasChar1;
					Validacion(numeroColumnasChar1);
				}
				system("cls");
				if (flag) {
					numeroFilas1 = atoi(numeroFilasChar1);
					numeroColumnas1 = atoi(numeroColumnasChar1);
					if (numeroColumnas != numeroFilas1)
					{
						cout << "El numero de columnas de la matriz 1 debe ser igual al numero de filas de la matriz 2" << endl;
						system("pause");
						system("cls");

						repetidor = 1;
						break;
					}

					ObtencionDeMatrices1(numeroFilas, numeroColumnas);
					if (flag) {
						ObtencionDeMatrices2(numeroFilas1, numeroColumnas1);
						if (flag) {
							cout << "MATRIZ 1:" << endl;
							ImpresionDeMatrices1(numeroFilas, numeroColumnas);
							cout << endl;

							cout << "MATRIZ 2:" << endl;
							ImpresionDeMatrices2(numeroFilas1, numeroColumnas1);
							cout << endl << endl;

							cout << "Multiplicacion de matrices:" << endl;
							MultiplicacionDeMatrices(numeroFilas, numeroColumnas1, numeroColumnas);
						}
					}
				}
			}
			repetidor = 1;
#pragma endregion
			break;

		case 'D':
		case 'd':
#pragma region MAGNITUD_MATRIZ
			cout << "Introduzca la cantidad de Filas y columnas de la matriz" << endl << "Filas: ";
			cin >> numeroFilas;
			cout << "Columnas: ";
			cin >> numeroColumnas;
			system("cls");

			cout << "Introduzca la magnitud del vector: " << endl;
			cin >> vector;
			system("cls");

			ObtencionDeMatrices1(numeroFilas, numeroColumnas);
			cout << "MATRIZ 1:" << endl;
			ImpresionDeMatrices1(numeroFilas, numeroColumnas);
			cout << endl;

			cout << "Magnitud del vector: " << vector << endl << endl;
			cout << "(Matriz1)(" << vector << "):" << endl;
			for (int i = 0; i < numeroFilas; i++) {
				for (int j = 0; j < numeroColumnas; j++) {
					cout << Estructura1[i].filas1[j] * vector << "\t";
				}
				cout << endl << endl;
			}
			system("pause");
			system("cls");
			repetidor = 1;
#pragma endregion
			break;

		case 'E':
		case 'e':
#pragma region MATRIZ_COMPUESTA
		{
			Estructura2[0].filas2[0] = NULL;
			Estructura1[0].filas1[0] = NULL;
			Instrucciones[0].filas1[0] = NULL;
			contador = 0;
			do
			{
				cout << "\t\t ***ADVERTENCIA No se pueden hacer mas de 100 transformaciones***" << endl << endl;
				cout << "\t\t ¿Que desea hacer?" << endl;
				cout << "\t\t a)Taslacion" << endl;
				cout << "\t\t b)Rotacion" << endl;
				cout << "\t\t c)Escalacion" << endl;
				cout << "\t\t d)*Para finalizar* Crear Matriz compuesta" << endl;
				cin >> Instrucciones[0].opcion[contador];
				system("cls");

				switch (Instrucciones[0].opcion[contador])
				{
				case'A':
				case'a':
					char Validacion1[100], Validacion2[100], Validacion3[100];
					cout << "TRASLACION" << endl << endl;
					cout << "introduzca el valor de la traslacion en el eje X: ";
					cin >> Validacion1;
					cout << endl;
					Validacion(Validacion1);
					if (flag) {


						cout << "introduzca el valor de la traslacion en el eje Y: ";
						cin >> Validacion2;
						cout << endl;
						Validacion(Validacion2);

						if (flag) {


							cout << "introduzca el valor de la traslacion en el eje Z: ";
							cin >> Validacion3;
							cout << endl;
							Validacion(Validacion3);

							if (flag) {
								Instrucciones[0].filas1[contador] = atoi(Validacion1);
								Instrucciones[0].filas2[contador] = atoi(Validacion2);
								Instrucciones[0].filas3[contador] = atoi(Validacion3);
								contador++;
								system("cls");
							}
						}




					}
					repetidor = 1;

					break;

				case'B':
				case'b':
					char ValidacionCir[100];
					cout << "ROTACION" << endl << endl;
					cout << "introduzca el valor del grado que del que se quiere rotar: ";
					cin >> ValidacionCir;
					Validacion(ValidacionCir);
					if (flag) {
						Instrucciones[0].filas1[contador] = atoi(ValidacionCir);
						cout << "\nintroduzca el eje en el que se quiere rotar: " << endl;
						cout << "Eje X" << endl;
						cout << "Eje Y" << endl;
						cout << "Eje Z" << endl;
						cin >> Instrucciones[0].rotacion[contador];
						cout << endl;



						contador++;
						system("cls");
					}
					repetidor = 1;

					break;

				case'C':
				case'c':
					char valorIngresadoEsc[100], valorIngresadoEsc1[100], valorIngresadoEsc2[100];
					cout << "ESCALACION" << endl << endl;
					cout << "introduzca el valor de la escalacion en el eje X: ";
					cin >> valorIngresadoEsc;
					Validacion(valorIngresadoEsc);
					cout << endl;
					if (flag) {
						cout << "introduzca el valor de la escalacion en el eje Y: ";
						cin >> valorIngresadoEsc1;
						Validacion(valorIngresadoEsc1);
						cout << endl;
						if (flag) {
							cout << "introduzca el valor de la escalacion en el eje Z: ";
							cin >> valorIngresadoEsc2;
							Validacion(valorIngresadoEsc2);
							if (flag) {
								Instrucciones[0].filas1[contador] = atoi(valorIngresadoEsc);
								Instrucciones[0].filas2[contador] = atoi(valorIngresadoEsc1);
								Instrucciones[0].filas3[contador] = atoi(valorIngresadoEsc2);
								cout << endl;

								contador++;
								system("cls");
							}
						}
					}
					repetidor = 1;
					break;

				case'D':
				case'd':

					if (Instrucciones[0].filas1[0] == NULL)
					{
						cout << "No se ha sleccionado ninguna instruccion anteriormente" << endl;
						system("pause");
						system("cls");
						repetidor = 1;
						Instrucciones[0].opcion[0] == NULL;
						break;
					}
					repetidor = 0;
					break;

				default:
					repetidor = 1;
					system("cls");
					break;
				}

			} while (repetidor == 1);

			system("cls");

			for (int i = contador - 1; i > -1; i--) {
				switch (Instrucciones[0].opcion[i])
				{
				case'A':
				case'a':

					ObtencionDeMatricesTrasladadas(4, 4, Instrucciones[0].filas1[i], Instrucciones[0].filas2[i], Instrucciones[0].filas3[i]);
					if (Estructura2[0].filas2[0] == NULL) {
						ConvertirMatriz1EnMatriz2(4, 4);
						break;
					}
					MultiplicacionDeMatrices2(4, 4, 4);
					ConvertirMatrizResultanteEnMatriz2(4, 4);
					break;

				case'B':
				case'b':

					ObtencionDeMatricesRotadas(4, 4, Instrucciones[0].filas1[i], Instrucciones[0].rotacion[i]);
					if (Estructura2[0].filas2[0] == NULL) {
						ConvertirMatriz1EnMatriz2(4, 4);
						break;
					}
					MultiplicacionDeMatrices2(4, 4, 4);
					ConvertirMatrizResultanteEnMatriz2(4, 4);
					break;

				case'C':
				case'c':

					ObtencionDeMatricesEscaladas(4, 4, Instrucciones[0].filas1[i], Instrucciones[0].filas2[i], Instrucciones[0].filas3[i]);
					if (Estructura2[0].filas2[0] == NULL) {
						ConvertirMatriz1EnMatriz2(4, 4);
						break;
					}
					MultiplicacionDeMatrices2(4, 4, 4);
					ConvertirMatrizResultanteEnMatriz2(4, 4);
					break;

				default:
					break;
				}

				cout << "Desarrollo de la matriz compuesta:" << endl;
				ImpresionDeMatrices2(4, 4);
				cout << endl << endl;
				system("pause");
				system("cls");
			}
			char cantidadDePuntosChar[100] = "";
			char Valoringresadox[50] = "";
			char Valoringresadoy[50] = "";
			char Valoringresadoz[50] = "";
			int cantidadDePuntos;

			bool ver = false;
			cout << "ingrese la cantidad de puntos que desea transformar con la matriz compuesta previamente creada: ";
			cin >> cantidadDePuntosChar;
			Validacion(cantidadDePuntosChar);
			if (flag) {
				cantidadDePuntos = atoi(cantidadDePuntosChar);
				system("pause");
				system("cls");

				for (int i = 0; i < cantidadDePuntos; i++) {
					cout << "Introduzca el Punto " << i + 1 << " que se va a multiplicar la matriz compuesta: " << endl;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 1; j++) {
							if (i == 0) {
								cout << "Introduzca el valor del eje X: ";
								cin >> Valoringresadox;
								Validacion(Valoringresadox);
								Estructura1[i].filas1[j] = atoi(Valoringresadox);

							}
							else if (i == 1) {
								cout << "Introduzca el valor del eje Y: ";
								cin >> Valoringresadoy;
								Validacion(Valoringresadoy);
								Estructura1[i].filas1[j] = atoi(Valoringresadoy);

							}
							else if (i == 2) {
								cout << "Introduzca el valor del eje Z: ";
								cin >> Valoringresadoz;
								Validacion(Valoringresadoz);
								Estructura1[i].filas1[j] = atoi(Valoringresadoz);

							}
							else if (i == 3) {
								Estructura1[i].filas1[j] = 1;
							}
						}
					}
					cout << endl;

					cout << "Matriz Compuesta:" << endl;
					ImpresionDeMatrices2(4, 4);
					cout << endl;

					cout << "Punto original:			Punto Transformado:" << endl;
					MultiplicacionDeMatrices2(4, 1, 4);
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 1; j++) {
							cout<<"                          "<< Estructura1[i].filas1[j];
						}
						for (int a = 0; a < 1; a++) {
						 cout<<"     "<< EstructuraResultante[i].filasResultantes[a];
						}
						cout << endl;
					}
					cout << endl << endl;
					cout << "/////////////////////////////////////////////////////////////////////" << endl;
				}
			}
			system("pause");
			system("cls");
		}
		repetidor = 1;
#pragma endregion
		break;

		case 'f':
		case 'F':
#pragma region MATRIZ_VECTOR
		{
			char Reserv[100] = "";
			flag = true;
			cout << "Multiplicacion de una Matriz por un Vector" << endl << endl;
			cout << "Introduzaca los valores de la Matriz:" << endl;
			for (int i = 0; i < 4; i++) {
				if (flag) {
					for (int j = 0; j < 4; j++) {
						cout << "introduzca el numero en la fila " << i + 1 << " columna " << j + 1 << ": ";
						cin >> Reserv;
						Validacion(Reserv);
						if (flag)
							Estructura1[i].filas1[j] = atoi(Reserv);
						else
							break;
					}
				}
				else
					break;

			}
			system("cls");
			if (flag) {
				char ValidacionX[100] = "";
				char ValidacionY[100] = "";
				char ValidacionZ[100] = "";
				cout << "Introduzca el Punto del vector por el que se va a multiplicar la matriz: " << endl;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 1; j++) {
						if (i == 0) {
							cout << "Introduzca el valor del eje X: ";
							cin >> ValidacionX;
							Validacion(ValidacionX);
							Estructura2[i].filas2[j] = atoi(ValidacionX);


						}
						else if (i == 1) {
							cout << "Introduzca el valor del eje Y: ";
							cin >> ValidacionY;
							Validacion(ValidacionY);
							Estructura2[i].filas2[j] = atoi(ValidacionY);


						}
						else if (i == 2) {
							cout << "Introduzca el valor del eje Z: ";
							cin >> ValidacionZ;
							Validacion(ValidacionZ);
							Estructura2[i].filas2[j] = atoi(ValidacionZ);

						}
						else if (i == 3) {
							Estructura2[i].filas2[j] = 1;
						}
						if (flag) {

						}
						else
							break;
					}
				}
				if (flag) {
					system("cls");
					cout << "MATRIZ 1:" << endl;
					ImpresionDeMatrices1(4, 4);
					cout << endl;

					cout << "MATRIZ 2:" << endl;
					ImpresionDeMatrices2(4, 1);
					cout << endl << endl;

					cout << "Multiplicacion	de Matriz por Vector:" << endl;
					MultiplicacionDeMatrices(4, 1, 4);
				}
			}
			repetidor = 1;
			system("pause");
			system("cls");
		}
#pragma endregion
		break;

		case 'g':
		case 'G':
			char EnteroChar[100], xhChar[100], yhChar[100], zhChar[100];
			int Entero;
			cout << "Introduzca los vectores correspondientes a ""x y z" << endl;
			cout << "Escribe la cantidad correspondiente al apartado entero" << endl;
			cin >> EnteroChar;
			Validacion(EnteroChar);

			if (flag) {
				cout << "Escribe la cantidad correspondiente al apartado i" << endl;
				cin >> xhChar;
				Validacion(xhChar);

				if (flag) {
					cout << "Escribe la cantidad correspondiente al apartado j" << endl;
					cin >> yhChar;
					Validacion(yhChar);

					if (flag) {
						cout << "Escribe la cantidad correspondiente al apartado k" << endl;
						cin >> zhChar;
						Validacion(zhChar);

						if (flag) {
							Entero = atoi(EnteroChar);
							xh = atoi(xhChar);
							yh = atoi(yhChar);
							zh = atoi(zhChar);
						}
					}
				}
			}
			if (flag) {
				ResultadoH = sqrt(pow(Entero, 2) + pow(xh, 2) + pow(yh, 2) + pow(zh, 2));
				cout << "\n Resultado " << endl;
				cout << Entero << "	+" << xh << "i   +" << "\t" << yh << "j   +" << "\t" << zh << "k" << endl;
				cout << "______________________________________________________________" << endl;
				cout << ResultadoH << endl;
				system("pause");
				system("cls");
			}
			repetidor = 1;
			break;
		case 'H':
		case 'h':
			cout << "INVERSO DE CUATERNIONES" << endl;
			cout << "Introduzca los vectores correspondientes a ""x y z" << endl;
			cout << "Escribe la cantidad correspondiente al apartado entero" << endl;
			cin >> EnteroChar;
			Validacion(EnteroChar);

			if (flag) {
				cout << "Escribe la cantidad correspondiente al apartado i" << endl;
				cin >> xhChar;
				Validacion(xhChar);

				if (flag) {
					cout << "Escribe la cantidad correspondiente al apartado j" << endl;
					cin >> yhChar;
					Validacion(yhChar);

					if (flag) {
						cout << "Escribe la cantidad correspondiente al apartado k" << endl;
						cin >> zhChar;
						Validacion(zhChar);

						if (flag) {
							Entero = atoi(EnteroChar);
							xh = atoi(xhChar);
							yh = atoi(yhChar);
							zh = atoi(zhChar);
						}
					}
				}
			}
			if (flag) {
				ResultadoH =pow(Entero, 2) + (pow(xh, 2) + pow(yh, 2) + pow(zh, 2));
				cout << "\n Resultado " << endl;
				cout << Entero << "	+" << xh << "i   +" << "\t" << yh << "j   +" << "\t" << zh << "k" << endl;
				cout << "______________________________________________________________" << endl;
				cout << ResultadoH << endl;
				system("pause");
				system("cls");
			}

			repetidor = 1;

			break;
		case 'i':
		case 'I':
			cout << "Coloque los valores correspondientes" << endl << endl;
			cout << "Coloque el valor referente al cuaternio 1 valor Entero" << endl;
			cin >> enteroI_1Char;
			Validacion(enteroI_1Char);
			if (flag) {
				cout << "Coloque el valor referente al cuaternio 1 valor en i" << endl;
				cin >> iI_1Char;
				Validacion(iI_1Char);
				if (flag) {
					cout << "Coloque el valor referente al cuaternio 1 valor j" << endl;
					cin >> jI_1Char;
					Validacion(jI_1Char);
					if (flag) {
						cout << "Coloque el valor referente al cuaternio 1 valor k" << endl;
						cin >> kI_1Char;
						Validacion(kI_1Char);
						if (flag) {
							enteroI_1 = atoi(enteroI_1Char);
							iI_1 = atoi(iI_1Char);
							jI_1 = atoi(jI_1Char);
							kI_1 = atoi(kI_1Char);
						}
					}
				}
			}

			if (flag) {
				char enteroI_1Char2[100], iI_1Char2[100], jI_1Char2[100], kI_1Char2[100];
				cout << "Coloque los valores correspondientes" << endl << endl;
				cout << "Coloque el valor referente al cuaternio 2 valor Entero" << endl;
				cin >> enteroI_1Char2;
				Validacion(enteroI_1Char2);
				if (flag) {
					cout << "Coloque el valor referente al cuaternio 2 valor en i" << endl;
					cin >> iI_1Char2;
					Validacion(iI_1Char2);
					if (flag) {
						cout << "Coloque el valor referente al cuaternio 2 valor j" << endl;
						cin >> jI_1Char2;
						Validacion(jI_1Char2);
						if (flag) {
							cout << "Coloque el valor referente al cuaternio 2 valor k" << endl;
							cin >> kI_1Char2;
							Validacion(kI_1Char2);
							if (flag) {
								enteroI_2 = atoi(enteroI_1Char2);
								iI_2 = atoi(iI_1Char2);
								jI_2 = atoi(jI_1Char2);
								kI_2 = atoi(kI_1Char2);
							}
						}
					}
				}
				if (flag) {
					REsultado1_1 = enteroI_1 + enteroI_2;
					REsultado1_2 = iI_1 + iI_2;
					REsultado1_3 = jI_1 + jI_2;
					REsultado1_4 = kI_1 + kI_2;

					system("cls");
					cout << REsultado1_1 << "\t+\t" << REsultado1_2 << "i" << "\t+\t" << REsultado1_3 << "j" << "\t+\t" << REsultado1_4 << "k" << endl;
				}
			}

			repetidor = 1;

			break;
		case 'j':
		case'J':	cout << "Coloque los valores correspondientes" << endl << endl;
			cout << "Coloque el valor referente al cuaternio 1 valor Entero" << endl;
			cin >> enteroI_1Char;
			Validacion(enteroI_1Char);
			if (flag) {
				cout << "Coloque el valor referente al cuaternio 1 valor en i" << endl;
				cin >> iI_1Char;
				Validacion(iI_1Char);
				if (flag) {
					cout << "Coloque el valor referente al cuaternio 1 valor j" << endl;
					cin >> jI_1Char;
					Validacion(jI_1Char);
					if (flag) {
						cout << "Coloque el valor referente al cuaternio 1 valor k" << endl;
						cin >> kI_1Char;
						Validacion(kI_1Char);
						if (flag) {
							enteroI_1 = atoi(enteroI_1Char);
							iI_1 = atoi(iI_1Char);
							jI_1 = atoi(jI_1Char);
							kI_1 = atoi(kI_1Char);
						}
					}
				}
			}

			if (flag) {
				char enteroI_1Char2[100], iI_1Char2[100], jI_1Char2[100], kI_1Char2[100];
				cout << "Coloque los valores correspondientes" << endl << endl;
				cout << "Coloque el valor referente al cuaternio 2 valor Entero" << endl;
				cin >> enteroI_1Char2;
				Validacion(enteroI_1Char2);
				if (flag) {
					cout << "Coloque el valor referente al cuaternio 2 valor en i" << endl;
					cin >> iI_1Char2;
					Validacion(iI_1Char2);
					if (flag) {
						cout << "Coloque el valor referente al cuaternio 2 valor j" << endl;
						cin >> jI_1Char2;
						Validacion(jI_1Char2);
						if (flag) {
							cout << "Coloque el valor referente al cuaternio 2 valor k" << endl;
							cin >> kI_1Char2;
							Validacion(kI_1Char2);
							if (flag) {
								enteroI_2 = atoi(enteroI_1Char2);
								iI_2 = atoi(iI_1Char2);
								jI_2 = atoi(jI_1Char2);
								kI_2 = atoi(kI_1Char2);
							}
						}
					}
				}
				if (flag) {
					REsultado1_1 = enteroI_1 - enteroI_2;
					REsultado1_2 = iI_1 - iI_2;
					REsultado1_3 = jI_1 - jI_2;
					REsultado1_4 = kI_1 - kI_2;

					system("cls");
					cout << REsultado1_1 << "\t+\t" << REsultado1_2 << "i" << "\t+\t" << REsultado1_3 << "j" << "\t+\t" << REsultado1_4 << "k" << endl;
				}
			}
			repetidor = 1;

			break;

		case 'k':
		case 'K':
			char enteroI_1Char[100], iI_1Char[100], jI_1Char[100], kI_1Char[100];
			cout << "Coloque los valores correspondientes" << endl << endl;
			cout << "Coloque el valor referente al cuaternio 1 valor Entero" << endl;
			cin >> enteroI_1Char;
			Validacion(enteroI_1Char);
			if (flag) {
				cout << "Coloque el valor referente al cuaternio 1 valor en i" << endl;
				cin >> iI_1Char;
				Validacion(iI_1Char);
				if (flag) {
					cout << "Coloque el valor referente al cuaternio 1 valor j" << endl;
					cin >> jI_1Char;
					Validacion(jI_1Char);
					if (flag) {
						cout << "Coloque el valor referente al cuaternio 1 valor k" << endl;
						cin >> kI_1Char;
						Validacion(kI_1Char);
						if (flag) {
							enteroI_1 = atoi(enteroI_1Char);
							iI_1 = atoi(iI_1Char);
							jI_1 = atoi(jI_1Char);
							kI_1 = atoi(kI_1Char);
						}
					}
				}
			}

			if (flag) {
				cout << "Coloque los valores correspondientes" << endl << endl;
				cout << "Coloque el valor referente al cuaternio 2 valor Entero" << endl;
				cin >> enteroI_1Char2;
				Validacion(enteroI_1Char2);
				if (flag) {
					cout << "Coloque el valor referente al cuaternio 2 valor en i" << endl;
					cin >> iI_1Char2;
					Validacion(iI_1Char2);
					if (flag) {
						cout << "Coloque el valor referente al cuaternio 2 valor j" << endl;
						cin >> jI_1Char2;
						Validacion(jI_1Char2);
						if (flag) {
							cout << "Coloque el valor referente al cuaternio 2 valor k" << endl;
							cin >> kI_1Char2;
							Validacion(kI_1Char2);
							if (flag) {
								enteroI_2 = atoi(enteroI_1Char2);
								iI_2 = atoi(iI_1Char2);
								jI_2 = atoi(jI_1Char2);
								kI_2 = atoi(kI_1Char2);
							}
						}
					}
				}
				if (flag) {
					REsultado1_1 = enteroI_1 * enteroI_2;
					REsultado1_2 = enteroI_1 * iI_2;
					REsultado1_3 = enteroI_1 * jI_2;
					REsultado1_4 = enteroI_1 * kI_2;

					REsultado2_1 = iI_1 * enteroI_2;
					REsultado2_2 = iI_1 * iI_2;
					REsultado2_3 = iI_1 * jI_2;
					REsultado2_4 = iI_1 * kI_2;

					REsultado3_1 = jI_1 * enteroI_2;
					REsultado3_2 = jI_1 * iI_2;
					REsultado3_3 = jI_1 * jI_2;
					REsultado3_4 = jI_1 * kI_2;

					REsultado4_1 = kI_1 * enteroI_2;
					REsultado4_2 = kI_1 * iI_2;
					REsultado4_3 = kI_1 * jI_2;
					REsultado4_4 = kI_1 * kI_2;


					system("cls");
					cout << REsultado1_1 << "\t" << REsultado1_2 << "i" << "\t" << REsultado1_3 << "j" << "\t" << REsultado1_4 << "k" << endl;
					cout << REsultado2_1 << "i\t" << (-1 * REsultado2_2) << "\t" << REsultado2_3 << "k" << "\t" << (-1 * REsultado2_4) << "j" << endl;
					cout << REsultado3_1 << "j\t" << (-1 * REsultado3_2) << "k" << "\t" << (-1 * REsultado3_3) << "\t" << (REsultado3_4) << "i" << endl;
					cout << REsultado4_1 << "k\t" << (REsultado4_2) << "j" << "\t" << (-1 * REsultado4_3) << "i" << "\t" << (-1 * REsultado4_4) << "\n\n\n\n";
					cout << "Resultado Final\n";


					cout << REsultado1_1 + (-1 * REsultado2_2) + (-1 * REsultado3_3) + (-1 * REsultado4_4) << "\t" <<
						REsultado1_2 + REsultado2_1 + REsultado3_4 + (-1 * REsultado4_3) << "i\t" <<
						REsultado3_1 + REsultado1_3 + (-1 * REsultado2_4) + REsultado4_2 << "j\t" <<
						REsultado4_1 + (-1 * REsultado3_2) + REsultado2_3 + REsultado1_4 << "k" << endl;


					system("pause");
					system("cls");
				}
			}
			repetidor = 1;



			break;

		case 'l':
		case 'L':
			setlocale(LC_ALL, "");
			char opc;
			system("cls");
			printf("Algoritmo de Bresenham\n1)Línea\n2)Circunferencia\n3)Elipse\n\nEsc: Salir\n");
			opc = _getch();
			system("cls");
			switch (opc) {
			case '1': {
				double x[2], y[2], difX, difY, pIni, pIni_2;
				char xChar[100], yChar[100];
				char xChar2[100], yChar2[100];
				printf("Algoritmo de Bresenham (Línea)\nIngrese el primer punto de la línea\nX: ");
				cin >> xChar;
				Validacion(xChar);
				if (flag) {
					printf("Y: ");
					cin >> yChar;
					Validacion(yChar);
					if (flag) {
						printf("Ingrese el segundo punto de la línea\nX: ");
						cin >> xChar2;
						Validacion(xChar2);
						if (flag) {
							printf("Y: ");
							cin >> yChar2;
							Validacion(yChar2);
							if (flag) {
								x[0] = atoi(xChar);
								x[1] = atoi(xChar2);
								y[0] = atoi(yChar);
								y[1] = atoi(yChar2);
							}
							system("cls");
						}
					}
				}
				if (flag) {
					difX = x[1] - x[0]; difY = y[1] - y[0];
					pIni = difY / difX;

					// ///////////////////////////////////////
					if (0 < pIni && pIni < 1) {
						if (x[0] < x[1]) {
							pIni_2 = 2 * difY - difX;
							aux = origen = new punto;
							origen->prev = NULL;
							origen->CoorX = x[0] + 1;

							if (pIni < 0) {
								origen->CoorY = y[0];
								origen->p = pIni_2 + (2 * difY);
							}
							else if (pIni >= 0) {
								origen->CoorY = y[0] + 1;
								origen->p = pIni_2 + 2 * difY - (2 * difX);
							}
							for (int i = 0; i < (difX - 1); i++) {
								aux->next = new punto;
								aux->next->prev = aux;
								aux = aux->next;
								aux->CoorX = aux->prev->CoorX + 1;
								if (aux->prev->p < 0) {
									aux->p = aux->prev->p + (2 * difY);
									aux->CoorY = aux->prev->CoorY;
								}
								else {
									aux->p = aux->prev->p + (2 * difY) - (2 * difX);
									aux->CoorY = aux->prev->CoorY + 1;
								}
							}aux->next = NULL; aux = origen;

							cout << "\n" << "k" << "\t( x,y )\t" << "pk";

							cout << "\n" << "0" << "\t(" << x[0] + 1 << "," << y[0] + 1 << ")\t" << pIni_2;

							int k = 1;

							while (aux != NULL) {
								if (aux->next) {
									cout << "\n" << k << "\t(" << aux->next->CoorX << "," << aux->next->CoorY << ")\t" << aux->p;
									origen = origen->next;
									delete aux;
									aux = origen;
								}
								else {
									aux = NULL;
								}
								k++;
							}
						}

						// /////////////////////
						else if (x[0] > x[1]) {
							pIni_2 = 2 * difY - difX;
							aux = origen = new punto;
							origen->prev = NULL;
							origen->CoorX = x[0] - 1;

							if (pIni < 0) {
								origen->CoorY = y[0] - 1;
								origen->p = pIni_2 + (2 * difY) + (-2 * difX);

							}
							else if (pIni >= 0) {

								origen->CoorY = y[0];
								origen->p = pIni_2 + (2 * difY);
							}
							for (int i = 0; i > (difX + 1); i--) {
								aux->next = new punto;
								aux->next->prev = aux;
								aux = aux->next;
								aux->CoorX = aux->prev->CoorX - 1;
								if (aux->prev->p < 0) {
									aux->p = aux->prev->p + (2 * difY) - (2 * difX);
									aux->CoorY = aux->prev->CoorY - 1;

								}
								else {
									aux->p = aux->prev->p + (2 * difY);
									aux->CoorY = aux->prev->CoorY;
								}
							}


							aux->next = NULL; aux = origen;



							cout << "\n" << "k" << "\t( x,y )\t" << "pk";

							cout << "\n" << "0" << "\t(" << x[0] - 1 << "," << y[0] - 1 << ")\t" << pIni_2;

							int k = 1;

							while (aux != NULL) {
								if (aux->next) {
									cout << "\n" << k << "\t(" << aux->next->CoorX << "," << aux->next->CoorY << ")\t" << aux->p;
									origen = origen->next;
									delete aux;
									aux = origen;
								}
								else {
									aux = NULL;
								}
								k++;
							}
						}
					}
					else {

						if (y[0] < y[1]) {
							pIni_2 = 2 * difX - difY;
							aux = origen = new punto;
							origen->prev = NULL;
							origen->CoorY = y[0] + 1;

							if (pIni < 0) {
								origen->CoorX = x[0];
								origen->p = pIni_2 + (2 * difX);

							}
							else if (pIni >= 0) {

								origen->CoorX = x[0] + 1;
								origen->p = pIni_2 + (2 * difX) + (-2 * difY);
							}
							for (int i = 0; i < (difY - 1); i++) {
								aux->next = new punto;
								aux->next->prev = aux;
								aux = aux->next;
								aux->CoorY = aux->prev->CoorY + 1;
								if (aux->prev->p < 0) {
									aux->p = aux->prev->p + (2 * difX);
									aux->CoorX = aux->prev->CoorX;

								}
								else {

									aux->p = aux->prev->p + (2 * difX) + (-2 * difY);
									aux->CoorX = aux->prev->CoorX + 1;
								}
							}
							aux->next = NULL; aux = origen;

							cout << "\n" << "k" << "\t( x,y )\t" << "pk";

							cout << "\n" << "0" << "\t(" << x[0] + 1 << "," << y[0] + 1 << ")\t" << pIni_2;

							int k = 1;

							while (aux != NULL) {
								if (aux->next) {
									cout << "\n" << k << "\t(" << aux->next->CoorX << "," << aux->next->CoorY << ")\t" << aux->p;
									origen = origen->next;
									delete aux;
									aux = origen;
								}
								else {
									aux = NULL;
								}
								k++;
							}
						}
						else if (y[0] > y[1]) {
							pIni_2 = 2 * difX - difY;
							aux = origen = new punto;
							origen->prev = NULL;
							origen->CoorY = y[0] - 1;

							if (pIni < 0) {
								origen->CoorX = x[0];
								origen->p = pIni_2 + (2 * difX);

							}
							else if (pIni >= 0) {

								origen->CoorX = x[0] - 1;
								origen->p = pIni_2 + (2 * difX) + (-2 * difY);

							}
							for (int i = 0; i > (difY + 1); i--) {
								aux->next = new punto;
								aux->next->prev = aux;
								aux = aux->next;
								aux->CoorY = aux->prev->CoorY - 1;
								if (aux->prev->p < 0) {

									aux->p = aux->prev->p + (2 * difX) + (-2 * difY);
									aux->CoorX = aux->prev->CoorX - 1;


								}
								else {
									aux->p = aux->prev->p + (2 * difX);
									aux->CoorX = aux->prev->CoorX;
								}
							}
							aux->next = NULL; aux = origen;

							cout << "\n" << "k" << "\t( x,y )\t" << "pk";

							cout << "\n" << "0" << "\t(" << x[0] - 1 << "," << y[0] - 1 << ")\t" << pIni_2;

							int k = 1;

							while (aux != NULL) {
								if (aux->next) {
									cout << "\n" << k << "\t(" << aux->next->CoorX << "," << aux->next->CoorY << ")\t" << aux->p;
									origen = origen->next;
									delete aux;
									aux = origen;
								}
								else {
									aux = NULL;
								}
								k++;
							}
						}
					}

					aux = NULL;
					origen = NULL;
					cout << "\n";
					system("pause");

				}

				break;
			case '2': {
				aux = origen = new punto;
				float r;
				char rChar[100];
				printf("Algoritmo de Bresenham (Circunferencia)\nIngrese el radio de la circunferencia\nR: ");
				cin >> rChar;
				Validacion(rChar);
				if (flag) {
					r = atoi(rChar);
					system("cls");
					origen->p = 1 - r;
					origen->CoorX = 0;
					origen->CoorY = r;
					origen->prev = NULL;
					while (aux->CoorX < aux->CoorY) {
						aux->next = new punto;
						aux->next->prev = aux;
						aux->next->CoorX = aux->CoorX + 1;
						if (aux->p < 0) {
							aux->next->CoorY = aux->CoorY;
							aux->next->p = aux->p + 2 * aux->CoorX + 3;
						}
						else {
							aux->next->CoorY = aux->CoorY - 1;
							aux->next->p = aux->p + (2 * aux->next->CoorX) + 1 + (-2 * aux->next->CoorY);
						}aux = aux->next;
					}aux->next = NULL; aux = origen;
					printf("Coordenadas de la circunferencia\n");
					cout << "\n" << "k\t" << "(x,y)\t\t" << "pk\t" << "2x\t"<<"2y";
					int k = 0;
					while (aux != NULL) {
						if (aux->next) {

							cout << "\n" << k << "\t(" << aux->next->CoorX << "," << aux->next->CoorY << ")\t\t" << aux->p << "\t" << aux->next->CoorX * 2<<"\t"<< aux->next->CoorY*2;
							origen = origen->next;
							delete aux;
							aux = origen;
						}
						else {
							aux=aux->next;
						}
						k++;
					}
				}
				if (flag) {
					cout << endl;
					system("pause");
				}
			}
			}break;
			case '3': {
				/*2 * pow(ry, 2) * aux->next->CoorX = 2 * pow(ry, 2) * aux->CoorX + 2 * pow(ry, 2)*/
				/*2 * pow(rx, 2) * aux->next->CoorY = 2 * pow(rx, 2) * aux->CoorY + 2 * pow(rx, 2)*/
				aux = origen = new punto;
				float rx, ry;
				char rxChar[100], ryChar[100];
				printf("Algoritmo de Bresenham (Elipse)\nIngrese el 1er radio: ");
				cin >> rxChar;
				Validacion(rxChar);
				if (flag) {
					printf("Ingrese el 2do radio: ");
					cin >> ryChar;
					Validacion(ryChar);
					if (flag) {
						rx = atoi(rxChar);
						ry = atoi(ryChar);
						system("cls"); origen->p = pow(ry, 2) - pow(rx, 2) * ry + (pow(rx, 2) / 4);
						origen->CoorX = 0; origen->CoorY = ry; origen->sección = false;
						origen->prev = NULL;
						while (2 * pow(ry, 2) * aux->CoorX < 2 * pow(rx, 2) * aux->CoorY) {
							aux->next = new punto;
							aux->next->prev = aux;
							aux->next->CoorX = aux->CoorX + 1;
							if (aux->p < 0) {
								aux->next->CoorY = aux->CoorY;
								aux->next->p = aux->p + 2 * pow(ry, 2) * aux->next->CoorX + pow(ry, 2);
								//aux->next->p = aux->p + 2 * pow(ry, 2) * aux->CoorX + 2 * pow(ry, 2) + pow(ry, 2);
							}
							else if (aux->p >= 0) {
								aux->next->CoorY = aux->CoorY - 1;
								aux->next->p = aux->p + 2 * pow(ry, 2) * aux->next->CoorX - 2 * pow(rx, 2) * aux->next->CoorY + pow(ry, 2);
								//aux->next->p = aux->p + 2 * pow(ry, 2) * aux->CoorX + 2 * pow(ry, 2) - 2 * pow(rx, 2) * aux->CoorY + 2 * pow(rx, 2) + pow(ry, 2);
							}aux = aux->next;
							aux->sección = false;
						}
						aux->next = new punto;
						aux->next->prev = aux;
						aux->next->CoorX = aux->CoorX; aux->next->CoorY = aux->CoorY;
						aux = aux->next;
						aux->p = pow(ry, 2) * pow((aux->CoorX + 0.5), 2) + pow(rx, 2) * pow((aux->CoorY - 1), 2) - pow(rx, 2) * pow(ry, 2);
						aux->sección = true;
						while (aux->CoorY != 0) {
							aux->next = new punto;
							aux->next->prev = aux;
							aux->next->CoorY = aux->CoorY - 1;
							if (aux->p < 0) {
								aux->next->CoorX = aux->CoorX + 1;
								aux->next->p = aux->p + 2 * pow(ry, 2) * aux->next->CoorX - 2 * pow(rx, 2) * aux->next->CoorY + pow(rx, 2);
								//aux->next->p = aux->p + 2 * pow(ry, 2) * aux->CoorX + 2 * pow(ry, 2) - 2 * pow(rx, 2) * aux->CoorY + 2 * pow(rx, 2) + pow(rx, 2);
							}
							else if (aux->p >= 0) {
								aux->next->CoorX = aux->CoorX;
								aux->next->p = aux->p - 2 * pow(rx, 2) * aux->next->CoorY + pow(rx, 2);
								//aux->next->p = aux->p - 2 * pow(rx, 2) * aux->CoorY + 2 * pow(rx, 2) + pow(rx, 2);
							}aux = aux->next;
							aux->sección = true;
						}aux->next = NULL; aux = origen;
						printf("Coordenadas de la Elipse\n\n-Región 1-\n");
						cout << "\n" << "k\t" << "(x,y)" << "\t"<<"pk";
						int k = 0;
						while (aux->sección == false) {
							if (aux->next) {
								cout << "\n" << k << "\t(" << aux->next->CoorX << "," << aux->next->CoorY << ")\t"<< aux->p;

							}
							origen = origen->next;
							delete aux;
							k++;
							aux = origen;

						}
						k = 0;
						printf("\n-Región 2-\n");
						cout << "\n" << "k\t" << "(x,y)" << "\t"<<"pk";
						while (aux != NULL) {
							if (aux->next) {
								cout<<"\n"<<k<<"\t("<< aux->next->CoorX<<","<< aux->next->CoorY<<")\t"<< aux->p;


							}
							origen = origen->next;
							delete aux;
							aux = origen;
							k++;

						}
						system("pause");
					}
				}
			}

			}
			repetidor = 1;
			break;



			break;
		case 'm':
		case 'M':
			repetidor = 0;
			break;

		default:
			cout << "Porfavor elija una opcion valida" << endl;
			system("pause");
			system("cls");
			repetidor = 1;
			break;
		}
	} while (repetidor == 1 || repetidor == 2);
}

void SumaRestaDeMatrices() {
	char numerofilasChar[100] = "";
	char numerocolumnaChar[100] = "";
	cout << "Introduzca la cantidad de Filas y columnas de las matrices" << endl << "Filas: ";
	cin >> numerofilasChar;
	cout << "Columnas: ";
	cin >> numerocolumnaChar;

	Validacion(numerofilasChar);
	if (flag) {
		Validacion(numerocolumnaChar);
	}
	else {
		cout << "No se permiten letras" << endl;
	}

	if (flag) {
		numeroFilas = atoi(numerofilasChar);
		numeroColumnas = atoi(numerocolumnaChar);
		system("cls");

		ObtencionDeMatrices1(numeroFilas, numeroColumnas);

		ObtencionDeMatrices2(numeroFilas, numeroColumnas);
		if (flag) {
			cout << "MATRIZ 1:" << endl;
			ImpresionDeMatrices1(numeroFilas, numeroColumnas);
			cout << endl;

			cout << "MATRIZ 2:" << endl;
			ImpresionDeMatrices2(numeroFilas, numeroColumnas);
			cout << endl << endl;
		}
		else {
			cout << "Intenta de nuevo ya que se siguio las instrucciones" << endl;
		}
	}
}

void MultiplicacionDeMatrices(int a, int b, int c) { //numeroFilas, numeroColumnas1, numeroColumnas
	float aux = 0;
	float impresionAux = 0;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++) {
				aux = Estructura1[i].filas1[k] * Estructura2[k].filas2[j];
				impresionAux = impresionAux + aux;
			}
			EstructuraResultante[i].filasResultantes[j] = impresionAux;
			cout << "     " << EstructuraResultante[i].filasResultantes[j];
			cout << "\t";
			impresionAux = 0;
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void MultiplicacionDeMatrices2(int a, int b, int c) { //numeroFilas, numeroColumnas1, numeroColumnas
	float aux = 0;
	float impresionAux = 0;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < c; k++) {
				aux = Estructura2[i].filas2[k] * Estructura1[k].filas1[j];
				impresionAux = impresionAux + aux;
			}
			EstructuraResultante[i].filasResultantes[j] = impresionAux;
			impresionAux = 0;
		}
	}
}

void ObtencionDeMatrices1(int a, int b) {
	cout << "MATRIZ 1:" << endl;
	flag = true;
	int valorIngresado;
	char valorIngresadoChar[50] = "";
	for (int i = 0; i < a; i++) {
		if (flag) {

			for (int j = 0; j < b; j++) {
				if (flag) {

					cout << "introduzca el numero en la fila " << i + 1 << " columna " << j + 1 << ": ";
					cin >> valorIngresadoChar;

					Validacion(valorIngresadoChar);
					if (flag) {
						valorIngresado =atoi( valorIngresadoChar);
						Estructura1[i].filas1[j] = valorIngresado;
						/*cin >> Estructura1[i].filas1[j];*/
					}
				}
				else {
					break;
				}
			}
		}
		else {
			break;
		}
	}
	system("cls");
}

void ObtencionDeMatrices2(int a, int b) {
	cout << "MATRIZ 2:" << endl;
	char valorIngresadoChar[50] = "";
	for (int i = 0; i < a; i++) {
		if (flag) {
			for (int j = 0; j < b; j++) {
				if (flag) {
					cout << "introduzca el numero en la fila " << i + 1 << " columna " << j + 1 << ": ";
					cin >> valorIngresadoChar;
					Validacion(valorIngresadoChar);
					if (flag) {
						strcpy_s(valorIngresado, valorIngresadoChar);
						Estructura2[i].filas2[j] = ValidacionFracciones(valorIngresado);
						/*cin >> Estructura1[i].filas1[j];*/
					}
				}
				else {
					break;
				}
			}
		}
		else {
			break;
		}
	}
	system("cls");
}


void ImpresionDeMatrices1(int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout<<"     "<< Estructura1[i].filas1[j];
		}
		cout << endl;
	}
}

void ImpresionDeMatrices2(int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout<<"     "<< Estructura2[i].filas2[j];
		}
		cout << endl;
	}
}

void ObtencionDeMatricesTrasladadas(int a, int b, float c, float d, float e) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i == j) {
				Estructura1[i].filas1[j] = 1;
			}
			else {
				if (i < 3 && j == 3) {
					if (i == 0) {
						Estructura1[i].filas1[j] = c;
					}
					if (i == 1) {
						Estructura1[i].filas1[j] = d;
					}
					if (i == 2) {
						Estructura1[i].filas1[j] = e;
					}
				}
				else {
					Estructura1[i].filas1[j] = 0;
				}
			}
		}
	}
}

void ConvertirMatriz1EnMatriz2(int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			Estructura2[i].filas2[j] = Estructura1[i].filas1[j];
		}
	}
}

void ConvertirMatrizResultanteEnMatriz2(int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			Estructura2[i].filas2[j] = EstructuraResultante[i].filasResultantes[j];
		}
	}
}

void ObtencionDeMatricesRotadas(int a, int b, int c, char d) {
	if (d == 'x' || d == 'X') {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (i > 0 && i < 3 && j > 0 && j < 3) {
					if (i == j) {
						Estructura1[i].filas1[j] = cos(c * PI / 180);
					}
					else {
						if (i == 1 && j == 2) {
							Estructura1[i].filas1[j] = -sin(c * PI / 180);
						}
						if (i == 2 && j == 1) {
							Estructura1[i].filas1[j] = sin(c * PI / 180);
						}
					}
				}
				else {
					if (i == j) {
						Estructura1[i].filas1[j] = 1;
					}
					else {
						Estructura1[i].filas1[j] = 0;
					}
				}
			}
		}
	}
	if (d == 'y' || d == 'Y') { //Corregido***
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (i == j && i == 0 && j == 0) {
					Estructura1[i].filas1[j] = cos(c * PI / 180);
				}
				else {
					if (i == j && i == 2 && j == 2) {
						Estructura1[i].filas1[j] = cos(c * PI / 180);
					}
					else {
						if (i == j) {
							Estructura1[i].filas1[j] = 1;
						}
						else {
							if (i == 0 && j == 2) {
								Estructura1[i].filas1[j] = sin(c * PI / 180);
							}
							else {
								if (i == 2 && j == 0) {
									Estructura1[i].filas1[j] = -sin(c * PI / 180);
								}
								else {
									Estructura1[i].filas1[j] = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	if (d == 'z' || d == 'Z') {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (i < 2 && j < 2) {
					if (i == j) {
						Estructura1[i].filas1[j] = cos(c * PI / 180);
					}
					else {
						if (i == 0 && j == 1) {
							Estructura1[i].filas1[j] = -sin(c * PI / 180);
						}
						if (i == 1 && j == 0) {
							Estructura1[i].filas1[j] = sin(c * PI / 180);
						}
					}

				}
				else {
					if (i == j) {
						Estructura1[i].filas1[j] = 1;
					}
					else {
						Estructura1[i].filas1[j] = 0;
					}
				}
			}
		}
	}
}

void ObtencionDeMatricesEscaladas(int a, int b, float c, float d, float e) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i == j) {
				if (i == 0) {
					Estructura1[i].filas1[j] = c;
				}
				else {
					if (i == 1) {
						Estructura1[i].filas1[j] = d;
					}
					else {
						if (i == 2) {
							Estructura1[i].filas1[j] = e;
						}
						else {
							Estructura1[i].filas1[j] = 1;
						}
					}
				}
			}
			else {
				Estructura1[i].filas1[j] = 0;
			}
		}
	}

}

float ValidacionFracciones(char x[]) {
	float resultado;
	string xStr(x);
	string antesFraccion;
	string postFraccion;
	int largo = 0;
	int varQueCuenta = 0;
	int posSimFrac = 0;
	float antesFracFloat = 0;
	float postFracFloat = 0;
	bool simboloFraccion = false;
	bool comprobante = true;
	largo = strlen(x);
	for (int i = 0; i <= largo; i++) {
		if (x[i] == '/') {
			comprobante = false;
		}
		if (i == largo && comprobante == true) {
			resultado = atof(x);
			return resultado;
		}
	}
	for (int i = 0; i < largo; i++) {
		if (x[i] >= '0' && x[i] <= '9' || x[i] == '.' || x[i] == '-' || x[i] == '/') {
			if (x[i] == '/' && simboloFraccion == false) {
				antesFraccion = xStr.substr(0, i);
				antesFracFloat = strtof(antesFraccion.c_str(), nullptr);
				posSimFrac = i + 1;
			}
		}
	}
	postFraccion = xStr.substr(posSimFrac, (largo - posSimFrac));
	postFracFloat = strtof(postFraccion.c_str(), nullptr);
	resultado = antesFracFloat / postFracFloat;
	return resultado;
}