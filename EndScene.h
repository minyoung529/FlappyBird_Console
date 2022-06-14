﻿#pragma once
#include"Scene.h"
#include"Core.h"

class EndScene : public Scene
{
public:
	EndScene();
	virtual ~EndScene();

public:
	virtual void Init();
	virtual void Update();
	virtual void ReleaseScene();

	void PrintWinText();
	void PrintFailText();
	void PrintAllText();

	wchar_t winText[6][129]
	{
		L" ██████╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗  █████╗ ████████╗██╗   ██╗██╗      █████╗ ████████╗██╗ ██████╗ ███╗   ██╗███████╗██╗",
		L"██╔════╝██╔═══██╗████╗  ██║██╔════╝ ██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██║     ██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝██║",
		L"██║     ██║   ██║██╔██╗ ██║██║  ███╗██████╔╝███████║   ██║   ██║   ██║██║     ███████║   ██║   ██║██║   ██║██╔██╗ ██║███████╗██║",
		L"██║     ██║   ██║██║╚██╗██║██║   ██║██╔══██╗██╔══██║   ██║   ██║   ██║██║     ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║╚════██║╚═╝",
		L"╚██████╗╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║██║  ██║   ██║   ╚██████╔╝███████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║███████║██╗",
		L" ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝"
	};

	wchar_t failText[10][45]
	{
		L"  █████▒▄▄▄       ██▓ ██▓                   ",
		L"▓██   ▒▒████▄    ▓██▒▓██▒                   ",
		L"▒████ ░▒██  ▀█▄  ▒██▒▒██░                   ",
		L"░▓█▒  ░░██▄▄▄▄██ ░██░▒██░                   ",
		L"░▒█░    ▓█   ▓██▒░██░░██████▒ ██▓  ██▓  ██▓ ",
		L" ▒ ░    ▒▒   ▓▒█░░▓  ░ ▒░▓  ░ ▒▓▒  ▒▓▒  ▒▓▒ ",
		L" ░       ▒   ▒▒ ░ ▒ ░░ ░ ▒  ░ ░▒   ░▒   ░▒  ",
		L" ░ ░     ░   ▒    ▒ ░  ░ ░    ░    ░    ░   ",
		L"             ░  ░ ░      ░  ░  ░    ░    ░  ",
		L"                               ░    ░    ░  "
	};
};