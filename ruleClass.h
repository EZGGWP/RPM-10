#pragma once
#ifndef ruleClass
#define ruleClass
#include <string>

///
/// @summary Этот класс правил маршрутизации
///
class RuleClass {
public:
	std::string inInt;
	std::string source;
	std::string dest;
	std::string outInt;
	std::string prot;
	std::string act;
	///
	/// @summary Это конструктор который собирает объект с пустыми строками
	///
	RuleClass();
};
#endif

