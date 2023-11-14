//项目名字：异界转生之旅
//作者： Black-Star
//更新日志
//修改日期：2023.11.9（添加背包功能雏形，完善地图）
//修改日期：2023.11.10（添加存档，读档功能，但错误） 
//修改日期：2023.11.11（添加文字输出延迟，改善游戏体验）
//					  （小地图：即村庄内）
//						(修复存档，读档功能的bug)
//修改日期：2023.11.12 (完善游戏重新输入，怪物模板完善） 
//                     （创造物品维度） 
//修改日期：2023.11.13 (完善背包系统) 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h> 
void Listen_move(struct Player *player,struct Map *state,struct Item *item);
void Move_player(struct Player *player,int x,int y,struct Map *state,struct Item *item);
void Listen_input(struct Player *player,struct Map *state,struct Item *item);
void Plater_fight_enemy(struct Player *player,struct Enemy *enemy);
void On_fight_victory(struct Player *player,struct Enemy *enemy) ;
void Fight(struct Player *player,struct Enemy *enemy);
void go_angling(struct Player *player,struct Item *item);
void Item_Pickup(struct Player *player,struct Item *item);
void cc(struct Player *player);
void dq(struct Player *player);
void View_Properties_player(struct Player *player); 
void Exit_game();
void Map_cell_5();
void Map_cell_5_1 ();
void Map_cell_8(struct Player *player);
void Map_cell_4();
void Map_cell_2(struct Player *player,struct Item *item);
void Map_cell_6(struct Player *player);
void On_map_cell(struct Player *player,struct Map *state,struct Item *item);
void Random_number();
struct Map{
	int state_1;
}; 
struct Map minimap(){
	struct Map state;
	state.state_1=0;
    return state;
};
//玩家属性 
struct Player{
	int x;
	int y;
	int Hp;
	int money;
	int atk; 
	int exp;
	int lev; 
	//char bag[5][20]; 
	char bag_1[20];
	int number_1;
	char bag_2[20];
	int number_2;
	char bag_3[20];
	int number_3;
	char bag_4[20];
	int number_4;
	char bag_5[20];
	int number_5;
	int a[7] = {lev,Hp,exp,money,atk,x,y};
};
//玩家初始属性 
struct Player init_player(){
	struct Player player;
	player.x = 1;
	player.y = 1;
	player.money = 0;
	player.Hp=10;
	player.atk=5; 
	player.exp=0;
	player.lev=1;
	//player.bag[5][20] = {0};
	player.bag_1[20]={0};
	player.number_1 =0;
	player.bag_2[20]={0};
	player.number_2 =0;
	player.bag_3[20]={0};
	player.number_3 =0;
	player.bag_4[20]={0};
	player.number_4 =0;
	player.bag_5[20]={0};
	player.number_5 =0;
	player.a[7];
	return player;
}
//怪物属性种类 
struct Enemy {
	char name[20];
	char attack_mode[20];
	int Hp;
	int atk; 
};
//创建怪物模板 
struct Enemy create_enemy(int Hp ,int atk ,char name[20],char attack_mode[20]){
	struct Enemy enemy;
	enemy.Hp = Hp;//错题：不小心把p打成大写，又定义int HP，导致HP为默认值 32762，史莱姆直接把我磨死了； 
	enemy.atk = atk;
	for(int i=0;i<=20;i++){
	enemy.name[i]=name[i];
	enemy.attack_mode[i]=attack_mode[i];
}
	return enemy;
}
struct Item{
	char name[20];
	int number;
};
struct Item crate_item(char name[20],int number){
	struct Item item;
	item.number = number;
	for(int i=0;i<20;i++){
	item.name[i]=name[i];
}
	return item;
}
int main(void){
	//导入玩家数据 
	struct Map state = minimap();
	struct Player player = init_player();
	struct Item item;
	//int *veillage;
	printf("你被女神转生到这个世界来，你的记忆很模糊，只记得你答应消灭魔王、拯救世界。\n");
	Sleep(2000);
	printf("你出生在一个平凡的村庄里，在父母的教育下，你茁壮成长，现在你成年了\n") ;
	Sleep(2000);
	printf("你走上了旅行者之路\n");
	while(1){
		//游戏世界
		Listen_input(&player,&state,&item); 
	}
	return 0;
}

