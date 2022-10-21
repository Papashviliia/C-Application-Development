#pragma once
#include <string>

public class exam {
private:
	std::string dis;
	std::string fio;
	int h, min, m, d, num;
public:
	exam();
	~exam();
	exam(int h, int min, int m, int d, int num, std::string dis, std::string fio);
	void set(int h, int min, int m, int d, int num, std::string dis, std::string fio);
	std::string getfio();
	std::string getdis();
	int getd();
	int getm();
	int getmin();
	int geth();
	int getnum();
};

exam::~exam() {

}
exam::exam() {
	num = 0;
	d = 0;
	m = 0;
	min = 0;
	h = 0;
	dis = "\0";
	fio = "\0";
}

void exam::set(int h, int min, int m, int d, int num, std::string dis, std::string fio) {
	this->h = h;
	this->m = m;
	this->min = min;
	this->d = d;
	this->num = num;
	this->dis = dis;
	this->fio = fio;
}

exam::exam(int h, int min, int m, int d, int num, std::string dis, std::string fio) {
	set(h, min, m, d, num, dis, fio);
}



std::string exam::getdis() { return dis; }
std::string exam::getfio() { return fio; }
int exam::getd() { return d; }
int exam::getm() { return m; }
int exam::getmin() { return min; }
int exam::getnum() { return num; }
int exam::geth() { return h; }