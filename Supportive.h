#ifndef Supportive
#define Supportive

//#include "packetFactory.h"
//#include <map>
#include "writeToFile.h"

///
/// @summary ��� �������, ������� ������� �����
///

void clearFiles() {
	std::ofstream file;
	//std::string path = DIR, path2 = DIR, path3 = DIR;
	std::string path, path2, path3;
	file.open("./Rejected.txt", std::ios::out);
	file.close();
	file.open("./Interface1.txt", std::ios::out);
	file.close();
	file.open("./Interface2.txt", std::ios::out);			// Был path += 
	file.close();
};

///
/// @summary Fills the packets.
/// @param intr ��� �������� ����������, ������ � �������� ����� �������
/// @param factoryList ��� ������, ������� ������ � ���� ������, ���������� ���������
/// @param newFactory ��� �������, ����������� ������
/// @return ���������� ��������� �� ������, ���������� ������, ���������� ���������
/// 
std::list<Packet*> fillPackets(std::string intr, std::list<Packet*>* factoryList, PacketFactory* newFactory) {
	std::ifstream file;
	std::string path;
	path.append("./In");
	//std::string path = "\\In";

	path = path + intr + ".txt";
	file.open(path.data());
	if (!file.is_open()) {
		std::cout << "File not open" << std::endl;
	};
	while (!file.eof()) {
	    Packet* packet = newFactory->work();
	    packet->setValues(&file);
	    packet->inInt = intr;

	    factoryList->push_back(packet);
	};
	file.close();
	return *factoryList;
};

void convey(std::list<Packet*> factoryList, std::map<std::string, TrafficPacketHandler*>* interfaces) {
	int cnt = 0;
	while (!factoryList.empty()) {
		for (auto iter = interfaces->begin(); iter != interfaces->end(); iter++) {
			if (factoryList.back()->outInt == iter->first) {
				iter->second->handlePacket(factoryList.back());
				factoryList.pop_back();
			} else {
				cnt++;
			} if (factoryList.size() == cnt) {
				writeStringToFile2(factoryList.back()->getStringData(), "Rejected");
				factoryList.pop_back();
			} if (factoryList.empty()) break;
		}
	};
};

std::list<RuleClass*> readRules(std::list<RuleClass*> *ruleList) {
	std::ifstream file;
	std::string path;
	path.append("./Rules.txt");
	file.open(path);
	if (!file.is_open()) {
		std::cout << "File not open" << std::endl;
	}
	else {
		while (!file.eof()) {
			ruleList->push_back(new RuleClass);
			getline(file, ruleList->back()->inInt, ' ');
			getline(file, ruleList->back()->source, ' ');
			getline(file, ruleList->back()->dest, ' ');
			getline(file, ruleList->back()->outInt, ' ');
			getline(file, ruleList->back()->prot, ' ');
			getline(file, ruleList->back()->act, '\n');
		};
	};
	file.close();
	return *ruleList;
}

#endif
