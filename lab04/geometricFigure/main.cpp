// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCanvas.h"
#include "ShapeController.h"

void HandleCommand(std::istream& input, std::ostream& output, CShapeController& shapeCntrl)
{
	while (!input.eof() && !input.fail())
	{
		output << "> ";

		if (!shapeCntrl.HandleCommand())
		{
			output << "Unknown command" << "\n";
		}
	}
}

bool Execute(std::istream& input, std::ostream& output)
{
	try
	{
		CCanvas canvas;
		CShapeController shapeCntrl(input, output, canvas);

		HandleCommand(input, output, shapeCntrl);

		shapeCntrl.PrintShapeWithMinPerimeter();
		shapeCntrl.PrintShapeWithMaxArea();
		shapeCntrl.Draw();

		return true;
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	return false;
}

int main()
{
	return static_cast<int>(Execute(std::cin, std::cout));
}

