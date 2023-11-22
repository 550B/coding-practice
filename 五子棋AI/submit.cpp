#include <iostream>
#include <string.h>
#include <time.h>			//计时 
#include <vector>			//vector容器 
#include <algorithm>
#include <unordered_map>		//无序容器 
#include <chrono>			//精确计时 

#define BOARD_SIZE 12		//棋盘尺寸 
#define EMPTY 0
#define BLACK 1
#define WHITE 2

#define START "START"		//指令 
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"

//棋型评分
#define ONE (10)			//活一 
#define TWO (100)			//活二
#define THREE (1000)		//活三 
#define FOUR (100000)		//活四 
#define FIVE (10000000)		//成五 
#define BLOCKED_ONE (1)		//眠一 
#define BLOCKED_TWO (10)		//眠二 
#define BLOCKED_THREE (100)	//眠三 
#define BLOCKED_FOUR (10000)	//眠四 

#define STRANGE_NUM (999)	//标记数 
#define MAX_SCORE (FIVE*10)	//最高分 
#define MIN_SCORE (-1*MAX_SCORE)	//最低分 
#define CNT_LIMIT (20)		//限制节点个数 
#define SPREAD_LIMIT (1)		//米字扩散限制 
using namespace std;

//指令结构体 
struct Command
{
    int x;
    int y;
};
char board[BOARD_SIZE][BOARD_SIZE] = {0};	//棋盘 
int myFlag;	//我方棋色 
int enemyFlag;	//敌方棋色 

int chessmanCount = 0;	//棋子数 
vector<struct Command>currentSteps;	//当前走法 
vector<struct Command>allSteps;		//所有走法 
vector<vector<int>>enemyScore(BOARD_SIZE,vector<int>(BOARD_SIZE,0));	//对方得分 
vector<vector<int>>myScore(BOARD_SIZE,vector<int>(BOARD_SIZE,0));	//我方得分 
int dirScore[2][4][BOARD_SIZE][BOARD_SIZE]={0};			//方向打分 

long long zobristValue[2][BOARD_SIZE][BOARD_SIZE];	//一种快速判断棋盘是否改变的哈希表 
long long currentZobrist;	//当前哈希值 

bool isStarSpread = true;	//要不要米字扩散 
bool isCached = true;	//要不要缓存 

int searchDepth=20;	//AB搜索深度 
int nodeCount=0;		//节点数 
int ABcut=0;		//AB剪枝数 
int cacheCount=0;		//缓存数 
int cacheGet=0;		//命中数
//节点结构体 
struct Node
{
	bool abcut;	//是否被剪枝 
	int depth;		//搜索深度 
	int score;		//评分 
	int step;		//步长 
	vector<struct Command>steps;	//详细步 
};
unordered_map<long long,struct Node>cache;		//AB节点缓存 
unordered_map<long long,struct Node>::iterator it;	//AB迭代器 

int VCX_MAX_SCORE = THREE;	//算杀最高分 
int VCX_MIN_SCORE = FOUR;	//算杀最低分
//算杀结构体 
struct VCX
{
	struct Command cmd;
	int score;
	bool b;	//是否能胜 
};
int vcxDepth=15;	//算杀深度 
unordered_map<long long,vector<struct VCX>>cacheVCF;	//冲四活三缓存 
unordered_map<long long,vector<struct VCX>>::iterator itVCF;	//冲四活三迭代器 
unordered_map<long long,vector<struct VCX>>cacheVCT;	//双三缓存 
unordered_map<long long,vector<struct VCX>>::iterator itVCT;	//双三迭代器 
struct VCX lastMaxPoint, lastMinPoint;	//最新极大点、极小点 

std::chrono::time_point<std::chrono::steady_clock> startTime,endTime;	//计时器 
std::chrono::duration<double,ratio<1,1>>duration;	//持续时间 

void place(struct Command cmd,int flag);	//声明落子函数 
void remove(struct Command cmd);		//声明去子函数 

//生成64位随机数
//用于生成Zobrist哈希值
//参数：void
//返回值：long long int 
long long random64()
{
    return (long long)rand() | ((long long)rand() << 15) | ((long long)rand() << 30) | ((long long)rand() << 45) | ((long long)rand() << 60);
}

//初始化Zobrist
//参数、返回值：void 
void initZobrist()
{
	for(int k=0;k<2;k++)
	{
		for(int i=0;i<BOARD_SIZE;i++)
		{
			for(int j=0;j<BOARD_SIZE;j++)
			{
				zobristValue[k][i][j]=random64();
			}
		}
	}
	currentZobrist=random64();
}

//落子Zobrist
//当前哈希值与棋盘对应位置哈希值按位异或后赋值当前哈希值
//参数：行-整型，列-整型，执子颜色-整型
//返回值：long long int 
long long goZobrist(int x,int y,int flag)
{
	currentZobrist ^= zobristValue[flag-1][x][y];
	return currentZobrist;
}

//重置预估分
//参数：四个整型的引用
//返回值：void 
void resetEvaluationEmpty(int&count,int&block,int&empty,int&secondCount)
{
	count=1;
	block=0;
	empty=-1;
	secondCount=0;
}

