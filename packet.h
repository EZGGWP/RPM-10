#pragma once
#ifndef PacketClass
#define PacketClass
#include <string>

/// 
/// @summary Ёто класс-пакет, который содержит соответствующие пакету пол€ и несколько методов
/// 
class Packet {
public:
	std::string inInt;
	std::string outInt;
	std::string dst;
	std::string src;
	std::string protocol;
	///  онструктор, который создаЄт объект с пустыми пол€ми
	Packet();
	///
	/// @summary Ёто метод установки значений в пол€ пакета
	/// @param file ѕринимает на вход указатель на файловый поток 
	///
	void setValues(std::ifstream* file);
	///
	/// @summary Ёто метод, который возвращает данные о пакете
	/// @return ¬озвращает строку, содержащую данные о пакете
	///
	std::string getStringData();
};
#endif
