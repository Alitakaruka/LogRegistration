#pragma once
enum LevelLogRegistration
{
	Error,
	Warning,
	Info
};

 static class LogRegistration
{
public:
	static char* Write_log(char* stingMessage);

	static bool Write_log(const char* stingMessage, LevelLogRegistration level);

	static bool Write_log(const char* stingMessage, LevelLogRegistration level, const char* path);
};

