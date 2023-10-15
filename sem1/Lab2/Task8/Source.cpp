#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL, "Russian");
	long double a, b, c, x, x1, x2, x3, x4, t, t1, t2;
	long double p, q, Q, y1, y2, y3, f;
	long double pi = 3.14159265;
	long long n;
	std::cout << "Выберите уравнение" << "\n" << "1 - ax^4 + bx^2 + c = 0" << " \n" << "2 - ax^4 + bx^3 + cx^2 + bx + a = 0" << "\n" << "3 - x^3 + px + q = 0"<<"\n";
	std::cin >> n;
	if (n != 1 && n != 2 && n != 3) {
		std::cout << "нет такого варианта";
		return 0;
	
	}
	switch (n) {
	case 1:


		std::cout << "1 - ax^4 + bx^2 + c = 0"<<"\n";
		std::cout << "введите a,b,c" << "\n";
		std::cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			std::cout << "x can be any";
			return 0;

		}
		if (a == 0 && b == 0) {
			std::cout << "no roots";
			return 0;
		}
		if (a == 0 && b != 0) {
			t = (-c) / b;
			if (t > 0) {
				x1 = sqrtl(t);
				x2 = -sqrtl(t);
				std::cout << x1 << " " << x2;
				return 0;
			}
			if (t < 0) {
				std::cout << "no roots";
				return 0;
			}
			if (t == 0) {
				std::cout << 0;
				return 0;
			}

		}
		if (b * b - 4 * a * c < 0) {
			std::cout << "no roots";
			return 0;
		}
		if ((b * b - 4 * a * c) == 0) {
			t = (-b) / 2 / a;
			if (t < 0) {
				std::cout << "no roots";
				return 0;
			}
			if (t == 0) {
				x = sqrtl(t);
				std::cout << x;
				return 0;
			}
			if (t > 0) {
				x1 = sqrtl(t);
				x2 = -sqrtl(t);
				std::cout << x1 << " " << x2;
				return 0;

			}

		}
		if (b * b - 4 * a * c > 0) {
			t1 = (-b + sqrtl(b * b - 4 * a * c)) / 2 / a;
			t2 = (-b - sqrtl(b * b - 4 * a * c)) / 2 / a;
			x1 = sqrtl(t1);
			x2 = -sqrtl(t1);
			x3 = sqrtl(t2);
			x4 = -sqrtl(t2);
			if (t1 > 0 && t2 > 0) {
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4;
				return 0;

			}
			if (t1 == 0 && t2 == 0) {
				std::cout << 0;
				return 0;

			}
			if (t1 == 0 && t2 > 0) {
				std::cout << 0 << " " << x3 << " " << x4;
				return 0;
			}
			if (t1 > 0 && t2 == 0) {
				std::cout << x1 << " " << x2 << " " << 0;
			}
			if (t1 < 0 && t2>0) {
				std::cout << x3 << " " << x4;
				return 0;
			}
			if (t1 > 0 && t2 < 0) {
				std::cout << x1 << " " << x2;
				return 0;
			}

			return 0;


		}
		break;
	case 2:
		std::cout << "2 - ax^4 + bx^3 + cx^2 + bx + a = 0"<<"\n";
		std::cout << "введите a,b,c"<<"\n";
		std::cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			std::cout << "x can be any";
			return 0;

		}
		if (a == 0 && b == 0) {
			std::cout << "no roots";
			return 0;
		}
		if (a == 0 && b != 0) {
			t = (-c + 2 * a) / b;
			if (t * t - 4 > 0) {
				x1 = (t + sqrtl(t * t - 4)) / 2;
				x2 = (t - sqrtl(t * t - 4)) / 2;
				std::cout << x1 << " " << x2;
				return 0;


			}
			if (t == 0) {
				std::cout << "no roots";
				return 0;



			}if (t * t - 4 < 0) {
				std::cout << "no roots";
				return 0;
			}



		}
		if (b * b - 4 * a * (c - 2 * a) < 0) {
			std::cout << "no roots";
			return 0;
		}
		if ((b * b - 4 * a * (c - 2 * a)) == 0) {
			t = (-b) / 2 / a;
			if (t * t - 4 > 0) {
				x1 = (t + sqrtl(t * t - 4)) / 2;
				x2 = (t - sqrtl(t * t - 4)) / 2;
				std::cout << x1 << " " << x2;
				return 0;


			}
			if (t == 0) {
				std::cout << "no roots";
				return 0;



			}
			if (t * t - 4 < 0) {
				std::cout << "no roots";
				return 0;
			}


		}
		if (b * b - 4 * a * (c - 2 * a) > 0) {
			t1 = (-b + sqrtl(b * b - 4 * a * (c - 2 * a))) / 2 / a;
			x1 = (t1 + sqrtl(t1 * t1 - 4)) / 2;
			x2 = (t1 - sqrtl(t1 * t1 - 4)) / 2;
			if (t1 * t1 - 4 > 0) {
				x1 = (t1 + sqrtl(t1 * t1 - 4)) / 2;
				x2 = (t1 - sqrtl(t1 * t1 - 4)) / 2;


			}



			t2 = (-b - sqrtl(b * b - 4 * a * (c - 2 * a))) / 2 / a;
			if (t2 * t2 - 4 > 0) {
				x3 = (t2 + sqrtl(t2 * t2 - 4)) / 2;
				x4 = (t2 - sqrtl(t2 * t2 - 4)) / 2;
			}

			if (t1 == 0 && t2 == 0) {
				std::cout << "no roots";
				return 0;

			}
			if (t1 * t1 - 4 > 0 && t2 * t2 - 4 > 0) {
				std::cout << x1 << " " << x2 << " " << x3 << " " << x4;
				return 0;

			}
			if (t1 * t1 - 4 > 0 && t2 * t2 - 4 < 0) {
				std::cout << x1 << " " << x2;
				return 0;

			}
			if (t1 * t1 - 4 < 0 && t2 * t2 - 4 > 0) {
				std::cout << x3 << " " << x4;
				return 0;
			}
			if (t1 * t1 - 4 < 0 && t2 * t2 - 4 < 0) {
				std::cout << "no roots";
				return 0;

			}


			
		}
		break;
	case 3:
			std::cout<< "3 - x^3 + px + q = 0"<<"\n";
			std::cout << "enter p and q" << '\n';
			
			std::cin >> p >> q;
			Q = (p / (long double)3) * (p / (long double)3) * (p / (long double)3) + (q / (long double)2) * (q / (long double)2);
			std::cout << Q << '\n';
			if (q < 0) {
				f = atan(sqrtl(-Q) / (-q / 2));
			}
			if (q > 0) {
				f = atan(sqrtl(-Q) / (-q / 2)) + pi;
			}
			if (q == 0) {
				f = pi / 2.;
			}
			if (Q < 0) {
				y1 = 2 * sqrtl(-p / 3) * cos(f / 3);
				y2 = 2 * sqrtl(-p / 3) * cos(f / 3 + 2 * pi / 3);
				y3 = 2 * sqrtl(-p / 3) * cos(f / 3 + 4 * pi / 3);
				std::cout << y1 << " " << y2 << " " << y3;
				return 0;
			}




			if (Q > 0) {
				a = powl(-q / (long double)2 + sqrtl(Q), (long double)1 / (long double)3);
				b = p / (long double)3 / (powl(-q / (long double)2 + sqrtl(Q), (long double)1 / (long double)3));
				std::cout << a - b;

				return 0;
			}
			if (Q == 0) {
				y1 = 2 * sqrtl(-p / 3) * cos(f / 3);
				y2 = 2 * sqrtl(-p / 3) * cos(f / 3 + 2 * pi / 3);
				y3 = 2 * sqrtl(-p / 3) * cos(f / 3 + 4 * pi / 3);
				std::cout << y1 << " " << y2;
				return 0;



			}
			break;
	default:
				std::cout << "нет такого варианта";
				return 0;


				break;
	}

	return 0;
}