#ifndef PacketClass
#define PacketClass
#include <string>

/// 
/// @summary ��� �����-�����, ������� �������� ��������������� ������ ���� � ��������� �������
/// 
class Packet {
public:
	std::string inInt;
	std::string outInt;
	std::string dst;
	std::string src;
	std::string protocol;
	/// �����������, ������� ������ ������ � ������� ������
	Packet();
	///
	/// @summary ��� ����� ��������� �������� � ���� ������
	/// @param file ��������� �� ���� ��������� �� �������� ����� 
	///
	void setValues(std::ifstream* file);
	///
	/// @summary ��� �����, ������� ���������� ������ � ������
	/// @return ���������� ������, ���������� ������ � ������
	///
	std::string getStringData();
};
#endif
