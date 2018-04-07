#include<iostream>
#include<string>
using namespace std;

// Person处有一个函数进行喂养动物，需以三种动物及Enclosure为友类来定义

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

class Enclosure		//大象，长颈鹿，猴子   花生，胡萝卜，香蕉
{
public:
	Enclosure();
	~Enclosure() {} ;
	bool Judge_Mess_Add_Day();
	int Return_Closed_Days();	//动物园初始化时创建地区对象长度为3的数组并在最后遍历输出数据
	void Animal_Feeded_Add_Mess(Animal*,int);
	bool get_state();
	void Reopen();

private:
	int Closed_Days;	//看看有没有进行计算
	bool State;
	int mess;
};

class AnimalFood
{
public:
	AnimalFood(string type);
	AnimalFood(int num, int price,string type);	//给FoodSeller
	AnimalFood(int num, string type);			//给Child
	~AnimalFood(){	delete this;}
	void Selled(int);	//Seller
	void Feeded(int);	//Child,后面视情况使用
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
	void InitSum(int);	//用于初始化
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
	void SellC(int);	//这三个都要进行对num?=0的检查
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

