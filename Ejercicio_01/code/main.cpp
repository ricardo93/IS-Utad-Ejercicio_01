#pragma warning (disable: 4820)
#pragma warning (disable: 4668)
#pragma warning (disable: 4710)

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define ESC 27
#define WIDTH 70



int main()
{
	//Posicion del personaje.
	int player_x = 10;

	//Posiciones de los disparos.
	int disparo_izq = -1;
	int disparo_dcha = -1;

	//Si ya hay una bala creada para cada direccion.
	bool disparo_izq_creado = false;
	bool disparo_dcha_creado = false;

	//Tecla pulsada.
	char tecla = '\0';

	//Tabulado superior.
	printf_s("\n\n\n\n\n");

	while(tecla != ESC)
	{
		//Si hemos pulsado una tecla.
		if (_kbhit())
		{
			//Tecla que se ha pulsado.
			tecla = static_cast<char>(_getch());

			//Si nos movemos a la izq.
			if (tecla == 'o' && player_x > 0)
			{
				player_x--;
			}

			//Si nos movemos a la dcha.
			else if (tecla == 'p' && player_x < WIDTH -1)
			{
				player_x++;
			}

			//Si disparamos a la izq y no hay otra.
			else if (tecla == 'q' && !disparo_izq_creado)
			{
				disparo_izq = player_x - 1;
				disparo_izq_creado = true;
			}

			//Si disparamos a la dcha y no hay otra.
			else if (tecla == 'w' && !disparo_dcha_creado)
			{
				disparo_dcha = player_x - 1;
				disparo_dcha_creado = true;
			}
		}





		//Actualizamos estado de las balas.

		//Si la bala izq esta creada.
		if (disparo_izq_creado)
		{
			if (disparo_izq < 0)
			{
				disparo_izq_creado = false;
			}
			else
			{
				disparo_izq--;
			}
		}

		//Si la bala dcha esta creada.
		if (disparo_dcha_creado)
		{
			if (disparo_dcha > WIDTH)
			{
				disparo_dcha_creado = false;
			}
			else
			{
				disparo_dcha++;
			}
		}





		//Retornamos el cursor.
		printf_s("\r");

		//Pintamos escenario.
		for (int i = 0; i < WIDTH; i++)
		{
			//Si en la posicion a pintar esta el player.
			if (i == player_x)
			{
				printf_s("X");
			}
			//Si tenemos que pintar la bala izq.
			else if (i == disparo_izq)
			{
				printf_s("<");
			}
			//Si tenemos que pintar la bala dcha.
			else if (i == disparo_dcha)
			{
				printf_s(">");
			}

			else
			{
				printf_s("_");
			}
		}

		//Espera de frame rate.
		Sleep(60);
	}

	return 0;
}