//拾取掉落物功能 
void Item_Pickup(struct Player *player,struct Item *item){ 
	
	/*if(player->bag == NULL || *player->bag == NULL){
		for(int i=0;i<5;i++){
			for(int j=0;j<20;j++){
				player->bag[0][j]=item->name[j];
			}
		}
	}*/
		if(player->bag_1 == NULL || *player->bag_1 == NULL){
			for(int i=0;i<20;i++){
			player->bag_1[i]=item->name[i];
			player->number_1 =item->number;}
		}else if(player->bag_2 == NULL || *player->bag_2 == NULL){
			for(int i=0;i<20;i++){
			player->bag_2[i]=item->name[i];
			player->number_2 =item->number;}
		}else if(player->bag_3 == NULL || *player->bag_3 == NULL){
			for(int i=0;i<20;i++){
			player->bag_3[i]=item->name[i];
			player->number_3 =item->number;}
		}else if(player->bag_4 == NULL || *player->bag_4 == NULL){
			for(int i=0;i<20;i++){
			player->bag_4[i]=item->name[i];
			player->number_4 =item->number; }
		}else if(player->bag_5 == NULL || *player->bag_5 == NULL){
			for(int i=0;i<20;i++){
			player->bag_5[i]=item->name[i];
			player->number_5 =item->number;
		}
	} 
	//while(player->bag_1[20] !=NULL){
	//	printf("%s",player->bag_1[20]) ;
	//}

	/*for(int i=0;i<=20;i++){
		printf("%c",player->bag_1[i]); 
	}
	printf("\t");
	for(int i=0;i<=20;i++){
		printf("%c",player->bag_2[i]); 
	}printf("\t");
	for(int i=0;i<=20;i++){
		printf("%c",player->bag_3[i]); 
	}printf("\t");
	for(int i=0;i<=20;i++){
		printf("%c",player->bag_4[i]); 
	}printf("\t");
	for(int i=0;i<=20;i++){
		printf("%c",player->bag_5[i]); 
	}
	printf("\n");*/
} 
//存储
void cc(struct Player *player)
{
	int b[7] ={player->lev,player->Hp,player->exp,player->money,player->atk,player->x,player->y};
	 FILE *fpWrite=fopen("diary_1.dat","wb");
	for(int i=0;i<=6;i++)
	{
	fprintf(fpWrite,"%08x ",b[i]);
    }
    fclose(fpWrite);
}
//读取
void dq(struct Player *player) 
{
     FILE *fpRead=fopen("diary_1.dat","rb");
     int b[7];
	for(int i=0;i<8;i++)
	{
		fscanf(fpRead,"%08x ",&b[i]);
		player->a[i]=b[i];
	}
	player->lev=player->a[0],player->Hp=player->a[1],player->exp=player->a[2],player->money=player->a[3],player->atk=player->a[4],player->x=player->a[5],player->y=player->a[6];
  }	
//玩家移动 
void Listen_move(struct Player *player,struct Map *state,struct Item *item){
	printf("请输入要前进的方向（a：向左 w：向上 d：向右 s：向下）：\n");
	char dir;
	while(getchar() != '\n');
	scanf("%c",&dir);
	int x = player->x;
	int y = player->y;
	int condition = 1;
	while(condition==1){
	switch (dir){
		case 'a':
		case 'A':
			printf("你选择了朝左边走\n");
			Move_player(player,x-1,y,state,item);
			condition=0;
			break;
		case 'w':
		case 'W':
			printf("你选择了朝上边走\n");
			Move_player(player,x,y-1,state,item);
			condition=0;
			break;
		case 'd':
		case 'D':
			printf("你选择了朝右边走\n");
			Move_player(player,x+1,y,state,item);
			condition=0;
			break;
		case 's':
		case 'S':
			printf("你选择了朝下边走\n");
			Move_player(player,x,y+1,state,item);
			condition=0;
			break;
		default:printf("无效输入，请重新输入\n");
		while(getchar() != '\n');
		scanf("%c",&dir);
		continue;
	}
}
}
//玩家移动 （判断边界） 
void Move_player(struct Player *player,int x,int y,struct Map *state,struct Item *item){
	int cols = 4;
	int rows = 4;
	if(x < 0 || x >= cols||y < 0 || y >= rows){
		printf("已到达边境之地！\n");
		printf("你来到坐标（%d,%d）的位置\n",player->x,player->y);
		return;
	}
	player->x = x;
	player->y = y;
	printf("你来到坐标（%d,%d）的位置\n",player->x,player->y);
	On_map_cell(player,state,item);
}
//查看属性 
void View_Properties_player(struct Player *player){
	printf("Hp:%d Atk：%d Lev：%d Exp:%d Money:%d\n",player->Hp,player->atk,player->lev,player->exp,player->money);
}
//监听玩家 
void Listen_input(struct Player *player,struct Map *state,struct Item *item){
	printf("接下来要做什么呢？1：查看地图，2：移动,3:查看属性,4：查看背包,5:存档，6：读档9：退出游戏\n");
	int type;
	scanf("%d",&type);
	int condition=1;
	while(condition==1){
	
	switch(type){
		case 1:if(state->state_1==1){
			printf("你选择了查看地图\n");
			printf("{  铁匠铺  ,  药铺 ,教堂}\n");
			printf("{冒险者公会, 村长家,空地}\n");
			printf("{  村民房2 ,村民房1, 家 }\n");
			condition==0;
			break;
		}else{
		
			printf("你选择了查看地图\n");
			printf("{ 酒馆 ,集市, 平原 }\n");
			printf("{母溪河,村庄,小树林}\n");
			printf("{ 山林 ,麦田, 平原 }\n");
			condition==0;
			break; 
			}
		case 2:Listen_move(player,state,item);condition==0;break; 
		case 3:View_Properties_player(player);condition==0;break;
		case 4://printf("背包：%s\n",player->bag);
		printf("背包：%s %d %s %d %s %d %s %d %s %d\n",player->bag_1,player->number_1,player->bag_2,player->number_2,player->bag_3,player->number_3,player->bag_4,player->number_4,player->bag_5,player->number_5);condition==0;break;
		case 5:cc(player);condition==0;break;
		case 6: dq(player);condition==0;break;
		case 9:printf("退出游戏\n");Exit_game();condition==0;break; 
		default: 
				printf("无效输入，请重新输入\n");
				while(getchar() != '\n');
				scanf("%d",&type);
				continue;
	} 
	break;
}
} 
 
