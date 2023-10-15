#include <iostream>
#include <cstdio>
int aboba(char * a  ,int l) {
	int amount = 0;
	int ans = 0;
	for (int i = 0; i < l; i++) {
		if ((a[i] - '0') == -16) {
			amount = 0;
		}
		
			++amount;
		
		if (amount == 5){
		ans++;
		}
		
	
	}
	return ans;


}
int bebra() {
	char* a = new char[81];
	int i = 0, tmp = 0;
	while (tmp != '\n') {
		tmp = 0;
		tmp = getchar();
		if (tmp == 48 || tmp == 49||tmp==32) {
			a[i] = tmp;
			i++;//length of string
		}
	}
	tmp = 0;
	int ans = aboba(a,i);
	return ans;
}
int main() {
   int ans = bebra();
   std::cout << "answer is " << ans;


}