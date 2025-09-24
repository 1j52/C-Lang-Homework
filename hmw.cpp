#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct {
    int HP=100;
	int PP=100;
	int IQ=0;
	char name[50];
	int mood;
	int day=1;
} Player;

void crtPlayer(Player *player)
{
	printf("请输入你的名字:");
	scanf("%s",player->name);
	player->HP=100;
	player->PP=100;
	player->IQ=0;
	player->mood=100;
}

void showP(Player *player)
{
	printf("\n============ 玩家状态 ============\n");
	printf("姓名:%s\n",player->name);
	printf("生命:%d\n",player->HP);
	printf("体力:%d\n",player->PP);
	printf("智力:%d\n",player->IQ);
	printf("心情:%d\n",player->mood);
}

void Event(Player *player)
{
	int event=0;
	printf("\n今天是在SWMU的周%d\n",player->day);	
	event=rand()%100;
	if(event<50){
		int choice;
		printf("\nOH NO!今天要上早八\n你的选择是:n1.早起学习 2.给自己'放假'\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			printf("Study Study Study Day Day Up\n");
			player->PP=80;player->IQ=5;
			showP(player);
		break;
		case 2:
			printf("'放假'固然舒适，但感觉有种不详之感涌上心头\n");
			player->PP=120;player->HP=80;
			showP(player);
		}
		}
	else if(event<100)
	{
		int choice;
		printf("\n今天无早八\n你的选择是:\n1.早起学习 2.外出散步\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			printf("Study Study Study Day Day Up\n");
			player->PP=80;player->IQ=5;
			showP(player);
			break;
		case 2:
			printf("运动有利于身体健康\n");
			player->PP=80;player->HP=120;
			showP(player);
			break;
	}
}
	printf("\n====== 上午事件：小组讨论 ======\n");
	int choice1;
	printf("今天有小组讨论\n你的选择是:\n1.积极参与 2.摸鱼划水\n");
	scanf("%d", &choice1);
	switch(choice1){
	case 1:
		printf("和组员激烈讨论，收获颇丰！\n");
		player->IQ += 8; player->PP -= 15; player->mood += 5;
		break;
	case 2:
		printf("默默玩手机，但被老师发现了...\n");
		player->PP -= 20; player->IQ -= 3; player->mood -= 10;
		break;
	}
	showP(player);
	printf("\n====== 中午事件：食堂选择 ======\n");
	int choice2;
	printf("食堂推出新菜品\n你的选择是:\n1.勇敢尝试 2.保守选择\n");
	scanf("%d", &choice2);
	switch(choice2){
	case 1:
		if(rand() % 100 < 70){
			printf("新菜品意外地好吃！\n");
			player->HP += 15; player->PP += 10; player->mood += 15;
		} else {
			printf("新菜品味道奇怪，肚子不舒服...\n");
			player->HP -= 10; player->PP -= 5; player->mood -= 10;
		}
		break;
	case 2:
		printf("安全第一，选择了经典套餐\n");
		player->HP += 10; player->PP += 5; player->mood += 5;
		break;
	}
	showP(player);
	printf("\n====== 下午事件：学习难题 ======\n");
	int choice3;
	printf("遇到难题不会做\n你的选择是:\n1.请教老师 2.自己钻研\n");
	scanf("%d", &choice3);
	switch(choice3){
	case 1:
		printf("老师耐心讲解，茅塞顿开！\n");
		player->IQ += 10; player->PP -= 10; player->mood += 8;
		break;
	case 2:
		if(rand() % 100 < 60){
			printf("苦思冥想，终于解决了问题！\n");
			player->IQ += 15; player->PP -= 20; player->mood += 12;
		} else {
			printf("想了很久还是不会，有点沮丧...\n");
			player->IQ += 5; player->PP -= 15; player->mood -= 8;
		}
		break;
	}
	showP(player);
	printf("\n====== 晚上事件：自由时间 ======\n");
	int nightChoice;
	if(player->mood > 60){
		printf("心情不错！晚上的计划是:\n1.图书馆自习 2.运动锻炼 3.和朋友出去玩\n");
	} else if(player->mood > 30){
		printf("心情一般，晚上的计划是:\n1.图书馆自习 2.运动锻炼 3.宿舍休息\n");
	} else {
		printf("心情低落，需要调整:\n1.听音乐放松 2.早点睡觉 3.吃零食治愈\n");
	}
	scanf("%d", &nightChoice);
	switch(nightChoice){
	case 1:
		printf("在图书馆高效学习！\n");
		player->IQ += 10; player->PP -= 15; player->mood += 3;
		break;
	case 2:
		if(player->mood > 60){
			printf("和朋友一起运动，超开心！\n");
			player->HP += 15; player->PP += 10; player->mood += 10;
		} else {
			printf("独自运动，出出汗舒服多了\n");
			player->HP += 15; player->PP += 10; player->mood += 5;
		}
		break;
	case 3:
		if(player->mood > 60){
			printf("和朋友出去玩，超开心！\n");
			player->HP += 10; player->PP += 15; player->mood += 12;
		} else if(player->mood > 30){
			printf("在宿舍好好休息\n");
			player->HP += 20; player->PP += 25; player->mood += 8;
		} else {
			printf("吃零食看剧，心情好多了\n");
			player->HP += 10; player->PP += 15; player->mood += 15;
		}
		break;
	}
	printf("\n====== 今日结算 ======\n");
	printf("SMNU的第%d天结束了！\n", player->day);
	player->day++;
	
	if(player->mood > 80){
		printf("今天过得很开心！明天精力充沛！\n");
		player->PP += 10;
	} else if(player->mood < 20){
		printf("心情低落，需要调整状态...\n");
		player->PP -= 10;
	}
	showP(player);
}

