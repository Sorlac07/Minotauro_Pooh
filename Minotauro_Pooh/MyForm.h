#pragma once

#include "Escenario.h"

namespace MinotauroPooh {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = this->CreateGraphics();
			escenario = new Escenario();
			fondo = gcnew Bitmap("img/ImagenFondo.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Escenario* escenario;
		Graphics^ g;
		Bitmap^ fondo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1047, 727);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		//movimientos direccionales del tauro 
		if (e->KeyCode == Keys::Up) {
			escenario->GetTauro()->SetDY(-10);
			escenario->GetTauro()->SetAccion(MovArriba);
		}
		if (e->KeyCode == Keys::Down) {
			escenario->GetTauro()->SetDY(10);
			escenario->GetTauro()->SetAccion(MovAbajo);
		}
		if (e->KeyCode == Keys::Right) {
			escenario->GetTauro()->SetDX(10);
			escenario->GetTauro()->SetAccion(MovDerecha);
		}
		if (e->KeyCode == Keys::Left) {
			escenario->GetTauro()->SetDX(-10);
			escenario->GetTauro()->SetAccion(MovIzquierda);
		}
		if (e->KeyCode == Keys::Space) {
			//SALTAR-> DISMINUIR SOLO EL Y
			escenario->GetTauro()->SetY(escenario->GetTauro()->GetY()-50);
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		escenario->GetTauro()->SetDX(0);
		escenario->GetTauro()->SetDY(0);
		std::cout<<"x"<<escenario->GetTauro()->GetX()<<endl;
		std::cout<<"y"<<escenario->GetTauro()->GetY()<<endl;

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		escenario->Mover(bf->Graphics);
		bf->Graphics->DrawImage(fondo, Rectangle(0, 0, fondo->Width * 1.8, fondo->Height * 1.8), Rectangle(0, 0, fondo->Width, fondo->Height), GraphicsUnit::Pixel);
		escenario->Dibujar(bf->Graphics);
		escenario->ColisionandMensajes(bf->Graphics);

		bf->Render(g);
		delete bf, bfc;
		if (escenario->AtrapoPooh()) {
			this->timer1->Enabled = false;
		}


	}
	};
}
