#pragma once
#include "Controlador.h"
#include "VistaPelicula.h"

namespace SebaSteam
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		// 1. Recibimos el controlador que ya carg� los datos desde Inicio.h
		MenuPrincipal(ControladoraPrincipal^ driverHeredado)
		{
			InitializeComponent();
			driver = driverHeredado;
			RegistrarSonidoBotones(this);
			this->DoubleBuffered = true;
		}

	protected:
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ TopVButton;
	private: System::Windows::Forms::Button^ MejorCalifButton;
	private: System::Windows::Forms::Button^ FiltrarBu;
	private: ControladoraPrincipal^ driver; // Puntero central

	private: System::Windows::Forms::Button^ R_1;
	private: System::Windows::Forms::Button^ R_2;
	private: System::Windows::Forms::Button^ L_2;
	private: System::Windows::Forms::Button^ L_1;
	private: System::Windows::Forms::Button^ L_3;
	private: System::Windows::Forms::Button^ R__3;

	private: System::Windows::Forms::Label^ TxtFila1;
	private: System::Windows::Forms::Panel^ F1_1;
	private: System::Windows::Forms::Panel^ F1_2;
	private: System::Windows::Forms::Panel^ F1_3;
	private: System::Windows::Forms::Panel^ F1_4;
	private: System::Windows::Forms::Panel^ F1_5;
	private: System::Windows::Forms::Panel^ F1_6;
	private: System::Windows::Forms::Button^ Boton_F1_1;
	private: System::Windows::Forms::Button^ Boton_F1_2;
	private: System::Windows::Forms::Button^ Boton_F1_3;
	private: System::Windows::Forms::Button^ Boton_F1_4;
	private: System::Windows::Forms::Button^ Boton_F1_5;
	private: System::Windows::Forms::Button^ Boton_F1_6;

	private: System::Windows::Forms::Panel^ F2_6;
	private: System::Windows::Forms::Panel^ F2_5;
	private: System::Windows::Forms::Panel^ F2_4;
	private: System::Windows::Forms::Panel^ F2_3;
	private: System::Windows::Forms::Panel^ F2_2;
	private: System::Windows::Forms::Panel^ F2_1;


	private: System::Windows::Forms::Panel^ F3_6;
	private: System::Windows::Forms::Panel^ F3_5;
	private: System::Windows::Forms::Panel^ F3_4;
	private: System::Windows::Forms::Panel^ F3_3;
	private: System::Windows::Forms::Panel^ F3_2;
	private: System::Windows::Forms::Panel^ F3_1;
	private: System::Windows::Forms::Button^ B_F3_6;
	private: System::Windows::Forms::Button^ B_F3_5;
	private: System::Windows::Forms::Button^ B_F3_4;
	private: System::Windows::Forms::Button^ B_F3_3;
	private: System::Windows::Forms::Button^ B_F3_2;
	private: System::Windows::Forms::Button^ B_F1_1;

	private: System::Windows::Forms::Label^ TxtF2;
	private: System::Windows::Forms::Label^ TxtF3;
	private: System::Windows::Forms::Button^ btnCerrarCatalogo;
	private: System::ComponentModel::Container^ components;

	private:
		System::Void ReproducirSonidoClick(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				SoundPlayer^ reproductor = gcnew SoundPlayer("Sonidos/click.wav");
				reproductor->Play();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Falla de sonido: " + ex->Message, "Depuraci�n");
			}
		}

		// Cierra el catalogo y regresa a la pantalla de Seleccion de Perfil
		// (SeleccionPerfil::AbrirMenuPrincipal vuelve a mostrarse cuando esta
		// ventana se cierra, ya que se abrio con ShowDialog()).
		System::Void btnCerrarCatalogo_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		void RegistrarSonidoBotones(System::Windows::Forms::Control^ contenedor)
		{
			for each (System::Windows::Forms::Control ^ control in contenedor->Controls)
			{
				if (dynamic_cast<System::Windows::Forms::Button^>(control) != nullptr)
				{
					control->Click += gcnew System::EventHandler(this, &MenuPrincipal::ReproducirSonidoClick);
				}
				if (control->HasChildren)
				{
					RegistrarSonidoBotones(control);
				}
			}
		}

