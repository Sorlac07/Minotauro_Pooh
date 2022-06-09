#pragma once
#include <iostream>

using namespace System::Drawing;

enum SpriteAccion {
	MovAbajo,
	MovIzquierda,
	MovDerecha,
	MovArriba
};



class Minotauro {
private:
	int x, y;
	int dx, dy;
	int Alto, Ancho;
	char* imagen;
	int IndX;
	SpriteAccion Accion;

public:

	Minotauro() {
		imagen = "img/tauro.png";
		x = y = 500 + rand() % 100;
		dx = dy = 0;
		Accion = MovDerecha;
		Alto = 0;
		Ancho = 0;
		IndX = 0;
	}
	~Minotauro() {}

	void Mover(Graphics^ g) {
		//movimiento 
		// hasta los limites de la derecha e ixzquierda
		if (x + dx >= 0 && x + Ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		// hasta los limites arriba y abajo 
		if (y + dy >= 0 && y + Alto + dy < g->VisibleClipBounds.Height)
			y += dy;

	}
	void Dibujar(Graphics^ g) {

		//IMAGEN 
		Bitmap^ img = gcnew Bitmap("img/tauro.png");

		//DIMENTCIONES DE LA IMAGEN
		Alto = img->Height / 4;
		Ancho = img->Width / 8;
		// MONDE DE LA IMAGEN
		Rectangle corte = Rectangle(IndX * Ancho, Accion * Alto, Ancho, Alto);
		// ZOON DE LA IMAGEN
		Rectangle Area(x, y, Ancho, Alto);
		//DIBUJAR IMAGEN EN EL CANVAS
		g->DrawImage(img, Area, corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area);

		//CAMBAIR IMAGEN DE MOV 
		if (dx != 0 || dy != 0)
		{
			IndX = (IndX + 1) % 8;
		}
		delete img;

	}
	//metodos de acceso
	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}	
	void SetX(int value)
	{
		x = value;
	}
	void SetY(int value)
	{
		y = value;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void SetAccion(SpriteAccion value)
	{
		Accion = value;
	}
	Rectangle Area() {
		return Rectangle(x,y,Ancho,Alto);
	}
};