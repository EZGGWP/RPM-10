#pragma once
#ifndef Factory
#define Factory

#include "packet.h"
/// 
/// @summary Это класс-фабрика, который создаёт объекты класса Packet (другими словами - сами сетевые пакеты)
/// @return Возвращает объект класса Packet
/// 
class PacketFactory {
public:
	Packet* work();
};
#endif