//按照棋型返回分数
//棋型是根据棋子个数和眠数判断的
//参数：棋子数-整型，眠数-整型，空位数-带默认值的整型 
//返回值：分数
int count2Score(int count,int block,int empty=STRANGE_NUM)
{
	if(empty==STRANGE_NUM) empty=0;	//处理默认值时情况 
	
	if(empty<=0)	//满的 
	{
		if(count>=5) return FIVE;	//连五 
		if(block==0)	//无眠 
		{
			switch(count)
			{
				case 1:
					return ONE;
				case 2:
					return TWO;
				case 3:
					return THREE;
				case 4:
					return FOUR;
			}
		}
		if(block==1)	//一个眠 
		{
			switch(count)
			{
				case 1:
					return BLOCKED_ONE;
				case 2:
					return BLOCKED_TWO;
				case 3:
					return BLOCKED_THREE;
				case 4:
					return BLOCKED_FOUR;
			}
		}
	}
	else if(empty==1||empty==count-1)	//缺一子 
	{
		if(count>=6) return FIVE;	//能连五 
		if(block==0)		//无眠 
		{
			switch(count)
			{
				case 2:
					return TWO/2;
				case 3:
					return THREE;
				case 4:
					return BLOCKED_FOUR;
				case 5:
					return FOUR;
			}
		}
		if(block==1)		//一个眠 
		{
			switch(count)
			{
				case 2:
					return BLOCKED_TWO;
				case 3:
					return BLOCKED_THREE;
				case 4:
					return BLOCKED_FOUR;
				case 5:
					return BLOCKED_FOUR;
			}
		}
	}
	else if(empty==2||empty==count-2)	//两个空位，依此类推 
	{
		if(count>=7) return FIVE;
		if(block==0)
		{
			switch(count)
			{
				case 3:
					return THREE;
				case 4:
				case 5:
					return BLOCKED_FOUR;
				case 6:
					return FOUR;
			}
		}
		if(block==1)
		{
			switch(count)
			{
				case 3:
					return BLOCKED_THREE;
				case 4:
					return BLOCKED_FOUR;
				case 5:
					return BLOCKED_FOUR;
				case 6:
					return FOUR;
			}
		}
		if(block==2)
		{
			switch(count)
			{
				case 4:
				case 5:
				case 6:
					return BLOCKED_FOUR; 
			}
		}
	}
	else if(empty==3||empty==count-3)
	{
		if(count>=8) return FIVE;
		if(block==0)
		{
			switch(count)
			{
				case 4:
				case 5:
					return THREE;
				case 6:
					return BLOCKED_FOUR;
				case 7:
					return FOUR;
			}
		}
		if(block==1)
		{
			switch(count)
			{
				case 4:
				case 5:
				case 6:
					return BLOCKED_FOUR;
				case 7:
					return FOUR;
			}
		}
		if(block==2)
		{
			switch(count)
			{
				case 4:
				case 5:
				case 6:
				case 7:
					return BLOCKED_FOUR;
			}
		}
	}
	else if(empty==4||empty==count-4)
	{
		if(count>=9) return FIVE;
		if(block==0)
		{
			switch(count)
			{
				case 5:
				case 6:
				case 7:
				case 8:
					return FOUR;
			}
		}
		if(block==1)
		{
			switch(count)
			{
				case 4:
				case 5:
				case 6:
				case 7:
					return BLOCKED_FOUR;
				case 8:
					return FOUR; 
			}
		}
		if(block==2)
		{
			switch(count)
			{
				case 5:
				case 6:
				case 7:
				case 8:
					return BLOCKED_FOUR;
			}
		}
	}
	else if(empty==5||empty==count-5)
	{
		return FIVE;
	}
	
	return 0;
}

