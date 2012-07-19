#pragma once

#include "app_cubic_spline/spline_manager.h"

namespace app_cubic_spline 
{

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


    private: System::Windows::Forms::ListBox^  SplineList;

    protected: 

    private:
        CSplineManager m_Splines;

    private: System::Windows::Forms::Label^  LabelSpline;

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
            this->SplineList = (gcnew System::Windows::Forms::ListBox());
            this->LabelSpline = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // panel_draw
            // 
            this->panel_draw->BackColor = System::Drawing::Color::White;
            this->panel_draw->Location = System::Drawing::Point(12, 12);
            this->panel_draw->Name = L"panel_draw";
            this->panel_draw->Size = System::Drawing::Size(617, 538);
            this->panel_draw->TabIndex = 0;
            this->panel_draw->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel_draw_MouseClick);
            // 
            // SplineList
            // 
            this->SplineList->FormattingEnabled = true;
            this->SplineList->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Spline 1", L"Spline 2", L"Spline 3"});
            this->SplineList->Location = System::Drawing::Point(635, 38);
            this->SplineList->Name = L"SplineList";
            this->SplineList->Size = System::Drawing::Size(137, 43);
            this->SplineList->TabIndex = 2;
            this->SplineList->DoubleClick += gcnew System::EventHandler(this, &Form1::SplineList_DoubleClick);
            // 
            // LabelSpline
            // 
            this->LabelSpline->AutoSize = true;
            this->LabelSpline->Location = System::Drawing::Point(636, 19);
            this->LabelSpline->Name = L"LabelSpline";
            this->LabelSpline->Size = System::Drawing::Size(44, 13);
            this->LabelSpline->TabIndex = 3;
            this->LabelSpline->Text = L"Splines:";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 562);
            this->Controls->Add(this->LabelSpline);
            this->Controls->Add(this->SplineList);
            this->Controls->Add(this->panel_draw);
            this->Name = L"Form1";
            this->Text = L"Kubische Spline Interpolation";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void Form1_Load_1(System::Object^  sender, System::EventArgs^  e) 
        {                 
        }

private: System::Void panel_draw_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
        {
            // -----------------------------------------------------------------------------
            // add click to instances (splines) selected in list
            // -----------------------------------------------------------------------------
            int SelectedIndex = SplineList->SelectedIndex;

            if (SelectedIndex != -1)
            {
                m_Splines.GetSpline(SelectedIndex)->AddPoint(e->X, e->Y);
            }
            
            // -----------------------------------------------------------------------------
            // redraw spline
            // -----------------------------------------------------------------------------
            DrawSpline();
        }
private: System::Void SplineList_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
            // -----------------------------------------------------------------------------
            // open dialog edit spline
            // -----------------------------------------------------------------------------

            
        }


    private:
        void DrawSpline()
        {
            // -----------------------------------------------------------------------------
            // draw point by point from spline
            // -----------------------------------------------------------------------------
            Graphics ^ Graphic = panel_draw->CreateGraphics();
            Pen ^ CurrentPen = gcnew Pen(Color::Red);

            Graphic->Clear(Color::White);

            for (int IndexOfSpline = 0; IndexOfSpline < CSplineManager::s_MAXSPLINES; ++IndexOfSpline)
            {
                if (IndexOfSpline == 1)
                {
                    CurrentPen->Color = Color::Green;
                }
                else if (IndexOfSpline == 2)
                {
                    CurrentPen->Color = Color::Blue;
                }

                // -----------------------------------------------------------------------------
                // draw points
                // -----------------------------------------------------------------------------
                std::vector<Core::Math::Float2*> Points = m_Splines.GetPoints(IndexOfSpline);

                int InsertedPoints = Points.size();

                for (int IndexOfPoint = 0; IndexOfPoint < InsertedPoints; ++IndexOfPoint)
                {
                    Core::Math::Float2* ActualPoint = Points[IndexOfPoint];
                    Point p1((*ActualPoint)[0], (*ActualPoint)[1]);

                    Graphic->DrawEllipse(CurrentPen, p1.X - 3, p1.Y - 3, 6, 6);
                }

                // -----------------------------------------------------------------------------
                // draw interpolation
                // -----------------------------------------------------------------------------
                CSpline^ CurrentSpline = m_Splines.GetSpline(IndexOfSpline);

                int MinX = CurrentSpline->MinX();
                int MaxX = CurrentSpline->MaxX();

                Point LastPoint(MinX, CurrentSpline->Interpolate(MinX));
                Point NextPoint(0, 0);

                for (int xPosition = MinX; xPosition < MaxX; ++xPosition)
                {
                    NextPoint.X = xPosition;
                    NextPoint.Y = CurrentSpline->Interpolate(xPosition);

                    Graphic->DrawLine(CurrentPen, LastPoint, NextPoint);

                    LastPoint = NextPoint;
                }

                delete CurrentSpline;
            }

            delete Graphic;
            delete CurrentPen;
        }
};
}

