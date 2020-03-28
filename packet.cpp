#include "packet.h"
#include <string>
#include <fstream>

Packet::Packet() {
	inInt = " ";
	src = " ";
	dst = " ";
	outInt = " ";
	protocol = " ";
};

std::string Packet::getStringData() {
	return this->inInt + ' ' + this->src + ' ' + this->dst + ' ' + this->outInt + ' ' + this->protocol;
}

void Packet::setValues(std::ifstream* file) {
	std::getline(*file, this->src, ' ');
	std::getline(*file, this->dst, ' ');
	std::getline(*file, this->outInt, ' ');
	std::getline(*file, this->protocol, '\n');
};