//粗略评估
//给空位打分
//参数：行数，列数，棋色，方向 
//返回值：总分 
int evaluateEmpty(int x,int y,int flag,int direction = -1)
{
	int result=0;	//总分 
	int count=0,block=0,empty=0,secondCount=0;
	
	//left&right
	if(direction==-1||direction==0)
	{
		resetEvaluationEmpty(count,block,empty,secondCount);
		
		for(int i=y+1;true;i++)
		{
			if(i>=BOARD_SIZE)
			{
				block++;
				break;
			}
			char tmp=board[x][i];
			if(tmp==EMPTY)
			{
				if(empty==-1&&i<BOARD_SIZE-1&&board[x][i+1]==flag)
				{
					empty=count;
					continue;
				}
				else
				{
					break;
				}
			}
			if(tmp==flag)
			{
				count++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		
		for(int i=y-1;true;i--)
		{
			if(i<0)
			{
				block++;
				break;
			}
			char tmp=board[x][i];
			if(tmp==EMPTY)
			{
				if(empty==-1&&i>0&&board[x][i-1]==flag)
				{
					empty=0;
					continue;
				}
				else
				{
					break;
				}
			}
			if(tmp==flag)
			{
				secondCount++;
				empty!=-1&&empty++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		
		count+=secondCount;
		
		dirScore[flag-1][0][x][y]=count2Score(count,block,empty);
	}
	result+=dirScore[flag-1][0][x][y];
	
	//up&down
	if(direction==-1||direction==1)
	{
		resetEvaluationEmpty(count,block,empty,secondCount);
		
		for(int i=x+1;true;i++)
		{
			if(i>=BOARD_SIZE)
			{
				block++;
				break;
			}
			char tmp=board[i][y];
			if(tmp==EMPTY)
			{
				if(empty==-1&&i<BOARD_SIZE-1&&board[i+1][y]==flag)
				{
					empty=count;
					continue;
				}
				else break;
			}
			if(tmp==flag)
			{
				count++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		for(int i=x-1;true;i--)
		{
			if(i<0)
			{
				block++;
				break;
			}
			char tmp=board[i][y];
			if(tmp==EMPTY)
			{
				if(empty==-1&&i>0&&board[i-1][y]==flag)
				{
					empty=0;
					continue;
				}
				else break;
			}
			if(tmp==flag)
			{
				secondCount++;
				if(empty!=-1) empty++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		count+=secondCount;
		dirScore[flag-1][1][x][y]=count2Score(count,block,empty);
	}
	result+=dirScore[flag-1][1][x][y];

	//leftup&rightdown
	if(direction==-1||direction==2)
	{
		resetEvaluationEmpty(count,block,empty,secondCount);
		
		for(int i=1;true;i++)
		{
			int tx=x+i;
			int ty=y+i;
			if(tx>=BOARD_SIZE||ty>=BOARD_SIZE)
			{
				block++;
				break;
			}
			char tmp=board[tx][ty];
			if(tmp==EMPTY)
			{
				if(empty==-1&&(tx<BOARD_SIZE-1&&ty<BOARD_SIZE-1)&&board[tx+1][ty+1]==flag)
				{
					empty=count;
					continue;
				}
				else break;
			}
			if(tmp==flag)
			{
				count++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		for(int i=1;true;i++)
		{
			int tx=x-i;
			int ty=y-i;
			if(tx<0||ty<0)
			{
				block++;
				break;
			}
			char tmp=board[tx][ty];
			if(tmp==EMPTY)
			{
				if(empty==-1&&(tx>0&&ty>0)&&board[tx-1][ty-1]==flag)
				{
					empty=0;
					continue;
				}
				else break;
			}
			if(tmp==flag)
			{
				secondCount++;
				if(empty!=-1) empty++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		count+=secondCount;
		dirScore[flag-1][2][x][y]=count2Score(count,block,empty);
	}
	result+=dirScore[flag-1][2][x][y];

	//rightup&leftdown
	if(direction==-1||direction==3)
	{
		resetEvaluationEmpty(count,block,empty,secondCount);
		
		for(int i=1;true;i++)
		{
			int tx=x+i;
			int ty=y-i;
			if(tx<0||ty<0||tx>=BOARD_SIZE||ty>=BOARD_SIZE)
			{
				block++;
				break;
			}
			char tmp=board[tx][ty];
			if(tmp==EMPTY)
			{
				if(empty==-1&&(tx<BOARD_SIZE-1&&ty>0)&&board[tx+1][ty-1]==flag)
				{
					empty=count;
					continue;
				}
				else break;
			}
			if(tmp==flag)
			{
				count++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		for(int i=1;true;i++)
		{
			int tx=x-i;
			int ty=y+i;
			if(tx<0||ty<0||tx>=BOARD_SIZE||ty>=BOARD_SIZE)
			{
				block++;
				break;
			}
			char tmp=board[tx][ty];
			if(tmp==EMPTY)
			{
				if(empty==-1&&(tx>0&&ty<BOARD_SIZE-1)&&board[tx-1][ty+1]==flag)
				{
					empty=0;
					continue;
				}
				else break;
			}
			if(tmp==flag)
			{
				secondCount++;
				if(empty!=-1) empty++;
				continue;
			}
			else
			{
				block++;
				break;
			}
		}
		count+=secondCount;
		dirScore[flag-1][3][x][y]=count2Score(count,block,empty);
	}
	result+=dirScore[flag-1][3][x][y];
	
	return result;
}

//相邻位置有没有棋子
//这个函数存在的意义就是减少搜索量
//每次只搜索周围有棋子的位置
//参数：行数，列数，距离，棋子数
//返回值：是否符合要求 
bool hasNeighbour(int x,int y,int distance,int count)
{
	int startX = x-distance;
	int endX = x+distance;
	int startY = y-distance;
	int endY = y+distance;
	for(int i=startX;i<=endX;i++)	//遍历四周，统计棋子个数 
	{
		if(i<0||i>=BOARD_SIZE) continue;
		for(int j=startY;j<=endY;j++)
		{
			if(j<0||j>=BOARD_SIZE) continue;
			if(i==x&&j==y) continue;
			if(board[i][j]!=EMPTY)
			{
				count--;
				if(count<=0) return true;
			}
		}
	}
	return false;
}

//对评估分数进行修正
//防止不停冲四
//参数：评分
//返回值：修正后的评分 
int fixScore(int type)
{
	if(type<FOUR&&type>=BLOCKED_FOUR)	//对眠四以上，活四以下的棋型修正 
	{
		if(type>=BLOCKED_FOUR&&type<(BLOCKED_FOUR+THREE))	//只冲四，意义不大 
		{
			return THREE;	//降格为活三 
		}
		else if(type>=BLOCKED_FOUR+THREE&&type<BLOCKED_FOUR*2)	//冲四活三 
		{
			return FOUR;	//升级为活四 
		}
		else
		{
			return FOUR*2;	//其他都是必杀棋，升 
		}
	}
	return type;
}

//棋面估分
//仅计算当前棋面分数
//参数：棋色
//返回值：棋面估分 
int evaluate(int flag)
{
	int myMaxScore = 0;
	int enemyMaxScore = 0;
	
	for(int i=0;i<BOARD_SIZE;i++)	//遍历整个棋盘 
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==myFlag)		//我方得分，加入我方得分 
			{
				myMaxScore+=fixScore(myScore[i][j]);
			}
			else if(board[i][j]==enemyFlag)	//敌方得分，加入敌方得分 
			{
				enemyMaxScore+=fixScore(enemyScore[i][j]);
			}
		}
	}
	int result=(flag==myFlag?1:-1)*(myMaxScore-enemyMaxScore);	//我分为正，敌分为负 
	return result;
}

//检查米字方向上的棋子
//对所有点位检查
//参数：坐标点，待检查的坐标点集
//返回值：是否符合米字 
bool checkStar(struct Command cmd,vector<struct Command>cmds={})
{
	if(cmds.empty()) return false;
	for(unsigned int i=0;i<cmds.size();i++)
	{
		if(abs(cmd.x-cmds[i].x)>4||abs(cmd.y-cmds[i].y)>4) return false;
		if(!(cmd.x==cmds[i].x||cmd.y==cmds[i].y||(abs(cmd.x-cmds[i].x)==abs(cmd.y-cmds[i].y)))) return false;
	}
	return true;
}

//启发函数 
//参数：棋色，只生成三，米字扩散
//返回值：坐标点集
vector<struct Command> generate(int flag,bool onlyThrees=false,bool starSpread=false)
{
	if(chessmanCount<=4)	//执黑，第一步堵白活二
	{
		return {{7,7}};
	}
	
	if(chessmanCount==6&&board[7][4]!=enemyFlag&&board[4][7]!=enemyFlag)
	{
		return {{7,4}};		//执黑，第二步自己活三
	}

	vector<struct Command>fives;			//成五
	vector<struct Command>myFours;			//我活四
	vector<struct Command>enemyFours;		//敌活四
	vector<struct Command>myBlockedFours;	//我眠四
	vector<struct Command>enemyBlockedFours;//敌眠四
	vector<struct Command>myTwoThrees;		//我双三
	vector<struct Command>enemyTwoThrees;	//敌双三
	vector<struct Command>myThrees;			//我活三
	vector<struct Command>enemyThrees;		//敌活三
	vector<struct Command>myTwos;			//我活二
	vector<struct Command>enemyTwos;		//敌活二
	vector<struct Command>neighbours;		//邻接点
	vector<struct Command>attack;			//攻
	vector<struct Command>defend;			//防
	vector<struct Command>result;			//结果
	
	if(starSpread&&isStarSpread)	//米字
	{
		int i=currentSteps.size()-1;	//计算防点
		while(i>=0)
		{
			struct Command pos=currentSteps[i];
			if(flag==enemyFlag&&enemyScore[pos.x][pos.y]>=THREE||
			   flag==myFlag&&myScore[pos.x][pos.y]>=THREE)
			{
			   	defend.push_back(pos);
			   	break;
			}
			i-=2;
		}
		
		int j=currentSteps.size()-2;	//计算攻点
		while(j>=0)
		{
			struct Command pos=currentSteps[j];
			if(flag==enemyFlag&&enemyScore[pos.x][pos.y]>=THREE||
			   flag==myFlag&&myScore[pos.x][pos.y]>=THREE)
			{
			   	attack.push_back(pos);
			   	break;
			}
			j-=2;
		}
		
		if(attack.empty())
		{
			struct Command pos=currentSteps[0];
			char tmp=board[pos.x][pos.y];
			attack.push_back(tmp==myFlag?pos:currentSteps[1]);
		}
		if(defend.empty())
		{
			struct Command pos=currentSteps[0];
			char tmp=board[pos.x][pos.y];
			attack.push_back(tmp==enemyFlag?pos:currentSteps[1]);
		}
	}
	
	for(int i=0;i<BOARD_SIZE;i++)	//遍历棋盘
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)	//为空
			{
				if(allSteps.size()<14)	//前14步，只下周围
				{
					if(!hasNeighbour(i,j,1,1)) continue;
				}
				else if(!hasNeighbour(i,j,2,2)) continue;
				
				int scoreMine=myScore[i][j];
				int scoreEnemy=enemyScore[i][j];
				int maxScore=max(scoreMine,scoreEnemy);
				
				if(onlyThrees&&maxScore<THREE) continue;
				
				//star spread
				if(starSpread&&isStarSpread)
				{
					if(maxScore>=FOUR){}
					else if(maxScore>=BLOCKED_FOUR&&checkStar(currentSteps[currentSteps.size()-1])){}
					else if(checkStar({i,j},attack)||checkStar({i,j},defend)){}
					else continue;
				}
				
				//把符合的点放入对应点集
				if(scoreMine>=FIVE) fives.push_back({i,j});
				else if(scoreEnemy>=FIVE) fives.push_back({i,j});
				else if(scoreMine>=FOUR) myFours.push_back({i,j});
				else if(scoreEnemy>=FOUR) enemyFours.push_back({i,j});
				else if(scoreMine>=BLOCKED_FOUR) myBlockedFours.push_back({i,j});
				else if(scoreEnemy>=BLOCKED_FOUR) enemyBlockedFours.push_back({i,j});
				else if(scoreMine>=2*THREE) myTwoThrees.push_back({i,j});
				else if(scoreEnemy>=2*THREE) enemyTwoThrees.push_back({i,j});
				else if(scoreMine>=THREE) myThrees.push_back({i,j});
				else if(scoreEnemy>=THREE) enemyThrees.push_back({i,j});
				else if(scoreMine>=TWO) myTwos.push_back({i,j});
				else if(scoreEnemy>=TWO) enemyTwos.push_back({i,j});
				else neighbours.push_back({i,j});
			}
		}
	}
	
	//five
	if(fives.size()) return fives;
	
	//four
	if(flag==myFlag&&!myFours.empty()) return myFours;
	if(flag==enemyFlag&&!enemyFours.empty()) return enemyFours;
	
	//enemy four
	if(flag==myFlag&&!enemyFours.empty()&&myBlockedFours.empty()) return enemyFours;
	if(flag==enemyFlag&&!myFours.empty()&&enemyBlockedFours.empty()) return myFours;
	
	//both four
	vector<struct Command>fours;
	vector<struct Command>blockedfours;
	if(flag==myFlag)
	{
		fours.insert(fours.begin(),myFours.begin(),myFours.end());
		fours.insert(fours.end(),enemyFours.begin(),enemyFours.end());
		blockedfours.insert(blockedfours.begin(),myBlockedFours.begin(),myBlockedFours.end());
		blockedfours.insert(blockedfours.end(),enemyBlockedFours.begin(),enemyBlockedFours.end());
	}
	else if(flag==enemyFlag)
	{
		fours.insert(fours.begin(),enemyFours.begin(),enemyFours.end());
		fours.insert(fours.end(),myFours.begin(),myFours.end());
		blockedfours.insert(blockedfours.begin(),enemyBlockedFours.begin(),enemyBlockedFours.end());
		blockedfours.insert(blockedfours.end(),myBlockedFours.begin(),myBlockedFours.end());
	}
	if(!fours.empty())
	{
		fours.insert(fours.begin(),blockedfours.begin(),blockedfours.end());
		return fours;
	}
	
	if(flag==myFlag)
	{
		result.insert(result.begin(),myTwoThrees.begin(),myTwoThrees.end());
		result.insert(result.end(),enemyTwoThrees.begin(),enemyTwoThrees.end());
		result.insert(result.end(),myBlockedFours.begin(),myBlockedFours.end());
		result.insert(result.end(),enemyBlockedFours.begin(),enemyBlockedFours.end());
		result.insert(result.end(),myThrees.begin(),myThrees.end());
		result.insert(result.end(),enemyThrees.begin(),enemyThrees.end());
	}
	if(flag==enemyFlag)
	{
		result.insert(result.begin(),enemyTwoThrees.begin(),enemyTwoThrees.end());
		result.insert(result.end(),myTwoThrees.begin(),myTwoThrees.end());
		result.insert(result.end(),enemyBlockedFours.begin(),enemyBlockedFours.end());
		result.insert(result.end(),myBlockedFours.begin(),myBlockedFours.end());
		result.insert(result.end(),enemyThrees.begin(),enemyThrees.end());
		result.insert(result.end(),myThrees.begin(),myThrees.end());
	}
	
	//double three
	if(!myTwoThrees.empty()||!enemyTwoThrees.empty()) return result;
	
	//only returns bigger than three
	if(onlyThrees) return result;
	
	vector<struct Command>twos;
	if(flag==myFlag)
	{
		twos.insert(twos.begin(),myTwos.begin(),myTwos.end());
		twos.insert(twos.end(),enemyTwos.begin(),enemyTwos.end());
	}
	else
	{
		twos.insert(twos.begin(),enemyTwos.begin(),enemyTwos.end());
		twos.insert(twos.end(),myTwos.begin(),myTwos.end());
	}
	
	sort(twos.begin(),twos.end(),[](struct Command a,struct Command b)->bool{
		return max(myScore[a.x][a.y],enemyScore[a.x][a.y])>max(myScore[b.x][b.y],enemyScore[b.x][b.y]);
	});
	if(!twos.empty())
	{
		result.insert(result.begin(),twos.begin(),twos.end());
	}
	else
	{
		result.insert(result.begin(),neighbours.begin(),neighbours.end());
	}
	
	//low score
	if(result.size()>CNT_LIMIT)
	{
		result.erase(result.begin()+CNT_LIMIT,result.end());
	}
	
	return result;
}

//初始化分数
//对棋盘上每个位置给出大致评分
//参数，返回值：void
void initScore()
{
	for(int i=0;i<BOARD_SIZE;i++)	//遍历棋盘
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)	//空位
			{
				if(hasNeighbour(i,j,2,2))
				{
					enemyScore[i][j]=evaluateEmpty(i,j,enemyFlag);	//敌我都要评估
					myScore[i][j]=evaluateEmpty(i,j,myFlag);
				}
			}
			else if(board[i][j]==enemyFlag)	//敌棋
			{
				enemyScore[i][j]=evaluateEmpty(i,j,enemyFlag);
				myScore[i][j]=0;
			}
			else if(board[i][j]==myFlag)	//我棋
			{
				myScore[i][j]=evaluateEmpty(i,j,myFlag);
				enemyScore[i][j]=0;
			}
		}
	}
}

//更新分数拆分出的步骤
//参数：行数，列数，方向
//返回值：void
void update(int x,int y,int direction)
{
	char role = board[x][y];
	if(role!=myFlag)
	{
		int tmp=evaluateEmpty(x,y,enemyFlag,direction);
		enemyScore[x][y]=tmp;
	}
	else enemyScore[x][y]=0;
	if(role!=enemyFlag)
	{
		int tmp=evaluateEmpty(x,y,myFlag,direction);
		myScore[x][y]=tmp;
	}
	else myScore[x][y]=0;
}

//根据方向更新分数
//参数：坐标
//返回值：void
void updateScore(struct Command cmd)
{
	int radius=4;
	
	//left&right
	for(int i=-radius;i<=radius;i++)
	{
		int x=cmd.x;
		int y=cmd.y+i;
		if(y<0) continue;
		if(y>=BOARD_SIZE) break;
		update(x,y,0);
	}
	
	//up&down
	for(int i=-radius;i<=radius;i++)
	{
		int x=cmd.x+i;
		int y=cmd.y;
		if(x<0) continue;
		if(x>=BOARD_SIZE) break;
		update(x,y,1);
	}
	
	//leftup&rightdown
	for(int i=-radius;i<=radius;i++)
	{
		int x=cmd.x+i;
		int y=cmd.y+i;
		if(x<0||y<0) continue;
		if(x>=BOARD_SIZE||y>=BOARD_SIZE) break;
		update(x,y,2);
	}
	
	//rightup&leftdown
	for(int i=-radius;i<=radius;i++)
	{
		int x=cmd.x+i;
		int y=cmd.y-i;
		if(x<0||y<0) continue;
		if(x>=BOARD_SIZE||y>=BOARD_SIZE) continue;
		update(x,y,3);
	}
}

//core algorithm
//checkmate
//find all positions whose scores are above threshold
//算杀之寻找最大值
//类似于minmax中最大层的一步
//参数：棋色，分数
//返回值：结点集合
vector<struct VCX> findMax(int flag, int score)
{
	vector<struct VCX>result;	//结果集合
	vector<struct VCX>fives;	//连五集合
	for(int i=0;i<BOARD_SIZE;i++)	//遍历棋盘
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)	//空位
			{
				struct VCX pos;
				pos.cmd.x=i;
				pos.cmd.y=j;
				
				if(enemyScore[i][j]>=FIVE)	//我下这，敌成五
				{
					pos.score=FIVE;
					if(flag==myFlag) pos.score*=-1;
					fives.push_back(pos);
				}
				else if(myScore[i][j]>=FIVE)	//敌下这，敌成五
				{
					pos.score=FIVE;
					if(flag==enemyFlag) pos.score*=-1;
					fives.push_back(pos);
				}
				else
				{
					//initialize in deeping()
					if((lastMaxPoint.cmd.x==STRANGE_NUM||
					    (i==lastMaxPoint.cmd.x||j==lastMaxPoint.cmd.y||
						 (abs(i-lastMaxPoint.cmd.x)==abs(j-lastMaxPoint.cmd.y)))))
					{
						int tmp = (flag==myFlag?myScore[i][j]:enemyScore[i][j]);
						pos.score = tmp;
						if (tmp >= score) result.push_back(pos);
					}
				}
			}
		}
	}
	if(!fives.empty()) return fives;	//先看连五
	//按照分数由大到小排序
	sort(result.begin(),result.end(),[](struct VCX a,struct VCX b)->bool{
		return b.score < a.score;
	});
	return result;
}

//core algorithm
//checkmate
//find all enemy positions whose scores are above threshold
//算杀之寻找最小值
//类似于minmax中最小层的一步
//参数：棋色，分数
//返回值：结点集合
vector<struct VCX> findMin(int flag, int score)
{
	vector<struct VCX>result;	//结果集合
	vector<struct VCX>fives;	//连五集合
	vector<struct VCX>fours;	//活四集合
	vector<struct VCX>blockedFours;	//眠四集合
	
	for(int i=0;i<BOARD_SIZE;i++)	//遍历棋盘
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)
			{
				struct VCX pos;
				pos.cmd.x=i;
				pos.cmd.y=j;
				
				int score1=(flag==myFlag?myScore[i][j]:enemyScore[i][j]);
				int score2=(flag==myFlag?enemyScore[i][j]:myScore[i][j]);
				
				if(score1>=FIVE)	//我连五，找最小的
				{
					pos.score = -score1;
					result.push_back(pos);
					return result;
				}
				if(score2>=FIVE)	//敌连五，找最大的
				{
					pos.score=score2;
					fives.push_back(pos);
					continue;
				}
				if(score1>=FOUR)	//我活四，找最小的
				{
					pos.score = -score1;
					fours.insert(fours.begin(),pos);
					continue;
				}
				if(score2>=FOUR)	//敌活四，找最大的
				{
					pos.score=score2;
					fours.push_back(pos);
					continue;
				}
				if(score1>=BLOCKED_FOUR)	//我眠四，找最小的
				{
					pos.score = -score1;
					blockedFours.insert(blockedFours.begin(),pos);
					continue;
				}
				if(score2>=BLOCKED_FOUR)	//敌眠四，找最大的
				{
					pos.score=score2;
					blockedFours.push_back(pos);
					continue;
				}
				if(score1>=score||score2>=score)	//超过阈值
				{
					pos.score=score1;
					result.push_back(pos);
				}
			}
		}
	}
	if(!fives.empty()) return fives;	//连五直接返回
	if(!fours.empty())		//把活四和眠四拼接一下
	{
		fours.insert(fours.end(),blockedFours.begin(),blockedFours.end());
		return fours;
	}
	result.insert(result.end(),blockedFours.begin(),blockedFours.end());
	//按照分数从大到小排序
	sort(result.begin(),result.end(),[](struct VCX a,struct VCX b)->bool{
		return abs(b.score) < abs(a.score);
	});
	return result;
}

