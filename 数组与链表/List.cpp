#include<iostream>
using namespace std;

class List
{
	private:
		int *arr;
		int arr_size = 0;
		int arr_capacity = 10;
		int extendratio = 2;
		
		
	public:
		
		List()
		{
			arr = new int[arr_capacity];	
		}
		
		~List()
		{
			delete[] arr;
		}
		
		int size()
		{
			return arr_size;
		}
		
		int capacity()
		{
			return arr_capacity;
		}
		
		//����Ԫ�� 
		int get(int index)
		{
			
			return arr[index];
		}
		
		//����Ԫ��
		void set(int index,int num)
		{
		
			arr[index] = num;
		}
		
		//ɾ��Ԫ��
		void remove(int index)
		{
			
			for(int i=index;i<arr_size-1;++i)
			{
				arr[i] = arr[i+1];
			}
			arr_size--;
		} 
		
		//����Ԫ��
		void insert(int index,int num)
		{
			
			arr_size++;
			if(arr_size>arr_capacity)
			{
				extend();
			}
			for(int i=arr_size-1;i>index;--i)
			{
				arr[i]=arr[i-1];
			}
			arr[index]=num;
		}
		
		
		//��β�����Ԫ�� 
		void push_back(int num)
		{
			arr_size++;
			if(arr_size>arr_capacity)
			{
				extend();
			}
			arr[arr_size-1]=num;
		}
		
		//��β��ɾ��Ԫ��
		void pop_back()
		{
			arr[arr_size-1]=0;
			arr_size--;
		} 
		
		//��������
		void extend()
		{
			int *tmp = arr;
			int *arr = new int[arr_capacity*extendratio];
			for(int i=0;i<arr_size;++i)
			{
				arr[i] = tmp[i];
			}
			delete[] tmp;
			arr_capacity*=extendratio;
		}
		
	
};

int main()
{
	List Mylist;
	
	for(int i=0;i<10;i++)
	{
		Mylist.set(i,i);
		//printf("%d\n",i);
		printf("%d\n",Mylist.get(i));
	}
	
	Mylist.push_back(1);
	printf("%d",Mylist.get(9));
	
	return 0;
}
