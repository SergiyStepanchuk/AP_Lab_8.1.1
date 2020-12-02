// Lab_8_1_1
// скануванням рядка ітераційним способом

#include <iostream>
#include <string>
using namespace std;

int count_strs(const char* str) {
	if (strlen(str) < 3)
		return 0;
	int count = 0;
	for (int i = 1; i < str[i+1] != '\0'; i++)
		if (str[i - 1] == ',' && str[i + 1] == '-')
			count++;
	return count;
}

void change_str(char* str)
{
	if (strlen(str) < 3)
		return;

	char* tmp = new char[strlen(str)+1];
	int i = 0, m = 0;
	while (str[i+2] != '\0') {
		if (str[i] == ',' && str[i + 2] == '-') {
			*(tmp + m++) = '*';
			*(tmp + m) = '*';
			i+=2;
		}
		else tmp[m] = str[i];
		i++; m++;
	}
	tmp[m++] = str[i++];
	tmp[m++] = str[i];
	tmp[m] = '\0';
	str[0] = '\0';
	strcpy(str, tmp);
	delete[] tmp;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << count_strs(str) << " groups of ', -'" << endl;
	change_str(str);
	cout << "Modified string (param) : " << str << endl;
	return 0;
}