vector<struct VCX> minFloor(int flag,int depth);	//声明
//core algorithm
//最大值层
//参数：棋色，深度
//返回值：节点集合
vector<struct VCX> maxFloor(int flag,int depth)
{
	vector<struct VCX>pos;
	if(depth<=1)	//在深度内没找到必杀点
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	
	pos=findMax(flag,VCX_MAX_SCORE);
	if(!pos.empty()&&pos[0].score>=FOUR)	//找到必杀点
	{
		vector<struct VCX>tmp;
		tmp.push_back(pos[0]);
		return tmp;
	}
	if(pos.empty())		//没找到
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	for(unsigned int i=0;i<pos.size();i++)	//处理一下找到的必杀点
	{
		struct VCX p=pos[i];
		place(p.cmd,flag);
		if(!(p.score<=-FIVE)) lastMaxPoint=p;
		vector<struct VCX> temp=minFloor(3-flag,depth-1);	//进入最小值层
		remove(p.cmd);
		if((temp[temp.size()-1].b&&temp[temp.size()-1].cmd.x==-1)||!temp.empty())
		{
			if(!temp.empty())
			{
				temp.insert(temp.begin(),p);
				return temp;
			}
			else
			{
				vector<struct VCX>tmp;
				tmp.push_back(p);
				return tmp;
			}
		}
	}
	struct VCX tt;
	tt.cmd.x=-1;
	tt.b=false;
	pos.push_back(tt);
	return pos;
}

