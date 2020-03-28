#pragma once
#ifndef WriteToFile
#define WriteToFile

///
/// @summary Эта функция записывает строку в файл
/// @param data Это строка, котрую нужно записать в файл
/// @param fileName Это имя файла, в который будет осуществляться запись данных
/// 
void writeStringToFile2(std::string data, std::string fileName) {
	std::ofstream file;
	std::string path = "C:\\Users\\Nikita\\Documents\\Разработка программных модулей\\Лаба10\\";
	path = path + fileName + ".txt";
	file.open(path.data(), std::ios::app);
	file << data << std::endl;
	file.close();
};

#endif
