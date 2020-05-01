//#define DIR "C:\\Users\\Nikita\\Desktop\\Temp"
#include <iostream>
#include <fstream>
#include "writeToFile.h"

///
/// @summary ��� ������� ���������� ������ � ����
/// @param data ��� ������, ������ ����� �������� � ����
/// @param fileName ��� ��� �����, � ������� ����� �������������� ������ ������
/// 
void writeStringToFile2(std::string data, std::string fileName) {
	std::ofstream file;
	//std::string path = "C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\����10\\";
	std::string path;
	path = "./" + fileName + ".txt";
	file.open(path.data(), std::ios::app);
	if (!file.is_open()) {
		std::cout << "Can't open!" << std::endl;
	}
	else {
		file << data << std::endl;
		file.close();
	}
}
