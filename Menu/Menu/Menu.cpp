#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

string removeVowels(const std::string& word) {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), [](char c) { return string("aeiouAEIOU").find(c) != string::npos; }), result.end());
    return result;
}

void removeConsonants(const std::string& word) {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), [](char c) { return string("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ").find(c) != string::npos; }), result.end());
    cout << "Слово без согласных: " << result << endl;
}

void shuffleWord(const std::string& word) {
    string shuffledWord = word;
    random_shuffle(shuffledWord.begin(), shuffledWord.end());
    cout << "Перемешанное слово: " << shuffledWord << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string word;
    int id;

    cout << "Введите слово: ";
    cin >> word;

    cout << "1. Слово выводится задом наперед.\n2. Вывести слово без гласных.\n3. Вывести слово без согласных.\n4. Рандомно раскидывать буквы заданного слова.\n";
    cin >> id;

    switch (id) {
    case 1:
    {
        string reversedWord = word;
        reverse(reversedWord.begin(), reversedWord.end());
        cout << "Слово задом наперед: " << reversedWord << endl;
        break;
    }
    case 2:
    {
        string result = removeVowels(word);
        cout << "Слово без гласных: " << result << endl;
        break;
    }
    case 3:
        removeConsonants(word);
        break;
    case 4:
        shuffleWord(word);
        break;
    default:
        cout << "Неверный выбор." << endl;
        break;
    }

    return 0;
}
