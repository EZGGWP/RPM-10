#ifndef Supportive
#define Supportive

#include "packetFactory.h"
#include <map>
#include "writeToFile.h"

///
/// @summary Это функция, которая очищает файлы
///
void clearFiles() {
	std::ofstream file;
	file.open("C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Patterns\\Rejected.txt");
	file.close();
	file.open("C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Patterns\\Interface1.txt");
	file.close();
	file.open("C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Patterns\\Interface2.txt");
	file.close();
};
///
/// @summary Fills the packets.
/// @param intr Это название интерфейса, пакеты с которого нужно принять
/// @param factoryList Это список, который хранит в себе пакеты, подлежащие обработке
/// @param newFactory Это фабрика, выпускающая пакеты
/// @return возвращает указатель на список, содержащий пакеты, подлежащие обработке
/// 
std::list<Packet*> fillPackets(std::string intr, std::list<Packet*>* factoryList, PacketFactory* newFactory) {
	std::ifstream file;
	std::string path = "C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Лаба10\\In";
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
/// @summary Эта функция записывает строку в файл
/// @param data Это строка, котрую нужно записать в файл
/// @param fileName Это имя файла, в который будет осуществляться запись данных
/// 
/*
void writeStringToFile(std::string data, std::string fileName) {
	std::ofstream file;
	std::string path = "C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Лаба10\\";
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
