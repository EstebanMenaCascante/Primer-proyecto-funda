
#include "Puente.h"



float vA, vB, vC, vD, sd, x0, x1, mcd;

void menu()
{
	// Se le solicita al usuario que ingrese los n�meros
	cout << "Ingrese el primer n�mero\n";
	cin >> vA; //v(X) significa variable(X)
	cout << "Ingrese el segundo n�mero\n";
	cin >> vB;
	cout << "Ingrese el tercer n�mero\n";
	cin >> vC;

	int opcion;
	bool salir = true;
	do {
		system("cls");
		cout << "Digite la opcion a realizar\n";
		cout << "Digite la opcion 1 para ordenar asendentemente los numeros\n";
		cout << "Digite la opcion 2 para calcular el MCM de los numeros\n";
		cout << "Digite la opcion 3 para determinar si dichos numeros cumplen las longitudes de un triangulo\n";
		cout << "Digite la opcion 4 para determinar si los numeros corresponden al teorema de pitagoras\n";
		cout << "Digite la opcion 5 para salir\n";
		cin >> opcion;
		switch (opcion) {
		case 1:
			acomoasend();
			system("pause");
			break;

		case 2:
			mcm_numeros();
			system("pause");
			break;

		case 3:
			esTriangulo();
			system("pause");
			break;
		case 4:
			teoremPitagoras();
			system("pause");
			break;

		case 5:
			cout << "Gracias por usar este programa :)\n\n\n";
			salir = false;

			break;

		default:
			cout << "Opcion invalida intente de nuevo" << endl;
			system("pause");
			break;
		}

	} while (salir == true);
}

int ecuacuadratica()
{
	vD = (vB*vB) - 4 * vA * vC;

	// Se verifica si la ecuaci�n tiene soluciones reales
	if (vD > 0)
	{
		// Se calculan las soluciones de la ecuaci�n cuadr�tica
		x0 = (-vB + sqrt(vD)) / (2 * vA);
		x1 = (-vB - sqrt(vD)) / (2 * vA);

		// Se muestran las soluciones
		cout << "\nLa ecuaci�n tiene dos soluciones reales:" << "\n";
		cout << "x0 = " << x0 << "\n";
		cout << "x1 = " << x1 << "\n";
	}
	else if (vD == 0)
	{
		// Se calcula la soluci�n �nica de la ecuaci�n cuadr�tica
		x0 = -vB / (2 * vA);

		// Se muestra la soluci�n
		cout << "\nLa ecuaci�n tiene una soluci�n real:" << "\n";
		cout << "x0 = " << x0 << "\n";
	}
	else
	{
		// Se muestra que la ecuaci�n no tiene soluciones reales
		cout << "\nLa ecuaci�n no tiene soluciones reales." << "\n";
	}

	return 0;
}

int acomoasend()
{
	// Ordenar los n�meros utilizando un bucle for y if anidados
	for (int i = 0; i < 2; i++) { /*El bucle for y los bloques if anidados se utilizan 
		en este fragmento de c�digo para ordenar tres n�meros de manera ascendente. 
		El bucle se repite dos veces y en cada iteraci�n, los n�meros adyacentes se comparan
		y se intercambian si el n�mero de la izquierda es mayor que el de la derecha. 
		Al final del segundo bucle for, los n�meros est�n ordenados de manera ascendente.*/
		if (vA > vB) {
			float temp = vA; /*Float temp se utiliza para intercambiar valores entre 
			vA, vB y vC durante el proceso de ordenamiento.*/
			vA = vB;
			vB = temp;
		}
		if (vB > vC) {
			float temp = vB;
			vB = vC;
			vC = temp;
		}
	}

	// Imprimir los n�meros ordenados
	cout << "\nLos n�meros ordenados son: " << vA << ", " << vB << ", " << vC << "\n";
		
	return 0;
}

int mcm_numeros()
{
	int a = vA; /* se hace el cambio de decimal a entero en caso de que hallan decimales*/
	int b = vB;
	int c = vC;

	/* Se verifica que los n�meros sean enteros positivos.
	Si alguno de los n�meros es cero o negativo, se muestra 
	un mensaje de error y se devuelve -1.*/
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << "\nError: los n�meros deben ser enteros positivos." << "\n";
		return -1;
	}

	/* Se encuentra el n�mero m�s grande de los tres ingresados
	por el usuario, y se almacena en la variable max.*/
	int max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}

	/* Se busca el M.C.M. multiplicando el n�mero
	m�s grande por 1, 2, 3, etc., hasta encontrar
	un n�mero que sea divisible por a, b y c.*/
	int mcm = max;
	while (mcm % a != 0 || mcm % b != 0 || mcm % c != 0) {
		mcm += max;
	}

	// Imprimir el resultado
	cout << "\nEl m.c.m. de " << a << ", " << b << " y " << c << " es " << mcm << "\n";

	return 0;
}

bool esTriangulo()
{
		// Verificar que los n�meros son enteros positivos
		if (vA <= 0 || vB <= 0 || vC <= 0) {
			cout << "\nError: los n�meros deben ser enteros positivos." << "\n";
			return false;
		}

		// Ordenar los n�meros de menor a mayor
		for (int i = 0; i < 2; i++) {
			if (vA > vB) {
				float temp = vA;
				vA = vB;
				vB = temp;
			}
			if (vB > vC) {
				float temp = vB;
				vB = vC;
				vC = temp;
			}
		}

		// Verificar la condici�n de desigualdad triangular
		if (vA + vB > vC) {
			cout << "\nLos n�meros ingresados corresponden a las longitudes de un tri�ngulo." << "\n";
			return true;
		}
		else {
			cout << "\nLos n�meros ingresados no corresponden a las longitudes de un tri�ngulo." << "\n";
			return false;
		}
	

	return false;
}

int teoremPitagoras() 
{

	int a = vA; /* se hace el cambio de decimal a entero en caso de que hallan decimales*/
	int b = vB;
	int c = vC;
	int f = a + b; //variable para determinar el teorema
	int ct, h;

	ct = (a * a) + (b * b); //suma de los catetos elevados al cuadrado
	h = c * c;
	if (ct = h) /*Si la suma de los catetos elevados al cuadrado es igual a el 
		resultado de la hipotenusa elevada al cuadrado, entonces si cumple con el teorema de Pitagoras*/
	{
		cout << "\n Los n�meros si cumplen el teorema de Pit�goras.\n";
	}

	else /*Si no se cumple la condicion anterior entonces se imprime en pantalla 
		que los numeros ingresados por el usuario no cumplen el teorema de Pitagoras*/
	{
		cout << "Los n�meros no cumplen el teorema de Pit�goras.\n";
	}
	
	return 0;
}
