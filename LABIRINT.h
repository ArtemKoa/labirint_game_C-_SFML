#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

#ifndef LABIRINT_H

#define LABIRINT_H
#define Goffset_x 444	//Глобальный сдвиг окна
#define Goffset_y 150

#define Size_x 7 //Кол-во ячеек по x в окне
#define Size_y 5 //Кол-во ячеек по y в окне

#define width 150 //Ширина и высота комнаты
#define height 150

#define window_width 1920 //Ширина и высота окна
#define window_height 1080

struct COORD //Координаты первой ячейки
{
	int x;
	int y;
};
class LABIRINT
{
public:
	int N = 0;
	int M = 0;
	int** arr = 0;
	int** wall_gor = 0;
	int** wall_vert = 0;
	COORD CreateLab(int N, int M);

	void Clear();
	LABIRINT();
	~LABIRINT();
};
#endif LABIRINT_H;