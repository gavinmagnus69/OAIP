#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iomanip>
void chklong(long long* a) {
    while (true) {
        std::cin >> *a;
        std::cin.ignore(111111, '\n');
        if (std::cin.fail() || (std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
            std::cin.clear();
            std::cin.ignore(111111, '\n');
            std::cerr << "Incorrect input,try again\n";
        }
        else
            return;
    }
}
long double chk() {
    while (true) {
        bool er = 0;
        int e, m;
        bool dot = 0, E = 0;
        std::string str;
        std::cin >> str;
        std::string str1 = str;
        if (str.size() == 1 && str[0] == '-') {
            std::cerr << "\nincorrect input,try again\n";
            std::cin.ignore(111111111, '\n');
            er = 1;
            break;
        }
        for (; str[0] == '0' && str[1] == '0';)
        {
            str.erase(0, 1);
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') {
                if (dot == 1) {
                    std::cerr << "\nincorrect input,try again\n";
                    std::cin.ignore(111111111, '\n');
                    er = 1;
                    break;
                }
                m = i;
                dot = 1;
            }
            else if (str[i] == 'E' || str[i] == 'e') {
                if (E == 1) {
                    std::cerr << "\nincorrect input, try again\n";
                    std::cin.ignore(111111111, '\n');
                    er = 1;
                    break;
                }
                e = i;
                E = 1;
            }
            else if (str[i] == 'E' && i != 0 && str[i - 1] != '-' && str[i - 1] != 'e') {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                break;
            }
            else if (str[i] != 'e' && str[i] != '.' && str[i] != 'E' && str[i] != '-' && (str[i] > '9' || str[i] < '0')) {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                break;
            }
        }
        if (er == 1) {
            continue;
        }
        if (dot == 1) {
            if (E == 1) {
                while (str[e - 1] == '0') {
                    str.erase(e - 1, 1);
                    e--;
                    m--;
                }
                while (str[e + 1] == '0') {
                    str.erase(e + 1, 1);
                    e--;
                    m--;
                }
            }
            else {
                while (str[str.size() - 1] == '0') {
                    str.erase(str.size() - 1, 1);
                }
            }
        }
        if (dot && !E) {
            str1[str1.size() - 1]--;
            if (stold(str) == stold(str1)) {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                continue;
            }
        }
        if (dot == 1 && E == 1 && str[e - 1] != '0') {
            str1[e - 1]--;
            if (stold(str) == stold(str1)) {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                continue;
            }
        }

        return stold(str);
    }
}
void odd(long long n) {
    long long ** a = NULL;
    a = (long long**)malloc((n+2) * sizeof(long long));
    for (int i = 0; i < n+2; i++) {
        a[i] = (long long*)malloc((n+2) * sizeof(long long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    int x = 0, y = n / 2;
    for (int i = 1; i <= n * n; i++)
    {
        a[x][y] = i;
        x--;
        y++;
        if (x<0 && y>n - 1) {
            x = x + 2; y = y - 1;
        }
        else if (x < 0) {
            x += n;
        }
        else if (y > n - 1){
            y -= n;
        }
        else if (a[x][y] != 0) 
        {
            x+=2;
            y -= 1; 
        }
    }
    for (int g = 0; g < n; g++) {
        for (int j =0; j < n; j++) {
        std::cout << a[g][j] << "   ";
        }
        std::cout << "\n";
    }

}
void deven(long long n) {
    long long** a = NULL;
    a = (long long**)malloc((n + 2) * sizeof(long long));
    for (int i = 0; i < n + 2; i++) {
        a[i] = (long long*)malloc((n + 2) * sizeof(long long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
   long long x = 0, y = 0;
   for (int i = 1; i <= n * n; i++) {
       a[x][y] = i;
       y++;
       if (y > n - 1) {
           x++;
           y -= n;
       }
   
   }
   for (int i = 0; i < n; i++)    {           
       for (int j = 0; j < n; j++) {
           if (i % 4 == 0 && j % 4 == 0) {
               for (int g = 0; g < 4; g++){
                   a[i + g][j + g] = (n * n + 1) - a[i + g][j + g];
               }
           }
           else if (i % 4 == 3 && j % 4 == 0) {
               for (int g = 0; g < 4; g++){
                   a[i - g][j + g] = (n * n + 1) - a[i - g][j + g];
               }
           }
       }
   }
   for (int g = 0; g < n; g++) {
       for (int j = 0; j < n; j++) {
           std::cout << a[g][j] << "   ";
       }
       std::cout << "\n";
   }
}
void even(long long n) {
    long long nn = n / 2;
    long long** a = NULL;
    a = (long long**)malloc((nn + nn) * sizeof(long long));
    for (int i = 0; i < nn + nn; i++) {
        a[i] = (long long*)malloc((nn + nn) * sizeof(long long));
    }
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
            a[i][j] = 0;
        }
    }
    int x = 0, y = nn / 2;
    for (int i = 1; i <= nn * nn; i++)
    {
        a[x][y] = i;
        x--;
        y++;
        if (x<0 && y>nn - 1) {
            x = x + 2; y = y - 1;
        }
        else if (x < 0) {
            x += nn;
        }
        else if (y > nn - 1) {
            y -= nn;
        }
        else if (a[x][y] != 0)
        {
            x += 2;
            y -= 1;
        }
    }
    
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++)
        {
            a[i + nn][j + nn] = a[i][j] + nn * nn;      
            a[i][j + nn] = a[i + nn][j + nn] + nn * nn;     
            a[i + nn][j] = a[i][j + nn] + nn * nn;       
        }
    }
    long long s = (n - 2) / 4;                          
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < s; j++) {
            if (i == nn / 2) {
                std::swap(a[i][i + j], a[i + nn][i + j]);
            }  
            else {
                std::swap(a[i][j], a[i + nn][j]);
            }
        }
    }           
    for (int i = 0; i < nn; i++) {
        for (int j = nn + nn / 2; j > nn + nn / 2 - (s - 1); j--) {
            std::swap(a[i][j], a[i + nn][j]);
        }
    }
    for (int g = 0; g < n; g++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[g][j] << "   ";
        }
        std::cout << "\n";
    }

}
bool p1(long long n)
{
    long long** a = NULL;
    a = (long long**)malloc((n + 2) * sizeof(long long));
    for (int i = 0; i < n + 2; i++) {
        a[i] = (long long*)malloc((n + 2) * sizeof(long long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    int x = 0, y = n / 2;
    for (int i = 1; i <= n * n; i++)
    {
        a[x][y] = i;
        x--;
        y++;
        if (x<0 && y>n - 1) {
            x = x + 2; y = y - 1;
        }
        else if (x < 0) {
            x += n;
        }
        else if (y > n - 1) {
            y -= n;
        }
        else if (a[x][y] != 0)
        {
            x += 2;
            y -= 1;
        }
    }
    long long sum = n * (n * n + 1) / 2;                                
    for (int i = 0; i < n; i++)
    {
        int rs = 0, ls = 0;
        for (int j = 0; j < n; j++)
        {
            rs += a[i][j];                       
            ls += a[j][i];                    
        }
        if (rs != sum || ls != sum) { 
            return false; }
    }
    long long sl = 0, sr = 0;
    for (int i = 0; i < n; i++)
    {
        sl += a[i][i];                             
        sr += a[n - i - 1][i];                     
    }
    if (sl != sum || sr != sum) {
        return false; }
    return true;
}
bool p2(long long n) {
    long long** a = NULL;
    a = (long long**)malloc((n + 2) * sizeof(long long));
    for (int i = 0; i < n + 2; i++) {
        a[i] = (long long*)malloc((n + 2) * sizeof(long long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    long long x = 0, y = 0;
    for (int i = 1; i <= n * n; i++) {
        a[x][y] = i;
        y++;
        if (y > n - 1) {
            x++;
            y -= n;
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 4 == 0 && j % 4 == 0) {
                for (int g = 0; g < 4; g++) {
                    a[i + g][j + g] = (n * n + 1) - a[i + g][j + g];
                }
            }
            else if (i % 4 == 3 && j % 4 == 0) {
                for (int g = 0; g < 4; g++) {
                    a[i - g][j + g] = (n * n + 1) - a[i - g][j + g];
                }
            }
        }
    }
    long long sum = n * (n * n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int rs = 0, ls = 0;
        for (int j = 0; j < n; j++)
        {
            rs += a[i][j];
            ls += a[j][i];
        }
        if (rs != sum || ls != sum) {
            return false;
        }
    }
    long long sl = 0, sr = 0;
    for (int i = 0; i < n; i++)
    {
        sl += a[i][i];
        sr += a[n - i - 1][i];
    }
    if (sl != sum || sr != sum) {
        return false;
    }
    return true;
}
bool p3(long long n) {
    long long nn = n / 2;
    long long** a = NULL;
    a = (long long**)malloc((nn + nn) * sizeof(long long));
    for (int i = 0; i < nn + nn; i++) {
        a[i] = (long long*)malloc((nn + nn) * sizeof(long long));
    }
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
            a[i][j] = 0;
        }
    }
    int x = 0, y = nn / 2;
    for (int i = 1; i <= nn * nn; i++)
    {
        a[x][y] = i;
        x--;
        y++;
        if (x<0 && y>nn - 1) {
            x = x + 2; y = y - 1;
        }
        else if (x < 0) {
            x += nn;
        }
        else if (y > nn - 1) {
            y -= nn;
        }
        else if (a[x][y] != 0)
        {
            x += 2;
            y -= 1;
        }
    }

    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++)
        {
            a[i + nn][j + nn] = a[i][j] + nn * nn;
            a[i][j + nn] = a[i + nn][j + nn] + nn * nn;
            a[i + nn][j] = a[i][j + nn] + nn * nn;
        }
    }
    long long s = (n - 2) / 4;
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < s; j++) {
            if (i == nn / 2) {
                std::swap(a[i][i + j], a[i + nn][i + j]);
            }
            else {
                std::swap(a[i][j], a[i + nn][j]);
            }
        }
    }
    for (int i = 0; i < nn; i++) {
        for (int j = nn + nn / 2; j > nn + nn / 2 - (s - 1); j--) {
            std::swap(a[i][j], a[i + nn][j]);
        }
    }
    for (int g = 0; g < n; g++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[g][j] << "   ";
        }
        std::cout << "\n";
    }
    long long sum = n * (n * n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int rs = 0, ls = 0;
        for (int j = 0; j < n; j++)
        {
            rs += a[i][j];
            ls += a[j][i];
        }
        if (rs != sum || ls != sum) {
            return false;
        }
    }
    long long sl = 0, sr = 0;
    for (int i = 0; i < n; i++)
    {
        sl += a[i][i];
        sr += a[n - i - 1][i];
    }
    if (sl != sum || sr != sum) {
        return false;
    }
    return true;
}
int main() {
    std::cout << "TASK 13\n";
    std::cout<<"Construct a magic square. The order of the square is set by user\n";
    long long n;
    std::cout << "enter length of a side(iteger positive numbers only)\n";
    chklong(&n);
    if (n < 3) {
        std::cout << "there are no squares like that";
        return 0;
    }
    if (n % 2 != 0&&p1(n)) { 
        odd(n);
        return 0;
    }
    if (n % 4 == 0&&p2(n)) {
        deven(n);
        return 0;
    }
    if (n % 2 == 0 && n % 4 != 0&&p3(n)) {
        even(n);
    }
    return 0;
}