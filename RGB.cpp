#include <iostream>

using namespace std;

class Color {
public:
	int R;
	int G;
	int B;

	Color() {
		R = 0;
		G = 0;
		B = 0;
	}
	Color(int R, int G, int B) {
		check(R, G, B);
		R = R;
		G = G;
		B = B;
	}
	void check(int& R, int& G, int& B) {
		while (R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255) {
			if (R > 255) {
				cout << "Некорректный ввод числа. Перезапишите число r от 0 до 255" << endl;
				cin >> R;
			}
			if (R < 0) {
				cout << "Некорректный ввод числа. Перезапишите число r от 0 до 255" << endl;
				cin >> R;
			}
			if (G > 255) {
				cout << "Некорректный ввод числа. Перезапишите число g от 0 до 255" << endl;
				cin >> G;
			}
			if (G < 0) {
				cout << "Некорректный ввод числа. Перезапишите число g от 0 до 255" << endl;
				cin >> G;
			}
			if (B > 255) {
				cout << "Некорректный ввод числа. Перезапишите число b от 0 до 255" << endl;
				cin >> B;
			}
			if (B < 0) {
				cout << "Некорректный ввод числа. Перезапишите число b от 0 до 255" << endl;
				cin >> B;
			}
		}
	}
	friend ostream& operator << (ostream& stream, const Color& A) {        //перегрузка оператора вывода
		stream << A.B<< "," << A.G << "," << A.B;

		return stream;
	}

	friend istream& operator >> (istream& in, Color& A) {                  //перегрузка оператора ввода
		int R;
		int G;
		int B;
		in >> R >> G >> B;
		A.check(R, G, B);
		A.R = R;
		A.G = G;
		A.B = B;
		return in;
	}
	bool operator == (const Color& A) {
		if (R == A.R && G == A.G && B == A.B) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator != (const Color& A) {
		if (this->R != A.R || this->G != A.G || this->B != A.B) {
			return true;
		}
		else {
			return false;
		}
	}
};






int main()
{
	setlocale(LC_ALL, "ru");
	Color a;
	Color b;
	cout << "Введите первое число в RGB " << endl;
	cin >> a;
	cout << a << endl;
	cout << "Введите второе число в RGB " << endl;
	cin >> b;
	cout << b << endl;
	cout << (a != b) << endl;
	cout << (a == b) << endl;




	return 0;
}