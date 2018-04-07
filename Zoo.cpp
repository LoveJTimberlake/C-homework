#include<iostream>
#include<string>
#include<time.h>
#include"zoo.h"
using namespace std;


AnimalFood::AnimalFood(string type)
{
	Type = type;
}

AnimalFood::AnimalFood(int num, int price, string type)
{
	this->num = num;
	price = price;
	Type = type;
}

AnimalFood::AnimalFood(int num, string type)
{
	this->num = num;
	Type = type;
}

void AnimalFood::Selled(int n)
{
	num -= n;
}

void AnimalFood::Feeded(int n)
{
	num -= n;
}

int AnimalFood::Get_Num()
{
	return num;
}

void AnimalFood::Child_GetFood(int num)
{
	this->num += num;
}

Animal::Animal()
{
	eat_amount = 0;
}


void Animal::Change_eat_amount(int food)
{
	eat_amount += food;
}

Elephant::Elephant()
{
	E_Capacity = 750;
	Reset_Eat_Amount();
	Trunk_Length = 160;
}

bool Elephant::Judge_Full_Reset()
{
	if(return_eat_amount() >= return_capacity())
	{
		Reset_Eat_Amount();
		return true;
	}
	else return false;
}

void Elephant::Eat_Food(int food)
{
	Change_eat_amount(food);
}

const int Animal::return_eat_amount()
{
	return eat_amount;
}

const int Elephant::return_capacity()
{
	return E_Capacity;
}

Giraffe::Giraffe()
{
	G_Capacity = 500;
	Reset_Eat_Amount();
	Neck_Length = 150;
}

bool Giraffe::Judge_Full_Reset()
{
	if(return_eat_amount() >= return_capacity())
	{
		Reset_Eat_Amount();
		return true;
	}
	else return false;
}

void Giraffe::Eat_Food(int food)
{
	Change_eat_amount(food);
}

const int Giraffe::return_capacity()
{
	return G_Capacity;
}

Monkey::Monkey()
{
	Arm_Length = 80;
	M_Capacity = 300;
	Reset_Eat_Amount();
}

bool Monkey::Judge_Full_Reset()
{
	if(return_eat_amount() >= return_capacity())
	{
		Reset_Eat_Amount();
		return true;
	}
	else return false;
}

void Monkey::Eat_Food(int food)
{
	Change_eat_amount(food);
}

const int Monkey::return_capacity()
{
	return M_Capacity;
}

Enclosure::Enclosure()
{
	mess = 0;
	State = true;
	Closed_Days = 0;
}

bool Enclosure::Judge_Mess_Add_Day()
{
	if(mess > 2000)
	{
		mess = 0;
		Closed_Days++;
		State = false;
		return true;
	}
	else return false;
}

int Enclosure::Return_Closed_Days()
{
	return Closed_Days;
}

bool Enclosure::get_state()
{
	return State;
}

void Enclosure::Animal_Feeded_Add_Mess(Animal * A, int food)
{
	A->Eat_Food(food);
	if(A->Judge_Full_Reset())	mess += A->return_capacity();
}

void Enclosure::Reopen()
{
	this->State = true;
}

Money::Money()
{
	InitSum(0);
}

void Money::InitSum(int s)
{
	sum = s;
}

void Money::Add(int s)
{
	sum += s;
}

void Money::Set(int s)
{
	sum = s;
}

int Money::return_sum()
{
	return sum;
}


Money operator+(Money&m1,Money&m2)
{
	Money result;
	result.Set(m1.return_sum() + m2.return_sum());
	return result;
}

Money operator-(Money &m1,Money&m2)
{
	Money result;
	result.Set(m1.return_sum() - m2.return_sum());
	return result;
}

Person::Person()
{
}

ZooKeeper::ZooKeeper()
{
	CleaningDay = 0;
}

void ZooKeeper::Add_CleaningDay()
{
	CleaningDay++;
}

int ZooKeeper::Return_CleaningDay()
{
	return CleaningDay;
}

ZooSeller::ZooSeller(int b,int bp, int p,int pp, int c,int cp):B(b,bp,"Banana"),P(p,pp,"Peanut"),C(c,cp,"Carrot")
{
	Benefit.InitSum(0);
}

