#include "trafficPacketHandler.h"
#include "writeToFile.h"

TrafficPacketHandler::TrafficPacketHandler(std::string name, std::list<RuleClass*> rules) {
	intName = name;

	for (std::list<RuleClass*>::iterator i = rules.begin(); i != rules.end(); i++) {
		if ((*i)->outInt == intName) {
			ruleList.push_back((*i));
		};
	};
};

void TrafficPacketHandler::handlePacket(Packet* object) {
	int cn = 0;
	for (std::list<RuleClass*>::iterator i = ruleList.begin(); i != ruleList.end(); i++) {
		if ((object->inInt == (*i)->inInt) && ((object->dst == (*i)->dest) || ((*i)->dest == "0")) && ((object->src == (*i)->source) || ((*i)->source == "0")) && (object->outInt == (*i)->outInt) && ((object->protocol == (*i)->prot) || (*i)->prot == "*") && ((*i)->act == "allow")) {
			writeStringToFile2(object->getStringData(), object->outInt);
		}
		else {
			cn++;
		};
	}
	if (ruleList.size() == cn) {
		writeStringToFile2(object->getStringData(), "Rejected");
	};
};