//core algorithm
//判断是否连五
//参数：行数，列数，棋色
//返回值：是否连五
bool isFive(int x,int y,int flag)
{
	int count=1;
	
	//left right
	for(int i=y+1;true;i++)
	{
		if(i>=BOARD_SIZE) break;
		if(board[x][i]!=flag) break;
		count++;
	}
	for(int i=y-1;true;i--)
	{
		if(i<0) break;
		if(board[x][i]!=flag) break;
		count++;
	}
	if(count>=5) return true;
	
	count=1;
	
	//up down
	for(int i=x+1;true;i++)
	{
		if(i>=BOARD_SIZE) break;
		if(board[i][y]!=flag) break;
		count++;
	}
	for(int i=x-1;true;i--)
	{
		if(i<0) break;
		if(board[i][y]!=flag) break;
		count++;
	}
	if(count>=5) return true;
	
	count=1;
	
	//left up right down
	for(int i=1;true;i++)
	{
		int a=x+i;
		int b=y+i;
		if(a>=BOARD_SIZE||b>=BOARD_SIZE) break;
		if(board[a][b]!=flag) break;
		count++;
	}
	for(int i=1;true;i++)
	{
		int a=x-i;
		int b=y-i;
		if(a<0||b<0) break;
		if(board[a][b]!=flag) break;
		count++;
	}
	if(count>=5) return true;
	
	count=1;
	
	//right up left down
	for(int i=1;true;i++)
	{
		int a=x+i;
		int b=y-i;
		if(a>=BOARD_SIZE||b>=BOARD_SIZE||a<0||b<0) break;
		if(board[a][b]!=flag) break;
		count++;
	}
	for(int i=1;true;i++)
	{
		int a=x-i;
		int b=y+i;
		if(a>=BOARD_SIZE||b>=BOARD_SIZE||a<0||b<0) break;
		if(board[a][b]!=flag) break;
		count++;
	}
	if(count>=5) return true;
	
	return false;
}

