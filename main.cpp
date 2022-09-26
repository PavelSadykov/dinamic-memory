//
//  main.cpp
//  Динамическая память
//
//  Created by Павел on 23.09.2022.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//Задача 1.
template<typename  T> //Заполняем массив случ числами
void fill_arr(T arr[],int length, int beg, int end){
    srand(time(0));
    for(int i=0; i< length; i++)
        arr[i] = rand()% (end-beg)+beg;
    
}
template <typename T>
void show_arr (T arr[], const T length){
cout<<"[ ";
for(int i = 0; i<length; i++){
cout<<arr[i]<<" ";
}
    cout<<"]\n";
}

template<typename T>
void arr_add(T *&arr, int length, int num){
  if(num<=0) // проверка на положительное значение
      return;// остановка выполнения программы
    T *tmp = new T [length+num] {};//создали промежуточный массив и увеличиваем длину массива на num, и заполняем его нулями {}
    for(int i=0; i<length;i++)//копируем элементы из arr в tmp
        tmp[i]=arr[i];
        //Очищаем изнач массив
     delete [] arr;
    arr = tmp; // перенаправляем на массив новой длины
    
}
//Задача 2.
template<typename T>
void arr_del(T *&arr, int length, int num){
  if(num<=0) // проверка на положительное значение
      return;// остановка выполнения программы
    if(num>=length){
        delete [] arr;
        arr = new T [0];
        return;
    }
    T *tmp = new T [length-num] ;//создали новый массив и уменьшаем длину массива на num
    for(int i=0; i<length-num;i++)//копируем элементы из arr в tmp
        tmp[i]=arr[i];
        //Очищаем изнач массив
     delete [] arr;
    arr = tmp; // перенаправляем указатель arr на массив новой длины
    
}


int main(int argc, const char * argv[]) {
    int n,m;

    //Выделение участка динамической памяти для хранения значения типа int
    int *p1=new int; //указатель хранит адрес  области динамической памяти
    cout<<"p1= "<<p1<<endl; //p1= 0x10103d440
    // разыменование ведет к области динамической памяти
    *p1=15;
    cout<<"*p1= "<<*p1<<endl;// *p1= 15
    
    //Очищаем область динамической памяти, на которую направлен указатель. Это нужно чтобы не было утечки данных (потери ячейки и ее адреса). Цель:  очистить ( разгрузить) память ненужной ячейкой с данными
    delete p1;
    
    p1=new int;//выделяем новый участок из оперативной памяти, т.е. перенаправление указателя
    cout<<"p1= "<<p1<<endl;//p1= 0x100742fa0
    cout<<"*p1= "<<*p1<<endl;//разыменование p1  это мусорное значение *p1= 0
    *p1=20;
    cout<<"*p1= "<<*p1<<endl;// 20
    delete p1;// контрольная зачистка
    p1=nullptr; //направляем указатель на нейтральную область памяти, чтобы прервать связь указателя с ячейкой динамической памяти
    //Проверяем
    if(p1==nullptr)
        cout<<"Указатель не направлен \n";
      else
          cout<<"*p1= "<<*p1<<endl;
    
    //динамический массив
   
    cout<<"Введите длину массива : ";
    cin>>n;
    //Выделение участка динамической памяти под динамический массив
    int *dArr = new int [n];
    
    for(int i=0; i<n ; i++){
        dArr[i] = (i+1)*10;
        cout<<dArr[i]<<" ";
        }
    cout<<endl;
    //Очистка памяти, выделенной под динамический массив
    delete[]dArr;
    dArr=nullptr;
    
    
    // Задача 1. Есть динамический массив ,он принимает длину и число после чего длина массива увеличивается на переданное значение
  
    cout<<"Введите длину массива : ";
    int size1;
    cin>>size1;
    int *arr1 = new int [size1];
    fill_arr(arr1,size1,1,100);
    cout<<"Изначальный массив : ";
    show_arr(arr1,size1);
    cout<<"Введите количество новых элементов : ";
    cin>>n;
    arr_add(arr1,size1,n);
    cout<<"Итоговый массив : ";
    if(n>0)
      size1+=n;
    show_arr(arr1,size1);
    cout<<endl;
    delete[]arr1;
    arr1=nullptr;
    
    
    //Задача 2. Есть динамический массив ,он принимает длину и число после чего длина массива уменьшается на переданное значение
    
    cout<<"Введите длину массива : ";
    int size2;
    cin>>size2;
    int *arr2 = new int [size2];
    fill_arr(arr2,size2,1,100);
    cout<<"Изначальный массив : ";
    show_arr(arr2,size2);
    cout<<"Сколько элементов удалить ? : ";
    cin>>n;
    arr_del(arr2,size2,n);
    if(n>=size2)
        size2=0;
    else
        if(n>0)
      size2-=n;
    cout<<"Итоговый массив : ";
    show_arr(arr2,size2);
    cout<<endl;
    delete[]arr2;
    arr2=nullptr;
    
    
    
    //Двумерный динамический массив - это указатель на указатели массивов
   // int *mx = new int[][];//неправильно!
    int rows = 5, cols = 3;
    int **mx = new int*[rows];
    for(int i = 0; i<rows;i++)
        mx[i] = new int [cols];
    //Очистка двумерного массива
   // delete[][]mx;//неправильно!
    for (int i=0;i<rows;i++)
        delete[]mx[i];
    delete[]mx;
    
    return 0;
}
