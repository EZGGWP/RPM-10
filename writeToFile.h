#pragma once
#ifndef WriteToFile
#define WriteToFile

///
/// @summary ��� ������� ���������� ������ � ����
/// @param data ��� ������, ������ ����� �������� � ����
/// @param fileName ��� ��� �����, � ������� ����� �������������� ������ ������
/// 
void writeStringToFile2(std::string data, std::string fileName) {
	std::ofstream file;
	std::string path = "C:\\Users\\Nikita\\Documents\\���������� ����������� �������\\����10\\";
	path = path + fileName + ".txt";
	file.open(path.data(), std::ios::app);
	file << data << std::endl;
	file.close();
};

#endif