//core algorithm
//to judge whether it's win or not
//判断是不是赢了
//参数：void
//返回值：能赢点的棋色
int isWin()
{
	for(int i=0;i<BOARD_SIZE;i++)
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]!=EMPTY)
			{
				if(isFive(i,j,board[i][j]))
				{
					return board[i][j];
				}
			}
		}
	}
	return 0;
}

//core algorithm
//最小值层
//参数：棋色，深度
//返回值：节点集合
vector<struct VCX> minFloor(int flag,int depth)
{
	vector<struct VCX>pos;
	int currentFlag=isWin();	//赢点棋色
	if(currentFlag==flag)		//我能赢
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	if(currentFlag==(3-flag))	//敌能赢
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=true;
		pos.push_back(tt);
		return pos;
	}
	if(depth<=1)		//深度内没找到必杀点
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	
	pos=findMin(flag,VCX_MIN_SCORE);
	if(pos.empty())		//没有
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	if(!pos.empty()&&(-1*pos[0].score)>=FOUR)	//必杀
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	
	vector<struct VCX>candidates;
	for(unsigned int i=0;i<pos.size();i++)	//遍历并找出候选点
	{
		struct VCX p=pos[i];
		place(p.cmd,flag);
		lastMinPoint=p;
		vector<struct VCX> temp=maxFloor(3-flag,depth-1);	//进入最大层
		remove(p.cmd);
		if((temp[temp.size()-1].b&&temp[temp.size()-1].cmd.x==-1)||!temp.empty())
		{
			if(!temp.empty())
			{
				temp.insert(temp.begin(),p);
				candidates.insert(candidates.end(),temp.begin(),temp.end());
				continue;
			}
			else
			{
				struct VCX tt;
				tt.cmd.x=-1;
				tt.b=false;
				temp.push_back(tt);
				return temp;
			}
		}
	}
	
	return candidates;
}

//缓存算杀节点
//缓存以当前Zobrist值为键，节点为值
//参数：节点集合，VCF还是VCT
//返回值：void
void saveVCX(vector<struct VCX>result,bool vcf)
{
	if(!isCached) return;	//关掉了缓存
	if(vcf)
	{
		cacheVCF[currentZobrist]=result;
	}
	else
	{
		cacheVCT[currentZobrist]=result;
	}
}

//获取缓存的算杀节点
//参数：VCF还是VCT
//返回值：获取到的节点集合
vector<struct VCX> getVCX(bool vcf)
{
	vector<struct VCX> result;
	if(vcf)
	{
		itVCF=cacheVCF.find(currentZobrist);
		if(itVCF!=cacheVCF.end())
		{
			result=itVCF->second;
		}
	}
	else
	{
		itVCT=cacheVCT.find(currentZobrist);
		if(itVCT!=cacheVCT.end())
		{
			result=itVCT->second;
		}
	}
	return result;
}

//core algorithm
//迭代加深算杀
//参数：棋色，深度
//返回值：节点集合
vector<struct VCX> deepingVCX(int flag,int depth)
{
	vector<struct VCX> result;	//结果节点集合
	for(int i=1;i<=depth;i++)
	{
		lastMaxPoint.cmd.x=STRANGE_NUM;	//初始化
		lastMinPoint.cmd.x=STRANGE_NUM;
		result=maxFloor(flag,depth);	//进入最大值层
		if((result[result.size()-1].cmd.x==-1&&result[result.size()-1].b)||!result.empty()) break;	//找到了，提前退出遍历
	}
	return result;
}

//core algorithm
//算杀
//参数：棋色，深度，只算大于等于活四
//返回值：符合条件的节点集合
vector<struct VCX> vcx(int flag,int depth,bool onlyFour)
{
	vector<struct VCX>result;
	if(depth<=0)	//深度有误
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		result.push_back(tt);
		return result;
	}
	
	if(onlyFour)	//开启了大于等于活四
	{
		VCX_MAX_SCORE=BLOCKED_FOUR;	//算杀最大分重新赋值
		VCX_MIN_SCORE=FIVE;			//算杀最小值重新赋值
		
		result=deepingVCX(flag,depth);	//迭代加深
		if((result[result.size()-1].cmd.x==-1&&result[result.size()-1].b)||!result.empty())	//找到
		{
			result[result.size()-1].score=FOUR;
			return result;
		}
		struct VCX tt;	//没找到
		tt.cmd.x=-1;
		tt.b=false;
		result.push_back(tt);
		return result;
	}
	else
	{
		VCX_MAX_SCORE=THREE;
		VCX_MIN_SCORE=BLOCKED_FOUR;
		
		result=deepingVCX(flag,depth);
		if((result[result.size()-1].cmd.x==-1&&result[result.size()-1].b)||!result.empty())
		{
			result[result.size()-1].score=THREE*2;
		}
		return result;
	}
	struct VCX tt;
	tt.cmd.x=-1;
	tt.b=false;
	result.push_back(tt);
	return result;
}