//游戏结束 
void Exit_game(){
	printf("good bye~\n");
	exit(0);
}
void Fight(struct Player *player,struct Enemy *enemy){
	Plater_fight_enemy(player,enemy);
	On_fight_victory(player,enemy);	
} 
//战斗细节 
void Plater_fight_enemy(struct Player *player,struct Enemy *enemy){
	while(enemy->Hp > 0 && player->Hp > 0){
	printf("你拔出木剑，砍向%s\n",enemy->name);
	enemy->Hp -= player->atk;
	if(enemy->Hp > 0) {
	Sleep(1000); 
	printf("%s受到你的攻击，减少了%d点生命\n",enemy->name,enemy->attack_mode,player->atk);
	player->Hp -= enemy->atk;
	Sleep(1000); 
	printf("%s%s，你受到了%d的伤害\n",enemy->name,enemy->atk);
}
}
	if(player->Hp <=0){
		Sleep(1000); 
		printf("你倒在地上，感觉意识正在流逝，你死了\n");
		Exit_game();
	}else if(enemy->Hp <=0){
		On_fight_victory(player,enemy);
		//printf("战斗结束，你战胜了怪物\n");
	}
}
//战斗结束 
void On_fight_victory(struct Player *player,struct Enemy *enemy){
	int exp = 10;
	player->exp +=exp;
	printf("战斗结束，你战胜了怪物,获得了%d经验\n",exp);
	int upgrade_exp = 3;
	if(player->exp >= upgrade_exp){
		int lev =player->exp /upgrade_exp;
		int left = player->exp % upgrade_exp;
		int ascending_series;
		ascending_series = lev; 
		player->lev += lev;
		player->exp = left;
		printf("你升级了，等级：%d，剩余经验：%d\n",player->lev,player->exp); 
		player->atk +=ascending_series*1;
	}
}
void go_angling(struct Player *player,struct Item *item){

		int  random_number; 
		int  fish=1;
		random_number=rand()%100+1;
		if(0<=random_number&&random_number<30){
			printf("钓到普通鱼了\n");
			//player->bag_1[20] = {"Fish"};
			//char fish[20]="Fish";
			struct Item fish = crate_item("Fish",1);
				   Item_Pickup(player,&fish); 
		}else if(30<=random_number&&random_number<50){
			printf("钓到黄金鱼了\n");
			struct Item gold_fish = crate_item("Gold-Fish",1);
				   Item_Pickup(player,&gold_fish); 
		}else{
			printf("你什么也没钓到\n");
		}
} 
//创建世界 
void Map_cell_1(){
	printf("你来到酒馆，酒馆内人声鼎沸，热闹非凡。各类人物齐聚一堂，形形色色的故事在此上演。");
	Sleep(1000); 
	printf("一盏摇曳的吊灯洒下温暖的光芒，为这个热闹的场所增添了几分浪漫与神秘。\n");
	Sleep(1000); 
	printf("你选择: 1:查看四周 2：喝一杯 3：吃饭\n");
	int choose; 
	scanf("%d",&choose);
	switch(choose){
		case 1:printf("木质桌椅，陈旧却干净，墙上挂满了各式各样的挂件，闪烁着岁月的光辉。\n粗犷的汉子举杯痛饮，婀娜的女子轻拨琴弦，吟游诗人低声诉说往日传奇。\n");break;
		case 2:break;
		case 3:break;
		default:break;
	}
	
}
void Map_cell_2(struct Player *player,struct Item *item){
	
	printf("这里是村庄的母亲河(母溪河)\n");
	Sleep(1000); 
	printf("你走进岸，河水轻轻拍打着岸边的石头，水中的鱼跃出水面，那声音如同自然的交响乐，深情而悠扬。\n");
	srand((unsigned int)time(NULL));
	while(1){
	printf(" 1:钓鱼 其它：离开\n");
	int choose_2;
	scanf("%d",&choose_2);
	if(choose_2==1){
		Random_number(); 
		go_angling(player,item);
	}else{
		break;
	}
	}
}
void Map_cell_5(struct Map *state){
	printf("这是一个祥和的村庄，村民们在这扎根已久\n");
	printf("是否进入：1：是，2：否\n");
	int choose;
	scanf("%d",&choose);
	if(choose==1){
		 state->state_1=1; 
	} else if(choose==2){
		
	} else{
		printf("输入错误\n");
	}
}
void Map_cell_5_1 (){
	printf("");
}
void Map_cell_8(struct Player *player)
{

	  printf("这是村子东边的小树林，有一只史莱姆在悠闲的吃着草\n");
	  Sleep(1000);
	  printf("1：攻击它2：置之不理\n");
	  int choose;
	  scanf("%d",&choose);
	 struct Enemy slime = create_enemy(6,1,"史莱姆","向你喷出腐蚀酸液");
	  switch(choose){
	  	case 1:Plater_fight_enemy(player,&slime);break;
	  	case 2:printf("你无视了它\n");break;
	  }
	//printf("这是村子东边的小树林，这里静悄悄的，什么也没有\n");
}
void Map_cell_6(struct Player *player){
	printf("这里是一大片麦田，金色的麦田如同一片金黄色的海洋。你感到很舒服。\n");
	Sleep(2000);
	printf("正值秋季，农民正在丰收中。\n") ;
	printf("  1:帮助农民收割农作物 2：离开\n");
	int choose;
	scanf("%d",&choose);
	int money=1;
	switch(choose){
		case 1:
			printf("农民们很感谢你，给了你一些钱\n");
		    printf("你获得了100铜币\n");
		    player->money += money;
		    break;
		case 2:
			break; 
	}
}
void Map_cell_4(){
	printf("热闹的集市\n");
}
void Map_cell_9(){
	printf("这里是一片草原\n");
	printf("1：往东北方向走2：往草原中心走\n");
	int choose,choose_1;
	scanf("%d",&choose);
	if(choose==1){
		printf("你被一群史莱姆发现了\n");
		printf("1：直接硬刚2：尼给路达哟~\n");
		scanf("%d",&choose_1);
		if(choose_1==1){
			
		} 
	}
} 
void On_map_cell(struct Player *player,struct Map *state,struct Item *item){
	int map[3][3] = {
					 {1,2,3},
					 {4,5,6},
					 {7,8,9},
					 };
					 
	int cell = map[player->x][player->y];
	//printf("请输入要查看的区域数字序号：");
	//printf("东：1南：2西：3北：4"); 
	//scanf("%d",&cell);
	switch(cell){
		case 1: Map_cell_1();break;
		case 2: Map_cell_2(player,item);break;
		case 3: break;
		case 4: Map_cell_4();break;
		case 5: Map_cell_5(state);break;
		case 6: Map_cell_6(player);break;
		case 7: break;
		case 8: Map_cell_8(player);break;
		case 9:  break;
		default: printf("这里什么也没有哦~\n");
	} 
}
void  Random_number(){
	unsigned int last_time=0;
				int current_time;
				int time_t_current_time; 
				time_t time_tcurrent=time(NULL);
	            if(current_time==last_time){
	            while(time(NULL)==last_time){} 
				}	
				last_time=current_time;
}

