
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int i;
    char text[256] = "difficult? data, array: variable; loop. math";
    cout << "Text: " << endl <<"\t" <<text<<endl;
    char cleanedText[256] = "";
    char wordsWithRepetition[256] = "";
    strcpy(cleanedText, text);

    char* oneWord = strtok(text, " ,.?!:;\t\n"); // розбиваємо рядок на слова

    while (oneWord!=NULL){
        //bool noRepetition = true;
        int lengthOfWord = strlen(oneWord);

        for (i = 0; i < lengthOfWord - 1; i++){
            if (oneWord[i] == oneWord[i + 1]) //перевіряємо чи містить слово подвоєння
            {
                strcat(wordsWithRepetition, oneWord); //об'єднуємо слово с пустим масивом
                strcat(wordsWithRepetition, " ");     //додаємо пробіл
                char* place = strstr(cleanedText, oneWord); //визначаємо чи входить наше слово доцього рядка
                                                            //та отримуємо вказівник на перше його входження
                if (place != NULL){
                    int diff = place - cleanedText; //знаходимо індекс першого символу слова у рядку
                    for (int i = diff; i < strlen(cleanedText); i++)
                        cleanedText[i] = cleanedText[i + lengthOfWord]; //перезаписуємо слово тими елементами,
                                                                        // що йдуть після цього слова
                }
                break; //прериваємо цикл for
            }
        }
        oneWord = strtok(0, " ,.?!:;\t\n");//знову розділяємо рядок починаючи з нуль термінатора
    }


    cout <<"cleaned text: " << endl <<"\t" <<cleanedText << endl;
    cout << "deleted words: " << endl <<"\t" <<wordsWithRepetition << endl;

    return 0;
}