//core algorithm
//冲四活三算杀
//参数：棋色，深度
//返回值：节点集合
vector<struct VCX> vcf(int flag,int depth)
{
	vector<struct VCX>tmp=getVCX(true);
	if(!tmp.empty()) return tmp;
	vector<struct VCX>result=vcx(flag,depth,true);
	saveVCX(result,true);
	return result;
}

//core algorithm
//双三算杀
//参数：棋色，深度
//返回值：节点集合
vector<struct VCX> vct(int flag,int depth)
{
	vector<struct VCX>tmp=getVCX(false);
	if(!tmp.empty()) return tmp;
	vector<struct VCX>result=vcx(flag,depth,false);
	saveVCX(result,false);
	return result;
}

//cache
//alpha-beta函数节点缓存
//仍使用当前Zobrist值作为键，AB节点作为值
//参数：深度，AB节点
//返回值：void
void save(int depth,struct Node score)
{
	if(!isCached) return;
	if(score.abcut) return;	//被剪掉了
	cache[currentZobrist]=score;
	cacheCount++;
}

//core algorithm
//alpha-beta算法中间关键一步
//参数：深度，alpha，beta，棋色，步长，路径，米字
//返回值：AB节点
struct Node middleStep(int depth,int alpha,int beta,int flag,int step,vector<struct Command>steps,int spread)
{
	if(isCached)	//是否缓存
	{
		it=cache.find(currentZobrist);	//迭代器找到当前Zobrist哈希值，否则返回end()
		if(it!=cache.end())		//找到了
		{
			if(it->second.depth>=depth)		//在下层
			{
				cacheGet++;
				return
				{
					it->second.abcut,
					it->second.depth,
					it->second.score,
					it->second.step+step,
					steps
				};
			}
			else
			{
				if(it->second.score>=FOUR||it->second.score<=-FOUR)
				{
					cacheGet++;
					return it->second;
				}
			}
		}
	}
	
	int evaluatedScore=evaluate(flag);	//棋面评估
	
	//叶节点
	struct Node leaf=
	{
		.abcut=false,
		.depth=depth,
		.score=evaluatedScore,
		.step=step,
		.steps=steps
	};
	
	nodeCount++;
	//算杀放在没找到高分棋的叶节点下面
	if(depth<=0||evaluatedScore>=FIVE||evaluatedScore<=-FIVE)
	{
		endTime = std::chrono::steady_clock::now();		//控制一下别超时了
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		if (duration.count() > 1.4) return leaf;
		
		//sha
		if(evaluatedScore<FOUR&&evaluatedScore>FOUR*-1)		//冲四活三杀
		{
			vector<struct VCX>tmp=vcf(flag,vcxDepth);
			vector<struct VCX>::iterator itt;
			int number=MIN_SCORE;
			
			for(itt=tmp.begin();itt!=tmp.end();itt++)
			{
				if(itt->score>number)
				{
					number=itt->score;
				}
			}
			if((tmp[tmp.size()-1].cmd.x==-1&&tmp[tmp.size()-1].b)||!tmp.empty())
			{
				struct Node t;
				t.abcut=false;
				t.depth=depth;
				t.score=number;
				t.step=step+tmp.size();
				t.steps=steps;
				return t;
			}
		}
		
		endTime = std::chrono::steady_clock::now();		//控制一下别超时了
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		if (duration.count() > 1.4) return leaf;
		
		if(evaluatedScore<THREE*2&&evaluatedScore>THREE*-2)		//双三杀
		{
			vector<struct VCX>tmp=vct(flag,vcxDepth);
			vector<struct VCX>::iterator itt;
			int number=MIN_SCORE;
			
			for(itt=tmp.begin();itt!=tmp.end();itt++)
			{
				if(itt->score>number)
				{
					number=itt->score;
				}
			}
			if((tmp[tmp.size()-1].cmd.x==-1&&tmp[tmp.size()-1].b)||!tmp.empty())
			{
				struct Node t;
				t.abcut=false;
				t.depth=depth;
				t.score=number;
				t.step=step+tmp.size();
				t.steps=steps;
				return t;
			}
		}
		//sha end
		return leaf;
	}
	
	//最佳节点
	struct Node best=
	{
		.abcut=false,
		.depth=depth,
		.score=MIN_SCORE,
		.step=step,
		.steps=steps
	};
	
	vector<struct Command> points = generate(flag,chessmanCount>10?step>1:step>3,step>1);	//下一步
	
	if(points.empty()) return leaf;		//没有好的位置
	
	for(unsigned int i=0;i<points.size();i++)	//遍历可能解
	{
		struct Command pos = points[i];
		place(pos,flag);			//着
		int newDepth = depth-1;
		int newSpread = spread;
		
		if(spread<SPREAD_LIMIT)
		{
			if((flag==myFlag&&enemyScore[pos.x][pos.y]>=FIVE)||(flag==enemyFlag&&myScore[pos.x][pos.y]>=FIVE))
			{
				newDepth+=2;
				newSpread++;
			}
		}
		
		vector<struct Command>newSteps;
		newSteps.insert(newSteps.begin(),steps.begin(),steps.end());
		newSteps.push_back(pos);
		struct Node tmp = middleStep(newDepth,-beta,-alpha,3-flag,step+1,newSteps,newSpread);	//递归
		tmp.score*=-1;		//隔层分数取反
		remove(pos);		//移除
		
		if(tmp.score>best.score)	//比当前最好的还要好
		{
			best=tmp;
		}
		alpha=max(best.score,alpha);	//更新alpha
		
		//ABcut
		if(tmp.score>=beta)		//剪枝
		{
			ABcut++;
			tmp.score=MAX_SCORE-1;
			tmp.abcut=true;
			return tmp;
		}
	}
	save(depth,best);		//缓存最佳节点
	return best;
}

//core algorithm
//min-max
//极大值极小值算法，很关键
//参数：候选点集合，棋色，深度，alpha，beta
//返回值：alpha
int minmax(vector<struct Node>candidates,int flag,int depth,int alpha,int beta)
{
	for(unsigned int i=0;i<candidates.size();i++)	//遍历候选点
	{
		struct Command pos=candidates[i].steps[candidates[i].steps.size()-1];
		place(pos,flag);		//下子
		vector<struct Command>steps;
		steps.insert(steps.begin(),candidates[i].steps.begin(),candidates[i].steps.end());	//把过程给到当前路径
		struct Node tmp = middleStep(depth-1,-beta,-alpha,3-flag,1,steps,0);	//调用递归函数
		tmp.score*=-1;		//隔层取反
		alpha=max(alpha,tmp.score);		//alpha取最大
		remove(pos);			//移除
		
		candidates[i].score=alpha;	//赋分
		
		//timeout
		endTime=std::chrono::steady_clock::now();		//控制时间，超时退出循环。下文有介绍排序与时间的关系
		duration=std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		if(duration.count()>1.5)break;
	}
	return alpha;
}

