#include <iostream>
#include <string.h>
#include <time.h>			//��ʱ 
#include <vector>			//vector���� 
#include <algorithm>
#include <unordered_map>		//�������� 
#include <chrono>			//��ȷ��ʱ 

#define BOARD_SIZE 12		//���̳ߴ� 
#define EMPTY 0
#define BLACK 1
#define WHITE 2

#define START "START"		//ָ�� 
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"

//��������
#define ONE (10)			//��һ 
#define TWO (100)			//���
#define THREE (1000)		//���� 
#define FOUR (100000)		//���� 
#define FIVE (10000000)		//���� 
#define BLOCKED_ONE (1)		//��һ 
#define BLOCKED_TWO (10)		//�߶� 
#define BLOCKED_THREE (100)	//���� 
#define BLOCKED_FOUR (10000)	//���� 

#define STRANGE_NUM (999)	//����� 
#define MAX_SCORE (FIVE*10)	//��߷� 
#define MIN_SCORE (-1*MAX_SCORE)	//��ͷ� 
#define CNT_LIMIT (20)		//���ƽڵ���� 
#define SPREAD_LIMIT (1)		//������ɢ���� 
using namespace std;

//ָ��ṹ�� 
struct Command
{
    int x;
    int y;
};
char board[BOARD_SIZE][BOARD_SIZE] = {0};	//���� 
int myFlag;	//�ҷ���ɫ 
int enemyFlag;	//�з���ɫ 

int chessmanCount = 0;	//������ 
vector<struct Command>currentSteps;	//��ǰ�߷� 
vector<struct Command>allSteps;		//�����߷� 
vector<vector<int>>enemyScore(BOARD_SIZE,vector<int>(BOARD_SIZE,0));	//�Է��÷� 
vector<vector<int>>myScore(BOARD_SIZE,vector<int>(BOARD_SIZE,0));	//�ҷ��÷� 
int dirScore[2][4][BOARD_SIZE][BOARD_SIZE]={0};			//������ 

long long zobristValue[2][BOARD_SIZE][BOARD_SIZE];	//һ�ֿ����ж������Ƿ�ı�Ĺ�ϣ�� 
long long currentZobrist;	//��ǰ��ϣֵ 

bool isStarSpread = true;	//Ҫ��Ҫ������ɢ 
bool isCached = true;	//Ҫ��Ҫ���� 

int searchDepth=20;	//AB������� 
int nodeCount=0;		//�ڵ��� 
int ABcut=0;		//AB��֦�� 
int cacheCount=0;		//������ 
int cacheGet=0;		//������
//�ڵ�ṹ�� 
struct Node
{
	bool abcut;	//�Ƿ񱻼�֦ 
	int depth;		//������� 
	int score;		//���� 
	int step;		//���� 
	vector<struct Command>steps;	//��ϸ�� 
};
unordered_map<long long,struct Node>cache;		//AB�ڵ㻺�� 
unordered_map<long long,struct Node>::iterator it;	//AB������ 

int VCX_MAX_SCORE = THREE;	//��ɱ��߷� 
int VCX_MIN_SCORE = FOUR;	//��ɱ��ͷ�
//��ɱ�ṹ�� 
struct VCX
{
	struct Command cmd;
	int score;
	bool b;	//�Ƿ���ʤ 
};
int vcxDepth=15;	//��ɱ��� 
unordered_map<long long,vector<struct VCX>>cacheVCF;	//���Ļ������� 
unordered_map<long long,vector<struct VCX>>::iterator itVCF;	//���Ļ��������� 
unordered_map<long long,vector<struct VCX>>cacheVCT;	//˫������ 
unordered_map<long long,vector<struct VCX>>::iterator itVCT;	//˫�������� 
struct VCX lastMaxPoint, lastMinPoint;	//���¼���㡢��С�� 

std::chrono::time_point<std::chrono::steady_clock> startTime,endTime;	//��ʱ�� 
std::chrono::duration<double,ratio<1,1>>duration;	//����ʱ�� 

