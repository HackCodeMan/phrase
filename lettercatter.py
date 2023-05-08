from os import system
from random import randrange, shuffle

def word_input():
    result = None
    isinputed = False
    while not isinputed:
        print("Введите слово, затем его буквы будут перемешаны: ")
        result = input()

        print(f"Ваше слово {result}")
        answer_sure = input("Уверены? (y/n)\n")

        if answer_sure == 'y': isinputed = True
        elif answer_sure == 'n': continue
        else: print("Я не понимаю вас")
    system("cls")
    return result.lower()

def letter_catter(word: str):
    letters = list(word)
    shuffle(letters)
    return "".join(letters)

def gameplay(original_word, word_catter, MAX_ATTEMPTS):
    isWin = False
    print(f"У тебя будет {MAX_ATTEMPTS} попыток отгадать слово {word_catter}")
    i = 0
    while i <= MAX_ATTEMPTS and not isWin:
        answer = input()
        if answer == original_word: isWin = True
        else: print("Неверно")
        i += 1
    return isWin

def main():
    system("cls")
    original_word = word_input()
    word_catter = letter_catter(original_word)
    MAX_ATTEMPTS = 5
    isWin = gameplay(original_word, word_catter, MAX_ATTEMPTS)
    if not isWin:
        for i in range(10): print("ЛОШАРА")
    elif isWin: print("МОЛОДЕЦ")
    print(f"Загаданное слово: {original_word.capitalize()}")
    input()

main()