int ZooSeller::Judge_OutofStore()
{
	if((P).Get_Num() <= 0 )
	{
		return 1;
	}
	else if((B).Get_Num() <= 0)
	{
		return 3;
	}
	else if((C).Get_Num() <= 0) return 2;
	else return 0;
}

void ZooSeller::SellP(int copies)
{
	if(P.Get_Num() - copies >= 0)
	{
		Benefit.Add(20 * copies);
		P.Selled(copies);
	}
	else 
	{
		Benefit.Add(20 * (P.Get_Num()));
		P.Selled(P.Get_Num());
	}
}

void ZooSeller::SellB(int copies)
{
	if(B.Get_Num() - copies >= 0)
	{
		Benefit.Add(20 * copies);
		B.Selled(copies);
	}
	else 
	{
		Benefit.Add(20 * (B.Get_Num()));
		B.Selled(B.Get_Num());
	}
}

void ZooSeller::SellC(int copies)
{
	if(C.Get_Num() - copies >= 0)
	{
		Benefit.Add(20 * copies);
		C.Selled(copies);
	}
	else 
	{
		Benefit.Add(20 * (C.Get_Num()));
		C.Selled(C.Get_Num());
	}
}

int ZooSeller::Get_Benefit()
{
	return Benefit.return_sum();
}

Child::Child():B(0,"Banana"),P(0,"Peanut"),C(0,"Carrot")
{

}

void Child::GetFood(int b,int p,int c)
{
	P.Child_GetFood(p);
	B.Child_GetFood(b);
	C.Child_GetFood(c);
}

Adult::Adult()
{
	int m,c;
	srand(int(time(0)));
	m = rand()%11+ 10;
	c = rand()%3 + 1;
	InitMoney(m*100);
	SetChild(c);
	BuyTic(100+40*c);
}

void Adult::SetChild(int c)
{
	childnum = c;
	childs = new Child[c];
}

void Adult::InitMoney(int m)
{
	money.InitSum(m);
}

int Adult::Get_Money()
{
	return money.return_sum();
}

int Adult::Get_ChildNum()
{
	return childnum;
}

void Adult::BuyTic(int s)
{
	money.Set(money.return_sum() - s);
}

Zoo::Zoo(int b,int bp,int p,int pp, int c,int cp):Seller( b, bp,p, pp,  c, cp)
{
	total_adult_num = 0;
	total_child_num = 0;
	open_day = 0;
	El = new Elephant[1];
	G = new Giraffe[2];
	M = new Monkey[3];
	e[0] = e[1] = e[2] = 0;
}

