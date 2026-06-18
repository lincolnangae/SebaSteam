#pragma once
#include"Controlador.h"
namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			
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
	protected:


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->TopVButton = (gcnew System::Windows::Forms::Button());
			this->MejorCalifButton = (gcnew System::Windows::Forms::Button());
			this->FiltrarBu = (gcnew System::Windows::Forms::Button());
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
			this->TopVButton->Location = System::Drawing::Point(720, 19);
			this->TopVButton->Name = L"TopVButton";
			this->TopVButton->Size = System::Drawing::Size(185, 46);
			this->TopVButton->TabIndex = 0;
			this->TopVButton->Text = L"TOP VISTOS";
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
			this->MejorCalifButton->Location = System::Drawing::Point(453, 19);
			this->MejorCalifButton->Name = L"MejorCalifButton";
			this->MejorCalifButton->Size = System::Drawing::Size(192, 49);
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
			this->FiltrarBu->Location = System::Drawing::Point(993, 19);
			this->FiltrarBu->Name = L"FiltrarBu";
			this->FiltrarBu->Size = System::Drawing::Size(186, 46);
			this->FiltrarBu->TabIndex = 2;
			this->FiltrarBu->Text = L"A - Z";
			this->FiltrarBu->UseVisualStyleBackColor = false;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 900);
			this->ControlBox = false;
			this->Controls->Add(this->FiltrarBu);
			this->Controls->Add(this->MejorCalifButton);
			this->Controls->Add(this->TopVButton);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
