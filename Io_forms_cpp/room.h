#pragma once
public class room
{
private:
	bool free;
	int d, m, h, min, num;
public: 
	room() {
		num = 0;
		d = 0;
		m = 0;
		h = 0;
		min = 0;
		free = false;
	}
	room(int d, int m, int h, int min, int num, bool free) {}
	void set(int d, int m, int h, int min, int num, bool free) {
		{
			this->d = d;
			this->m = m;
			this->h = h;
			this->min = min;
			this->num = num;
			this->free = free;
		}
	}
	int getd() { return d; }
	int getm() { return m; }
	int getnum() { return num; }
	int geth() { return h; }
	int getmin() { return min; }
	bool getfree() { return free; }
};
