#pragma once

#include "core/cubic_spline.h"
#include "core/vector2.h"

namespace app_cubic_spline {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Panel^  panel_draw;
    protected: 

    private: System::Windows::Forms::Button^  bInterpolate;

    protected: 

    private:
        Core::Math::CCubicSpline* m_pCubicSpline;

    private:
        void DrawSpline()
        {
            // -----------------------------------------------------------------------------
            // draw point by point from spline
            // -----------------------------------------------------------------------------
        }

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
            this->panel_draw = (gcnew System::Windows::Forms::Panel());
            this->bInterpolate = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // panel_draw
            // 
            this->panel_draw->BackColor = System::Drawing::Color::White;
            this->panel_draw->Location = System::Drawing::Point(12, 12);
            this->panel_draw->Name = L"panel_draw";
            this->panel_draw->Size = System::Drawing::Size(617, 538);
            this->panel_draw->TabIndex = 0;
            this->panel_draw->Click += gcnew System::EventHandler(this, &Form1::panel_draw_Click);
            this->panel_draw->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel_draw_Paint);
            this->panel_draw->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel_draw_MouseClick);
            // 
            // bInterpolate
            // 
            this->bInterpolate->Location = System::Drawing::Point(635, 12);
            this->bInterpolate->Name = L"bInterpolate";
            this->bInterpolate->Size = System::Drawing::Size(137, 23);
            this->bInterpolate->TabIndex = 1;
            this->bInterpolate->Text = L"Interpolate";
            this->bInterpolate->UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 562);
            this->Controls->Add(this->bInterpolate);
            this->Controls->Add(this->panel_draw);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
                 m_pCubicSpline = new Core::Math::CCubicSpline();
             }
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
             }
    private: System::Void panel_draw_Click(System::Object^  sender, System::EventArgs^  e) {
             }
    private: System::Void panel_draw_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
                 // -----------------------------------------------------------------------------
                 // add click to panel and spline
                 // -----------------------------------------------------------------------------
                 Core::Math::Float2 ClickPoint;

                 ClickPoint[0] = e->Location.X;
                 ClickPoint[1] = e->Location.Y;

                 //m_pCubicSpline->AddPoint(ClickPoint);


                 // -----------------------------------------------------------------------------
                 // redraw spline
                 // -----------------------------------------------------------------------------
                 DrawSpline();
             }
private: System::Void panel_draw_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
         }
};
}