void place(struct Command cmd,int flag);	//�������Ӻ��� 
void remove(struct Command cmd);		//����ȥ�Ӻ��� 

//����64λ�����
//��������Zobrist��ϣֵ
//������void
//����ֵ��long long int 
long long random64()
{
    return (long long)rand() | ((long long)rand() << 15) | ((long long)rand() << 30) | ((long long)rand() << 45) | ((long long)rand() << 60);
}

//��ʼ��Zobrist
//����������ֵ��void 
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

//����Zobrist
//��ǰ��ϣֵ�����̶�Ӧλ�ù�ϣֵ��λ����ֵ��ǰ��ϣֵ
//��������-���ͣ���-���ͣ�ִ����ɫ-����
//����ֵ��long long int 
long long goZobrist(int x,int y,int flag)
{
	currentZobrist ^= zobristValue[flag-1][x][y];
	return currentZobrist;
}

//����Ԥ����
//�������ĸ����͵�����
//����ֵ��void 
void resetEvaluationEmpty(int&count,int&block,int&empty,int&secondCount)
{
	count=1;
	block=0;
	empty=-1;
	secondCount=0;
}

//�������ͷ��ط���
//�����Ǹ������Ӹ����������жϵ�
//������������-���ͣ�����-���ͣ���λ��-��Ĭ��ֵ������ 
//����ֵ������
int count2Score(int count,int block,int empty=STRANGE_NUM)
{
	if(empty==STRANGE_NUM) empty=0;	//����Ĭ��ֵʱ��� 
	
	if(empty<=0)	//���� 
	{
		if(count>=5) return FIVE;	//���� 
		if(block==0)	//���� 
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
		if(block==1)	//һ���� 
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
	else if(empty==1||empty==count-1)	//ȱһ�� 
	{
		if(count>=6) return FIVE;	//������ 
		if(block==0)		//���� 
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
		if(block==1)		//һ���� 
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
	else if(empty==2||empty==count-2)	//������λ���������� 
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

//��������
//����λ���
//��������������������ɫ������ 
//����ֵ���ܷ� 
int evaluateEmpty(int x,int y,int flag,int direction = -1)
{
	int result=0;	//�ܷ� 
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

//����λ����û������
//����������ڵ�������Ǽ���������
//ÿ��ֻ������Χ�����ӵ�λ��
//���������������������룬������
//����ֵ���Ƿ����Ҫ�� 
bool hasNeighbour(int x,int y,int distance,int count)
{
	int startX = x-distance;
	int endX = x+distance;
	int startY = y-distance;
	int endY = y+distance;
	for(int i=startX;i<=endX;i++)	//�������ܣ�ͳ�����Ӹ��� 
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

//������������������
//��ֹ��ͣ����
//����������
//����ֵ������������� 
int fixScore(int type)
{
	if(type<FOUR&&type>=BLOCKED_FOUR)	//���������ϣ��������µ��������� 
	{
		if(type>=BLOCKED_FOUR&&type<(BLOCKED_FOUR+THREE))	//ֻ���ģ����岻�� 
		{
			return THREE;	//����Ϊ���� 
		}
		else if(type>=BLOCKED_FOUR+THREE&&type<BLOCKED_FOUR*2)	//���Ļ��� 
		{
			return FOUR;	//����Ϊ���� 
		}
		else
		{
			return FOUR*2;	//�������Ǳ�ɱ�壬�� 
		}
	}
	return type;
}

//�������
//�����㵱ǰ�������
//��������ɫ
//����ֵ��������� 
int evaluate(int flag)
{
	int myMaxScore = 0;
	int enemyMaxScore = 0;
	
	for(int i=0;i<BOARD_SIZE;i++)	//������������ 
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==myFlag)		//�ҷ��÷֣������ҷ��÷� 
			{
				myMaxScore+=fixScore(myScore[i][j]);
			}
			else if(board[i][j]==enemyFlag)	//�з��÷֣�����з��÷� 
			{
				enemyMaxScore+=fixScore(enemyScore[i][j]);
			}
		}
	}
	int result=(flag==myFlag?1:-1)*(myMaxScore-enemyMaxScore);	//�ҷ�Ϊ�����з�Ϊ�� 
	return result;
}

//������ַ����ϵ�����
//�����е�λ���
//����������㣬����������㼯
//����ֵ���Ƿ�������� 
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

//�������� 
//��������ɫ��ֻ��������������ɢ
//����ֵ������㼯
vector<struct Command> generate(int flag,bool onlyThrees=false,bool starSpread=false)
{
	if(chessmanCount<=4)	//ִ�ڣ���һ���°׻��
	{
		return {{7,7}};
	}
	
	if(chessmanCount==6&&board[7][4]!=enemyFlag&&board[4][7]!=enemyFlag)
	{
		return {{7,4}};		//ִ�ڣ��ڶ����Լ�����
	}

	vector<struct Command>fives;			//����
	vector<struct Command>myFours;			//�һ���
	vector<struct Command>enemyFours;		//�л���
	vector<struct Command>myBlockedFours;	//������
	vector<struct Command>enemyBlockedFours;//������
	vector<struct Command>myTwoThrees;		//��˫��
	vector<struct Command>enemyTwoThrees;	//��˫��
	vector<struct Command>myThrees;			//�һ���
	vector<struct Command>enemyThrees;		//�л���
	vector<struct Command>myTwos;			//�һ��
	vector<struct Command>enemyTwos;		//�л��
	vector<struct Command>neighbours;		//�ڽӵ�
	vector<struct Command>attack;			//��
	vector<struct Command>defend;			//��
	vector<struct Command>result;			//���
	
	if(starSpread&&isStarSpread)	//����
	{
		int i=currentSteps.size()-1;	//�������
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
		
		int j=currentSteps.size()-2;	//���㹥��
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
	
	for(int i=0;i<BOARD_SIZE;i++)	//��������
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)	//Ϊ��
			{
				if(allSteps.size()<14)	//ǰ14����ֻ����Χ
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
				
				//�ѷ��ϵĵ�����Ӧ�㼯
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

//��ʼ������
//��������ÿ��λ�ø�����������
//����������ֵ��void
void initScore()
{
	for(int i=0;i<BOARD_SIZE;i++)	//��������
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)	//��λ
			{
				if(hasNeighbour(i,j,2,2))
				{
					enemyScore[i][j]=evaluateEmpty(i,j,enemyFlag);	//���Ҷ�Ҫ����
					myScore[i][j]=evaluateEmpty(i,j,myFlag);
				}
			}
			else if(board[i][j]==enemyFlag)	//����
			{
				enemyScore[i][j]=evaluateEmpty(i,j,enemyFlag);
				myScore[i][j]=0;
			}
			else if(board[i][j]==myFlag)	//����
			{
				myScore[i][j]=evaluateEmpty(i,j,myFlag);
				enemyScore[i][j]=0;
			}
		}
	}
}

//���·�����ֳ��Ĳ���
//����������������������
//����ֵ��void
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

//���ݷ�����·���
//����������
//����ֵ��void
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
//��ɱ֮Ѱ�����ֵ
//������minmax�������һ��
//��������ɫ������
//����ֵ����㼯��
vector<struct VCX> findMax(int flag, int score)
{
	vector<struct VCX>result;	//�������
	vector<struct VCX>fives;	//���弯��
	for(int i=0;i<BOARD_SIZE;i++)	//��������
	{
		for(int j=0;j<BOARD_SIZE;j++)
		{
			if(board[i][j]==EMPTY)	//��λ
			{
				struct VCX pos;
				pos.cmd.x=i;
				pos.cmd.y=j;
				
				if(enemyScore[i][j]>=FIVE)	//�����⣬�г���
				{
					pos.score=FIVE;
					if(flag==myFlag) pos.score*=-1;
					fives.push_back(pos);
				}
				else if(myScore[i][j]>=FIVE)	//�����⣬�г���
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
	if(!fives.empty()) return fives;	//�ȿ�����
	//���շ����ɴ�С����
	sort(result.begin(),result.end(),[](struct VCX a,struct VCX b)->bool{
		return b.score < a.score;
	});
	return result;
}

//core algorithm
//checkmate
//find all enemy positions whose scores are above threshold
//��ɱ֮Ѱ����Сֵ
//������minmax����С���һ��
//��������ɫ������
//����ֵ����㼯��
vector<struct VCX> findMin(int flag, int score)
{
	vector<struct VCX>result;	//�������
	vector<struct VCX>fives;	//���弯��
	vector<struct VCX>fours;	//���ļ���
	vector<struct VCX>blockedFours;	//���ļ���
	
	for(int i=0;i<BOARD_SIZE;i++)	//��������
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
				
				if(score1>=FIVE)	//�����壬����С��
				{
					pos.score = -score1;
					result.push_back(pos);
					return result;
				}
				if(score2>=FIVE)	//�����壬������
				{
					pos.score=score2;
					fives.push_back(pos);
					continue;
				}
				if(score1>=FOUR)	//�һ��ģ�����С��
				{
					pos.score = -score1;
					fours.insert(fours.begin(),pos);
					continue;
				}
				if(score2>=FOUR)	//�л��ģ�������
				{
					pos.score=score2;
					fours.push_back(pos);
					continue;
				}
				if(score1>=BLOCKED_FOUR)	//�����ģ�����С��
				{
					pos.score = -score1;
					blockedFours.insert(blockedFours.begin(),pos);
					continue;
				}
				if(score2>=BLOCKED_FOUR)	//�����ģ�������
				{
					pos.score=score2;
					blockedFours.push_back(pos);
					continue;
				}
				if(score1>=score||score2>=score)	//������ֵ
				{
					pos.score=score1;
					result.push_back(pos);
				}
			}
		}
	}
	if(!fives.empty()) return fives;	//����ֱ�ӷ���
	if(!fours.empty())		//�ѻ��ĺ�����ƴ��һ��
	{
		fours.insert(fours.end(),blockedFours.begin(),blockedFours.end());
		return fours;
	}
	result.insert(result.end(),blockedFours.begin(),blockedFours.end());
	//���շ����Ӵ�С����
	sort(result.begin(),result.end(),[](struct VCX a,struct VCX b)->bool{
		return abs(b.score) < abs(a.score);
	});
	return result;
}

vector<struct VCX> minFloor(int flag,int depth);	//����
//core algorithm
//���ֵ��
//��������ɫ�����
//����ֵ���ڵ㼯��
vector<struct VCX> maxFloor(int flag,int depth)
{
	vector<struct VCX>pos;
	if(depth<=1)	//�������û�ҵ���ɱ��
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	
	pos=findMax(flag,VCX_MAX_SCORE);
	if(!pos.empty()&&pos[0].score>=FOUR)	//�ҵ���ɱ��
	{
		vector<struct VCX>tmp;
		tmp.push_back(pos[0]);
		return tmp;
	}
	if(pos.empty())		//û�ҵ�
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	for(unsigned int i=0;i<pos.size();i++)	//����һ���ҵ��ı�ɱ��
	{
		struct VCX p=pos[i];
		place(p.cmd,flag);
		if(!(p.score<=-FIVE)) lastMaxPoint=p;
		vector<struct VCX> temp=minFloor(3-flag,depth-1);	//������Сֵ��
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
//�ж��Ƿ�����
//��������������������ɫ
//����ֵ���Ƿ�����
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
//�ж��ǲ���Ӯ��
//������void
//����ֵ����Ӯ�����ɫ
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
//��Сֵ��
//��������ɫ�����
//����ֵ���ڵ㼯��
vector<struct VCX> minFloor(int flag,int depth)
{
	vector<struct VCX>pos;
	int currentFlag=isWin();	//Ӯ����ɫ
	if(currentFlag==flag)		//����Ӯ
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	if(currentFlag==(3-flag))	//����Ӯ
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=true;
		pos.push_back(tt);
		return pos;
	}
	if(depth<=1)		//�����û�ҵ���ɱ��
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	
	pos=findMin(flag,VCX_MIN_SCORE);
	if(pos.empty())		//û��
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	if(!pos.empty()&&(-1*pos[0].score)>=FOUR)	//��ɱ
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		pos.push_back(tt);
		return pos;
	}
	
	vector<struct VCX>candidates;
	for(unsigned int i=0;i<pos.size();i++)	//�������ҳ���ѡ��
	{
		struct VCX p=pos[i];
		place(p.cmd,flag);
		lastMinPoint=p;
		vector<struct VCX> temp=maxFloor(3-flag,depth-1);	//��������
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

//������ɱ�ڵ�
//�����Ե�ǰZobristֵΪ�����ڵ�Ϊֵ
//�������ڵ㼯�ϣ�VCF����VCT
//����ֵ��void
void saveVCX(vector<struct VCX>result,bool vcf)
{
	if(!isCached) return;	//�ص��˻���
	if(vcf)
	{
		cacheVCF[currentZobrist]=result;
	}
	else
	{
		cacheVCT[currentZobrist]=result;
	}
}

//��ȡ�������ɱ�ڵ�
//������VCF����VCT
//����ֵ����ȡ���Ľڵ㼯��
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
//����������ɱ
//��������ɫ�����
//����ֵ���ڵ㼯��
vector<struct VCX> deepingVCX(int flag,int depth)
{
	vector<struct VCX> result;	//����ڵ㼯��
	for(int i=1;i<=depth;i++)
	{
		lastMaxPoint.cmd.x=STRANGE_NUM;	//��ʼ��
		lastMinPoint.cmd.x=STRANGE_NUM;
		result=maxFloor(flag,depth);	//�������ֵ��
		if((result[result.size()-1].cmd.x==-1&&result[result.size()-1].b)||!result.empty()) break;	//�ҵ��ˣ���ǰ�˳�����
	}
	return result;
}

//core algorithm
//��ɱ
//��������ɫ����ȣ�ֻ����ڵ��ڻ���
//����ֵ�����������Ľڵ㼯��
vector<struct VCX> vcx(int flag,int depth,bool onlyFour)
{
	vector<struct VCX>result;
	if(depth<=0)	//�������
	{
		struct VCX tt;
		tt.cmd.x=-1;
		tt.b=false;
		result.push_back(tt);
		return result;
	}
	
	if(onlyFour)	//�����˴��ڵ��ڻ���
	{
		VCX_MAX_SCORE=BLOCKED_FOUR;	//��ɱ�������¸�ֵ
		VCX_MIN_SCORE=FIVE;			//��ɱ��Сֵ���¸�ֵ
		
		result=deepingVCX(flag,depth);	//��������
		if((result[result.size()-1].cmd.x==-1&&result[result.size()-1].b)||!result.empty())	//�ҵ�
		{
			result[result.size()-1].score=FOUR;
			return result;
		}
		struct VCX tt;	//û�ҵ�
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
//���Ļ�����ɱ
//��������ɫ�����
//����ֵ���ڵ㼯��
vector<struct VCX> vcf(int flag,int depth)
{
	vector<struct VCX>tmp=getVCX(true);
	if(!tmp.empty()) return tmp;
	vector<struct VCX>result=vcx(flag,depth,true);
	saveVCX(result,true);
	return result;
}

//core algorithm
//˫����ɱ
//��������ɫ�����
//����ֵ���ڵ㼯��
vector<struct VCX> vct(int flag,int depth)
{
	vector<struct VCX>tmp=getVCX(false);
	if(!tmp.empty()) return tmp;
	vector<struct VCX>result=vcx(flag,depth,false);
	saveVCX(result,false);
	return result;
}

//cache
//alpha-beta�����ڵ㻺��
//��ʹ�õ�ǰZobristֵ��Ϊ����AB�ڵ���Ϊֵ
//��������ȣ�AB�ڵ�
//����ֵ��void
void save(int depth,struct Node score)
{
	if(!isCached) return;
	if(score.abcut) return;	//��������
	cache[currentZobrist]=score;
	cacheCount++;
}

//core algorithm
//alpha-beta�㷨�м�ؼ�һ��
//��������ȣ�alpha��beta����ɫ��������·��������
//����ֵ��AB�ڵ�
struct Node middleStep(int depth,int alpha,int beta,int flag,int step,vector<struct Command>steps,int spread)
{
	if(isCached)	//�Ƿ񻺴�
	{
		it=cache.find(currentZobrist);	//�������ҵ���ǰZobrist��ϣֵ�����򷵻�end()
		if(it!=cache.end())		//�ҵ���
		{
			if(it->second.depth>=depth)		//���²�
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
	
	int evaluatedScore=evaluate(flag);	//��������
	
	//Ҷ�ڵ�
	struct Node leaf=
	{
		.abcut=false,
		.depth=depth,
		.score=evaluatedScore,
		.step=step,
		.steps=steps
	};
	
	nodeCount++;
	//��ɱ����û�ҵ��߷����Ҷ�ڵ�����
	if(depth<=0||evaluatedScore>=FIVE||evaluatedScore<=-FIVE)
	{
		endTime = std::chrono::steady_clock::now();		//����һ�±�ʱ��
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		if (duration.count() > 1.4) return leaf;
		
		//sha
		if(evaluatedScore<FOUR&&evaluatedScore>FOUR*-1)		//���Ļ���ɱ
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
		
		endTime = std::chrono::steady_clock::now();		//����һ�±�ʱ��
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		if (duration.count() > 1.4) return leaf;
		
		if(evaluatedScore<THREE*2&&evaluatedScore>THREE*-2)		//˫��ɱ
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
	
	//��ѽڵ�
	struct Node best=
	{
		.abcut=false,
		.depth=depth,
		.score=MIN_SCORE,
		.step=step,
		.steps=steps
	};
	
	vector<struct Command> points = generate(flag,chessmanCount>10?step>1:step>3,step>1);	//��һ��
	
	if(points.empty()) return leaf;		//û�кõ�λ��
	
	for(unsigned int i=0;i<points.size();i++)	//�������ܽ�
	{
		struct Command pos = points[i];
		place(pos,flag);			//��
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
		struct Node tmp = middleStep(newDepth,-beta,-alpha,3-flag,step+1,newSteps,newSpread);	//�ݹ�
		tmp.score*=-1;		//�������ȡ��
		remove(pos);		//�Ƴ�
		
		if(tmp.score>best.score)	//�ȵ�ǰ��õĻ�Ҫ��
		{
			best=tmp;
		}
		alpha=max(best.score,alpha);	//����alpha
		
		//ABcut
		if(tmp.score>=beta)		//��֦
		{
			ABcut++;
			tmp.score=MAX_SCORE-1;
			tmp.abcut=true;
			return tmp;
		}
	}
	save(depth,best);		//������ѽڵ�
	return best;
}

//core algorithm
//min-max
//����ֵ��Сֵ�㷨���ܹؼ�
//��������ѡ�㼯�ϣ���ɫ����ȣ�alpha��beta
//����ֵ��alpha
int minmax(vector<struct Node>candidates,int flag,int depth,int alpha,int beta)
{
	for(unsigned int i=0;i<candidates.size();i++)	//������ѡ��
	{
		struct Command pos=candidates[i].steps[candidates[i].steps.size()-1];
		place(pos,flag);		//����
		vector<struct Command>steps;
		steps.insert(steps.begin(),candidates[i].steps.begin(),candidates[i].steps.end());	//�ѹ��̸�����ǰ·��
		struct Node tmp = middleStep(depth-1,-beta,-alpha,3-flag,1,steps,0);	//���õݹ麯��
		tmp.score*=-1;		//����ȡ��
		alpha=max(alpha,tmp.score);		//alphaȡ���
		remove(pos);			//�Ƴ�
		
		candidates[i].score=alpha;	//����
		
		//timeout
		endTime=std::chrono::steady_clock::now();		//����ʱ�䣬��ʱ�˳�ѭ���������н���������ʱ��Ĺ�ϵ
		duration=std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		if(duration.count()>1.5)break;
	}
	return alpha;
}

//maths
//�е�
//����������˫���ȸ�����
//����ֵ����һ����Χ����Ϊ��ȷ�
bool isEqual(double a,double b)
{
	return (b>=0?((a>=(b/1.15))&&(a<=(b*1.15))):((a>=(b*1.15))&&(a<=(b/1.15))));
}

//core algorithm
//��������
//�Ӵ˿�ʼ����
//��������ѡ�㼯�ϣ���ɫ�����
//����ֵ��AB�ڵ�
struct Node deeping(vector<struct Node>candidates,int flag,int depth)
{
	//start time
	startTime=std::chrono::steady_clock::now();		//�����￪ʼ��ʱ
	cache.clear();		//�建��
	
	int bestScore;
	for(int i=2;i<=depth;i+=2)		//�����ֵ�������ֵ
	{
		bestScore=minmax(candidates,myFlag,i,MIN_SCORE,MAX_SCORE);
		if(bestScore>=FIVE) break;
	}
	
	//����������Ҫ��һ���̶��Ͼ���ʱ�䳤��
	//����ֵ�������ĵ����ǰ�棬����ʱ�����ģ�Ҳ��ֹʱ�䲻����Ӳ����
	sort(candidates.begin(),candidates.end(),[](struct Node a,struct Node b)->bool{
		if(isEqual(a.score,b.score))	//��������
		{
			if(a.score>=0)		//����������������
			{
				if(a.step!=b.step) return a.step<b.step;	//ѡ�����̵�
				else return b.score<a.score;	//ѡ�ָߵ�
			}
			else				//���ָ������Ҳ���
			{
				if(a.step!=b.step) return b.step<a.step;	//ѡ��������
				else return b.score<a.score;	//ѡ�ָߵ�
			}
		}
		else return (b.score<a.score);	//�ָߵ���ǰ��
	});
	
	return candidates[0];	//������õ�
}

//core algorithm
//����
//����С��AB�㷨�͵����������ɱ�����
//��������ɫ��������ȣ�д�����ɵ���
//����ֵ���ӵ�TURN�󷵻ص�����
struct Command calculate(int flag,int depth=searchDepth)
{
	vector<struct Command>tmp=generate(flag);	//��һ��
	vector<struct Node>candidates;		//��ѡ�˼���
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
	
	temp=deeping(candidates,flag,depth);	//��������
	struct Command result=temp.steps[0];	//�յ����
	
	return result;
}

//����������д�Ĵ���ģ�壬���ض���
void debug(const char *str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}
bool isInBound(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

//����
//���������꣬��ɫ
//����ֵ��void
void place(struct Command cmd,int flag)
{
    board[cmd.x][cmd.y] = flag;		//λ����Ϊ��ɫ
    goZobrist(cmd.x,cmd.y,flag);	//�޸�Zobrist
    updateScore(cmd);				//�����������
    allSteps.push_back(cmd);		//·��������һ��
    currentSteps.push_back(cmd);	//��ǰ����
    chessmanCount++;				//������+1
}

//�Ƴ�
//����������
//����ֵ��void
void remove(struct Command cmd)
{
	char ch=board[cmd.x][cmd.y];	//��ȡ��ɫ
	goZobrist(cmd.x,cmd.y,ch);		//�޸�Zobrist
	board[cmd.x][cmd.y]=EMPTY;		//��������Ϊ��
	updateScore(cmd);				//�����������
	allSteps.pop_back();			//����
	currentSteps.pop_back();		//����
	chessmanCount--;				//������-1
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

//����ʱ��ӡ����
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
	if(isWin()==1) cout<<"��ʤ��"<<endl;
	else if(isWin()==2) cout<<"��ʤ��"<<endl;
	else if(isWin()==0&&chessmanCount==144) cout<<"���壡"<<endl;
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
