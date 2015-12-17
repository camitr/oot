/* Insertion program with random array generation.
  Implementation of Inheritence and example of drive class constructor.*/
#include<iostream>
#include<cstdlib>

using namespace std;

class Arrays{							//base class.

protected:
	int sizeofarray;
	int* arrayList;
public:
		Arrays(int num);

void	arrayRandom();
void	arrayInput();
void	arrayShow();
};

class Insertion : public Arrays {           // Derived class.

public:
        Insertion(int num) : Arrays(num)	//constructor defined.	
		{
			sizeofarray = num;
		}
void	insertionSort();
int		insertionComp(int num1, int num2);
};

Arrays::Arrays(int num)
{
	sizeofarray = num;
}

void Arrays::arrayRandom()
{
	arrayList = new int[sizeofarray];                                                                        
    srand((unsigned)time(NULL));                                                                              
        for(int i=0;i<sizeofarray;i++)                                                                        
        {                                                                                                     
            this->arrayList[i] = 1 + rand() %100;                                                            
            cout<<arrayList[i]<<endl;                                                                        
        }                                                                                                     
}       

void Insertion::insertionSort()
{
	int swap =0,comp=0,compresult;
	if (sizeofarray ==1)
	{
		cout<<"array has only one element"<<endl;
		exit;
	}
	cout<<"size of array "<<sizeofarray<<endl;
	for(int i=1; i<sizeofarray; i++)
	{
		for(int j=i;j>0;j--)
		{
			compresult=insertionComp(arrayList[j-1],arrayList[j]);
			++comp;
			if(compresult==-1)
			{
			swap = swap + 1;
			int temp = arrayList[j-1];
				arrayList[j-1] = arrayList[j];
				arrayList[j] = temp;
			
			}
		}
		arrayShow();
	}

	
cout<<"Number of swaps= "<<swap<<endl;
cout<<"Number of comparision= "<<comp<<endl;

}
void Arrays::arrayShow()
{
	for(int i =0; i<sizeofarray; i++)
	{
		cout<<arrayList[i]<<"\t";
	}
	cout<<endl;
}

void Arrays::arrayInput()
{
	arrayList = new int[sizeofarray];
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<"enter the "<<i<<"th element of the array"<<endl;
		cin>>arrayList[i];
	}
}


int Insertion::insertionComp(int a,int b)
{
	if(a>b)
	{
	return -1;
	}
}
int main()
{
	int size;
	char opton;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	Insertion obj(size);					//Object of drive class created. 
	cout<<"For random array press R"<<endl;
	cin>>opton;
	if(opton == 'R')
	{
		obj.arrayRandom();					// Drive class function called.
	}
	else
	{
		obj.arrayInput();
	}
cout<<"Sorted array"<<endl;
	obj.insertionSort();

}

