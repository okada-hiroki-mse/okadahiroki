#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//平均を出す関数の定義
int avg(int x, int y, int z) {
	return (x + y + z)/3;
}

//クラスの定義
class game {
	
	//クラスに5つの要素を作る
	string name;
	int gameA = 0;
	int gameB = 0;
	int gameC = 0;
	int average = avg(gameA, gameB, gameC);
	
//publicに変換
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

	//ファイルを開く
	ifstream datafile("C:/Users/okadahiroki/Desktop/Visual Studio 2019/data.dat");

	//ファイルが開けたことの確認
	if (!datafile) {
		cout << "nofile" << endl;
	}

	else {
		string Name;
		int A, B, C, D;
	
		//vectorを作る
		vector<game> all;

		int i = 0;

		//ファイルの読み込み
		while (datafile >> Name >> A >> B >> C ) {
			
			//vectorに要素を追加する
			all.emplace_back(Name, A, B, C, D);
		}

		//ファイルを閉じる
		datafile.close();

		//初期化
		int j = 0;
		int k = 0;
		int l = 0;
		int m = 0;
		
		//gameAの結果に基づいて点数の高い順に並べ替えて出力
		cout << "gameAの順位" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getgameA() > rhs.getgameA();});
		for (auto p : all)
			cout << ++j << ". " << p.getname() << " : " << p.getgameA() << endl;

		//gameBの結果に基づいて点数の高い順に並べ替えて出力
		cout << "gameBの順位" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getgameB() > rhs.getgameB();});
		for (auto p : all)
			cout << ++k << ". " << p.getname() << " : " << p.getgameB() << endl;

		//gameCの結果に基づいて点数の高い順に並べ替えて出力
		cout << "gameCの順位" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getgameC() > rhs.getgameC();});
		for (auto p : all)
			cout << ++l << ". " << p.getname() << " : " << p.getgameC() << endl;

		//gameA～gameCの得点を平均して高い順に順位付けして出力
		cout << "totalの順位" << endl;
		cout << "name : point" << endl;
		sort(all.begin(), all.end(),
			[](game& lhs, game& rhs) {return lhs.getaverage() > rhs.getaverage();});
		for (auto p : all)
			cout << ++m << ". " << p.getname() << " : " << p.getaverage() << endl;

	}
		
}