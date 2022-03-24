/*
This file consist of :
    - IsLess & IsGreater functions

    - A Templated dynamically growing array has the following :
        1-  constructor that receive 2 inputs from user
            size        : default 5
            defaultOpt  : default optimization to choose between ("RAM" or "TIME"), when expanding the array
                          if you choose "RAM" --> the array grow element by element, "TIME" --> will duplicate the capacity

        2- cap ->           the capacity of the array
        3- nrOfEl ->        number of elements in the
        4- push_back ->     adds a single element to the array
        5- remove_if ->     takes pointer to function and number to compare with to remove elements that satisfies that predicate
        6- [] operator ->   to access the elements
        7- size() ->        return the number of elements
*/
#include<iostream>
#include<string>


using namespace std;



template<typename T>
bool IsLess (T cond, T element) {
    return( element < cond );
}

template<typename T>
bool IsGreater (T cond, T element) {
    return( element > cond );
}


template<typename T>
class dynArr
{
private:
	T **arr;
	int cap;
	int nrOfEl;
	string opt;

public:
	dynArr(int size = 5, string defaultOpt="RAM");
	~dynArr();

	void expand();
	void push_back(T element);
	void remove_if(bool (*predicate)(T,T) , int);
	const int& size()const { return this->nrOfEl; }
	T operator[] (const int index);
};


template<typename T>
dynArr<T>::dynArr(int size,string defaultOpt)
{
	this->cap = size;
	this->nrOfEl = 0;
	this->arr = new T*[this->cap];
	this->opt=defaultOpt;
}

template<typename T>
dynArr<T>::~dynArr()
{
	for (size_t i = 0; i < nrOfEl; i++)
	{
		delete this->arr[i];
	}
	delete[]this->arr;
}





template<typename T>
void dynArr<T>::push_back(T element)
{
    //cout<<this->cap<<endl;
    if (this->nrOfEl >= this->cap)
	{
		this->expand();
	}
    this->arr[this->nrOfEl++]= new T(element);
}


template<typename T>
void dynArr<T>::expand()
{
    if(opt=="RAM")
    {
        this->cap+=1;
    }
    if(opt=="TIME")
    {
        this->cap*=2;
    }
    T **tempArr= new T*[this->cap];
    for(int i=0; i<this->nrOfEl; i++)
    {
        tempArr[i]=this->arr[i];
    }
    this->arr=tempArr;
}

template<typename T>
void dynArr<T>::remove_if(bool (*predicate)(T,T), int cond)
{

    for(int i=0; i<this->nrOfEl; i++)
    {
        if(predicate(cond, (*this->arr[i]) ))
        {
            for(int j=i; j<this->nrOfEl-1; j++)
            {
                *this->arr[j]=*this->arr[j+1];
            }

            delete this->arr[this->nrOfEl-1];
            i--;    //step back one index to handle removed elements
            this->nrOfEl--; //decrease number of elements
        }
    }



}

template<typename T>
T dynArr<T>::operator[](const int index)
{
	if (index < 0 || index >= this->nrOfEl)
    {
		throw std::out_of_range("Invalid position!");
    }
	return *this->arr[index];
}

int main()
{

	dynArr<int> MyDyArr(5,"TIME");

	MyDyArr.push_back(220);
	MyDyArr.push_back(2003);
	MyDyArr.push_back(20300);
	MyDyArr.push_back(24000);
	MyDyArr.push_back(20006);
	MyDyArr.push_back(230);
	MyDyArr.push_back(260);
	MyDyArr.push_back(205);
	MyDyArr.push_back(205);
	MyDyArr.push_back(24000);
	MyDyArr.push_back(280);
	MyDyArr.push_back(205);
    MyDyArr.push_back(220);
	MyDyArr.push_back(2003);
	MyDyArr.push_back(20300);
	MyDyArr.push_back(2400);
	MyDyArr.push_back(20006);
	MyDyArr.push_back(230);
	MyDyArr.push_back(260);
	MyDyArr.push_back(205);
	MyDyArr.push_back(205);
	MyDyArr.push_back(5000);
	MyDyArr.push_back(280);
	MyDyArr.push_back(277);
    MyDyArr.push_back(220);
	MyDyArr.push_back(2003);
	MyDyArr.push_back(10);
	MyDyArr.push_back(24000);
	MyDyArr.push_back(20006);
	MyDyArr.push_back(230);
	MyDyArr.push_back(260);
	MyDyArr.push_back(205);
	MyDyArr.push_back(205);
	MyDyArr.push_back(270);
	MyDyArr.push_back(280);
	MyDyArr.push_back(205);


	cout<<"Befor removing ...   Size = "<<MyDyArr.size()<<endl;
	for (size_t i = 0; i < MyDyArr.size(); i++)
	{
		cout << MyDyArr[i] << endl;
	}


    MyDyArr.remove_if(&IsLess, 250);
	cout<<"After removing elements less than 250 ... Size = "<<MyDyArr.size()<<endl;
	for (size_t i = 0; i < MyDyArr.size(); i++)
	{
		cout << MyDyArr[i] << endl;
	}


    MyDyArr.remove_if(&IsGreater, 300);
	cout<<"After removing elements Greater than 300 ... Size = "<<MyDyArr.size()<<endl;

	for (size_t i = 0; i < MyDyArr.size(); i++)
	{
		cout << MyDyArr[i] << endl;
	}


	return 0;
}
