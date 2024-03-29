// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ParseURL.h"

void PrintUserHelp(std::ostream &output);
void HandleURL(std::ostream &output, URL &url);
void HandleUserCommand(std::istream &input, std::ostream &output);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	HandleUserCommand(std::cin, std::cout);

	return 0;
}

void PrintUserHelp(std::ostream &output)
{
	output << "Используйте: \n"
		"протокол://хост[:порт][/документ],\n"
		"где протокол – http, https или ftp (в любом регистре),\n"
		"порт – положительное число от 1 до 65535\n"
		"хост – непустая строка\n";
}

void HandleURL(std::ostream &output, URL &url)
{
	output << "\n";

	if (ParseURL(url.urlStr, url.protocol, url.port, url.host, url.document))
	{
		PrintURLData(output, url);
	}
	else
	{
		output << "Невалидный URL.\n";
		PrintUserHelp(output);
	}

	output << "\n";
}

void HandleUserCommand(std::istream &input, std::ostream &output)
{
	URL url;

	while (ReadURL(input, url))
	{
		HandleURL(output, url);
	}
}
