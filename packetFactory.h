#ifndef Factory
#define Factory

#include "packet.h"
/// 
/// @summary ��� �����-�������, ������� ������ ������� ������ Packet (������� ������� - ���� ������� ������)
/// @return ���������� ������ ������ Packet
/// 
class PacketFactory {
public:
	Packet* work();
};
#endif

