#include <iostream>
#include <vector>
using namespace std;

//1
/*int main()
{
	int a, b;

	cout << "Wybierz Liczbe a: ";
	cin >> a; 

	cout << "Wybierz Liczbe b: "; 
	cin >> b;
	

	



	if (a > b) {
		cout << "Pierwsza Liczba Wieksza";
	}
	else{ 
		cout << "Druga liczba wieksza";
	}
	

	 

	return (0);
}
*/
//2
/*int main()
{
	int a, b, c;

	cout << "Wybierz Liczbe a: ";
	cin >> a;

	cout << "Wybierz Liczbe b: ";
	cin >> b;

	cout << "Wybierz Liczbe c ";
	cin >> c;


	cout << a + b + c << endl;







	return(0);
}
*/
//3
/*int main() {

	int a, b, c, d, e;

	cout << "Wybierz Liczbe a: ";
	cin >> a;

	cout << "Wybierz Liczbe b: ";
	cin >> b;

	cout << "Wybierz Liczbe c ";
	cin >> c;

	cout << "Wybierz Liczbe d ";
	cin >> d;

	cout << "Wybierz Liczbe e ";
	cin >> e;

	int suma(a + b + c + d + e);

	cout << suma / 5 << "Srednie arytmetyczne:  " << endl;





	return(0);
}
*/
//4
/*int main() {
	int n;
	unsigned long long silnia = 1; 

	cout << "Podaj liczbe, aby obliczyc silnie: ";
	cin >> n;

	if (n < 0) {
		cout << "Silnia nie jest zdefiniowana dla liczb ujemnych!" << endl;
	}
	else {
		for (int i = 1; i <= n; ++i) {
			silnia *= i; 
		}
		cout << "Silnia liczby " << n << " wynosi: " << silnia << endl;
	}

	return 0;
}
*/
//5
/*int main()
{
	int a, b, c;

	cout << "Wpisz 3 liczby: ";
	cin >> a >> b >> c;




	int min;

	if (a < b && a < c) {
		min = a;
	}
	else if (b < c) {
		min = b;
	}
	else {
		min = c;
	}

	cout << "Najmniejsza z trzech liczb: " << min << endl;


	return (0);
}
*/
//6
/*int main()
{
	int a, b, c, d;

	cout << "Wpisz 4 liczby: ";
	cin >> a >> b >> c >> d;




	int max;

	if (a > b && a > c && a > d) {
		max = a;
	}
	else if (b > c) {
		max = b;
	}
	else if (c > d) {
		max = c;
	}
	else {
		max = d;
	}

	cout << "Najwieksza z czterech liczb: " << max << endl;


	return (0);
}
*/
//7
/*int main() {

	int n;
	
	cout << "Wpisz liczbe Fibonacciego: "; cin >> n;

	if (n < 0) {
		cout << "Indeks musi byc nieujemny!" << endl;
		return 1;
	}

	if (n == 0) {
		cout << "Liczba Fibonacciego F(0) = 0" << endl;
		return 0;
	}

	if (n == 1) {
		cout << "Liczba Fibonacciego F(1) = 1" << endl;
		return 0;
	}

	unsigned long long a = 0, b = 1, c = 0;

	for (int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;     
		b = c;
	}

	cout << "Liczba Fibonacciego F(" << n << ") = " << c << endl;


		

	return(0);
}
*/
//8
/*int main()
{
	int a, b, temp;

		cout << "Podaj liczbe a:";
		cin >> a;
		
		cout << "Podaj liczbe b: ";
		cin >> b;

		cout << "Wyswietli przed zmianna: a = " << a << ", b = " << b << endl;

		temp = a;
		a = b;
		temp = b;

		cout << "Wyswietli nowe zmianne : a = " << a << ", b = " << b << endl;





	return(0);
}
*/
//9.1
/*int main() {
	
	int n;
	cout << "Wpisz ilosc liczb: n = ";
	cin >> n;

	vector<int> numbers(n);
	cout << "Wpisz " << n << " liczb: ";
	for (int i = 0; i < n; ++i) { 
		cin >> numbers[i];
	}

	cout << "Liczby parzyste: ";
	for (int i = 0; i < n; ++i) { 
		if (numbers[i] % 2 == 0) { 
			cout << numbers[i] << " ";
		}
	}
	cout << endl;

	return 0;
}
*/
//9.2
/*int main() {

	int n;
	cout << "Wpisz liczbe: n ";
	cin >> n;

	cout << "Liczby parzyste od 1 do " << n << ": ";
	for (int i = 1; i < n; ++i) {
		if (i % 2 == 0) {
			cout << i << " ";
		}
	}

	cout << endl;






	return(0);
}
*/
//10
/*int main() {

	int suma_parzystych = 0, suma_nieparzystych = 0, n;
	cout << "Wpisz liczbe: n ";
	cin >> n;
	 
	for (int i = 1; i < n; ++i) {
		if (i % 2 == 0) {
			 suma_parzystych += i;

		}
		else {
			 suma_nieparzystych += i;
		
		}

	}

	cout << "Suma liczb parzystych: " << suma_parzystych << endl;
	cout << "Suma liczb nieparzystych: " << suma_nieparzystych << endl;

	return(0);
}
*/
//11
/*int main() {

	int n;
	cout << "Wpisz liczbe: n ";
	cin >> n;

	for (int i = 1; i < n; ++i) {
		
		if (i % 3 == 0) {
			cout << "Liczbe podzielne przez 3: " << i << " ";
		}
		
		else if (i % 5 == 0) {
			cout << "Liczbe podzielne przez 5: " << i << " ";
		}
	}



	return(0);
}
*/
