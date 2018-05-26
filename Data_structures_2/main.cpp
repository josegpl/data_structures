#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"structs.h"
#include"AVL.h"
#include"RedBlack.h"
#include "list.h"
#include "Binary.h"

using namespace std;

vector<string> vector_of_words(string frase);
void ocurrences(Data* data, vector<string> doc);
Data *vamo(string frase);

int main(){
    AVLnode* AVLroot = NULL;
    RBnode* RBroot= NULL;
    lista* listRoot = NULL;
    Bnode* Broot = NULL;

    ifstream entrada;
    entrada.open("test.txt");
    int i = 0;
    char *teste;
    int line = 1;
    vector<string> documento;//contém todas as linhas
    vector<int> chaves;
    //criar vector com todas as linhas
    while(!entrada.eof()){
        char buffer[1000];
        entrada.getline(buffer,1000);
        string str = buffer;
        documento.push_back(str);
    }

    for(int i = 0; i < documento.size(); i++) {
        Data *dado = vamo(documento[i]);
        if (dado!=NULL) {
            /*AVL*/
                    AVLroot = insert_AVLnode(AVLroot, dado);
                    /*Red and Black*/
                    RB_Insert(&RBroot, dado);
                    /*Lista*/
                    insFim(&listRoot, dado);
                    /*Binary Tree*/
                    B_Insert(&Broot, dado);
        }
    }
    //começar adicionar elementos
    /*
    for(int i = 0; i < documento.size(); i++){
        /*gerar palavras*/ /*
        vector<string> palavras = vector_of_words(documento[i]);
        for(int j = 0; j < palavras.size(); j++){
            //busca se elemento ja existe
            //verifica o tamanho
            if(palavras[j].size() > 2){
                Data* dado = new Data[1];
                if(dado != NULL){
                    dado->key = valorString(palavras[j]);
                    dado->palavra = palavras[j];
                    ocurrences(dado, documento);
                    /*Inserções*/

                    /*AVL*/ /*
                    AVLroot = insert_AVLnode(AVLroot, dado);
                    /*Red and Black*/ /*
                    RB_Insert(&RBroot, dado);
                    /*Lista*/ /*
                    insFim(&listRoot, dado);
                    /*Binary Tree*/ /*
                    B_Insert(&Broot, dado);
                }
            }
        }
    } */
    entrada.close();



    /*Buscas nas estruturas*/
    //Váriaveis
    Data *dado = NULL;
    int passos = 0;
    char buffer[100];
    int keytofind;
    string busca;
    //BUSCA NA AVL
    cout << "digite a palavra que quer buscar" << endl;
    //cin.getline(buffer,100);
    cin >> keytofind;
    busca = buffer;
    //Busca elemento na AVL
    Query(AVLroot, &dado, keytofind, &passos);
    cout<<"tempo gasto na busca AVL: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout << "palavra: "<<dado->palavra << endl;
       /* for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl; */
    }


    /*Busca na RB*/
passos=0;
    cout << "digite a palavra que quer buscar" << endl;
    /*cin.getline(buffer,1000);
    busca = buffer; */
    cin >> keytofind;
    RBQuery(RBroot, &dado, keytofind, &passos);
    cout<<"tempo gasto na busca REDBLACK: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout << "palavra: "<<dado->palavra << endl; /*
        for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl; */
    }else{
        cout<<"não foi encontrado";
    }
passos=0;
    /*Busca na Lista Encadeada*/
     cout << "digite a palavra que quer buscar" << endl;
    /*cin.getline(buffer,1000);
    busca = buffer;*/
    cin >> keytofind;
    listaQuery(listRoot, &dado, keytofind, &passos);
    cout<<"tempo gasto na busca LISTA: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout <<"chave: " << dado->key <<" dado2: " <<dado->dado1  <<" palavra: "<<dado->palavra << endl; /*
        for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl; */
    }else{
        cout<<"não foi encontrado";
    }

    /*Busca na Binary Tree*/
passos=0;
    cout << "digite a palavra que quer buscar" << endl;
    /*cin.getline(buffer,1000);
    busca = buffer; */
    cin >> keytofind;
    BinaryQuery(Broot, &dado, keytofind, &passos);
    cout<<"tempo gasto na busca BINARY: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout << "palavra: "<<dado->palavra << endl; /*
        for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl; */
    }else{
        cout<<"não foi encontrado";
    }

    Destroy(AVLroot);
    //RBDestroy(RBroot);
    //tDestroy(Broot);
    //int x = listaDestroy(listRoot);
    return 0;
}
Data *vamo(string frase) {

    Data *newdata = new Data[1];
    string del = " "; //delimitador
    int i;
    size_t pos = frase.find(del);
    char str[10];
    string aux = frase.substr(0, pos);
    strcpy(str, aux.c_str());
    int newkey = atoi(str);
    newdata->key = newkey;
    frase.erase(0, pos + del.length());
    pos = frase.find(del);
    aux = frase.substr(0, pos);
    strcpy(str, aux.c_str());
    float newfloat = atof(str);
    newdata->dado1 = newfloat;
    frase.erase(0, pos + del.length());
    string str3 = frase;
    newdata->palavra = str3;

    return newdata;

}
//Pega palavras da frase
vector<string> vector_of_words(string frase){
    vector<string> vet;
    string del = " ";//delimitador
    size_t pos = 0;
    string word;
    while((pos = frase.find(del)) != string::npos){
        word = frase.substr(0, pos);
        vet.push_back(word);
        frase.erase(0, pos + del.length());
    }
    //Para pegar a última palavra da frase
    word = frase.substr(0, pos);
    vet.push_back(word);

    return vet;
}

/*Função que verifica as ocorrências no texto
  e preencher o struct data*/
void ocurrences(Data* data, vector<string> doc){
    //ver onde ocorre a palavra
    int line = 1;
    for(int i = 0; i < doc.size(); i++){
        if(doc[i].find(data->palavra) != string::npos){
            //data->linhas.push_back(doc[i]);
            //data->ocorrencias.push_back(line);
        }
        line++;
    }
}
