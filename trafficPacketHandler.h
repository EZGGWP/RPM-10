#pragma once
#ifndef trafficPacketHandler
#define trafficPacketHandler

#include <list>
//#include <string>
#include <fstream>
#include <iostream>
#include "ruleClass.h"
#include "packet.h"

///
/// @summary Это класс, отвечающий за обработку пакетов по правилам для интерфейса
///
class TrafficPacketHandler {
public:
	std::string intName;
	std::list<RuleClass*> ruleList;

	///
	/// @summary Это конструктор обработчика пакетов, который забирает соответствующие правила из файла и записывает в список
	/// 
	explicit TrafficPacketHandler(std::string name);

	///
	/// @summary Это функция-обработчик пакетов
	/// @param object Принимает объект класса Packet
	///
	void handlePacket(Packet* object);
};

#endif


