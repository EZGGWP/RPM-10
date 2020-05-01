//#define DIR "C:\\Users\\Nikita\\Desktop\\Temp"
#include <list>
#include <map>
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
	std::list<RuleClass*> rules;
	readRules(&rules);
	std::ifstream file;
	std::ofstream file2;
	std::list<Packet*> factoryList;
	std::map<std::string, TrafficPacketHandler*> interfaces;
	TrafficPacketHandler tph1(std::string("Interface1"), rules);
	TrafficPacketHandler tph2(std::string("Interface2"), rules);
	interfaces.insert(std::make_pair("Interface1", &tph1));
	interfaces.insert(std::make_pair("Interface2", &tph2));
	fillPackets("Interface1", &factoryList, &newFactory);
	fillPackets("Interface2", &factoryList, &newFactory);
	convey(factoryList, &interfaces);
	return 0;
};
