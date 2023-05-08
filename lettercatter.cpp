#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <windows.h>


void keep_windows_open(){int k; std::cin >> k;}

// Преобразование строк в верхний или нижний регистр
std::string to_registrs(std::string str, std::string mode)
{
	using namespace std;
	string result = "";

	if (str == "") cerr << "Error: Your string have invalid value";

	if (mode == "UPPER") {for(char i : str) result += toupper(i);}
	else if (mode == "lower"){for(char i : str) result += tolower(i);}
	else if (mode == "Capitalize") 
	{
		string first_letter = to_string(toupper(char(str[0])));
		string other_letters = "";
		for (int i = 1; i < str.length(); i++) {other_letters += tolower(char(str[i]));}
		result += first_letter + other_letters;
	}
	else cerr << "Errors: invalid argument";
	return result;
}

// Генератор случайных чисел в диапазоне
int randomize(int start_range, int end_range) {return start_range + rand() % end_range;} 

// Ввод слова
std::string word_input()
{
	using namespace std;
	string result;
	for (bool isinputed = false; !(isinputed);)
	{
		cout << "Введите слово, затем его буквы будут перемешаны: \n";
		cin >> result;

		cout << "Ваше слово " << result << endl
		<< "Уверены? (y/n)\n";
		char answer_sure;
		cin >> answer_sure;

		if (answer_sure == 'y') isinputed = true;
		else if (answer_sure == 'n') continue;
		else cout << "Я не понимаю вас\n";
	}
	system("cls");
	return to_registrs(result,"lower");
}         
// Размешивает буквы в слове
std::string letter_catter(std::string word)
{
	using namespace std;
	string result = "";
	vector<char> letters_in_word(word.length());
	for (int i = 0; i < word.length(); i++) letters_in_word[i] = char(word[i]);
	for (int i = 0; i < randomize(0,100); i++)
	{
		int rand_item = randomize(0,word.length() - 1);
		char x = letters_in_word.back();
		letters_in_word[letters_in_word.size() - 1] = letters_in_word[rand_item];
		letters_in_word[rand_item] = x;
	}
	for (int i = 0; i < letters_in_word.size(); i++)
	{
		result += letters_in_word[i];
	}
	return result;
}

// Основной геймплей игры 
bool gameplay(std::string original_word, std::string word_catter,int max_attempts)
{
	using namespace std;
	bool isWin = false;

	cout << "У тебя будет " << max_attempts <<" попыток отгадать слово " << word_catter << endl;
	for (int i = 0; (i <= max_attempts)&&(!isWin); i++)
	{
		string answer;
		cin >> answer;

		if (answer == original_word) isWin = true;
		else cout << "Неверно\n";
	}
	return isWin;
}

int main(int argc, char const *argv[])
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(0));
	system("cls");
	std::string original_word = word_input();
	std::string word_catter = letter_catter(original_word);
	constexpr unsigned short int max_attempts = 5;
	bool isWin = gameplay(original_word, word_catter, max_attempts);
	if (!isWin) {for (int i; i <= 10; i++) std::cout << "ЛОШАРА\n";}
	else if (isWin) std::cout << "МОЛОДЕЦ\n";
	std::cout << "Загаданное слово: " << to_registrs(original_word,"Capitalize") <<  std::endl;
	keep_windows_open();
	return 0;
}