//maths
//判等
//参数：两个双精度浮点数
//返回值：在一定范围内认为相等否
bool isEqual(double a,double b)
{
	return (b>=0?((a>=(b/1.15))&&(a<=(b*1.15))):((a>=(b*1.15))&&(a<=(b/1.15))));
}

//core algorithm
//迭代加深
//从此开始计算
//参数：候选点集合，棋色，深度
//返回值：AB节点
struct Node deeping(vector<struct Node>candidates,int flag,int depth)
{
	//start time
	startTime=std::chrono::steady_clock::now();		//从这里开始计时
	cache.clear();		//清缓存
	
	int bestScore;
	for(int i=2;i<=depth;i+=2)		//在最大值层找最大值
	{
		bestScore=minmax(candidates,myFlag,i,MIN_SCORE,MAX_SCORE);
		if(bestScore>=FIVE) break;
	}
	
	//排序函数很重要，一定程度上决定时间长短
	//把最值得搜索的点放在前面，减少时间消耗，也防止时间不够被硬砍掉
	sort(candidates.begin(),candidates.end(),[](struct Node a,struct Node b)->bool{
		if(isEqual(a.score,b.score))	//分数相似
		{
			if(a.score>=0)		//评分正，对我有利
			{
				if(a.step!=b.step) return a.step<b.step;	//选步长短的
				else return b.score<a.score;	//选分高的
			}
			else				//评分负，对我不利
			{
				if(a.step!=b.step) return b.step<a.step;	//选步长长的
				else return b.score<a.score;	//选分高的
			}
		}
		else return (b.score<a.score);	//分高的在前面
	});
	
	return candidates[0];	//返回最好的
}

//core algorithm
//计算
//极大极小和AB算法和迭代加深和算杀的入口
//参数：棋色，搜索深度（写死，可调）
//返回值：接到TURN后返回的坐标
struct Command calculate(int flag,int depth=searchDepth)
{
	vector<struct Command>tmp=generate(flag);	//下一步
	vector<struct Node>candidates;		//候选人集合
	struct Node temp=
	{
		.abcut=false,
		.depth=1,
		.score=0,
		.step=1
	};
	for(unsigned int i=0;i<tmp.size();i++)
	{
		temp.steps.push_back(tmp[i]);
		candidates.push_back(temp);
	}
	
	temp=deeping(candidates,flag,depth);	//迭代加深
	struct Command result=temp.steps[0];	//收到结果
	
	return result;
}

//下面是助教写的代码模板，不必多言
void debug(const char *str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}
bool isInBound(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

//下子
//参数：坐标，棋色
//返回值：void
void place(struct Command cmd,int flag)
{
    board[cmd.x][cmd.y] = flag;		//位置设为棋色
    goZobrist(cmd.x,cmd.y,flag);	//修改Zobrist
    updateScore(cmd);				//更新棋面分数
    allSteps.push_back(cmd);		//路径推入这一步
    currentSteps.push_back(cmd);	//当前坐标
    chessmanCount++;				//棋子数+1
}

//移除
//参数：坐标
//返回值：void
void remove(struct Command cmd)
{
	char ch=board[cmd.x][cmd.y];	//获取棋色
	goZobrist(cmd.x,cmd.y,ch);		//修改Zobrist
	board[cmd.x][cmd.y]=EMPTY;		//坐标设置为空
	updateScore(cmd);				//更新棋面分数
	allSteps.pop_back();			//弹出
	currentSteps.pop_back();		//弹出
	chessmanCount--;				//棋子数-1
}
void initAI(int me)
{
    enemyFlag = 3 - me;
}
void start(int flag)
{
    initAI(flag);
    memset(board, 0, sizeof(board));
    int middlePlace = BOARD_SIZE / 2;
    struct Command command =
    {
    	.x = middlePlace - 1,
        .y = middlePlace - 1,
    };
    place(command,WHITE);
    command.x=middlePlace;
    command.y=middlePlace;
    place(command,WHITE);
    command.x=middlePlace-1;
    command.y=middlePlace;
    place(command,BLACK);
    command.x=middlePlace;
    command.y=middlePlace-1;
    place(command,BLACK);
    initScore();
    initZobrist();
}
void turn()
{
	struct Command cmd=calculate(myFlag);
	printf("%d %d", cmd.x, cmd.y);
    printf("\n");
    fflush(stdout);
    place(cmd,myFlag);
    return;
}
void end(int x)
{
    exit(0);
}

//调试时打印棋盘
void printBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
    {
    	if(i==0)
    	{
    		cout<<"  0 1 2 3 4 5 6 7 8 9 A B "<<endl;
		}
        for (int j = 0; j < BOARD_SIZE; j++)
        {
        	if(j==0)
        	{
        		if(i==10) cout<<"A ";
        		else if(i==11) cout<<"B ";
        		else cout<<i<<" ";
			}
			if(board[i][j]==0) cout<<"- ";
			else if(board[i][j]==1) cout<<"# ";
			else cout<<"O ";
        	if(j==BOARD_SIZE-1)
        	{
        		if(i==10) cout<<"A";
        		else if(i==11) cout<<"B";
        		else cout<<i;
			}
		}
		cout<<endl;
		if(i==BOARD_SIZE-1)
    	{
    		cout<<"  0 1 2 3 4 5 6 7 8 9 A B "<<endl;
		}
	}
	if(isWin()==1) cout<<"黑胜！"<<endl;
	else if(isWin()==2) cout<<"白胜！"<<endl;
	else if(isWin()==0&&chessmanCount==144) cout<<"和棋！"<<endl;
}
void loop()
{
    char tag[10] = {0};
    struct Command command =
        {
            .x = 0,
            .y = 0,
        };
    int status;
    while (true)
    {
        memset(tag, 0, sizeof(tag));
        scanf("%s", tag);
        if (strcmp(tag, START) == 0)
        {
            scanf("%d", &myFlag);
            start(myFlag);
            printf("OK\n");
            fflush(stdout);
        }
        else if (strcmp(tag, PLACE) == 0)
        {
            scanf("%d %d", &command.x, &command.y);
            place(command,enemyFlag);
        }
        else if (strcmp(tag, TURN) == 0)
        {
            turn();
        }
        else if (strcmp(tag, END) == 0)
        {
            scanf("%d", &status);
            end(status);
        }
    }
}
int main(int argc, char *argv[])
{
    loop();
    return 0;
}
