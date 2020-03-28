#include <string>
//#include <fstream>
#include <list>
#include <map>
//#include "writeToFile.h"
#include "packet.h"
#include "trafficPacketHandler.h"
#include "packetFactory.h"
#include "Supportive.h"

///
/// @summary Это функция мэйн, в которой вызываются разные функции
///
int main() {
	clearFiles();
	PacketFactory newFactory;
	std::ifstream file;
	std::ofstream file2;
	std::list<Packet*> factoryList;
	std::map<std::string, TrafficPacketHandler*> interfaces;
	interfaces.insert(std::make_pair("Interface1", new TrafficPacketHandler("Interface1")));
	interfaces.insert(std::make_pair("Interface2", new TrafficPacketHandler("Interface2")));
	fillPackets("Interface1", &factoryList, &newFactory);
	fillPackets("Interface2", &factoryList, &newFactory);
	convey(factoryList, &interfaces);
	return 0;
};
