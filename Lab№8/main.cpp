
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

    char* oneWord = strtok(text, " ,.?!:;\t\n"); // ��������� ����� �� �����

    while (oneWord!=NULL){
        //bool noRepetition = true;
        int lengthOfWord = strlen(oneWord);

        for (i = 0; i < lengthOfWord - 1; i++){
            if (oneWord[i] == oneWord[i + 1]) //���������� �� ������ ����� ��������
            {
                strcat(wordsWithRepetition, oneWord); //��'������ ����� � ������ �������
                strcat(wordsWithRepetition, " ");     //������ �����
                char* place = strstr(cleanedText, oneWord); //��������� �� ������� ���� ����� ������� �����
                                                            //�� �������� �������� �� ����� ���� ���������
                if (place != NULL){
                    int diff = place - cleanedText; //��������� ������ ������� ������� ����� � �����
                    for (int i = diff; i < strlen(cleanedText); i++)
                        cleanedText[i] = cleanedText[i + lengthOfWord]; //������������ ����� ���� ����������,
                                                                        // �� ����� ���� ����� �����
                }
                break; //��������� ���� for
            }
        }
        oneWord = strtok(0, " ,.?!:;\t\n");//����� ��������� ����� ��������� � ���� ����������
    }


    cout <<"cleaned text: " << endl <<"\t" <<cleanedText << endl;
    cout << "deleted words: " << endl <<"\t" <<wordsWithRepetition << endl;

    return 0;
}