void FridayAchievement(Player *player) {
	printf("\n====== 周五成就结算 ======\n");
	printf("SMNU本周结束！本周成就：\n");
	if (player->HP > 150) {
		printf("健康达人：HP超过150！身体状态极佳\n");
	} else if (player->HP < 50) {
		printf("虚弱警告：HP低于50，需要注意健康\n");
	}
	if (player->PP > 150) {
		printf("精力旺盛：PP超过150！活力充沛\n");
	} else if (player->PP < 50) {
		printf("疲惫不堪：PP低于50，需要休息恢复\n");
	}
	
	if (player->IQ > 30) {
		printf("学霸附体：IQ超过30！学习成果显著\n");;
	} else if (player->IQ > 15) {
		printf("学习积极分子：IQ超过15！保持学习热情\n");
	}
	if (player->mood > 80) {
		printf("心情愉悦：心情超过80！保持良好心态\n");
	} else if (player->mood < 20) {
		printf("情绪低落：心情低于20，建议调整状态\n");
	}
	if (player->HP > 100 && player->PP > 100 && player->IQ > 20) {
		printf("全面发展：各项属性均衡优秀\n");
	}
	
	if (player->HP < 60 && player->PP < 60) {
		printf("状态不佳：健康和体力都需要关注\n");
	}
	if (player->mood > 90 && player->IQ > 25) {
		printf("快乐学习：心态好学习效率高\n");
	}
	if (player->HP < 40 && player->PP < 40 && player->mood < 30) {
		printf("急需调整：全面状态不佳\n");
	}
	printf("周末好好休息，下周继续加油！\n");
}

void SaveGame(Player *player) {
	FILE *file = fopen("D:\\C lang\\Arc.txt","wb");
	if (file == NULL) {
		printf("存档失败！无法创建存档文件\n");
		return;
	}
	fwrite(player, sizeof(Player), 1, file);
	fclose(file);
	printf("游戏已自动存档！\n");
	printf("HP:%d PP:%d IQ:%d Mood:%d\n", 
		player->HP, player->PP, player->IQ, player->mood);
}

void LoadGame(Player *player) {
	FILE *file = fopen("D:\\C lang\\Arc.txt", "rb");
	
	if (file == NULL) {
		printf("未找到存档文件，开始新游戏\n");
		return;
	}
	 int result = fread(player, sizeof(Player), 1, file);
	fclose(file);
	
	if (result == 1) {
		printf("存档加载成功！\n");
		printf("欢迎回到SMNU第%d天\n", player->day);
		printf("当前状态：Name:%s HP:%d PP:%d IQ:%d Mood:%d\n", 
			player->name,player->HP, player->PP, player->IQ, player->mood);
	} else {
		printf("存档文件损坏，开始新游戏\n");
	}
}

int main()
{
	Player player;
	printf("1. 新游戏\n2. 加载存档\n选择：");
	int choice;
	scanf("%d", &choice);
	
	if (choice == 2) {
		LoadGame(&player);
	}
	else
	{
		crtPlayer(&player);
	}
	for(int i=player.day;i<6;i++)
	{
		Event(&player);
		SaveGame(&player);
	}
	FridayAchievement(&player);
	return 0;
}
