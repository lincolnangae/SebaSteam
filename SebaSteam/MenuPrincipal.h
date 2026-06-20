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
		MenuPrincipal(ControladoraPrincipal^idk)
		{
			InitializeComponent();
			driver = idk;
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
		ControladoraPrincipal^ driver;
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
	private: System::Windows::Forms::Label^ TxtF2;

	private: System::Windows::Forms::Label^ TxtF3;








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
			this->R_1 = (gcnew System::Windows::Forms::Button());
			this->R_2 = (gcnew System::Windows::Forms::Button());
			this->L_2 = (gcnew System::Windows::Forms::Button());
			this->L_1 = (gcnew System::Windows::Forms::Button());
			this->L_3 = (gcnew System::Windows::Forms::Button());
			this->R__3 = (gcnew System::Windows::Forms::Button());
			this->TxtFila1 = (gcnew System::Windows::Forms::Label());
			this->F1_1 = (gcnew System::Windows::Forms::Panel());
			this->F1_2 = (gcnew System::Windows::Forms::Panel());
			this->F1_3 = (gcnew System::Windows::Forms::Panel());
			this->F1_4 = (gcnew System::Windows::Forms::Panel());
			this->F1_5 = (gcnew System::Windows::Forms::Panel());
			this->F1_6 = (gcnew System::Windows::Forms::Panel());
			this->F2_6 = (gcnew System::Windows::Forms::Panel());
			this->F2_5 = (gcnew System::Windows::Forms::Panel());
			this->F2_4 = (gcnew System::Windows::Forms::Panel());
			this->F2_3 = (gcnew System::Windows::Forms::Panel());
			this->F2_2 = (gcnew System::Windows::Forms::Panel());
			this->F2_1 = (gcnew System::Windows::Forms::Panel());
			this->F3_6 = (gcnew System::Windows::Forms::Panel());
			this->F3_5 = (gcnew System::Windows::Forms::Panel());
			this->F3_4 = (gcnew System::Windows::Forms::Panel());
			this->F3_3 = (gcnew System::Windows::Forms::Panel());
			this->F3_2 = (gcnew System::Windows::Forms::Panel());
			this->F3_1 = (gcnew System::Windows::Forms::Panel());
			this->TxtF2 = (gcnew System::Windows::Forms::Label());
			this->TxtF3 = (gcnew System::Windows::Forms::Label());
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
			// R_1
			// 
			this->R_1->BackColor = System::Drawing::Color::Transparent;
			this->R_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"R_1.BackgroundImage")));
			this->R_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->R_1->FlatAppearance->BorderSize = 0;
			this->R_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->R_1->ForeColor = System::Drawing::Color::Transparent;
			this->R_1->Location = System::Drawing::Point(1241, 200);
			this->R_1->Name = L"R_1";
			this->R_1->Size = System::Drawing::Size(52, 96);
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
			this->R_2->Location = System::Drawing::Point(1241, 463);
			this->R_2->Name = L"R_2";
			this->R_2->Size = System::Drawing::Size(52, 96);
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
			this->L_2->Location = System::Drawing::Point(12, 463);
			this->L_2->Name = L"L_2";
			this->L_2->Size = System::Drawing::Size(52, 96);
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
			this->L_1->Location = System::Drawing::Point(12, 200);
			this->L_1->Name = L"L_1";
			this->L_1->Size = System::Drawing::Size(52, 96);
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
			this->L_3->Location = System::Drawing::Point(12, 738);
			this->L_3->Name = L"L_3";
			this->L_3->Size = System::Drawing::Size(52, 96);
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
			this->R__3->Location = System::Drawing::Point(1241, 738);
			this->R__3->Name = L"R__3";
			this->R__3->Size = System::Drawing::Size(52, 96);
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
			this->TxtFila1->Location = System::Drawing::Point(7, 130);
			this->TxtFila1->Name = L"TxtFila1";
			this->TxtFila1->Size = System::Drawing::Size(270, 25);
			this->TxtFila1->TabIndex = 14;
			this->TxtFila1->Text = L"Recientemente agregados:";
			// 
			// F1_1
			// 
			this->F1_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F1_1.BackgroundImage")));
			this->F1_1->Location = System::Drawing::Point(79, 158);
			this->F1_1->Name = L"F1_1";
			this->F1_1->Size = System::Drawing::Size(170, 170);
			this->F1_1->TabIndex = 15;
			// 
			// F1_2
			// 
			this->F1_2->Location = System::Drawing::Point(274, 158);
			this->F1_2->Name = L"F1_2";
			this->F1_2->Size = System::Drawing::Size(170, 170);
			this->F1_2->TabIndex = 16;
			// 
			// F1_3
			// 
			this->F1_3->Location = System::Drawing::Point(475, 158);
			this->F1_3->Name = L"F1_3";
			this->F1_3->Size = System::Drawing::Size(170, 170);
			this->F1_3->TabIndex = 17;
			// 
			// F1_4
			// 
			this->F1_4->Location = System::Drawing::Point(673, 158);
			this->F1_4->Name = L"F1_4";
			this->F1_4->Size = System::Drawing::Size(170, 170);
			this->F1_4->TabIndex = 18;
			// 
			// F1_5
			// 
			this->F1_5->Location = System::Drawing::Point(868, 158);
			this->F1_5->Name = L"F1_5";
			this->F1_5->Size = System::Drawing::Size(170, 170);
			this->F1_5->TabIndex = 19;
			// 
			// F1_6
			// 
			this->F1_6->Location = System::Drawing::Point(1060, 158);
			this->F1_6->Name = L"F1_6";
			this->F1_6->Size = System::Drawing::Size(170, 170);
			this->F1_6->TabIndex = 20;
			// 
			// F2_6
			// 
			this->F2_6->Location = System::Drawing::Point(1060, 426);
			this->F2_6->Name = L"F2_6";
			this->F2_6->Size = System::Drawing::Size(170, 170);
			this->F2_6->TabIndex = 26;
			// 
			// F2_5
			// 
			this->F2_5->Location = System::Drawing::Point(868, 426);
			this->F2_5->Name = L"F2_5";
			this->F2_5->Size = System::Drawing::Size(170, 170);
			this->F2_5->TabIndex = 25;
			// 
			// F2_4
			// 
			this->F2_4->Location = System::Drawing::Point(673, 426);
			this->F2_4->Name = L"F2_4";
			this->F2_4->Size = System::Drawing::Size(170, 170);
			this->F2_4->TabIndex = 24;
			// 
			// F2_3
			// 
			this->F2_3->Location = System::Drawing::Point(475, 426);
			this->F2_3->Name = L"F2_3";
			this->F2_3->Size = System::Drawing::Size(170, 170);
			this->F2_3->TabIndex = 23;
			// 
			// F2_2
			// 
			this->F2_2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->F2_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->F2_2->CausesValidation = false;
			this->F2_2->Location = System::Drawing::Point(274, 426);
			this->F2_2->Name = L"F2_2";
			this->F2_2->Size = System::Drawing::Size(170, 170);
			this->F2_2->TabIndex = 22;
			// 
			// F2_1
			// 
			this->F2_1->Location = System::Drawing::Point(79, 426);
			this->F2_1->Name = L"F2_1";
			this->F2_1->Size = System::Drawing::Size(170, 170);
			this->F2_1->TabIndex = 21;
			// 
			// F3_6
			// 
			this->F3_6->Location = System::Drawing::Point(1060, 697);
			this->F3_6->Name = L"F3_6";
			this->F3_6->Size = System::Drawing::Size(170, 170);
			this->F3_6->TabIndex = 32;
			// 
			// F3_5
			// 
			this->F3_5->Location = System::Drawing::Point(868, 697);
			this->F3_5->Name = L"F3_5";
			this->F3_5->Size = System::Drawing::Size(170, 170);
			this->F3_5->TabIndex = 31;
			// 
			// F3_4
			// 
			this->F3_4->Location = System::Drawing::Point(673, 697);
			this->F3_4->Name = L"F3_4";
			this->F3_4->Size = System::Drawing::Size(170, 170);
			this->F3_4->TabIndex = 30;
			// 
			// F3_3
			// 
			this->F3_3->Location = System::Drawing::Point(475, 697);
			this->F3_3->Name = L"F3_3";
			this->F3_3->Size = System::Drawing::Size(170, 170);
			this->F3_3->TabIndex = 29;
			// 
			// F3_2
			// 
			this->F3_2->Location = System::Drawing::Point(274, 697);
			this->F3_2->Name = L"F3_2";
			this->F3_2->Size = System::Drawing::Size(170, 170);
			this->F3_2->TabIndex = 28;
			// 
			// F3_1
			// 
			this->F3_1->Location = System::Drawing::Point(79, 697);
			this->F3_1->Name = L"F3_1";
			this->F3_1->Size = System::Drawing::Size(170, 170);
			this->F3_1->TabIndex = 27;
			// 
			// TxtF2
			// 
			this->TxtF2->AutoSize = true;
			this->TxtF2->BackColor = System::Drawing::Color::Transparent;
			this->TxtF2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtF2->ForeColor = System::Drawing::Color::Transparent;
			this->TxtF2->Location = System::Drawing::Point(7, 398);
			this->TxtF2->Name = L"TxtF2";
			this->TxtF2->Size = System::Drawing::Size(293, 25);
			this->TxtF2->TabIndex = 33;
			this->TxtF2->Text = L"Reproducidos recientemente:";
			// 
			// TxtF3
			// 
			this->TxtF3->AutoSize = true;
			this->TxtF3->BackColor = System::Drawing::Color::Transparent;
			this->TxtF3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtF3->ForeColor = System::Drawing::Color::Transparent;
			this->TxtF3->Location = System::Drawing::Point(7, 669);
			this->TxtF3->Name = L"TxtF3";
			this->TxtF3->Size = System::Drawing::Size(168, 25);
			this->TxtF3->TabIndex = 34;
			this->TxtF3->Text = L"Recomendados:";
			// 
			// MenuPrincipal
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 900);
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
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
	System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	//BOTONES IZQUIERDOS
	System::Void L_1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void L_2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void L_3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	//Botones Derechos
	System::Void R_1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void R_2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void R__3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	
};
}
