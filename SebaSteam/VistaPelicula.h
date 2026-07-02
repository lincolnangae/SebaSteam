#pragma once
#include "Pelicula.h"
#include <msclr/marshal_cppstd.h>
#include"Calificar.h"
namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class VistaPelicula : public System::Windows::Forms::Form
	{
	public:
		VistaPelicula(Pelicula* peli)
		{
			InitializeComponent();
			CargarDatos(peli);
		}

	protected:
		~VistaPelicula()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ MostrarPelicula;
	protected:

	protected:
	private: System::Windows::Forms::Button^ SalirVista;
	private: System::Windows::Forms::Label^ CalificacionP;
	private: System::Windows::Forms::Label^ VistasTotalesP;
	private: System::Windows::Forms::Label^ SinopsisP;
	private: System::Windows::Forms::Label^ CategoriaP;
	private: System::Windows::Forms::PictureBox^ ImgPelicula;
	private: System::Windows::Forms::Label^ TituloPelicula;
	private: System::Windows::Forms::Button^ Calificar_boton;


	private: System::Windows::Forms::Button^ Reproducir;
	private: System::Windows::Forms::Button^ VerMasTarde;


	private:
		System::ComponentModel::Container^ components;

		// Llena los controles con los datos reales de la pelicula seleccionada
		void CargarDatos(Pelicula* peli)
		{
			if (peli == nullptr) return;
			peliGuardada = peli;
			TituloPelicula->Text = marshal_as<String^>(peli->getNombre());
			SinopsisP->Text = marshal_as<String^>(peli->getSinopsis());
			CalificacionP->Text = peli->getCalificacion().ToString("0.0000");
			//Colores
			if (peli->getCalificacion() < 5.0) CalificacionP->ForeColor = Color::Red;
			else if (peli->getCalificacion() < 7.0) CalificacionP->ForeColor = Color::Orange;
			else CalificacionP->ForeColor = Color::Green;
			VistasTotalesP->Text = peli->getVistas().ToString();
			
			// Las categorias vienen como vector<string>, se unen con coma
			std::vector<std::string> cats = peli->getCategorias();
			String^ categorias = "";
			for (size_t i = 0; i < cats.size(); i++)
			{
				categorias += marshal_as<String^>(cats[i]);
				if (i + 1 < cats.size()) categorias += ", ";
			}
			CategoriaP->Text = categorias;

			String^ ruta = marshal_as<String^>(peli->getIdImagen());
			try
			{
				if (System::IO::File::Exists(ruta))
				{
					ImgPelicula->BackgroundImage = Image::FromFile(ruta);
				}
			}
			catch (Exception^)
			{
				// Si falla la imagen se deja la que ya tenia por defecto
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VistaPelicula::typeid));
			this->MostrarPelicula = (gcnew System::Windows::Forms::Panel());
			this->Reproducir = (gcnew System::Windows::Forms::Button());
			this->VerMasTarde = (gcnew System::Windows::Forms::Button());
			this->Calificar_boton = (gcnew System::Windows::Forms::Button());
			this->SalirVista = (gcnew System::Windows::Forms::Button());
			this->CalificacionP = (gcnew System::Windows::Forms::Label());
			this->VistasTotalesP = (gcnew System::Windows::Forms::Label());
			this->SinopsisP = (gcnew System::Windows::Forms::Label());
			this->CategoriaP = (gcnew System::Windows::Forms::Label());
			this->ImgPelicula = (gcnew System::Windows::Forms::PictureBox());
			this->TituloPelicula = (gcnew System::Windows::Forms::Label());
			this->MostrarPelicula->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImgPelicula))->BeginInit();
			this->SuspendLayout();
			// 
			// MostrarPelicula
			// 
			this->MostrarPelicula->BackColor = System::Drawing::Color::Transparent;
			this->MostrarPelicula->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MostrarPelicula.BackgroundImage")));
			this->MostrarPelicula->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MostrarPelicula->Controls->Add(this->Reproducir);
			this->MostrarPelicula->Controls->Add(this->VerMasTarde);
			this->MostrarPelicula->Controls->Add(this->Calificar_boton);
			this->MostrarPelicula->Controls->Add(this->SalirVista);
			this->MostrarPelicula->Controls->Add(this->CalificacionP);
			this->MostrarPelicula->Controls->Add(this->VistasTotalesP);
			this->MostrarPelicula->Controls->Add(this->SinopsisP);
			this->MostrarPelicula->Controls->Add(this->CategoriaP);
			this->MostrarPelicula->Controls->Add(this->ImgPelicula);
			this->MostrarPelicula->Controls->Add(this->TituloPelicula);
			this->MostrarPelicula->Location = System::Drawing::Point(0, 0);
			this->MostrarPelicula->Margin = System::Windows::Forms::Padding(4);
			this->MostrarPelicula->Name = L"MostrarPelicula";
			this->MostrarPelicula->Size = System::Drawing::Size(1296, 796);
			this->MostrarPelicula->TabIndex = 34;
			this->MostrarPelicula->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VistaPelicula::MostrarPelicula_Paint);
			// 
			// Reproducir
			// 
			this->Reproducir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Reproducir.BackgroundImage")));
			this->Reproducir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Reproducir->Location = System::Drawing::Point(893, 616);
			this->Reproducir->Name = L"Reproducir";
			this->Reproducir->Size = System::Drawing::Size(367, 93);
			this->Reproducir->TabIndex = 9;
			this->Reproducir->UseVisualStyleBackColor = true;
			this->Reproducir->Click += gcnew System::EventHandler(this, &VistaPelicula::Reproducir_Click);
			// 
			// VerMasTarde
			// 
			this->VerMasTarde->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"VerMasTarde.BackgroundImage")));
			this->VerMasTarde->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->VerMasTarde->Location = System::Drawing::Point(462, 616);
			this->VerMasTarde->Name = L"VerMasTarde";
			this->VerMasTarde->Size = System::Drawing::Size(367, 93);
			this->VerMasTarde->TabIndex = 8;
			this->VerMasTarde->UseVisualStyleBackColor = true;
			this->VerMasTarde->Click += gcnew System::EventHandler(this, &VistaPelicula::VerMasTarde_Click);
			// 
			// Calificar_boton
			// 
			this->Calificar_boton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Calificar_boton.BackgroundImage")));
			this->Calificar_boton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Calificar_boton->Location = System::Drawing::Point(27, 616);
			this->Calificar_boton->Name = L"Calificar_boton";
			this->Calificar_boton->Size = System::Drawing::Size(367, 93);
			this->Calificar_boton->TabIndex = 7;
			this->Calificar_boton->UseVisualStyleBackColor = true;
			this->Calificar_boton->Click += gcnew System::EventHandler(this, &VistaPelicula::Calificar_Click);
			// 
			// SalirVista
			// 
			this->SalirVista->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SalirVista.BackgroundImage")));
			this->SalirVista->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->SalirVista->Cursor = System::Windows::Forms::Cursors::Default;
			this->SalirVista->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->SalirVista->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->SalirVista->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SalirVista->Location = System::Drawing::Point(10, 4);
			this->SalirVista->Margin = System::Windows::Forms::Padding(4);
			this->SalirVista->Name = L"SalirVista";
			this->SalirVista->Size = System::Drawing::Size(130, 46);
			this->SalirVista->TabIndex = 6;
			this->SalirVista->UseVisualStyleBackColor = true;
			this->SalirVista->Click += gcnew System::EventHandler(this, &VistaPelicula::SalirVista_Click);
			// 
			// CalificacionP
			// 
			this->CalificacionP->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 21, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CalificacionP->ForeColor = System::Drawing::Color::Green;
			this->CalificacionP->Location = System::Drawing::Point(195, 474);
			this->CalificacionP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CalificacionP->Name = L"CalificacionP";
			this->CalificacionP->Size = System::Drawing::Size(155, 39);
			this->CalificacionP->TabIndex = 5;
			this->CalificacionP->Text = L"10,0000";
			this->CalificacionP->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VistasTotalesP
			// 
			this->VistasTotalesP->Font = (gcnew System::Drawing::Font(L"MS Reference Specialty", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VistasTotalesP->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->VistasTotalesP->Location = System::Drawing::Point(488, 436);
			this->VistasTotalesP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->VistasTotalesP->Name = L"VistasTotalesP";
			this->VistasTotalesP->Size = System::Drawing::Size(155, 34);
			this->VistasTotalesP->TabIndex = 4;
			this->VistasTotalesP->Text = L"1.5K";
			this->VistasTotalesP->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->VistasTotalesP->Click += gcnew System::EventHandler(this, &VistaPelicula::VistasTotalesP_Click);
			// 
			// SinopsisP
			// 
			this->SinopsisP->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SinopsisP->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->SinopsisP->Location = System::Drawing::Point(485, 258);
			this->SinopsisP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SinopsisP->Name = L"SinopsisP";
			this->SinopsisP->Size = System::Drawing::Size(542, 151);
			this->SinopsisP->TabIndex = 3;
			this->SinopsisP->Text = L"Titulo de Pelicula Default Titulo de Pelicula Default Titulo de Pelicula Default "
				L"Titulo de Pelicula Default Titulo de Pelicula Default";
			// 
			// CategoriaP
			// 
			this->CategoriaP->Cursor = System::Windows::Forms::Cursors::Default;
			this->CategoriaP->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CategoriaP->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->CategoriaP->Location = System::Drawing::Point(472, 171);
			this->CategoriaP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CategoriaP->Name = L"CategoriaP";
			this->CategoriaP->Size = System::Drawing::Size(542, 60);
			this->CategoriaP->TabIndex = 2;
			this->CategoriaP->Text = L"Accion , Drama";
			this->CategoriaP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ImgPelicula
			// 
			this->ImgPelicula->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ImgPelicula.BackgroundImage")));
			this->ImgPelicula->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ImgPelicula->Location = System::Drawing::Point(163, 180);
			this->ImgPelicula->Margin = System::Windows::Forms::Padding(4);
			this->ImgPelicula->Name = L"ImgPelicula";
			this->ImgPelicula->Size = System::Drawing::Size(218, 264);
			this->ImgPelicula->TabIndex = 1;
			this->ImgPelicula->TabStop = false;
			// 
			// TituloPelicula
			// 
			this->TituloPelicula->Font = (gcnew System::Drawing::Font(L"Stencil", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TituloPelicula->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->TituloPelicula->Location = System::Drawing::Point(224, 25);
			this->TituloPelicula->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->TituloPelicula->Name = L"TituloPelicula";
			this->TituloPelicula->Size = System::Drawing::Size(839, 126);
			this->TituloPelicula->TabIndex = 0;
			this->TituloPelicula->Text = L"Titulo de Pelicula Default";
			this->TituloPelicula->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->TituloPelicula->Click += gcnew System::EventHandler(this, &VistaPelicula::TituloPelicula_Click);
			// 
			// VistaPelicula
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1300, 800);
			this->ControlBox = false;
			this->Controls->Add(this->MostrarPelicula);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"VistaPelicula";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VistaPelicula";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VistaPelicula::VistaPelicula_Paint);
			this->MostrarPelicula->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImgPelicula))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		Pelicula* peliGuardada;
		System::Void SalirVista_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		// Dibuja un marco blanco delgado para diferenciar la ventana del escritorio
		System::Void VistaPelicula_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			Pen^ borde = gcnew Pen(Color::White, 4);
			e->Graphics->DrawRectangle(borde, 2, 2, this->ClientSize.Width - 4, this->ClientSize.Height - 4);
		}
	private: System::Void TituloPelicula_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	System::Void MostrarPelicula_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
private: System::Void VistasTotalesP_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   //Botones
	System::Void Calificar_Click(System::Object^ sender, System::EventArgs^ e) {
		Calificar^ calif = gcnew Calificar(peliGuardada);
		calif->StartPosition = FormStartPosition::CenterParent;
		int posX = this->Location.X + 292;
		int posY = this->Location.Y + 290;
		calif->Location = System::Drawing::Point(posX, posY);
		calif->TopMost = 1;
		calif->ShowDialog();
		if (calif->califcado) {
			CalificacionP->Text = peliGuardada->getCalificacion().ToString("0.0000");
		}
	}
	System::Void VerMasTarde_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	System::Void Reproducir_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Funcionalidad de reproducir no implementada en esta versión, si ves esto, agregar imagenes para la reproduccion cmo en next data y cmo hiciste pa q lo botones se vean asi d clean elipticas y no cn mancha blanca cmo ahora", "Reproducir", MessageBoxButtons::OK, MessageBoxIcon::Information);
		peliGuardada->incrementarVistas();
		VistasTotalesP->Text = peliGuardada->getVistas().ToString();
	}
};
}