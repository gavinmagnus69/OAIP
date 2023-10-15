#include <iostream>
#include <cmath>
int main() {
	long double W, H, x1, y1, x2, y2, w, h, ho1, ho2, wo2, wo1, hsi, wsi, a, b, c1, c, d, e, f, g, c2;
	std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
	ho1 = y1;
	ho2 = H - y2;
	wo1 = x1;
	wo2 = W - x2;
	hsi = y2 - y1;
	wsi = x2 - x1;
	if ((w + wsi) > W && (h + hsi) > H) {
		std::cout << -1;
		return 0;
	}
	if ((w < x1 && h < y1) || (H - h > y2 && w < x1) || (H - h > y2 && W - w > x2) || (h<y1 && W - w>x2)) {
		std::cout << 0;
		return 0;

	}
	a = w - x1;//width
	b = h - y1;//height

	if (a >= 0 && b >= 0) {

		c1 = std::min(a, b);
	}
	if (a >= 0 && b < 0) {

		c1 = a;
	}
	if (a < 0 && b >= 0) {

		c1 = b;
	}
	if (ho1 == 0) {


		c1 = a;
	}
	if (wo2 == 0) {

		c1 = b;
	}
	c = y2 - H + h;//height
	d = w - x1;//width
	if (c >= 0 && d >= 0) {

		c2 = std::min(c, d);
	}
	if (c >= 0 && d < 0) {

		c2 = c;
	}
	if (c < 0 && d >= 0) {

		c2 = d;
	}
	if (ho2 == 0) {

		c2 = d;
	}
	if (wo1 == 0) {

		c2 = c;

	}
	e = w - (W - x2);//width
	if (wo1 == 0) {
		e = c2;

	}
	if (e < 0) {

		g = std::min(c1, c2);
		std::cout << g;
		return 0;


	}
	g = std::min(e, std::min(c1, c2));
	std::cout << g;




}