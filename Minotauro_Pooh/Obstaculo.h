#pragma once

using namespace System::Drawing;

class Objeto {
private:
	int x, y;
	int Alto, Ancho;
public:
	//EMENTOS PARA LOS BLOQUES
	Objeto(int px,int py,int ancho,int alto) {
		x = px;
		y = py;
		Ancho = ancho;
		Alto = alto;
	}
	~Objeto() {

	}
	void Dibujar(Graphics^ g) {
		Pen^ pen = gcnew  Pen(Color::Red);
		g->DrawRectangle(pen,Area());
		delete pen;
	}
	Rectangle Area() {
		//AREA DEL BLOQUE
		return Rectangle(x,y,Ancho,Alto);
	}
};