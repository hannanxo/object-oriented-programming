#include <iostream>
using namespace std;
class listType{
	public:
		int array[5];
		int top;
		int size;
		//Constructor
		listType()
		{
			top=-1;
			size=5;
		}
		//Checks if list is Empty
		bool isEmptyList()
		{
			return top==-1;
		}
		//Checks if list is Full
		bool isFullList()
		{
			return top==size-1;
		}
		//Insert in list
		void insert(int value)
		{
			if(!isFullList())
			{
				array[++top]=value;
			}
			else
			{
				cout<<"List is Full";
			}
		}
		//Print the elements of list
		void printList(){
			for(int i=0;i<=top;i++){
				cout<<array[i];
			}
		}
		//sorting the elements of list for searching
		void sorting() {
			for (int i = 0; i <= top; i++) 
			{
				int temp;
				for (int j = 0; j <= top; j++) {
					if (array[i] <= array[j]) {
						temp = array[j];
						array[j] = array[i];
						array[i] = temp;
					}
				}
			}
		}
		//searching the element
		int search(int value)
		 {
			sorting();
			int l = 0, h = (top);
			int mid = -1;
			while (h >= l) {
				mid = l + (h - l) / 2;
				if (value == array[mid]) {
					return mid;
				} else if (value < array[mid]) {
					h = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			return mid;
		}
		//fillroom for deleting element
		void fillRoom(int position) {
			if (position != size - 1) {
				for (int i = position; i <= top; i++) {
					array[i] = array[i + 1];
				}
				//cout << "Room Filled" << endl;
			} else {
				cout << "Already Filled" << endl;
			}
			top--;
		}
		//remove function
		void remove(int value) {
			int index = search(value);
			if (index != -1) {
				fillRoom(index);
			} else {
				cout << "Value not found" << endl;
			}
		}
		//Destroy list
		void destroylist(){
			top=-1;
		}
};
int main(){
	listType *l1=new listType();
	l1->insert(1);
	l1->insert(2);
	l1->insert(3);
	l1->printList();
	int position=l1->search(1);
	cout<<endl;
	cout<<"Value found at="<<position;
	l1->remove(2);
	cout<<endl;
	l1->printList();
	l1->destroylist();
	cout<<endl;
	l1->printList();
	l1->insert(1);
	cout<<endl;
	l1->printList();
	system("pause");
	return 0;
}
