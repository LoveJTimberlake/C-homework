#include<iostream>
#include<string>
using namespace std;

// Person����һ����������ι������������ֶ��ＰEnclosureΪ����������

class Animal
{
public:
	Animal();
	~Animal() {};
	virtual bool Judge_Full_Reset() = 0;
	virtual void Eat_Food(int) = 0;
	virtual const int return_capacity() = 0;	
	const int return_eat_amount();
	virtual void Reset_Eat_Amount() { this->eat_amount = 0;}
	void Change_eat_amount(int);

private:
	int weight;
	int eat_amount;

};

class Elephant : public Animal
{
public:
	Elephant();
	~Elephant() {};
	virtual bool Judge_Full_Reset();
	virtual void Eat_Food(int);
	virtual const int return_capacity();
private:
	int Trunk_Length;
	int E_Capacity;
};

class Giraffe : public Animal
{
public:
	Giraffe();
	~Giraffe() {};
	virtual bool Judge_Full_Reset();
	virtual void Eat_Food(int);
	virtual const int return_capacity();
private:
	int G_Capacity;
	int Neck_Length;
};

class Monkey : public Animal
{
public:
	Monkey();
	~Monkey() {};
	virtual bool Judge_Full_Reset();
	virtual void Eat_Food(int);
	virtual const int return_capacity();
private:
	int M_Capacity;
	int Arm_Length;

};

class Enclosure		//���󣬳���¹������   ���������ܲ����㽶
{
public:
	Enclosure();
	~Enclosure() {} ;
	bool Judge_Mess_Add_Day();
	int Return_Closed_Days();	//����԰��ʼ��ʱ�����������󳤶�Ϊ3�����鲢���������������
	void Animal_Feeded_Add_Mess(Animal*,int);
	bool get_state();
	void Reopen();

private:
	int Closed_Days;	//������û�н��м���
	bool State;
	int mess;
};

class AnimalFood
{
public:
	AnimalFood(string type);
	AnimalFood(int num, int price,string type);	//��FoodSeller
	AnimalFood(int num, string type);			//��Child
	~AnimalFood(){	delete this;}
	void Selled(int);	//Seller
	void Feeded(int);	//Child,���������ʹ��
	void Child_GetFood(int);
	int Get_Num();

private:
	int num;
	int price;
	string Type;
};

class Person
{
public:
	Person();
	~Person() {};
private:
	string name;
	int age;
};

class Vistor :public Person
{
public:
	Vistor();
	~Vistor() {} ;
private:
	string ID;
};

class Child : public Person
{
public:
	Child();
	~Child() {};
	void GetFood(int ,int ,int);
private:
	AnimalFood B;
	AnimalFood P;
	AnimalFood C;
};

class Money
{
public:
	Money();
	~Money() {};
	void InitSum(int);	//���ڳ�ʼ��
	void Add(int);
	void Set(int);
	int return_sum();
	int return_dollar();
	int return_cent();
	friend Money operator+(Money& m1, Money& m2);
	friend Money operator-(Money& m1, Money& m2);
private:
	int sum;
	
};

class Adult : public Person
{
public:
	Adult();
	~Adult(){delete childs;};
	void InitMoney(int);
	void SetChild(int);
	void BuyTic(int);
	int Get_Money();
	int Get_ChildNum();
private:
	Money money;
	Child * childs;
	int childnum;
};


class ZooKeeper : public Person
{
public:
	ZooKeeper();
	~ZooKeeper(){};
	void Add_CleaningDay();
	int Return_CleaningDay();
private:
	int CleaningDay;
};

class ZooSeller:public Person
{
public:
	ZooSeller();
	ZooSeller(int,int,int,int,int,int);

	int Judge_OutofStore();
	void SellP(int);
	void SellB(int);
	void SellC(int);	//��������Ҫ���ж�num?=0�ļ��
	int Get_Benefit();

private:
	AnimalFood P;
	AnimalFood B;
	AnimalFood C;
	Money Benefit;
};

class Zoo
{
public:
	Zoo(int b,int bp,int p,int pp, int c,int cp);
	~Zoo();
	void Simulate_One_Day();
	void Print_Result();
	bool Judge_StateofZoo();
private:
	ZooKeeper Keeper;
	ZooSeller Seller;
	Adult * A;
	Elephant * El;
	Giraffe *G;
	Monkey *M;
	Enclosure E[3];
	int total_adult_num;
	int total_child_num;
	int open_day;
	int e[3];
};

