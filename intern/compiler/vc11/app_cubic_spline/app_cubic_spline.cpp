// app_cubic_spline.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Form1.h"

using namespace app_cubic_spline;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausf�hren
	Application::Run(gcnew Form1());
	return 0;
}
