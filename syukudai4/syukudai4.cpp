#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const char* str[] = { "グー","チョキ","パー" };

void initrand()
{
	srand((unsigned int)time(NULL));
}


class Player
{
public:
	int hand;

	void ChoiceHand();
};

class Cpu
{
public:
	int cpuhand;

	void RandomHand();
};

class Judge
{
public:
	void judge(int hand,int cpuhand);
};

void Cpu::RandomHand()
{
	cpuhand = rand() % 3;
	cout << "CPUは" << str[cpuhand] << "を出したよ" << endl;
}

void Player::ChoiceHand()
{
	cout << "出したい手をえらんでね" << endl
		<< "グー:0 || チョキ:1 || パー:2" << endl;
	cin >> hand;
	if (hand < 0 || hand>2)
	{
		ChoiceHand();
	}
	else
	{
		cout << "あなたは" << str[hand] << "を出したね" << endl;
	}
}

void Judge::judge(int hand,int cpuhand)
{
	cout << "結果は";
	if (hand == cpuhand)
	{
		cout << "あいこ" << endl;
	}
	else if ((hand == 0 && cpuhand == 1) || (hand == 1 && cpuhand == 2) || (hand == 2 && cpuhand == 0))
	{
		cout << "あなたの勝ち！" << endl;
	}
	else
	{
		cout << "負けですね" << endl;
	}
}

int main()
{
	initrand();

	Player player;
	player.ChoiceHand();
	Cpu cpu;
	cpu.RandomHand();
	Judge game;
	game.judge(player.hand, cpu.cpuhand);
}