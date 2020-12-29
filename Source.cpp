#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

bool isNumberNumeric();
int inputNumber(int a);

class  Appliances            	 //базовый 
{
protected:
	double buy;
public:
	Appliances(int w) {
		buy = w;
	}				 // конструктор 
	virtual void proc() = 0;
	virtual void print() = 0;
};

class technik_sen : public Appliances //произв
{
private:
	int client;
public:
	technik_sen(int buy,int client) :Appliances(buy) {
		this->buy = buy;
		this->client = client;
	}
	void print()
	{
		cout << "Количество клиентов : " << client<<endl;
		cout << "Клиенты в сентябре ";
	}
	void proc()
	{
		cout << "купили" << buy << " единиц техники. Процент покупок: " << buy / 20 * 100 << "%." << endl;
	}
};

class technik_ok : public Appliances //производный 
{
private:
	int feedback;
public:
	technik_ok(int buy,int feedback) :Appliances(buy) {
		this->buy = buy;
		this->feedback=feedback;
	}
	void print()
	{
		cout << "Количество положительных отзывов : " <<feedback<<endl;
		cout << "Клиенты в октябре ";
	}
	void proc()
	{
		cout << "купили " << buy << " единиц техники. Процент покупок: " << buy / 32 * 100 << "%." << endl;
	}
};

class technik_nov : public Appliances //производный
{
private:
	int rating;
public:
	technik_nov(int buy, int rating) :Appliances(buy) {
		this->buy = buy;
		this->rating=rating;
	}
	void print()
	{
		cout << "Рейтинг в этом месяце " <<rating<<endl;
		cout << "Клиeнты в ноябре ";
	}
	void proc()
	{
		cout << "купили " << buy << " единиц техники. Процент покупок: " << (buy / 25) * 100 << "%." << endl;
	}
};


int main() {

	setlocale(0, " ");
	int client, feedback, rating;
	cout << "Введите кол-во клиентов в этом месяце: ";
	client = inputNumber(100);
	cout << endl;
	cout << "Введите кол-во отзывов в этом месяце: ";
	feedback = inputNumber(100);
	cout << endl;
	cout << "Введите рейтинг в этом месяце: ";
	rating = inputNumber(5);

	int s, o, n;
	cout << "Количество техники, которую купили в:" << endl
		<< "сентябре (из колличества 20 штук):";  s = inputNumber(20); technik_sen sen(s,client);
	cout << "октябре (из колличества 32 штук):"; o = inputNumber(32); technik_ok ok(o,feedback);
	cout << "ноябре (из колличества 25 штук):"; n = inputNumber(25); technik_nov nov(n,rating);
	cout << endl;

	Appliances* h[3];
	h[0] = &sen; h[1] = &ok; h[2] = &nov;

	for (int i = 0; i < 3; i++) {
		h[i]->print(); h[i]->proc(); cout << endl;
	}
}

bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
int inputNumber(int a)
{
	double number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && number >= 0 && number <= a && number - int(number) == 0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}
