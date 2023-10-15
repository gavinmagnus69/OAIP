#include <iostream>
#include <cmath>
int main() {
	setlocale(LC_ALL, "RU");
	long double x1, y1, x2, y2, r, R, l;
	std::cout << "x1 and y1 coordinates and r'\n";
	std::cin >> x1 >> y1 >> r;
	if (r <= 0) {
		std::cout << "incorrect input";
		return 0;
	}
	std::cout << "x2 and y2 coordinates and R'\n";
	std::cin >> x2 >> y2 >> R;
	if (R <= 0) {
		std::cout << "incorrect input";
		return 0;
	}
	l = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (l > r + R) {
		std::cout << "Ни одно условие не выполнено";
		return 0;
	}
	
	
	//M1>M2 r>R
	//m1-r m2-R
	if (r>=R&&l <= r) {
		if (x1 == x2 && y1 == y2 && r == R) {
			std::cout << "да,но верно и обратное";
			return 0;
		
		}
		if (l + R <= r) {
			std::cout << "Да, но верно и обратное";
			return 0;
		}
		if (l +  R > r) {
			std::cout << "Фигуры пересекаются";
			return 0;
		} 
	}
	else if (l > r) {
		if (l - r <= R) {
			std::cout << "фигуры пересекаются";
			return 0;
		}
		
	
	}
	if (R >=r && l <= R) {
		if (x1 == x2 && y1 == y2 && r == R) {
			std::cout << "да,но верно и обратное";
			return 0;

		}
		if (l + r <= R) {
			std::cout << "Да";
			return 0;
		}
		if (l + r > R) {
			std::cout << "Фигуры пересекаются";
			return 0;
		}
	}
	else if (l > R) {
		if (l - R <= r) {
			std::cout << "фигуры пересекаются";
			return 0;
		}


	}




}