#define _CRT_SECURE_NO_WARNINGS

#include "LogRegistration.h"
#include <fstream>
#include<chrono>
#include <iostream>
#include <ctime>

namespace dateTime {
	char* splitDate(char* dateStr);
	char* NowDate() {
		auto ym = std::chrono::system_clock::now();
		auto nowDate = std::chrono::system_clock::to_time_t(ym);
		return splitDate(std::ctime(&nowDate));
	}
	char* splitDate(char* dateStr) {
		char* oldPtr = dateStr;
		while (true) {
			
			if (*dateStr == '\n' || *dateStr == '\0' ) {
				*dateStr = ' ';
				return oldPtr;
			}
			dateStr++;
		}
	}
}
char* LogRegistration::Write_log(char* stingMessage)
{
	char path[] = "Loger.txt";
	std::ofstream file;
	file.open(path, std::ios::app);
	if (file.is_open()) {
		char* nowDate = dateTime::NowDate();
		file << nowDate << "  :" << stingMessage << std::endl;
	}
	file.close();
	return path;
}

bool LogRegistration::Write_log(const char* stingMessage, LevelLogRegistration level)
{
	char path[] = "Loger.txt";
	char* nowDate = dateTime::NowDate();
	std::ofstream file;
	try {
		file.open(path, std::ios::app);
		if (file.is_open()) {
			
			if (level == LevelLogRegistration::Error) {
				file << nowDate << "  :" << "Eroor!:" << stingMessage << std::endl;
			}
			if (level == LevelLogRegistration::Info) {
				file << nowDate << "  :" << "Info:" << stingMessage << std::endl;
			}
			if (level == LevelLogRegistration::Warning) {
				file << nowDate << "  :" << "Warning:" << stingMessage << std::endl;
			}
		}
	}
	catch (...) {
		char* ErrorMessage = new char(std::strlen(nowDate) + strlen("Ошибка записи лога!") +1);
		std::strcat(ErrorMessage,nowDate);
		std::strcat(ErrorMessage, "Ошибка записи лога!");
		Write_log(ErrorMessage);
		return false;
	}

}

bool LogRegistration::Write_log(const char* stingMessage, LevelLogRegistration level, const char* path)
{
	std::ofstream file;
	char* nowDate = dateTime::NowDate();
	try {
		file.open(path, std::ios::app);
		if (file.is_open()) {
			if (level == LevelLogRegistration::Error) {
				file << nowDate << "  :" << "Eroor!:" << stingMessage << std::endl;
			}
			if (level == LevelLogRegistration::Info) {
				file << nowDate << "  :" << "Info:" << stingMessage << std::endl;
			}
			if (level == LevelLogRegistration::Warning) {
				file << nowDate << "  :" << "Warning:" << stingMessage << std::endl;
			}
		}
	}
	catch (...) {
		char* ErrorMessage = new char(std::strlen(nowDate) + strlen("Ошибка записи лога!") + 1);
		std::strcat(ErrorMessage, nowDate);
		std::strcat(ErrorMessage, "Ошибка записи лога!");
		Write_log(ErrorMessage);
		return false;
	}
}