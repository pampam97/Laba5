#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

class appliances {
protected:
	int serial_number;
	string type;
	int weight;
	int power;
public:
	appliances() {

	}
	void set_serial_number(int serial_number) {
		this->serial_number = serial_number;
	}
	void set_weight(int weight) {
		this->weight = weight;
	}
	void set_power(int power) {
		this->power = power;
	}
	void set_type(string type) {
		this->type = type;
	}
	string get_type() {
		return type;
	}
	int get_serial_number() {
		return serial_number;
	}
	int get_weight() {
		return weight;
	}
	int get_power() {
		return power;
	}
	virtual void view() = 0;
};

class technik : public appliances {
protected:
	int voltage;
	string color;
public:
	void set_voltage(int voltage) {
		this->voltage = voltage;
	}
	void set_color(string color) {
		this->color = color;
	}
	int get_voltage() {
		return voltage;
	}
	string get_color() {
		return color;
	}
	technik();
	technik(int serial_number, string type, int weight, int power, int voltage, string color) {
		this-> serial_number = serial_number;
		this-> type = type;
		this-> weight = weight;
		this-> power = power;
		this-> voltage = voltage;
		this-> color = color;
	}
	void view() override
	{
		cout << "Объект создан!" << endl;
		cout << "Серийный номер: " << serial_number << endl;
		cout << "Тип техники: " << type<< endl;
		cout << "Вес: " << weight<< endl;
		cout << "Мощность: " <<power<< endl;
		cout << "Напряжение: " <<voltage << endl;
		cout << "Цвет: " << color << endl;
	}
};

class technik_info : public appliances {
protected:
	int width;
	int height;
public:
	void set_width(int width) {
		this->width = width;
	}
	void set_height(int height) {
		this->height = height;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
	technik_info();
	technik_info(int serial_number, string type, int weight, int power, int width, int height) {
		this-> serial_number = serial_number;
		this-> type = type;
		this-> weight= weight;
		this-> power = power;
		this-> width = width;
		this-> height = height;
	}
	void view() override
	{

		cout << "Object created!" << endl;
		cout << "Серийный номер: " << serial_number << endl;
		cout << "Тип техники: " << type << endl;
		cout << "Вес: " << weight << endl;
		cout << "Мощность: " << power << endl;
		cout << "Высота: " << height << endl;
		cout << "Ширина: " << width << endl;
	}
};

class technik_dopinfo : public appliances {
protected:
	string brand;
	int price;
public:
	string get_brand() {
		return brand;
	}
	int get_price() {
		return price;
	}
	void set_price(int price) {
		this->price = price;
	}
	void set_brand(string brand) {
		this->brand = brand;
	}
	technik_dopinfo();
	technik_dopinfo(int serial_number, string type, int weight, int power, string brand, int price) {
		this-> serial_number = serial_number;
		this-> type = type;
		this-> weight = weight;
		this-> power = power;
		this-> brand = brand;
		this-> price = price;
	}
	void view() override
	{
		cout << "Объект создан!" << endl;
		cout << "Серийный номер: " << get_serial_number() << endl;
		cout << "Тип техникик: " << get_type() << endl;
		cout << "Вес : " << get_weight() << endl;
		cout << "Мощность: " << get_power() << endl;
		cout << "Ценник : " << get_price() << endl;
		cout << "Бренд: " << get_brand() << endl;
	}
};

void view(appliances* obj) {
	obj->view();
}

void menu_choise() {
	cout << "Выберите, с чем вы хотите работать: " << endl;
	cout << "1 - Информация о технике " << endl;
	cout << "2 - Параметры техники с основной информацией" << endl;
	cout << "3 - Информация техники с основной информацией" << endl;
	cout << "0 - Exit " << endl;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int main() {
	bool flag = true;
	int choise = 0;

	setlocale(0, " ");

	while (flag == true) {
		menu_choise();
		cin >> choise;
		switch (choise)
		{

		case 1: {
			int serial_number = 0, power = 0, weight = 0, voltage = 0;
			string type, color;
			system("cls");
			cout << "Ввод информации : " << endl;
			cout << "Серийный номер: ";
			serial_number = writeNumbers();
			system("cls");
			cout << "Тип: ";
			type = writeWords() ;
			system("cls");
			cout << "Вес: ";
			weight = writeNumbers();
			system("cls");
			cout << "Мощность: ";
			power = writeNumbers();
			system("cls");
			cout << "Напряжение: ";
			voltage = writeNumbers();
			system("cls");
			cout << "Цвет : ";
			color = writeWords();
			system("cls");
			technik obj(serial_number, type, weight, power, voltage, color);
			view(&obj);
			break;
		}
		case 2: {
			int serial_number = 0, power = 0, weight = 0, height = 0, width = 0;
			string type;

			system("cls");
			cout << "Ввод информации : " << endl;
			cout << "Серийный номер : ";
			serial_number = writeNumbers();
			system("cls");
			cout << "Тип: ";
			type = writeNumbers();
			system("cls");
			cout << "Вес : ";
			weight = writeNumbers();
			system("cls");
			cout << "Мощность : ";
			power = writeNumbers();
			system("cls");
			cout << "Ширина : ";
			width = writeNumbers();
			system("cls");
			cout << "Высота : ";
			height = writeNumbers();
			system("cls");
			technik_info obj3(serial_number, type, weight, power, width, height);
			view(&obj3);
			break;
		}
		case 3: {
			int serial_number = 0, power = 0, weight = 0, price = 0;
			string type, brand;

			system("cls");
			cout << "Ввод информации: " << endl;
			cout << "Серийный номер: ";
			serial_number = writeNumbers();
			system("cls");
			cout << "Тип : ";
			type = writeNumbers();
			system("cls");
			cout << "Вес : ";
			weight = writeNumbers();
			system("cls");
			cout << "Мощность: ";
			power = writeNumbers();
			system("cls");
			cout << "Ценник: ";
			price = writeNumbers();
			system("cls");
			cout << "Бренд: ";
			brand = writeWords();
			system("cls");
			technik_dopinfo obj2(serial_number, type, weight, power, brand, price);
			view(&obj2);
			break;
		}
		case 0: {
			flag = false; break;
		}
		default: {
			system("cls"); cout << "Ничего не найдено!" << endl; break;
		}
		}
	}
	system("pause");
	return 0;
}