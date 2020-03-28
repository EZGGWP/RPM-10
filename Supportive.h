#ifndef Supportive
#define Supportive

#include "packetFactory.h"
#include <map>
#include "writeToFile.h"

///
/// @summary ��� �������, ������� ������� �����
///
void clearFiles() {
	std::ofstream file;
	file.open("C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\Patterns\\Rejected.txt");
	file.close();
	file.open("C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\Patterns\\Interface1.txt");
	file.close();
	file.open("C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\Patterns\\Interface2.txt");
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
	std::string path = "C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\����10\\In";
	path = path + intr + ".txt";
	file.open(path.data());
	if (!file.is_open()) {
		std::cout << "File not open" << std::endl;
	};
	while (!file.eof()) {
		factoryList->push_back(newFactory->work());
		factoryList->back()->setValues(&file);
		factoryList->back()->inInt = intr;
	};
	file.close();
	return *factoryList;
};

///
/// @summary ��� ������� ���������� ������ � ����
/// @param data ��� ������, ������ ����� �������� � ����
/// @param fileName ��� ��� �����, � ������� ����� �������������� ������ ������
/// 
/*
void writeStringToFile(std::string data, std::string fileName) {
	std::ofstream file;
	std::string path = "C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\����10\\";
	path = path + fileName + ".txt";
	file.open(path.data(), std::ios::app);
	file << data << std::endl;
	file.close();
};
*/

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
#endif