void Zoo::Simulate_One_Day()
{
	open_day++;
	if(open_day == e[0]+ 2 && !E[0].get_state() && e[0] != 0)
	{
		E[0].Reopen();
	}
	else if(open_day == e[1]+ 2 && !E[1].get_state() && e[1] != 0)
	{
		E[1].Reopen();
	}
	else if(open_day == e[2]+ 2 && !E[2].get_state() && e[2] != 0)
	{
		E[2].Reopen();
	}
	int adult_num_perday;
	srand(int(time(0)));
	adult_num_perday = rand()%21 + 20;
	total_adult_num += adult_num_perday;
	A = new Adult[adult_num_perday];
	for(int i = 0; i < adult_num_perday;i++)
	{
		total_child_num+=A[i].Get_ChildNum();
		int food_money = A[i].Get_Money();
		int EachFoodCopies;
		if(E[0].get_state() && E[1].get_state() && E[2].get_state())
		{
			EachFoodCopies = food_money/100;
			Seller.SellB(EachFoodCopies);
			Seller.SellC(EachFoodCopies);
			Seller.SellP(EachFoodCopies);
			E[0].Animal_Feeded_Add_Mess(&El[0],EachFoodCopies);
			for(int j = 0; j < 2; j++)	E[1].Animal_Feeded_Add_Mess(&G[j],EachFoodCopies);
			for(int j = 0; j < 3; j++)	E[2].Animal_Feeded_Add_Mess(&M[j],EachFoodCopies);
		}
		else if(E[0].get_state()&& E[1].get_state() && !E[2].get_state())
		{
			EachFoodCopies = food_money/50;
			Seller.SellC(EachFoodCopies);
			Seller.SellP(EachFoodCopies);
			E[0].Animal_Feeded_Add_Mess(&El[0],EachFoodCopies);
			for(int j = 0; j < 2; j++)	E[1].Animal_Feeded_Add_Mess(&G[j],EachFoodCopies/2);
		}
		else if(!E[0].get_state()&& E[1].get_state() && E[2].get_state())
		{
			EachFoodCopies = food_money/80;
			Seller.SellB(EachFoodCopies);
			Seller.SellC(EachFoodCopies);
			for(int j = 0; j < 2; j++)	E[1].Animal_Feeded_Add_Mess(&G[j],EachFoodCopies/2);
			for(int j = 0; j < 3; j++)	E[2].Animal_Feeded_Add_Mess(&M[j],EachFoodCopies/3);
		}
		else if(E[0].get_state()&& !E[1].get_state() && E[2].get_state())
		{
			EachFoodCopies = food_money/70;
			Seller.SellB(EachFoodCopies);
			Seller.SellP(EachFoodCopies);
			E[0].Animal_Feeded_Add_Mess(&El[0],EachFoodCopies);
			for(int j = 0; j < 3; j++)	E[2].Animal_Feeded_Add_Mess(&M[j],EachFoodCopies/3);
		}
			
		if(Seller.Judge_OutofStore())
		{
			break;
		}
		E[0].Animal_Feeded_Add_Mess(&El[0],EachFoodCopies);
		for(int j = 0; j < 2; j++)	E[1].Animal_Feeded_Add_Mess(&G[j],EachFoodCopies);
		for(int j = 0; j < 3; j++)	E[2].Animal_Feeded_Add_Mess(&M[j],EachFoodCopies);
	}
	for(int i = 0; i < 3;i++)
	{
		if(E[i].Judge_Mess_Add_Day())
		{
			e[i] = open_day;
			this->Keeper.Add_CleaningDay();
			break;
		}
	}
}

bool Zoo::Judge_StateofZoo()
{
	if(Keeper.Return_CleaningDay() >= 10)
	{
		cout<<"园长捡粪捡成咸鱼，背着平板锅带着小姨子跑路啦！"<<endl;
		this->Print_Result();
		return false;
	}
	else if(Seller.Judge_OutofStore() == 1)
	{
		cout<<"花生卖完啦！黑心小贩子溜啦！"<<endl;
		Print_Result();
		return false;
	}
	else if(Seller.Judge_OutofStore() == 2)
	{
		cout<<"胡萝卜卖完啦！黑心小贩子溜啦！"<<endl;
		Print_Result();
		return false;
	}
	else if(this->Seller.Judge_OutofStore() == 3)
	{
		cout<<"香蕉卖完啦！黑心小贩子溜啦！"<<endl;
		Print_Result();
		return false;
	}
	else return true;
}

void Zoo::Print_Result()
{
	cout<<"动物园共开了 "<<this->open_day<<"天"<<endl;
	cout<<"共有 "<<this->total_adult_num<<" 个成人以及 "<<this->total_child_num<<" 个小孩参观"<<endl;
	cout<<"共得收入为："<<this->Seller.Get_Benefit()/100 + this->total_adult_num + this->total_child_num * 0.4<<"美元"<<endl;
	cout<<"园长共捡粪了 "<<this->Keeper.Return_CleaningDay()<<" 天"<<endl;
	int E_day = E[0].Return_Closed_Days();
	int G_day = E[1].Return_Closed_Days();
	int M_day = E[2].Return_Closed_Days();
	cout<<"大象的家被园长抢了 "<<E_day<<" 天的粪"<<endl;
	cout<<"长颈鹿的家被园长抢了 "<<G_day<<" 天的粪"<<endl;
	cout<<"猴子的家被园长抢了 "<<M_day<<" 天的粪"<<endl;
}

Zoo::~Zoo()
{
	delete A;
	delete El;
	delete G;
	delete M;
}