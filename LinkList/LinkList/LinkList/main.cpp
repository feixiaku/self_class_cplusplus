#include <iostream>
#include <assert.h>

using namespace std;

typedef struct Student {
	int number;
	int age;
	char* name;
	Student* next;
};

Student* CreatLinkList(int num)
{
	char* nameArray[3] = { "wangl", "whh", "wjk" };
	int ageArray[3] = {27, 26, 60};
	Student *pNew, *pHead, *pRear;
	for (int i = 0; i < num; i++)
	{
		pNew = new Student;
		pNew->number = i + 1;
		pNew->age = ageArray[i];
		pNew->name = nameArray[i];
		pNew->next = NULL;
		
		if (i == 0)
		{
			pHead = pRear = pNew;
		}
		else
		{ 
			pRear->next = pNew;
		}
		
		//Pointer to another position
		pRear = pNew;
		
	}
	return pHead;
}

void PrintLinkList(Student* pHead)
{
	Student* pTmp = pHead;
	assert(pTmp != NULL);
	while (pTmp != NULL)
	{
		cout << "p->number: " << pTmp->number << " p->name: " << pTmp->name << endl;
		pTmp = pTmp->next;
	}
}

Student* InsertItem(Student *pHead, int num)
{
	assert(pHead != NULL);
	Student *p = pHead;
	int ageInsert = 30;
	int numberInsert = 4;
	char* nameInsert = "wangf";
	Student *pInsert = new Student;
	pInsert->age = ageInsert;
	pInsert->name = nameInsert;
	pInsert->number = numberInsert;

	while (p != NULL && p->number != (num - 1))
	{
		p = p->next;
	}
	
	pInsert->next = p->next;
	p->next = pInsert;
		
	//delete[] pInsert;
	return pHead;
}

void DeletItem(Student *p, int num)
{
	assert(p != NULL);
	Student *pTmp;
	while (p && p->number != (num - 1))
	{
		p = p->next;
	}

	p->next = p->next->next;
}

Student* GetItem(Student *pHead, int num)
{
	assert(pHead != NULL);
	Student *p = pHead;
	while (p && p->number != num)
	{
		p = p->next;
	}

	return p;
}

void main()
{
	Student *pHead;
	int num;
	printf("Create a LinkList\n");
	num = 3;

	//Create A LinkList
	pHead = CreatLinkList(num);
	PrintLinkList(pHead);

	//Insert A Item
	pHead = InsertItem(pHead, 4);
	cout << "Insert Item" << endl;
	PrintLinkList(pHead);

	//Delet A Item
	DeletItem(pHead, 2);
	cout << "Delet Item" << endl;
	PrintLinkList(pHead);

	//Get Item
	Student *target = GetItem(pHead, 3);
	cout << "num:  " << target->number << " name: " << target->name << endl;
	return;
}