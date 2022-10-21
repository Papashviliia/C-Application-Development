#pragma once
template <class T>
class List
{
private:
	T *mas;
	int n;
public:
	List();
	~List();
	T get(int k);
	void add(T elem, int k);
	int size();
};


template <class T>
List<T>::List() {
	n = 0;
	mas = new T[0];
}

template <class T>
List<T>::~List() {
	delete[] mas;
}

template <class T>
T List<T>::get(int k) {
	return mas[k];
}

template <class T>
void List<T>::add(T elem, int k) {
	bool l = 1;
	n++;
	while (l) {
			if (k >= n || k < 0) throw "Невозможно вставить на эту позицию";
			l = 0;
	}
	T *temp = mas;
	mas = new T[n];

	for (int i = 0; i < n; i++) {
		if (i == k) {
			l = 1;
			mas[i] = elem;
			continue;
		}
		if (!l) {
			mas[i] = temp[i];
		}
		else {
			mas[i] = temp[i - 1];
		}
	}
	delete[] temp;
}


template <class T>
int List<T>::size() {
	return n;
}

