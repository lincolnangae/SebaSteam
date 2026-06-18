#pragma once
#include "Controlador.h"

namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Programa : public System::Windows::Forms::Form
	{
	public:
		Programa(void)
		{
			InitializeComponent();
			controlador = gcnew ControladoraPrincipal();

			this->DoubleBuffered = true;
			mostrarCatalogo = false;

			imagenFondoCatalogo = System::Drawing::Image::FromFile("Imagenes/Menus/MenuPrincipal.png");

			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Programa::Programa_Paint);
		}

	protected:
		~Programa()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Button^ BotonIniciarSesion;
		System::Windows::Forms::Button^ BotonRegirtar;
		System::Windows::Forms::TextBox^ IDUsuario;
		System::Windows::Forms::TextBox^ ClaveUsuario;
		System::Drawing::Image^ imagenFondoCatalogo;

		ControladoraPrincipal^ controlador;
	private: System::Windows::Forms::Panel^ P7;
	private: System::Windows::Forms::Button^ B7;

	private: System::Windows::Forms::Panel^ P2;
	private: System::Windows::Forms::Button^ B2;

	private: System::Windows::Forms::Panel^ P1;
	private: System::Windows::Forms::Button^ B1;

	private: System::Windows::Forms::Panel^ P3;
	private: System::Windows::Forms::Button^ B3;

	private: System::Windows::Forms::Panel^ P4;
	private: System::Windows::Forms::Button^ B4;

	private: System::Windows::Forms::Panel^ P5;
	private: System::Windows::Forms::Button^ B5;

	private: System::Windows::Forms::Panel^ P6;
	private: System::Windows::Forms::Button^ B6;
	private: System::Windows::Forms::Panel^ P13;
	private: System::Windows::Forms::Button^ B13;



	private: System::Windows::Forms::Panel^ P12;
	private: System::Windows::Forms::Button^ B12;


	private: System::Windows::Forms::Panel^ P11;
	private: System::Windows::Forms::Button^ B11;


	private: System::Windows::Forms::Panel^ P10;
	private: System::Windows::Forms::Button^ B10;


	private: System::Windows::Forms::Panel^ P9;
	private: System::Windows::Forms::Button^ B9;


	private: System::Windows::Forms::Panel^ P14;


	private: System::Windows::Forms::Button^ B8;

	private: System::Windows::Forms::Panel^ P8;
	private: System::Windows::Forms::Panel^ P20;
	private: System::Windows::Forms::Button^ B20;


	private: System::Windows::Forms::Panel^ P19;
	private: System::Windows::Forms::Button^ B19;


	private: System::Windows::Forms::Panel^ P18;
	private: System::Windows::Forms::Button^ B18;


	private: System::Windows::Forms::Panel^ P17;
	private: System::Windows::Forms::Button^ B17;


	private: System::Windows::Forms::Panel^ P16;
	private: System::Windows::Forms::Button^ B16;


	private: System::Windows::Forms::Panel^ P21;
	private: System::Windows::Forms::Button^ B21;
	private: System::Windows::Forms::Button^ B15;



	private: System::Windows::Forms::Panel^ P15;
	private: System::Windows::Forms::Button^ B14;
	private: System::Windows::Forms::Button^ R1;
	private: System::Windows::Forms::Button^ R2;
	private: System::Windows::Forms::Button^ R3;
	private: System::Windows::Forms::Button^ L3;

	private: System::Windows::Forms::Button^ L1;
	private: System::Windows::Forms::Button^ L2;
	private: System::Windows::Forms::Button^ TopPCalificadas;
	private: System::Windows::Forms::Button^ TopPVistas;
	private: System::Windows::Forms::Button^ TopAlfabetico;
	private: System::Windows::Forms::Panel^ VistaPelicula;
	private: System::Windows::Forms::Label^ CalificacionP;
	private: System::Windows::Forms::Label^ VistasTotalesP;
	private: System::Windows::Forms::Label^ SinopsisP;
	private: System::Windows::Forms::Label^ CategoriaP;
	private: System::Windows::Forms::PictureBox^ ImgPelicula;
	private: System::Windows::Forms::Label^ TituloPelicula;
	private: System::Windows::Forms::Button^ SalirVista;

		   Pelicula* peliculaActualEnVista;
		   bool mostrarCatalogo;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Programa::typeid));
			   this->BotonIniciarSesion = (gcnew System::Windows::Forms::Button());
			   this->BotonRegirtar = (gcnew System::Windows::Forms::Button());
			   this->IDUsuario = (gcnew System::Windows::Forms::TextBox());
			   this->ClaveUsuario = (gcnew System::Windows::Forms::TextBox());
			   this->P7 = (gcnew System::Windows::Forms::Panel());
			   this->B7 = (gcnew System::Windows::Forms::Button());
			   this->P2 = (gcnew System::Windows::Forms::Panel());
			   this->B2 = (gcnew System::Windows::Forms::Button());
			   this->P1 = (gcnew System::Windows::Forms::Panel());
			   this->B1 = (gcnew System::Windows::Forms::Button());
			   this->P3 = (gcnew System::Windows::Forms::Panel());
			   this->B3 = (gcnew System::Windows::Forms::Button());
			   this->P4 = (gcnew System::Windows::Forms::Panel());
			   this->B4 = (gcnew System::Windows::Forms::Button());
			   this->P5 = (gcnew System::Windows::Forms::Panel());
			   this->B5 = (gcnew System::Windows::Forms::Button());
			   this->P6 = (gcnew System::Windows::Forms::Panel());
			   this->B6 = (gcnew System::Windows::Forms::Button());
			   this->P13 = (gcnew System::Windows::Forms::Panel());
			   this->B13 = (gcnew System::Windows::Forms::Button());
			   this->P12 = (gcnew System::Windows::Forms::Panel());
			   this->B12 = (gcnew System::Windows::Forms::Button());
			   this->P11 = (gcnew System::Windows::Forms::Panel());
			   this->B11 = (gcnew System::Windows::Forms::Button());
			   this->P10 = (gcnew System::Windows::Forms::Panel());
			   this->B10 = (gcnew System::Windows::Forms::Button());
			   this->P9 = (gcnew System::Windows::Forms::Panel());
			   this->B9 = (gcnew System::Windows::Forms::Button());
			   this->P14 = (gcnew System::Windows::Forms::Panel());
			   this->B14 = (gcnew System::Windows::Forms::Button());
			   this->B8 = (gcnew System::Windows::Forms::Button());
			   this->P8 = (gcnew System::Windows::Forms::Panel());
			   this->P20 = (gcnew System::Windows::Forms::Panel());
			   this->B20 = (gcnew System::Windows::Forms::Button());
			   this->P19 = (gcnew System::Windows::Forms::Panel());
			   this->B19 = (gcnew System::Windows::Forms::Button());
			   this->P18 = (gcnew System::Windows::Forms::Panel());
			   this->B18 = (gcnew System::Windows::Forms::Button());
			   this->P17 = (gcnew System::Windows::Forms::Panel());
			   this->B17 = (gcnew System::Windows::Forms::Button());
			   this->P16 = (gcnew System::Windows::Forms::Panel());
			   this->B16 = (gcnew System::Windows::Forms::Button());
			   this->P21 = (gcnew System::Windows::Forms::Panel());
			   this->B21 = (gcnew System::Windows::Forms::Button());
			   this->B15 = (gcnew System::Windows::Forms::Button());
			   this->P15 = (gcnew System::Windows::Forms::Panel());
			   this->R1 = (gcnew System::Windows::Forms::Button());
			   this->R2 = (gcnew System::Windows::Forms::Button());
			   this->R3 = (gcnew System::Windows::Forms::Button());
			   this->L1 = (gcnew System::Windows::Forms::Button());
			   this->L2 = (gcnew System::Windows::Forms::Button());
			   this->L3 = (gcnew System::Windows::Forms::Button());
			   this->TopPCalificadas = (gcnew System::Windows::Forms::Button());
			   this->TopPVistas = (gcnew System::Windows::Forms::Button());
			   this->TopAlfabetico = (gcnew System::Windows::Forms::Button());
			   this->VistaPelicula = (gcnew System::Windows::Forms::Panel());
			   this->SalirVista = (gcnew System::Windows::Forms::Button());
			   this->CalificacionP = (gcnew System::Windows::Forms::Label());
			   this->VistasTotalesP = (gcnew System::Windows::Forms::Label());
			   this->SinopsisP = (gcnew System::Windows::Forms::Label());
			   this->CategoriaP = (gcnew System::Windows::Forms::Label());
			   this->ImgPelicula = (gcnew System::Windows::Forms::PictureBox());
			   this->TituloPelicula = (gcnew System::Windows::Forms::Label());
			   this->P7->SuspendLayout();
			   this->P2->SuspendLayout();
			   this->P1->SuspendLayout();
			   this->P3->SuspendLayout();
			   this->P4->SuspendLayout();
			   this->P5->SuspendLayout();
			   this->P6->SuspendLayout();
			   this->P13->SuspendLayout();
			   this->P12->SuspendLayout();
			   this->P11->SuspendLayout();
			   this->P10->SuspendLayout();
			   this->P9->SuspendLayout();
			   this->P14->SuspendLayout();
			   this->P8->SuspendLayout();
			   this->P20->SuspendLayout();
			   this->P19->SuspendLayout();
			   this->P18->SuspendLayout();
			   this->P17->SuspendLayout();
			   this->P16->SuspendLayout();
			   this->P21->SuspendLayout();
			   this->P15->SuspendLayout();
			   this->VistaPelicula->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImgPelicula))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // BotonIniciarSesion
			   // 
			   this->BotonIniciarSesion->BackColor = System::Drawing::Color::Transparent;
			   this->BotonIniciarSesion->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BotonIniciarSesion.BackgroundImage")));
			   this->BotonIniciarSesion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->BotonIniciarSesion->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->BotonIniciarSesion->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->BotonIniciarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->BotonIniciarSesion->Location = System::Drawing::Point(43, 550);
			   this->BotonIniciarSesion->Name = L"BotonIniciarSesion";
			   this->BotonIniciarSesion->Size = System::Drawing::Size(212, 60);
			   this->BotonIniciarSesion->TabIndex = 2;
			   this->BotonIniciarSesion->Text = L"txt";
			   this->BotonIniciarSesion->UseVisualStyleBackColor = false;
			   this->BotonIniciarSesion->Click += gcnew System::EventHandler(this, &Programa::BotonIniciarSesion_Click);
			   // 
			   // BotonRegirtar
			   // 
			   this->BotonRegirtar->BackColor = System::Drawing::Color::Transparent;
			   this->BotonRegirtar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BotonRegirtar.BackgroundImage")));
			   this->BotonRegirtar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->BotonRegirtar->Cursor = System::Windows::Forms::Cursors::Default;
			   this->BotonRegirtar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->BotonRegirtar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->BotonRegirtar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->BotonRegirtar->Location = System::Drawing::Point(298, 550);
			   this->BotonRegirtar->Name = L"BotonRegirtar";
			   this->BotonRegirtar->Size = System::Drawing::Size(212, 60);
			   this->BotonRegirtar->TabIndex = 3;
			   this->BotonRegirtar->UseVisualStyleBackColor = false;
			   this->BotonRegirtar->Click += gcnew System::EventHandler(this, &Programa::BotonRegirtar_Click);
			   // 
			   // IDUsuario
			   // 
			   this->IDUsuario->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->IDUsuario->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->IDUsuario->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->IDUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->IDUsuario->ForeColor = System::Drawing::SystemColors::WindowText;
			   this->IDUsuario->Location = System::Drawing::Point(135, 378);
			   this->IDUsuario->Name = L"IDUsuario";
			   this->IDUsuario->Size = System::Drawing::Size(263, 26);
			   this->IDUsuario->TabIndex = 4;
			   this->IDUsuario->Text = L"Poner Usuario";
			   this->IDUsuario->WordWrap = false;
			   // 
			   // ClaveUsuario
			   // 
			   this->ClaveUsuario->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->ClaveUsuario->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->ClaveUsuario->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->ClaveUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ClaveUsuario->ForeColor = System::Drawing::SystemColors::WindowText;
			   this->ClaveUsuario->Location = System::Drawing::Point(135, 444);
			   this->ClaveUsuario->Name = L"ClaveUsuario";
			   this->ClaveUsuario->Size = System::Drawing::Size(263, 26);
			   this->ClaveUsuario->TabIndex = 5;
			   this->ClaveUsuario->Text = L"Poner Clave";
			   this->ClaveUsuario->WordWrap = false;
			   // 
			   // P7
			   // 
			   this->P7->BackColor = System::Drawing::Color::Transparent;
			   this->P7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P7.BackgroundImage")));
			   this->P7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P7->Controls->Add(this->B7);
			   this->P7->Enabled = false;
			   this->P7->Location = System::Drawing::Point(1033, 112);
			   this->P7->Name = L"P7";
			   this->P7->Size = System::Drawing::Size(136, 167);
			   this->P7->TabIndex = 11;
			   this->P7->Visible = false;
			   // 
			   // B7
			   // 
			   this->B7->BackColor = System::Drawing::Color::Transparent;
			   this->B7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B7->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B7->FlatAppearance->BorderSize = 0;
			   this->B7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B7->Location = System::Drawing::Point(3, 14);
			   this->B7->Name = L"B7";
			   this->B7->Size = System::Drawing::Size(126, 139);
			   this->B7->TabIndex = 0;
			   this->B7->UseVisualStyleBackColor = false;
			   // 
			   // P2
			   // 
			   this->P2->BackColor = System::Drawing::Color::Transparent;
			   this->P2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P2.BackgroundImage")));
			   this->P2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P2->Controls->Add(this->B2);
			   this->P2->Enabled = false;
			   this->P2->Location = System::Drawing::Point(213, 112);
			   this->P2->Name = L"P2";
			   this->P2->Size = System::Drawing::Size(136, 167);
			   this->P2->TabIndex = 12;
			   this->P2->Visible = false;
			   // 
			   // B2
			   // 
			   this->B2->BackColor = System::Drawing::Color::Transparent;
			   this->B2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B2->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B2->FlatAppearance->BorderSize = 0;
			   this->B2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B2->Location = System::Drawing::Point(3, 14);
			   this->B2->Name = L"B2";
			   this->B2->Size = System::Drawing::Size(126, 139);
			   this->B2->TabIndex = 0;
			   this->B2->UseVisualStyleBackColor = false;
			   // 
			   // P1
			   // 
			   this->P1->BackColor = System::Drawing::Color::Transparent;
			   this->P1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P1.BackgroundImage")));
			   this->P1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P1->Controls->Add(this->B1);
			   this->P1->Enabled = false;
			   this->P1->Location = System::Drawing::Point(52, 112);
			   this->P1->Name = L"P1";
			   this->P1->Size = System::Drawing::Size(136, 167);
			   this->P1->TabIndex = 12;
			   this->P1->Visible = false;
			   // 
			   // B1
			   // 
			   this->B1->BackColor = System::Drawing::Color::Transparent;
			   this->B1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B1->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B1->FlatAppearance->BorderSize = 0;
			   this->B1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B1->Location = System::Drawing::Point(3, 14);
			   this->B1->Name = L"B1";
			   this->B1->Size = System::Drawing::Size(126, 139);
			   this->B1->TabIndex = 0;
			   this->B1->UseVisualStyleBackColor = false;
			   // 
			   // P3
			   // 
			   this->P3->BackColor = System::Drawing::Color::Transparent;
			   this->P3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P3.BackgroundImage")));
			   this->P3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P3->Controls->Add(this->B3);
			   this->P3->Enabled = false;
			   this->P3->Location = System::Drawing::Point(374, 112);
			   this->P3->Name = L"P3";
			   this->P3->Size = System::Drawing::Size(136, 167);
			   this->P3->TabIndex = 13;
			   this->P3->Visible = false;
			   // 
			   // B3
			   // 
			   this->B3->BackColor = System::Drawing::Color::Transparent;
			   this->B3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B3->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B3->FlatAppearance->BorderSize = 0;
			   this->B3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B3->Location = System::Drawing::Point(3, 14);
			   this->B3->Name = L"B3";
			   this->B3->Size = System::Drawing::Size(126, 139);
			   this->B3->TabIndex = 0;
			   this->B3->UseVisualStyleBackColor = false;
			   // 
			   // P4
			   // 
			   this->P4->BackColor = System::Drawing::Color::Transparent;
			   this->P4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P4.BackgroundImage")));
			   this->P4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P4->Controls->Add(this->B4);
			   this->P4->Enabled = false;
			   this->P4->Location = System::Drawing::Point(538, 112);
			   this->P4->Name = L"P4";
			   this->P4->Size = System::Drawing::Size(136, 167);
			   this->P4->TabIndex = 14;
			   this->P4->Visible = false;
			   // 
			   // B4
			   // 
			   this->B4->BackColor = System::Drawing::Color::Transparent;
			   this->B4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B4->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B4->FlatAppearance->BorderSize = 0;
			   this->B4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B4->Location = System::Drawing::Point(3, 14);
			   this->B4->Name = L"B4";
			   this->B4->Size = System::Drawing::Size(126, 139);
			   this->B4->TabIndex = 0;
			   this->B4->UseVisualStyleBackColor = false;
			   // 
			   // P5
			   // 
			   this->P5->BackColor = System::Drawing::Color::Transparent;
			   this->P5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P5.BackgroundImage")));
			   this->P5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P5->Controls->Add(this->B5);
			   this->P5->Enabled = false;
			   this->P5->Location = System::Drawing::Point(697, 112);
			   this->P5->Name = L"P5";
			   this->P5->Size = System::Drawing::Size(136, 167);
			   this->P5->TabIndex = 15;
			   this->P5->Visible = false;
			   // 
			   // B5
			   // 
			   this->B5->BackColor = System::Drawing::Color::Transparent;
			   this->B5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B5->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B5->FlatAppearance->BorderSize = 0;
			   this->B5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B5->Location = System::Drawing::Point(3, 14);
			   this->B5->Name = L"B5";
			   this->B5->Size = System::Drawing::Size(126, 139);
			   this->B5->TabIndex = 0;
			   this->B5->UseVisualStyleBackColor = false;
			   // 
			   // P6
			   // 
			   this->P6->BackColor = System::Drawing::Color::Transparent;
			   this->P6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P6.BackgroundImage")));
			   this->P6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P6->Controls->Add(this->B6);
			   this->P6->Enabled = false;
			   this->P6->Location = System::Drawing::Point(863, 112);
			   this->P6->Name = L"P6";
			   this->P6->Size = System::Drawing::Size(136, 167);
			   this->P6->TabIndex = 16;
			   this->P6->Visible = false;
			   // 
			   // B6
			   // 
			   this->B6->BackColor = System::Drawing::Color::Transparent;
			   this->B6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B6->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B6->FlatAppearance->BorderSize = 0;
			   this->B6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B6->Location = System::Drawing::Point(3, 14);
			   this->B6->Name = L"B6";
			   this->B6->Size = System::Drawing::Size(126, 139);
			   this->B6->TabIndex = 0;
			   this->B6->UseVisualStyleBackColor = false;
			   // 
			   // P13
			   // 
			   this->P13->BackColor = System::Drawing::Color::Transparent;
			   this->P13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P13.BackgroundImage")));
			   this->P13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P13->Controls->Add(this->B13);
			   this->P13->Enabled = false;
			   this->P13->Location = System::Drawing::Point(863, 344);
			   this->P13->Name = L"P13";
			   this->P13->Size = System::Drawing::Size(136, 167);
			   this->P13->TabIndex = 23;
			   this->P13->Visible = false;
			   // 
			   // B13
			   // 
			   this->B13->BackColor = System::Drawing::Color::Transparent;
			   this->B13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B13->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B13->FlatAppearance->BorderSize = 0;
			   this->B13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B13->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B13->Location = System::Drawing::Point(3, 14);
			   this->B13->Name = L"B13";
			   this->B13->Size = System::Drawing::Size(126, 139);
			   this->B13->TabIndex = 0;
			   this->B13->UseVisualStyleBackColor = false;
			   this->B13->Click += gcnew System::EventHandler(this, &Programa::B13_Click);
			   // 
			   // P12
			   // 
			   this->P12->BackColor = System::Drawing::Color::Transparent;
			   this->P12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P12.BackgroundImage")));
			   this->P12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P12->Controls->Add(this->B12);
			   this->P12->Enabled = false;
			   this->P12->Location = System::Drawing::Point(697, 344);
			   this->P12->Name = L"P12";
			   this->P12->Size = System::Drawing::Size(136, 167);
			   this->P12->TabIndex = 22;
			   this->P12->Visible = false;
			   // 
			   // B12
			   // 
			   this->B12->BackColor = System::Drawing::Color::Transparent;
			   this->B12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B12->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B12->FlatAppearance->BorderSize = 0;
			   this->B12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B12->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B12->Location = System::Drawing::Point(3, 14);
			   this->B12->Name = L"B12";
			   this->B12->Size = System::Drawing::Size(126, 139);
			   this->B12->TabIndex = 0;
			   this->B12->UseVisualStyleBackColor = false;
			   this->B12->Click += gcnew System::EventHandler(this, &Programa::B12_Click);
			   // 
			   // P11
			   // 
			   this->P11->BackColor = System::Drawing::Color::Transparent;
			   this->P11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P11.BackgroundImage")));
			   this->P11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P11->Controls->Add(this->B11);
			   this->P11->Enabled = false;
			   this->P11->Location = System::Drawing::Point(538, 344);
			   this->P11->Name = L"P11";
			   this->P11->Size = System::Drawing::Size(136, 167);
			   this->P11->TabIndex = 21;
			   this->P11->Visible = false;
			   // 
			   // B11
			   // 
			   this->B11->BackColor = System::Drawing::Color::Transparent;
			   this->B11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B11->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B11->FlatAppearance->BorderSize = 0;
			   this->B11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B11->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B11->Location = System::Drawing::Point(3, 14);
			   this->B11->Name = L"B11";
			   this->B11->Size = System::Drawing::Size(126, 139);
			   this->B11->TabIndex = 0;
			   this->B11->UseVisualStyleBackColor = false;
			   this->B11->Click += gcnew System::EventHandler(this, &Programa::B11_Click);
			   // 
			   // P10
			   // 
			   this->P10->BackColor = System::Drawing::Color::Transparent;
			   this->P10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P10.BackgroundImage")));
			   this->P10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P10->Controls->Add(this->B10);
			   this->P10->Enabled = false;
			   this->P10->Location = System::Drawing::Point(374, 344);
			   this->P10->Name = L"P10";
			   this->P10->Size = System::Drawing::Size(136, 167);
			   this->P10->TabIndex = 20;
			   this->P10->Visible = false;
			   // 
			   // B10
			   // 
			   this->B10->BackColor = System::Drawing::Color::Transparent;
			   this->B10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B10->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B10->FlatAppearance->BorderSize = 0;
			   this->B10->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B10->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B10->Location = System::Drawing::Point(3, 14);
			   this->B10->Name = L"B10";
			   this->B10->Size = System::Drawing::Size(126, 139);
			   this->B10->TabIndex = 0;
			   this->B10->UseVisualStyleBackColor = false;
			   this->B10->Click += gcnew System::EventHandler(this, &Programa::B10_Click);
			   // 
			   // P9
			   // 
			   this->P9->BackColor = System::Drawing::Color::Transparent;
			   this->P9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P9.BackgroundImage")));
			   this->P9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P9->Controls->Add(this->B9);
			   this->P9->Enabled = false;
			   this->P9->Location = System::Drawing::Point(213, 344);
			   this->P9->Name = L"P9";
			   this->P9->Size = System::Drawing::Size(136, 167);
			   this->P9->TabIndex = 18;
			   this->P9->Visible = false;
			   // 
			   // B9
			   // 
			   this->B9->BackColor = System::Drawing::Color::Transparent;
			   this->B9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B9->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B9->FlatAppearance->BorderSize = 0;
			   this->B9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B9->Location = System::Drawing::Point(3, 14);
			   this->B9->Name = L"B9";
			   this->B9->Size = System::Drawing::Size(126, 139);
			   this->B9->TabIndex = 0;
			   this->B9->UseVisualStyleBackColor = false;
			   this->B9->Click += gcnew System::EventHandler(this, &Programa::B9_Click);
			   // 
			   // P14
			   // 
			   this->P14->BackColor = System::Drawing::Color::Transparent;
			   this->P14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P14.BackgroundImage")));
			   this->P14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P14->Controls->Add(this->B14);
			   this->P14->Enabled = false;
			   this->P14->Location = System::Drawing::Point(1033, 344);
			   this->P14->Name = L"P14";
			   this->P14->Size = System::Drawing::Size(136, 167);
			   this->P14->TabIndex = 17;
			   this->P14->Visible = false;
			   // 
			   // B14
			   // 
			   this->B14->BackColor = System::Drawing::Color::Transparent;
			   this->B14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B14->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B14->FlatAppearance->BorderSize = 0;
			   this->B14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B14->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B14->Location = System::Drawing::Point(3, 14);
			   this->B14->Name = L"B14";
			   this->B14->Size = System::Drawing::Size(126, 139);
			   this->B14->TabIndex = 0;
			   this->B14->UseVisualStyleBackColor = false;
			   this->B14->Click += gcnew System::EventHandler(this, &Programa::B14_Click);
			   // 
			   // B8
			   // 
			   this->B8->BackColor = System::Drawing::Color::Transparent;
			   this->B8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B8->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B8->FlatAppearance->BorderSize = 0;
			   this->B8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B8->Location = System::Drawing::Point(3, 14);
			   this->B8->Name = L"B8";
			   this->B8->Size = System::Drawing::Size(126, 139);
			   this->B8->TabIndex = 0;
			   this->B8->UseVisualStyleBackColor = false;
			   this->B8->Click += gcnew System::EventHandler(this, &Programa::B8_Click);
			   // 
			   // P8
			   // 
			   this->P8->BackColor = System::Drawing::Color::Transparent;
			   this->P8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P8.BackgroundImage")));
			   this->P8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P8->Controls->Add(this->B8);
			   this->P8->Enabled = false;
			   this->P8->Location = System::Drawing::Point(52, 344);
			   this->P8->Name = L"P8";
			   this->P8->Size = System::Drawing::Size(136, 167);
			   this->P8->TabIndex = 19;
			   this->P8->Visible = false;
			   // 
			   // P20
			   // 
			   this->P20->BackColor = System::Drawing::Color::Transparent;
			   this->P20->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P20.BackgroundImage")));
			   this->P20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P20->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P20->Controls->Add(this->B20);
			   this->P20->Enabled = false;
			   this->P20->Location = System::Drawing::Point(868, 569);
			   this->P20->Name = L"P20";
			   this->P20->Size = System::Drawing::Size(136, 167);
			   this->P20->TabIndex = 23;
			   this->P20->Visible = false;
			   // 
			   // B20
			   // 
			   this->B20->BackColor = System::Drawing::Color::Transparent;
			   this->B20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B20->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B20->FlatAppearance->BorderSize = 0;
			   this->B20->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B20->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B20->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B20->Location = System::Drawing::Point(3, 14);
			   this->B20->Name = L"B20";
			   this->B20->Size = System::Drawing::Size(126, 139);
			   this->B20->TabIndex = 0;
			   this->B20->UseVisualStyleBackColor = false;
			   // 
			   // P19
			   // 
			   this->P19->BackColor = System::Drawing::Color::Transparent;
			   this->P19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P19.BackgroundImage")));
			   this->P19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P19->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P19->Controls->Add(this->B19);
			   this->P19->Enabled = false;
			   this->P19->Location = System::Drawing::Point(702, 569);
			   this->P19->Name = L"P19";
			   this->P19->Size = System::Drawing::Size(136, 167);
			   this->P19->TabIndex = 22;
			   this->P19->Visible = false;
			   // 
			   // B19
			   // 
			   this->B19->BackColor = System::Drawing::Color::Transparent;
			   this->B19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B19->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B19->FlatAppearance->BorderSize = 0;
			   this->B19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B19->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B19->Location = System::Drawing::Point(3, 14);
			   this->B19->Name = L"B19";
			   this->B19->Size = System::Drawing::Size(126, 139);
			   this->B19->TabIndex = 0;
			   this->B19->UseVisualStyleBackColor = false;
			   // 
			   // P18
			   // 
			   this->P18->BackColor = System::Drawing::Color::Transparent;
			   this->P18->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P18.BackgroundImage")));
			   this->P18->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P18->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P18->Controls->Add(this->B18);
			   this->P18->Enabled = false;
			   this->P18->Location = System::Drawing::Point(543, 569);
			   this->P18->Name = L"P18";
			   this->P18->Size = System::Drawing::Size(136, 167);
			   this->P18->TabIndex = 21;
			   this->P18->Visible = false;
			   // 
			   // B18
			   // 
			   this->B18->BackColor = System::Drawing::Color::Transparent;
			   this->B18->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B18->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B18->FlatAppearance->BorderSize = 0;
			   this->B18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B18->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B18->Location = System::Drawing::Point(3, 14);
			   this->B18->Name = L"B18";
			   this->B18->Size = System::Drawing::Size(126, 139);
			   this->B18->TabIndex = 0;
			   this->B18->UseVisualStyleBackColor = false;
			   // 
			   // P17
			   // 
			   this->P17->BackColor = System::Drawing::Color::Transparent;
			   this->P17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P17.BackgroundImage")));
			   this->P17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P17->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P17->Controls->Add(this->B17);
			   this->P17->Enabled = false;
			   this->P17->Location = System::Drawing::Point(379, 569);
			   this->P17->Name = L"P17";
			   this->P17->Size = System::Drawing::Size(136, 167);
			   this->P17->TabIndex = 20;
			   this->P17->Visible = false;
			   // 
			   // B17
			   // 
			   this->B17->BackColor = System::Drawing::Color::Transparent;
			   this->B17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B17->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B17->FlatAppearance->BorderSize = 0;
			   this->B17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B17->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B17->Location = System::Drawing::Point(3, 14);
			   this->B17->Name = L"B17";
			   this->B17->Size = System::Drawing::Size(126, 139);
			   this->B17->TabIndex = 0;
			   this->B17->UseVisualStyleBackColor = false;
			   // 
			   // P16
			   // 
			   this->P16->BackColor = System::Drawing::Color::Transparent;
			   this->P16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P16.BackgroundImage")));
			   this->P16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P16->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P16->Controls->Add(this->B16);
			   this->P16->Enabled = false;
			   this->P16->Location = System::Drawing::Point(218, 569);
			   this->P16->Name = L"P16";
			   this->P16->Size = System::Drawing::Size(136, 167);
			   this->P16->TabIndex = 18;
			   this->P16->Visible = false;
			   // 
			   // B16
			   // 
			   this->B16->BackColor = System::Drawing::Color::Transparent;
			   this->B16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B16->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B16->FlatAppearance->BorderSize = 0;
			   this->B16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B16->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B16->Location = System::Drawing::Point(3, 14);
			   this->B16->Name = L"B16";
			   this->B16->Size = System::Drawing::Size(126, 139);
			   this->B16->TabIndex = 0;
			   this->B16->UseVisualStyleBackColor = false;
			   // 
			   // P21
			   // 
			   this->P21->BackColor = System::Drawing::Color::Transparent;
			   this->P21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P21.BackgroundImage")));
			   this->P21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P21->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P21->Controls->Add(this->B21);
			   this->P21->Enabled = false;
			   this->P21->Location = System::Drawing::Point(1038, 569);
			   this->P21->Name = L"P21";
			   this->P21->Size = System::Drawing::Size(136, 167);
			   this->P21->TabIndex = 17;
			   this->P21->Visible = false;
			   // 
			   // B21
			   // 
			   this->B21->BackColor = System::Drawing::Color::Transparent;
			   this->B21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B21->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B21->FlatAppearance->BorderSize = 0;
			   this->B21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B21->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B21->Location = System::Drawing::Point(3, 14);
			   this->B21->Name = L"B21";
			   this->B21->Size = System::Drawing::Size(126, 139);
			   this->B21->TabIndex = 0;
			   this->B21->UseVisualStyleBackColor = false;
			   // 
			   // B15
			   // 
			   this->B15->BackColor = System::Drawing::Color::Transparent;
			   this->B15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->B15->Cursor = System::Windows::Forms::Cursors::Default;
			   this->B15->FlatAppearance->BorderSize = 0;
			   this->B15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->B15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->B15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->B15->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->B15->Location = System::Drawing::Point(3, 14);
			   this->B15->Name = L"B15";
			   this->B15->Size = System::Drawing::Size(126, 139);
			   this->B15->TabIndex = 0;
			   this->B15->UseVisualStyleBackColor = false;
			   // 
			   // P15
			   // 
			   this->P15->BackColor = System::Drawing::Color::Transparent;
			   this->P15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P15.BackgroundImage")));
			   this->P15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->P15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->P15->Controls->Add(this->B15);
			   this->P15->Enabled = false;
			   this->P15->Location = System::Drawing::Point(57, 569);
			   this->P15->Name = L"P15";
			   this->P15->Size = System::Drawing::Size(136, 167);
			   this->P15->TabIndex = 19;
			   this->P15->Visible = false;
			   // 
			   // R1
			   // 
			   this->R1->BackColor = System::Drawing::Color::Transparent;
			   this->R1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R1.BackgroundImage")));
			   this->R1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->R1->Cursor = System::Windows::Forms::Cursors::Default;
			   this->R1->Enabled = false;
			   this->R1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->R1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->R1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->R1->Location = System::Drawing::Point(1184, 154);
			   this->R1->Name = L"R1";
			   this->R1->Size = System::Drawing::Size(38, 85);
			   this->R1->TabIndex = 24;
			   this->R1->UseVisualStyleBackColor = false;
			   this->R1->Visible = false;
			   this->R1->Click += gcnew System::EventHandler(this, &Programa::R1_Click);
			   // 
			   // R2
			   // 
			   this->R2->BackColor = System::Drawing::Color::Transparent;
			   this->R2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R2.BackgroundImage")));
			   this->R2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->R2->Cursor = System::Windows::Forms::Cursors::Default;
			   this->R2->Enabled = false;
			   this->R2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->R2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->R2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->R2->Location = System::Drawing::Point(1184, 383);
			   this->R2->Name = L"R2";
			   this->R2->Size = System::Drawing::Size(38, 85);
			   this->R2->TabIndex = 25;
			   this->R2->UseVisualStyleBackColor = false;
			   this->R2->Visible = false;
			   this->R2->Click += gcnew System::EventHandler(this, &Programa::R2_Click);
			   // 
			   // R3
			   // 
			   this->R3->BackColor = System::Drawing::Color::Transparent;
			   this->R3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R3.BackgroundImage")));
			   this->R3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->R3->Cursor = System::Windows::Forms::Cursors::Default;
			   this->R3->Enabled = false;
			   this->R3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->R3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->R3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->R3->Location = System::Drawing::Point(1184, 610);
			   this->R3->Name = L"R3";
			   this->R3->Size = System::Drawing::Size(38, 85);
			   this->R3->TabIndex = 26;
			   this->R3->UseVisualStyleBackColor = false;
			   this->R3->Visible = false;
			   // 
			   // L1
			   // 
			   this->L1->BackColor = System::Drawing::Color::Transparent;
			   this->L1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"L1.BackgroundImage")));
			   this->L1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->L1->Cursor = System::Windows::Forms::Cursors::Default;
			   this->L1->Enabled = false;
			   this->L1->FlatAppearance->BorderSize = 0;
			   this->L1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->L1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->L1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->L1->Location = System::Drawing::Point(8, 154);
			   this->L1->Name = L"L1";
			   this->L1->Size = System::Drawing::Size(38, 85);
			   this->L1->TabIndex = 27;
			   this->L1->UseVisualStyleBackColor = false;
			   this->L1->Visible = false;
			   this->L1->Click += gcnew System::EventHandler(this, &Programa::L1_Click);
			   // 
			   // L2
			   // 
			   this->L2->BackColor = System::Drawing::Color::Transparent;
			   this->L2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"L2.BackgroundImage")));
			   this->L2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->L2->Cursor = System::Windows::Forms::Cursors::Default;
			   this->L2->Enabled = false;
			   this->L2->FlatAppearance->BorderSize = 0;
			   this->L2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->L2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->L2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->L2->Location = System::Drawing::Point(3, 383);
			   this->L2->Name = L"L2";
			   this->L2->Size = System::Drawing::Size(38, 85);
			   this->L2->TabIndex = 28;
			   this->L2->UseVisualStyleBackColor = false;
			   this->L2->Visible = false;
			   this->L2->Click += gcnew System::EventHandler(this, &Programa::L2_Click);
			   // 
			   // L3
			   // 
			   this->L3->BackColor = System::Drawing::Color::Transparent;
			   this->L3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"L3.BackgroundImage")));
			   this->L3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->L3->Cursor = System::Windows::Forms::Cursors::Default;
			   this->L3->Enabled = false;
			   this->L3->FlatAppearance->BorderSize = 0;
			   this->L3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->L3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->L3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->L3->Location = System::Drawing::Point(8, 616);
			   this->L3->Name = L"L3";
			   this->L3->Size = System::Drawing::Size(38, 85);
			   this->L3->TabIndex = 29;
			   this->L3->UseVisualStyleBackColor = false;
			   this->L3->Visible = false;
			   // 
			   // TopPCalificadas
			   // 
			   this->TopPCalificadas->Enabled = false;
			   this->TopPCalificadas->FlatAppearance->BorderSize = 0;
			   this->TopPCalificadas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TopPCalificadas->Location = System::Drawing::Point(449, 21);
			   this->TopPCalificadas->Name = L"TopPCalificadas";
			   this->TopPCalificadas->Size = System::Drawing::Size(142, 29);
			   this->TopPCalificadas->TabIndex = 31;
			   this->TopPCalificadas->Text = L"MEJOR CALIFICADOS";
			   this->TopPCalificadas->UseVisualStyleBackColor = true;
			   this->TopPCalificadas->Visible = false;
			   // 
			   // TopPVistas
			   // 
			   this->TopPVistas->Enabled = false;
			   this->TopPVistas->FlatAppearance->BorderSize = 0;
			   this->TopPVistas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TopPVistas->Location = System::Drawing::Point(697, 21);
			   this->TopPVistas->Name = L"TopPVistas";
			   this->TopPVistas->Size = System::Drawing::Size(142, 29);
			   this->TopPVistas->TabIndex = 32;
			   this->TopPVistas->Text = L"TOP VISTOS";
			   this->TopPVistas->UseVisualStyleBackColor = true;
			   this->TopPVistas->Visible = false;
			   // 
			   // TopAlfabetico
			   // 
			   this->TopAlfabetico->Enabled = false;
			   this->TopAlfabetico->FlatAppearance->BorderSize = 0;
			   this->TopAlfabetico->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TopAlfabetico->Location = System::Drawing::Point(961, 21);
			   this->TopAlfabetico->Name = L"TopAlfabetico";
			   this->TopAlfabetico->Size = System::Drawing::Size(142, 29);
			   this->TopAlfabetico->TabIndex = 33;
			   this->TopAlfabetico->Text = L"A - Z";
			   this->TopAlfabetico->UseVisualStyleBackColor = true;
			   this->TopAlfabetico->Visible = false;
			   // 
			   // VistaPelicula
			   // 
			   this->VistaPelicula->BackColor = System::Drawing::Color::Transparent;
			   this->VistaPelicula->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"VistaPelicula.BackgroundImage")));
			   this->VistaPelicula->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->VistaPelicula->Controls->Add(this->SalirVista);
			   this->VistaPelicula->Controls->Add(this->CalificacionP);
			   this->VistaPelicula->Controls->Add(this->VistasTotalesP);
			   this->VistaPelicula->Controls->Add(this->SinopsisP);
			   this->VistaPelicula->Controls->Add(this->CategoriaP);
			   this->VistaPelicula->Controls->Add(this->ImgPelicula);
			   this->VistaPelicula->Controls->Add(this->TituloPelicula);
			   this->VistaPelicula->Enabled = false;
			   this->VistaPelicula->Location = System::Drawing::Point(3, 0);
			   this->VistaPelicula->Name = L"VistaPelicula";
			   this->VistaPelicula->Size = System::Drawing::Size(1232, 762);
			   this->VistaPelicula->TabIndex = 34;
			   this->VistaPelicula->Visible = false;
			   // 
			   // SalirVista
			   // 
			   this->SalirVista->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SalirVista.BackgroundImage")));
			   this->SalirVista->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->SalirVista->Cursor = System::Windows::Forms::Cursors::Default;
			   this->SalirVista->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			   this->SalirVista->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			   this->SalirVista->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->SalirVista->Location = System::Drawing::Point(9, 3);
			   this->SalirVista->Name = L"SalirVista";
			   this->SalirVista->Size = System::Drawing::Size(171, 59);
			   this->SalirVista->TabIndex = 6;
			   this->SalirVista->UseVisualStyleBackColor = true;
			   this->SalirVista->Click += gcnew System::EventHandler(this, &Programa::SalirVista_Click);
			   // 
			   // CalificacionP
			   // 
			   this->CalificacionP->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 21, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->CalificacionP->ForeColor = System::Drawing::Color::Green;
			   this->CalificacionP->Location = System::Drawing::Point(186, 456);
			   this->CalificacionP->Name = L"CalificacionP";
			   this->CalificacionP->Size = System::Drawing::Size(146, 36);
			   this->CalificacionP->TabIndex = 5;
			   this->CalificacionP->Text = L"8,89 ";
			   this->CalificacionP->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // VistasTotalesP
			   // 
			   this->VistasTotalesP->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->VistasTotalesP->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->VistasTotalesP->Location = System::Drawing::Point(466, 419);
			   this->VistasTotalesP->Name = L"VistasTotalesP";
			   this->VistasTotalesP->Size = System::Drawing::Size(146, 31);
			   this->VistasTotalesP->TabIndex = 4;
			   this->VistasTotalesP->Text = L"1.5K";
			   this->VistasTotalesP->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // SinopsisP
			   // 
			   this->SinopsisP->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->SinopsisP->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->SinopsisP->Location = System::Drawing::Point(466, 247);
			   this->SinopsisP->Name = L"SinopsisP";
			   this->SinopsisP->Size = System::Drawing::Size(510, 138);
			   this->SinopsisP->TabIndex = 3;
			   this->SinopsisP->Text = L"Titulo de Pelicula Default Titulo de Pelicula Default Titulo de Pelicula Default "
				   L"Titulo de Pelicula Default Titulo de Pelicula Default";
			   this->SinopsisP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   // 
			   // CategoriaP
			   // 
			   this->CategoriaP->Cursor = System::Windows::Forms::Cursors::Default;
			   this->CategoriaP->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 21, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->CategoriaP->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->CategoriaP->Location = System::Drawing::Point(444, 157);
			   this->CategoriaP->Name = L"CategoriaP";
			   this->CategoriaP->Size = System::Drawing::Size(510, 55);
			   this->CategoriaP->TabIndex = 2;
			   this->CategoriaP->Text = L"Accion , Drama";
			   this->CategoriaP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   // 
			   // ImgPelicula
			   // 
			   this->ImgPelicula->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ImgPelicula.BackgroundImage")));
			   this->ImgPelicula->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ImgPelicula->Location = System::Drawing::Point(145, 170);
			   this->ImgPelicula->Name = L"ImgPelicula";
			   this->ImgPelicula->Size = System::Drawing::Size(220, 257);
			   this->ImgPelicula->TabIndex = 1;
			   this->ImgPelicula->TabStop = false;
			   // 
			   // TituloPelicula
			   // 
			   this->TituloPelicula->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TituloPelicula->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->TituloPelicula->Location = System::Drawing::Point(364, 44);
			   this->TituloPelicula->Name = L"TituloPelicula";
			   this->TituloPelicula->Size = System::Drawing::Size(510, 55);
			   this->TituloPelicula->TabIndex = 0;
			   this->TituloPelicula->Text = L"Titulo de Pelicula Default";
			   this->TituloPelicula->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // Programa
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::DarkOrange;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1234, 761);
			   this->Controls->Add(this->VistaPelicula);
			   this->Controls->Add(this->TopAlfabetico);
			   this->Controls->Add(this->TopPVistas);
			   this->Controls->Add(this->TopPCalificadas);
			   this->Controls->Add(this->L3);
			   this->Controls->Add(this->L2);
			   this->Controls->Add(this->L1);
			   this->Controls->Add(this->R3);
			   this->Controls->Add(this->R2);
			   this->Controls->Add(this->R1);
			   this->Controls->Add(this->P20);
			   this->Controls->Add(this->P13);
			   this->Controls->Add(this->P19);
			   this->Controls->Add(this->P18);
			   this->Controls->Add(this->P6);
			   this->Controls->Add(this->P17);
			   this->Controls->Add(this->P12);
			   this->Controls->Add(this->P16);
			   this->Controls->Add(this->P5);
			   this->Controls->Add(this->P21);
			   this->Controls->Add(this->P11);
			   this->Controls->Add(this->P15);
			   this->Controls->Add(this->P4);
			   this->Controls->Add(this->P10);
			   this->Controls->Add(this->P9);
			   this->Controls->Add(this->P3);
			   this->Controls->Add(this->P14);
			   this->Controls->Add(this->P2);
			   this->Controls->Add(this->P8);
			   this->Controls->Add(this->P1);
			   this->Controls->Add(this->P7);
			   this->Controls->Add(this->ClaveUsuario);
			   this->Controls->Add(this->IDUsuario);
			   this->Controls->Add(this->BotonRegirtar);
			   this->Controls->Add(this->BotonIniciarSesion);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"Programa";
			   this->Text = L"Programa";
			   this->Load += gcnew System::EventHandler(this, &Programa::Programa_Load);
			   this->P7->ResumeLayout(false);
			   this->P2->ResumeLayout(false);
			   this->P1->ResumeLayout(false);
			   this->P3->ResumeLayout(false);
			   this->P4->ResumeLayout(false);
			   this->P5->ResumeLayout(false);
			   this->P6->ResumeLayout(false);
			   this->P13->ResumeLayout(false);
			   this->P12->ResumeLayout(false);
			   this->P11->ResumeLayout(false);
			   this->P10->ResumeLayout(false);
			   this->P9->ResumeLayout(false);
			   this->P14->ResumeLayout(false);
			   this->P8->ResumeLayout(false);
			   this->P20->ResumeLayout(false);
			   this->P19->ResumeLayout(false);
			   this->P18->ResumeLayout(false);
			   this->P17->ResumeLayout(false);
			   this->P16->ResumeLayout(false);
			   this->P21->ResumeLayout(false);
			   this->P15->ResumeLayout(false);
			   this->VistaPelicula->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImgPelicula))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   void LimpiarElementosInicio() {
			   this->SuspendLayout();

			   this->BotonIniciarSesion->Visible = false;
			   this->BotonIniciarSesion->Enabled = false;
			   this->BotonRegirtar->Visible = false;
			   this->BotonRegirtar->Enabled = false;
			   this->IDUsuario->Visible = false;
			   this->IDUsuario->Enabled = false;
			   this->ClaveUsuario->Visible = false;
			   this->ClaveUsuario->Enabled = false;

			   this->BackgroundImage = nullptr;

			   this->TopAlfabetico->Visible = true;  this->TopAlfabetico->Enabled = true;
			   this->TopPVistas->Visible = true;    this->TopPVistas->Enabled = true;
			   this->TopPCalificadas->Visible = true; this->TopPCalificadas->Enabled = true;

			   this->P1->Visible = true;  this->P1->Enabled = true;
			   this->P2->Visible = true;  this->P2->Enabled = true;
			   this->P3->Visible = true;  this->P3->Enabled = true;
			   this->P4->Visible = true;  this->P4->Enabled = true;
			   this->P5->Visible = true;  this->P5->Enabled = true;
			   this->P6->Visible = true;  this->P6->Enabled = true;
			   this->P7->Visible = true;  this->P7->Enabled = true;
			   this->L1->Visible = true;  this->L1->Enabled = true;
			   this->R1->Visible = true;  this->R1->Enabled = true;

			   this->P8->Visible = true;  this->P8->Enabled = true;
			   this->P9->Visible = true;  this->P9->Enabled = true;
			   this->P10->Visible = true; this->P10->Enabled = true;
			   this->P11->Visible = true; this->P11->Enabled = true;
			   this->P12->Visible = true; this->P12->Enabled = true;
			   this->P13->Visible = true; this->P13->Enabled = true;
			   this->P14->Visible = true; this->P14->Enabled = true;
			   this->L2->Visible = true;  this->L2->Enabled = true;
			   this->R2->Visible = true;  this->R2->Enabled = true;

			   this->P15->Visible = true; this->P15->Enabled = true;
			   this->P16->Visible = true; this->P16->Enabled = true;
			   this->P17->Visible = true; this->P17->Enabled = true;
			   this->P18->Visible = true; this->P18->Enabled = true;
			   this->P19->Visible = true; this->P19->Enabled = true;
			   this->P20->Visible = true; this->P20->Enabled = true;
			   this->P21->Visible = true; this->P21->Enabled = true;
			   this->L3->Visible = true;  this->L3->Enabled = true;
			   this->R3->Visible = true;  this->R3->Enabled = true;

			   this->ActualizarFilaMasVistos();

			   mostrarCatalogo = true;

			   this->ResumeLayout(false);
			   this->Refresh();
		   }

		   void MostrarDetallePelicula(Pelicula* p) {
			   if (p == nullptr) return;

			   this->peliculaActualEnVista = p;

			   this->TituloPelicula->Text = gcnew String(p->getNombre().c_str());
			   this->SinopsisP->Text = gcnew String(p->getSinopsis().c_str());

			   int vistas = p->getVistas();
			   String^ textoVistas;

			   if (vistas >= 1000000) {
				   textoVistas = (vistas / 1000000.0).ToString("F1") + "M";
			   }
			   else if (vistas >= 1000) {
				   textoVistas = (vistas / 1000.0).ToString("F1") + "K";
			   }
			   else {
				   textoVistas = vistas.ToString();
			   }

			   this->VistasTotalesP->Text = textoVistas;

			   String^ cadenaCategorias = "";
			   std::vector<std::string> cats = p->getCategorias();
			   for (size_t i = 0; i < cats.size(); ++i) {
				   cadenaCategorias += gcnew String(cats[i].c_str());
				   if (i < cats.size() - 1) cadenaCategorias += " | ";
			   }
			   this->CategoriaP->Text = cadenaCategorias;

			   float nota = p->getCalificacion();
			   this->CalificacionP->Text = nota.ToString("F1") + " / 5.0";

			   if (nota >= 4.5f) {
				   this->CalificacionP->ForeColor = System::Drawing::Color::LimeGreen;  // Verde brillante (Excelente)
			   }
			   else if (nota >= 3.0f) {
				   this->CalificacionP->ForeColor = System::Drawing::Color::Gold;       // Amarillo/Dorado (Aceptable)
			   }
			   else {
				   this->CalificacionP->ForeColor = System::Drawing::Color::OrangeRed;  // Naranja/Rojo (Baja calificacion)
			   }

			   try {
				   String^ rutaImg = gcnew String(p->getIdImagen().c_str()) + ".png";
				   if (System::IO::File::Exists(rutaImg)) {
					   this->ImgPelicula->Image = System::Drawing::Image::FromFile(rutaImg);
				   }
			   }
			   catch (Exception^) {

			   }

			   this->VistaPelicula->Visible = true;
			   this->VistaPelicula->Enabled = true;
			   this->VistaPelicula->BringToFront();
		   }

		   void ActualizarFilaMasVistos() {
			   // Agruparlos para un trabajo mas limpio
			   cli::array<System::Windows::Forms::Button^>^ botonesFila2 = {
				   B8, B9, B10, B11, B12, B13, B14
			   };

			   for (int i = 0; i < 7; ++i) {
				   Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(i);

				   if (p != nullptr) {
					   botonesFila2[i]->Parent->Visible = true;
				   }
				   else {
				   }
			   }
		   }

	private: System::Void Programa_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void BotonIniciarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = IDUsuario->Text;
		String^ clave = ClaveUsuario->Text;

		try {
			if (id->Trim()->Length == 0 || clave->Trim()->Length == 0) {
				MessageBox::Show("Campos vacios");
				return;
			}

			bool accesoConcedido = controlador->autenticarUsuario(id, clave);

			if (accesoConcedido) {
				this->LimpiarElementosInicio();
			}
			else {
				MessageBox::Show("Credenciales incorrectas");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en el inicio de sesion: " + ex->Message);
		}
	}

	private: System::Void BotonRegirtar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = IDUsuario->Text;
		String^ clave = ClaveUsuario->Text;

		try {
			if (id->Trim()->Length == 0 || clave->Trim()->Length == 0) {
				MessageBox::Show("Campos vacios");
				return;
			}

			bool registroExitoso = controlador->agregarUsuario(id, clave);

			if (registroExitoso) {
				MessageBox::Show("Usuario creado");
				IDUsuario->Clear();
				ClaveUsuario->Clear();
			}
			else {
				MessageBox::Show("El ID ya existe o es invalido");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en el registro: " + ex->Message);
		}
	}

		   // Manejador del espacio de dibujado principal del sistema
	private: System::Void Programa_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (!mostrarCatalogo) return;

		Graphics^ g = e->Graphics;

		try {
			if (imagenFondoCatalogo != nullptr) {
				g->DrawImage(imagenFondoCatalogo, this->ClientRectangle);


			}
		}
		catch (Exception^ ex) {
		}
	}
	private: System::Void SalirVista_Click(System::Object^ sender, System::EventArgs^ e) {
		this->VistaPelicula->Visible = false;
		this->VistaPelicula->Enabled = false;

		this->peliculaActualEnVista = nullptr;

		this->Refresh();
	}


		   //Vista de Pelicula mas vistos de la segunda fila (aun no completo)
	private: System::Void B8_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(0);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}
	private: System::Void B9_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(1);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}
	private: System::Void B10_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(2);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}
	private: System::Void B11_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(3);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}
	private: System::Void B12_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(4);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}
	private: System::Void B13_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(5);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}
	private: System::Void B14_Click(System::Object^ sender, System::EventArgs^ e) {
		Pelicula* p = controlador->ObtenerPeliculaFilaMasVistos(6);
		if (p != nullptr) {
			controlador->RegistrarVisualizacion(p);
			this->MostrarDetallePelicula(p);
		}
	}

		   // Cambios de pivote segun la direccio
	private: System::Void R1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void R2_Click(System::Object^ sender, System::EventArgs^ e) {
		controlador->AvanzarCarruselMasVistos();
		this->ActualizarFilaMasVistos();
	}

	private: System::Void L1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void L2_Click(System::Object^ sender, System::EventArgs^ e) {
		controlador->RetrocederCarruselMasVistos();
		this->ActualizarFilaMasVistos();
	}
	};
}