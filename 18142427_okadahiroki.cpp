#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//���ς��o���֐��̒�`
int avg(int x, int y, int z) {
	return (x + y + z)/3;
}

//�N���X�̒�`
class game {
	
	//�N���X��5�̗v�f�����
	string name;
	int gameA = 0;
	int gameB = 0;
	int gameC = 0;
	int average = avg(gameA, gameB, gameC);
	
//public�ɕϊ�
public:
	game(const string& newname, int newgameA, int newgameB, int newgameC, int newaverage) :
		name(newname), gameA(newgameA), gameB(newgameB), gameC(newgameC) {}
	void setname(const string& newname) { name = newname; }
	string getname() { return name; }
	void setgameA(int newgameA) { gameA = newgameA; }
	int getgameA() { return gameA; }
	void setgameB(int newgameB) { gameB = newgameB; }
	int getgameB() { return gameB; }
	void setgameC(int newgameC) { gameC = newgameC; }
	int getgameC() { return gameC; }
	void setaverage(int newaverage) { gameC = newaverage; }
	int getaverage() { return average; }
};

int main() {

	//�t�@�C�����J��
	ifstream datafile("C:/Users/okadahiroki/Desktop/Visual Studio 2019/data.dat");

	//�t�@�C�����J�������Ƃ̊m�F
	if (!datafile) {
		cout << "nofile" << endl;
	}

	else {
		string Name;
		int A, B, C, D;
	
		//vector�����
		vector<game> all;

		int i = 0;

		//�t�@�C���̓ǂݍ���
		while (datafile >> Name >> A >> B >> C ) {
			
			//vector�ɗv�f��ǉ�����
			all.emplace_back(Name, A, B, C, D);
		}

		//�t�@�C�������
		datafile.close();

		//������
		int j = 0;
		int k = 0;
		int l = 0;
		int m = 0;
		
		//gameA�̌��ʂɊ�Â��ē_���̍������ɕ��בւ��ďo��
		cout << "gameA�̏���" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getgameA() > rhs.getgameA();});
		for (auto p : all)
			cout << ++j << ". " << p.getname() << " : " << p.getgameA() << endl;

		//gameB�̌��ʂɊ�Â��ē_���̍������ɕ��בւ��ďo��
		cout << "gameB�̏���" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getgameB() > rhs.getgameB();});
		for (auto p : all)
			cout << ++k << ". " << p.getname() << " : " << p.getgameB() << endl;

		//gameC�̌��ʂɊ�Â��ē_���̍������ɕ��בւ��ďo��
		cout << "gameC�̏���" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getgameC() > rhs.getgameC();});
		for (auto p : all)
			cout << ++l << ". " << p.getname() << " : " << p.getgameC() << endl;

		//gameA�`gameC�̓��_�𕽋ς��č������ɏ��ʕt�����ďo��
		cout << "total�̏���" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getaverage() > rhs.getaverage();});
		for (auto p : all)
			cout << ++m << ". " << p.getname() << " : " << p.getaverage() << endl;

	}
		
}