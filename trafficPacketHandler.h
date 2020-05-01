#ifndef trafficPacketHandler
#define trafficPacketHandler

#include <list>
//#include <string>
#include <fstream>
#include <iostream>
#include "ruleClass.h"
#include "packet.h"

///
/// @summary ��� �����, ���������� �� ��������� ������� �� �������� ��� ����������
///
class TrafficPacketHandler {
public:
	std::string intName;
	std::list<RuleClass*> ruleList;

	///
	/// @summary ��� ����������� ����������� �������, ������� �������� ��������������� ������� �� ����� � ���������� � ������
	/// 
	explicit TrafficPacketHandler(std::string name, std::list<RuleClass*> ruleList);

	///
	/// @summary ��� �������-���������� �������
	/// @param object ��������� ������ ������ Packet
	///
	void handlePacket(Packet* object);
};

#endif