#pragma region
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->TopVButton = (gcnew System::Windows::Forms::Button());
			this->MejorCalifButton = (gcnew System::Windows::Forms::Button());
			this->FiltrarBu = (gcnew System::Windows::Forms::Button());
			this->R_1 = (gcnew System::Windows::Forms::Button());
			this->R_2 = (gcnew System::Windows::Forms::Button());
			this->L_2 = (gcnew System::Windows::Forms::Button());
			this->L_1 = (gcnew System::Windows::Forms::Button());
			this->L_3 = (gcnew System::Windows::Forms::Button());
			this->R__3 = (gcnew System::Windows::Forms::Button());
			this->TxtFila1 = (gcnew System::Windows::Forms::Label());
			this->F1_1 = (gcnew System::Windows::Forms::Panel());
			this->Boton_F1_1 = (gcnew System::Windows::Forms::Button());
			this->F1_2 = (gcnew System::Windows::Forms::Panel());
			this->Boton_F1_2 = (gcnew System::Windows::Forms::Button());
			this->F1_3 = (gcnew System::Windows::Forms::Panel());
			this->Boton_F1_3 = (gcnew System::Windows::Forms::Button());
			this->F1_4 = (gcnew System::Windows::Forms::Panel());
			this->Boton_F1_4 = (gcnew System::Windows::Forms::Button());
			this->F1_5 = (gcnew System::Windows::Forms::Panel());
			this->Boton_F1_5 = (gcnew System::Windows::Forms::Button());
			this->F2_6 = (gcnew System::Windows::Forms::Panel());
			this->F2_5 = (gcnew System::Windows::Forms::Panel());
			this->F2_4 = (gcnew System::Windows::Forms::Panel());
			this->F2_3 = (gcnew System::Windows::Forms::Panel());
			this->F2_2 = (gcnew System::Windows::Forms::Panel());
			this->F2_1 = (gcnew System::Windows::Forms::Panel());
			this->F3_6 = (gcnew System::Windows::Forms::Panel());
			this->B_F3_6 = (gcnew System::Windows::Forms::Button());
			this->F3_4 = (gcnew System::Windows::Forms::Panel());
			this->B_F3_4 = (gcnew System::Windows::Forms::Button());
			this->F3_3 = (gcnew System::Windows::Forms::Panel());
			this->B_F3_3 = (gcnew System::Windows::Forms::Button());
			this->F3_2 = (gcnew System::Windows::Forms::Panel());
			this->B_F3_2 = (gcnew System::Windows::Forms::Button());
			this->F3_1 = (gcnew System::Windows::Forms::Panel());
			this->B_F1_1 = (gcnew System::Windows::Forms::Button());
			this->TxtF2 = (gcnew System::Windows::Forms::Label());
			this->TxtF3 = (gcnew System::Windows::Forms::Label());
			this->Boton_F1_6 = (gcnew System::Windows::Forms::Button());
			this->F1_6 = (gcnew System::Windows::Forms::Panel());
			this->B_F3_5 = (gcnew System::Windows::Forms::Button());
			this->F3_5 = (gcnew System::Windows::Forms::Panel());
			this->F1_1->SuspendLayout();
			this->F1_2->SuspendLayout();
			this->F1_3->SuspendLayout();
			this->F1_4->SuspendLayout();
			this->F1_5->SuspendLayout();
			this->F3_6->SuspendLayout();
			this->F3_4->SuspendLayout();
			this->F3_3->SuspendLayout();
			this->F3_2->SuspendLayout();
			this->F3_1->SuspendLayout();
			this->F1_6->SuspendLayout();
			this->F3_5->SuspendLayout();
			this->SuspendLayout();
			// 
			// TopVButton
			// 
			this->TopVButton->BackColor = System::Drawing::Color::Transparent;
			this->TopVButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->TopVButton->FlatAppearance->BorderSize = 0;
			this->TopVButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TopVButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TopVButton->Location = System::Drawing::Point(720, 12);
			this->TopVButton->Name = L"TopVButton";
			this->TopVButton->Size = System::Drawing::Size(185, 43);
			this->TopVButton->TabIndex = 0;
			this->TopVButton->Text = L"Vistos recientemente";
			this->TopVButton->UseVisualStyleBackColor = false;
			// 
			// MejorCalifButton
			// 
			this->MejorCalifButton->BackColor = System::Drawing::Color::Transparent;
			this->MejorCalifButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->MejorCalifButton->FlatAppearance->BorderSize = 0;
			this->MejorCalifButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MejorCalifButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MejorCalifButton->Location = System::Drawing::Point(453, 16);
			this->MejorCalifButton->Name = L"MejorCalifButton";
			this->MejorCalifButton->Size = System::Drawing::Size(192, 39);
			this->MejorCalifButton->TabIndex = 1;
			this->MejorCalifButton->Text = L"MEJOR CALIFICADOS";
			this->MejorCalifButton->UseVisualStyleBackColor = false;
			// 
			// FiltrarBu
			// 
			this->FiltrarBu->BackColor = System::Drawing::Color::Transparent;
			this->FiltrarBu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->FiltrarBu->FlatAppearance->BorderSize = 0;
			this->FiltrarBu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FiltrarBu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FiltrarBu->Location = System::Drawing::Point(993, 12);
			this->FiltrarBu->Name = L"FiltrarBu";
			this->FiltrarBu->Size = System::Drawing::Size(186, 56);
			this->FiltrarBu->TabIndex = 2;
			this->FiltrarBu->Text = L"A - Z";
			this->FiltrarBu->UseVisualStyleBackColor = false;
			// 
			// R_1
			// 
			this->R_1->BackColor = System::Drawing::Color::Transparent;
			this->R_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R_1.BackgroundImage")));
			this->R_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->R_1->FlatAppearance->BorderSize = 0;
			this->R_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->R_1->ForeColor = System::Drawing::Color::Transparent;
			this->R_1->Location = System::Drawing::Point(1241, 183);
			this->R_1->Name = L"R_1";
			this->R_1->Size = System::Drawing::Size(47, 71);
			this->R_1->TabIndex = 6;
			this->R_1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->R_1->UseVisualStyleBackColor = false;
			this->R_1->Click += gcnew System::EventHandler(this, &MenuPrincipal::R_1_Click);
			// 
			// R_2
			// 
			this->R_2->BackColor = System::Drawing::Color::Transparent;
			this->R_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R_2.BackgroundImage")));
			this->R_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->R_2->FlatAppearance->BorderSize = 0;
			this->R_2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->R_2->ForeColor = System::Drawing::Color::Transparent;
			this->R_2->Location = System::Drawing::Point(1241, 420);
			this->R_2->Name = L"R_2";
			this->R_2->Size = System::Drawing::Size(52, 71);
			this->R_2->TabIndex = 7;
			this->R_2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->R_2->UseVisualStyleBackColor = false;
			this->R_2->Click += gcnew System::EventHandler(this, &MenuPrincipal::R_2_Click);
			// 
			// L_2
			// 
			this->L_2->BackColor = System::Drawing::Color::Transparent;
			this->L_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"L_2.BackgroundImage")));
			this->L_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->L_2->FlatAppearance->BorderSize = 0;
			this->L_2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->L_2->ForeColor = System::Drawing::Color::Transparent;
			this->L_2->Location = System::Drawing::Point(9, 420);
			this->L_2->Name = L"L_2";
			this->L_2->Size = System::Drawing::Size(55, 71);
			this->L_2->TabIndex = 10;
			this->L_2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->L_2->UseVisualStyleBackColor = false;
			this->L_2->Click += gcnew System::EventHandler(this, &MenuPrincipal::L_2_Click);
			// 
			// L_1
			// 
			this->L_1->BackColor = System::Drawing::Color::Transparent;
			this->L_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"L_1.BackgroundImage")));
			this->L_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->L_1->FlatAppearance->BorderSize = 0;
			this->L_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->L_1->ForeColor = System::Drawing::Color::Transparent;
			this->L_1->Location = System::Drawing::Point(12, 183);
			this->L_1->Name = L"L_1";
			this->L_1->Size = System::Drawing::Size(52, 83);
			this->L_1->TabIndex = 11;
			this->L_1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->L_1->UseVisualStyleBackColor = false;
			this->L_1->Click += gcnew System::EventHandler(this, &MenuPrincipal::L_1_Click);
			// 
			// L_3
			// 
			this->L_3->BackColor = System::Drawing::Color::Transparent;
			this->L_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"L_3.BackgroundImage")));
			this->L_3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->L_3->FlatAppearance->BorderSize = 0;
			this->L_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->L_3->ForeColor = System::Drawing::Color::Transparent;
			this->L_3->Location = System::Drawing::Point(9, 661);
			this->L_3->Name = L"L_3";
			this->L_3->Size = System::Drawing::Size(55, 77);
			this->L_3->TabIndex = 13;
			this->L_3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->L_3->UseVisualStyleBackColor = false;
			this->L_3->Click += gcnew System::EventHandler(this, &MenuPrincipal::L_3_Click);
			// 
			// R__3
			// 
			this->R__3->BackColor = System::Drawing::Color::Transparent;
			this->R__3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R__3.BackgroundImage")));
			this->R__3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->R__3->FlatAppearance->BorderSize = 0;
			this->R__3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->R__3->ForeColor = System::Drawing::Color::Transparent;
			this->R__3->Location = System::Drawing::Point(1241, 661);
			this->R__3->Name = L"R__3";
			this->R__3->Size = System::Drawing::Size(47, 77);
			this->R__3->TabIndex = 12;
			this->R__3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->R__3->UseVisualStyleBackColor = false;
			this->R__3->Click += gcnew System::EventHandler(this, &MenuPrincipal::R__3_Click);
			// 
			// TxtFila1
			// 
			this->TxtFila1->AutoSize = true;
			this->TxtFila1->BackColor = System::Drawing::Color::Transparent;
			this->TxtFila1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtFila1->ForeColor = System::Drawing::Color::Transparent;
			this->TxtFila1->Location = System::Drawing::Point(7, 113);
			this->TxtFila1->Name = L"TxtFila1";
			this->TxtFila1->Size = System::Drawing::Size(270, 25);
			this->TxtFila1->TabIndex = 14;
			this->TxtFila1->Text = L"Recientemente agregados:";
			// 
			// F1_1
			// 
			this->F1_1->Controls->Add(this->Boton_F1_1);
			this->F1_1->Location = System::Drawing::Point(79, 141);
			this->F1_1->Name = L"F1_1";
			this->F1_1->Size = System::Drawing::Size(170, 145);
			this->F1_1->TabIndex = 15;
			// 
			// Boton_F1_1
			// 
			this->Boton_F1_1->BackColor = System::Drawing::Color::Transparent;
			this->Boton_F1_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Boton_F1_1->FlatAppearance->BorderSize = 0;
			this->Boton_F1_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_F1_1->ForeColor = System::Drawing::Color::Transparent;
			this->Boton_F1_1->Location = System::Drawing::Point(0, 0);
			this->Boton_F1_1->Name = L"Boton_F1_1";
			this->Boton_F1_1->Size = System::Drawing::Size(170, 145);
			this->Boton_F1_1->TabIndex = 5;
			this->Boton_F1_1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Boton_F1_1->UseVisualStyleBackColor = false;
			// 
			// F1_2
			// 
			this->F1_2->Controls->Add(this->Boton_F1_2);
			this->F1_2->Location = System::Drawing::Point(274, 141);
			this->F1_2->Name = L"F1_2";
			this->F1_2->Size = System::Drawing::Size(179, 145);
			this->F1_2->TabIndex = 16;
			// 
			// Boton_F1_2
			// 
			this->Boton_F1_2->BackColor = System::Drawing::Color::Transparent;
			this->Boton_F1_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Boton_F1_2->FlatAppearance->BorderSize = 0;
			this->Boton_F1_2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_F1_2->ForeColor = System::Drawing::Color::Transparent;
			this->Boton_F1_2->Location = System::Drawing::Point(-3, -3);
			this->Boton_F1_2->Name = L"Boton_F1_2";
			this->Boton_F1_2->Size = System::Drawing::Size(182, 148);
			this->Boton_F1_2->TabIndex = 6;
			this->Boton_F1_2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Boton_F1_2->UseVisualStyleBackColor = false;
			// 
			// F1_3
			// 
			this->F1_3->Controls->Add(this->Boton_F1_3);
			this->F1_3->Location = System::Drawing::Point(475, 141);
			this->F1_3->Name = L"F1_3";
			this->F1_3->Size = System::Drawing::Size(170, 145);
			this->F1_3->TabIndex = 17;
			// 
			// Boton_F1_3
			// 
			this->Boton_F1_3->BackColor = System::Drawing::Color::Transparent;
			this->Boton_F1_3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Boton_F1_3->FlatAppearance->BorderSize = 0;
			this->Boton_F1_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_F1_3->ForeColor = System::Drawing::Color::Transparent;
			this->Boton_F1_3->Location = System::Drawing::Point(0, 0);
			this->Boton_F1_3->Name = L"Boton_F1_3";
			this->Boton_F1_3->Size = System::Drawing::Size(170, 145);
			this->Boton_F1_3->TabIndex = 7;
			this->Boton_F1_3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Boton_F1_3->UseVisualStyleBackColor = false;
			// 
			// F1_4
			// 
			this->F1_4->Controls->Add(this->Boton_F1_4);
			this->F1_4->Location = System::Drawing::Point(673, 141);
			this->F1_4->Name = L"F1_4";
			this->F1_4->Size = System::Drawing::Size(170, 145);
			this->F1_4->TabIndex = 18;
			// 
			// Boton_F1_4
			// 
			this->Boton_F1_4->BackColor = System::Drawing::Color::Transparent;
			this->Boton_F1_4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Boton_F1_4->FlatAppearance->BorderSize = 0;
			this->Boton_F1_4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_F1_4->ForeColor = System::Drawing::Color::Transparent;
			this->Boton_F1_4->Location = System::Drawing::Point(0, 0);
			this->Boton_F1_4->Name = L"Boton_F1_4";
			this->Boton_F1_4->Size = System::Drawing::Size(167, 145);
			this->Boton_F1_4->TabIndex = 8;
			this->Boton_F1_4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Boton_F1_4->UseVisualStyleBackColor = false;
			// 
			// F1_5
			// 
			this->F1_5->Controls->Add(this->Boton_F1_5);
			this->F1_5->Location = System::Drawing::Point(868, 141);
			this->F1_5->Name = L"F1_5";
			this->F1_5->Size = System::Drawing::Size(170, 145);
			this->F1_5->TabIndex = 19;
			// 
			// Boton_F1_5
			// 
			this->Boton_F1_5->BackColor = System::Drawing::Color::Transparent;
			this->Boton_F1_5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Boton_F1_5->FlatAppearance->BorderSize = 0;
			this->Boton_F1_5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_F1_5->ForeColor = System::Drawing::Color::Transparent;
			this->Boton_F1_5->Location = System::Drawing::Point(0, 0);
			this->Boton_F1_5->Name = L"Boton_F1_5";
			this->Boton_F1_5->Size = System::Drawing::Size(170, 145);
			this->Boton_F1_5->TabIndex = 9;
			this->Boton_F1_5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Boton_F1_5->UseVisualStyleBackColor = false;
			// 
			// F2_6
			// 
			this->F2_6->Location = System::Drawing::Point(1057, 383);
			this->F2_6->Name = L"F2_6";
			this->F2_6->Size = System::Drawing::Size(170, 150);
			this->F2_6->TabIndex = 26;
			// 
			// F2_5
			// 
			this->F2_5->Location = System::Drawing::Point(865, 383);
			this->F2_5->Name = L"F2_5";
			this->F2_5->Size = System::Drawing::Size(160, 150);
			this->F2_5->TabIndex = 25;
			// 
			// F2_4
			// 
			this->F2_4->Location = System::Drawing::Point(670, 383);
			this->F2_4->Name = L"F2_4";
			this->F2_4->Size = System::Drawing::Size(162, 150);
			this->F2_4->TabIndex = 24;
			// 
			// F2_3
			// 
			this->F2_3->Location = System::Drawing::Point(472, 383);
			this->F2_3->Name = L"F2_3";
			this->F2_3->Size = System::Drawing::Size(173, 150);
			this->F2_3->TabIndex = 23;
			// 
			// F2_2
			// 
			this->F2_2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->F2_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->F2_2->CausesValidation = false;
			this->F2_2->Location = System::Drawing::Point(271, 383);
			this->F2_2->Name = L"F2_2";
			this->F2_2->Size = System::Drawing::Size(173, 150);
			this->F2_2->TabIndex = 22;
			// 
			// F2_1
			// 
			this->F2_1->Location = System::Drawing::Point(76, 383);
			this->F2_1->Name = L"F2_1";
			this->F2_1->Size = System::Drawing::Size(173, 150);
			this->F2_1->TabIndex = 21;
			// 
			// F3_6
			// 
			this->F3_6->Controls->Add(this->B_F3_6);
			this->F3_6->Location = System::Drawing::Point(1057, 620);
			this->F3_6->Name = L"F3_6";
			this->F3_6->Size = System::Drawing::Size(170, 151);
			this->F3_6->TabIndex = 32;
			// 
			// B_F3_6
			// 
			this->B_F3_6->BackColor = System::Drawing::Color::Transparent;
			this->B_F3_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_F3_6.BackgroundImage")));
			this->B_F3_6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_F3_6->FlatAppearance->BorderSize = 0;
			this->B_F3_6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B_F3_6->ForeColor = System::Drawing::Color::Transparent;
			this->B_F3_6->Location = System::Drawing::Point(0, 0);
			this->B_F3_6->Name = L"B_F3_6";
			this->B_F3_6->Size = System::Drawing::Size(170, 151);
			this->B_F3_6->TabIndex = 39;
			this->B_F3_6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->B_F3_6->UseVisualStyleBackColor = false;
			// 
			// F3_4
			// 
			this->F3_4->Controls->Add(this->B_F3_4);
			this->F3_4->Location = System::Drawing::Point(670, 620);
			this->F3_4->Name = L"F3_4";
			this->F3_4->Size = System::Drawing::Size(162, 151);
			this->F3_4->TabIndex = 30;
			// 
			// B_F3_4
			// 
			this->B_F3_4->BackColor = System::Drawing::Color::Transparent;
			this->B_F3_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_F3_4.BackgroundImage")));
			this->B_F3_4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_F3_4->FlatAppearance->BorderSize = 0;
			this->B_F3_4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B_F3_4->ForeColor = System::Drawing::Color::Transparent;
			this->B_F3_4->Location = System::Drawing::Point(0, 0);
			this->B_F3_4->Name = L"B_F3_4";
			this->B_F3_4->Size = System::Drawing::Size(162, 151);
			this->B_F3_4->TabIndex = 38;
			this->B_F3_4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->B_F3_4->UseVisualStyleBackColor = false;
			// 
			// F3_3
			// 
			this->F3_3->Controls->Add(this->B_F3_3);
			this->F3_3->Location = System::Drawing::Point(472, 620);
			this->F3_3->Name = L"F3_3";
			this->F3_3->Size = System::Drawing::Size(173, 151);
			this->F3_3->TabIndex = 29;
			// 
			// B_F3_3
			// 
			this->B_F3_3->BackColor = System::Drawing::Color::Transparent;
			this->B_F3_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_F3_3.BackgroundImage")));
			this->B_F3_3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_F3_3->FlatAppearance->BorderSize = 0;
			this->B_F3_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B_F3_3->ForeColor = System::Drawing::Color::Transparent;
			this->B_F3_3->Location = System::Drawing::Point(0, 0);
			this->B_F3_3->Name = L"B_F3_3";
			this->B_F3_3->Size = System::Drawing::Size(173, 151);
			this->B_F3_3->TabIndex = 37;
			this->B_F3_3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->B_F3_3->UseVisualStyleBackColor = false;
			// 
			// F3_2
			// 
			this->F3_2->Controls->Add(this->B_F3_2);
			this->F3_2->Location = System::Drawing::Point(271, 620);
			this->F3_2->Name = L"F3_2";
			this->F3_2->Size = System::Drawing::Size(173, 151);
			this->F3_2->TabIndex = 28;
			// 
			// B_F3_2
			// 
			this->B_F3_2->BackColor = System::Drawing::Color::Transparent;
			this->B_F3_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_F3_2.BackgroundImage")));
			this->B_F3_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_F3_2->FlatAppearance->BorderSize = 0;
			this->B_F3_2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B_F3_2->ForeColor = System::Drawing::Color::Transparent;
			this->B_F3_2->Location = System::Drawing::Point(0, 0);
			this->B_F3_2->Name = L"B_F3_2";
			this->B_F3_2->Size = System::Drawing::Size(173, 151);
			this->B_F3_2->TabIndex = 36;
			this->B_F3_2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->B_F3_2->UseVisualStyleBackColor = false;
			// 
			// F3_1
			// 
			this->F3_1->Controls->Add(this->B_F1_1);
			this->F3_1->Location = System::Drawing::Point(76, 620);
			this->F3_1->Name = L"F3_1";
			this->F3_1->Size = System::Drawing::Size(173, 151);
			this->F3_1->TabIndex = 27;
			// 
			// B_F1_1
			// 
			this->B_F1_1->BackColor = System::Drawing::Color::Transparent;
			this->B_F1_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_F1_1.BackgroundImage")));
			this->B_F1_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_F1_1->FlatAppearance->BorderSize = 0;
			this->B_F1_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B_F1_1->ForeColor = System::Drawing::Color::Transparent;
			this->B_F1_1->Location = System::Drawing::Point(0, 0);
			this->B_F1_1->Name = L"B_F1_1";
			this->B_F1_1->Size = System::Drawing::Size(173, 151);
			this->B_F1_1->TabIndex = 35;
			this->B_F1_1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->B_F1_1->UseVisualStyleBackColor = false;
			// 
			// TxtF2
			// 
			this->TxtF2->AutoSize = true;
			this->TxtF2->BackColor = System::Drawing::Color::Transparent;
			this->TxtF2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtF2->ForeColor = System::Drawing::Color::Transparent;
			this->TxtF2->Location = System::Drawing::Point(4, 355);
			this->TxtF2->Name = L"TxtF2";
			this->TxtF2->Size = System::Drawing::Size(168, 25);
			this->TxtF2->TabIndex = 33;
			this->TxtF2->Text = L"Recomendados:";
			// 
			// TxtF3
			// 
			this->TxtF3->AutoSize = true;
			this->TxtF3->BackColor = System::Drawing::Color::Transparent;
			this->TxtF3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtF3->ForeColor = System::Drawing::Color::Transparent;
			this->TxtF3->Location = System::Drawing::Point(4, 592);
			this->TxtF3->Name = L"TxtF3";
			this->TxtF3->Size = System::Drawing::Size(165, 25);
			this->TxtF3->TabIndex = 34;
			this->TxtF3->Text = L"Top mas vistos:";
			// 
			// Boton_F1_6
			// 
			this->Boton_F1_6->BackColor = System::Drawing::Color::Transparent;
			this->Boton_F1_6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Boton_F1_6->FlatAppearance->BorderSize = 0;
			this->Boton_F1_6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_F1_6->ForeColor = System::Drawing::Color::Transparent;
			this->Boton_F1_6->Location = System::Drawing::Point(0, 0);
			this->Boton_F1_6->Name = L"Boton_F1_6";
			this->Boton_F1_6->Size = System::Drawing::Size(167, 145);
			this->Boton_F1_6->TabIndex = 35;
			this->Boton_F1_6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Boton_F1_6->UseVisualStyleBackColor = false;
			// 
			// F1_6
			// 
			this->F1_6->Controls->Add(this->Boton_F1_6);
			this->F1_6->Location = System::Drawing::Point(1060, 141);
			this->F1_6->Name = L"F1_6";
			this->F1_6->Size = System::Drawing::Size(167, 145);
			this->F1_6->TabIndex = 20;
			// 
			// B_F3_5
			// 
			this->B_F3_5->BackColor = System::Drawing::Color::Transparent;
			this->B_F3_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_F3_5.BackgroundImage")));
			this->B_F3_5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_F3_5->FlatAppearance->BorderSize = 0;
			this->B_F3_5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B_F3_5->ForeColor = System::Drawing::Color::Transparent;
			this->B_F3_5->Location = System::Drawing::Point(0, 0);
			this->B_F3_5->Name = L"B_F3_5";
			this->B_F3_5->Size = System::Drawing::Size(160, 151);
			this->B_F3_5->TabIndex = 39;
			this->B_F3_5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->B_F3_5->UseVisualStyleBackColor = false;
			// 
			// F3_5
			// 
			this->F3_5->Controls->Add(this->B_F3_5);
			this->F3_5->Location = System::Drawing::Point(865, 620);
			this->F3_5->Name = L"F3_5";
			this->F3_5->Size = System::Drawing::Size(160, 151);
			this->F3_5->TabIndex = 31;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 800);
			this->ControlBox = false;
			this->Controls->Add(this->TxtF3);
			this->Controls->Add(this->TxtF2);
			this->Controls->Add(this->F3_6);
			this->Controls->Add(this->F2_6);
			this->Controls->Add(this->F3_5);
			this->Controls->Add(this->F1_6);
			this->Controls->Add(this->F3_4);
			this->Controls->Add(this->F2_5);
			this->Controls->Add(this->F3_3);
			this->Controls->Add(this->F3_2);
			this->Controls->Add(this->F1_5);
			this->Controls->Add(this->F3_1);
			this->Controls->Add(this->F2_4);
			this->Controls->Add(this->F1_4);
			this->Controls->Add(this->F2_3);
			this->Controls->Add(this->F2_2);
			this->Controls->Add(this->F1_3);
			this->Controls->Add(this->F2_1);
			this->Controls->Add(this->F1_2);
			this->Controls->Add(this->F1_1);
			this->Controls->Add(this->TxtFila1);
			this->Controls->Add(this->L_3);
			this->Controls->Add(this->R__3);
			this->Controls->Add(this->L_1);
			this->Controls->Add(this->L_2);
			this->Controls->Add(this->R_2);
			this->Controls->Add(this->R_1);
			this->Controls->Add(this->FiltrarBu);
			this->Controls->Add(this->MejorCalifButton);
			this->Controls->Add(this->TopVButton);
			//
			// btnCerrarCatalogo (boton "X" propio: el formulario no tiene barra de titulo)
			// Al cerrar el catalogo se vuelve a la pantalla de Seleccion de Perfil
			// (ver AbrirMenuPrincipal en SeleccionPerfil.h), no se cierra toda la app.
			//
			this->btnCerrarCatalogo = gcnew System::Windows::Forms::Button();
			this->btnCerrarCatalogo->BackColor = System::Drawing::Color::Transparent;
			this->btnCerrarCatalogo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCerrarCatalogo->FlatAppearance->BorderSize = 0;
			this->btnCerrarCatalogo->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(229, 9, 20);
			this->btnCerrarCatalogo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->btnCerrarCatalogo->ForeColor = System::Drawing::Color::White;
			this->btnCerrarCatalogo->Location = System::Drawing::Point(1300 - 55, 15);
			this->btnCerrarCatalogo->Name = L"btnCerrarCatalogo";
			this->btnCerrarCatalogo->Size = System::Drawing::Size(40, 40);
			this->btnCerrarCatalogo->TabStop = false;
			this->btnCerrarCatalogo->Text = L"X";
			this->btnCerrarCatalogo->UseVisualStyleBackColor = false;
			this->btnCerrarCatalogo->Cursor = System::Windows::Forms::Cursors::Hand;
			// Nota: no se asigna Anchor (el formulario no se puede redimensionar)
			this->btnCerrarCatalogo->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnCerrarCatalogo_Click);
			this->Controls->Add(this->btnCerrarCatalogo);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimizeBox = false;
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MenuPrincipal::MenuPrincipal_Paint);
			this->F1_1->ResumeLayout(false);
			this->F1_2->ResumeLayout(false);
			this->F1_3->ResumeLayout(false);
			this->F1_4->ResumeLayout(false);
			this->F1_5->ResumeLayout(false);
			this->F3_6->ResumeLayout(false);
			this->F3_4->ResumeLayout(false);
			this->F3_3->ResumeLayout(false);
			this->F3_2->ResumeLayout(false);
			this->F3_1->ResumeLayout(false);
			this->F1_6->ResumeLayout(false);
			this->F3_5->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




	private:
		void LoadTopVistos()
		{
			if (driver == nullptr) return;

			cli::array<System::Windows::Forms::Button^>^ botonesTopVistos = {
				B_F1_1, B_F3_2, B_F3_3, B_F3_4, B_F3_5, B_F3_6
			};

			// Pintamos secuencialmente las 6 peliculas visibles
			for (int i = 0; i < 6; i++)
			{
				// Recuperamos la pelicula segun la posicion actual del pivote del carrusel
				Pelicula* p = driver->ObtenerPeliculaFilaMasVistos(i);

				if (p != nullptr)
				{
					botonesTopVistos[i]->Tag = System::IntPtr(p);
					botonesTopVistos[i]->Click -= gcnew System::EventHandler(this, &MenuPrincipal::AbrirVistaPelicula);
					botonesTopVistos[i]->Click += gcnew System::EventHandler(this, &MenuPrincipal::AbrirVistaPelicula);

					// El repositorio ya guarda la ruta como "Imagenes/Peliculas/img1.jpg"
					String^ ruta = gcnew String(p->getIdImagen().c_str());
					try
					{
						if (System::IO::File::Exists(ruta))
						{
							botonesTopVistos[i]->BackgroundImage = Image::FromFile(ruta);
						}
					}
					catch (Exception^)
					{
						// Proteccion por si falta una imagen en la carpeta
					}
				}
			}
		}

		System::Void AbrirVistaPelicula(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ btn = (Button^)sender;
			Pelicula* p = (Pelicula*)(void*)((IntPtr)btn->Tag);
			VistaPelicula^ vista = gcnew VistaPelicula(p);

			this->Hide();
			vista->ShowDialog();
			this->Show();
		}

	private:
		System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e)
		{
			this->LoadTopVistos();
		}

		System::Void MenuPrincipal_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			if (driver == nullptr) this->Close();

			// Marco blanco para diferenciar la ventana del escritorio
			Pen^ borde = gcnew Pen(Color::White, 4);
			e->Graphics->DrawRectangle(borde, 2, 2, this->ClientSize.Width - 4, this->ClientSize.Height - 4);
		}

	private:
		System::Void L_1_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void L_2_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void L_3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			driver->RetrocederCarruselMasVistos();
			this->LoadTopVistos();
		}

	private:
		System::Void R_1_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void R_2_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}

		System::Void R__3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			driver->AvanzarCarruselMasVistos();
			this->LoadTopVistos();
		}

	};
}