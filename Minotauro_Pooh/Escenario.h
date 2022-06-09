#pragma once
#include "Obstaculo.h"
#include "Minotauro.h"
#include "vector"

using namespace std;


class Escenario {
private:
	//a qui se evidencia la composicion 
	// del persojnaje y el encenario
	Minotauro* Tauro;
	//bloques para el mapa
	vector<Objeto*>objetos;
	//valida si colisiono con pooh
	bool EncontroPooh;
public:

	Escenario() {
		//minotauro
		Tauro = new Minotauro();
		//bool si encontro con poh
		EncontroPooh = false;
		//POOH
		objetos.push_back(new Objeto(91,181,281-91,361-181));
		//ARBOOL
		objetos.push_back(new Objeto(127,381,321-127,615-381));
		//ARBOL2
		objetos.push_back(new Objeto(691,401,971-691,700-401));
		//CASA
		objetos.push_back(new Objeto(441,261,571-441,391-261));
	}
	~Escenario() {
		delete Tauro;
	}
	//contiene los movimientos de las entidades
	void Mover(Graphics^ g) {
		Tauro->Mover(g);
	}
	//dibuja los elemtnos del mapa
	void Dibujar(Graphics^ g) {
		for (int i = 0; i < objetos.size();i++)
			objetos[i]->Dibujar(g);
		
		Tauro->Dibujar(g);
		
	}
	//muestra los mensajes segun la colision con los
	//objetos
	void ColisionandMensajes(Graphics^ g) {
		int puntoControl = g->VisibleClipBounds.Width / 2;  //referencia para que se muestre uno u no panel
		
		for (int i = 0; i < objetos.size();i++) {
			
			//si encontro a pooh 
			if (Tauro->Area().IntersectsWith(objetos[0]->Area())) {
				Font^ letra = gcnew Font("Arial", 10.5);
				g->FillRectangle(Brushes::Green, puntoControl - 100, 50, 400, 40);
				//el texto		
				g->DrawString("Lo lograste, encontraste a Pooh", letra, Brushes::Black, puntoControl - 90, 52);
				EncontroPooh = true;
			}
			//si va a la casa
			if (Tauro->Area().IntersectsWith(objetos[3]->Area())) {
				Font^ letra = gcnew Font("Arial", 10.5);
				g->FillRectangle(Brushes::Red, puntoControl - 100, 50, 200, 40);
				//el texto		
				g->DrawString("Aquí no está Pooh, busca en otro lugar", letra, Brushes::Black, puntoControl - 90, 52);

			}

			if (Tauro->Area().IntersectsWith(objetos[2]->Area())) {
				Font^ letra = gcnew Font("Arial", 10.5);
				g->FillRectangle(Brushes::Red, puntoControl - 100, 50, 200, 40);
				//el texto		
				g->DrawString("Aquí no está Pooh, busca en otro lugar", letra, Brushes::Black, puntoControl - 90, 52);

			}


		}

	
	}

	Minotauro* GetTauro() {
		return Tauro;
	}
	bool AtrapoPooh() {
		return EncontroPooh;
	}

};