#include "trafficPacketHandler.h"
#include "writeToFile.h"

TrafficPacketHandler::TrafficPacketHandler(std::string name) {
	intName = name;
	std::ifstream file;
	file.open("C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Лаба10\\Rules.txt");
	if (!file.is_open()) {
		std::cout << "File not open" << std::endl;
	}
	else {
		while (!file.eof()) {
			ruleList.push_back(new RuleClass);
			getline(file, ruleList.back()->inInt, ' ');
			getline(file, ruleList.back()->source, ' ');
			getline(file, ruleList.back()->dest, ' ');
			getline(file, ruleList.back()->outInt, ' ');
			getline(file, ruleList.back()->prot, ' ');
			getline(file, ruleList.back()->act, '\n');
			if (ruleList.back()->outInt != intName) {
				ruleList.pop_back();
			};
		};
	};
	file.close();
};

void TrafficPacketHandler::handlePacket(Packet* object) {
	int cn = 0;;
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