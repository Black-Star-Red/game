//��Ŀ���֣����ת��֮��
//���ߣ� Black-Star
//������־
//�޸����ڣ�2023.11.9����ӱ������ܳ��Σ����Ƶ�ͼ��
//�޸����ڣ�2023.11.10����Ӵ浵���������ܣ������� 
//�޸����ڣ�2023.11.11�������������ӳ٣�������Ϸ���飩
//					  ��С��ͼ������ׯ�ڣ�
//						(�޸��浵���������ܵ�bug)
//�޸����ڣ�2023.11.12 (������Ϸ�������룬����ģ�����ƣ� 
//                     ��������Ʒά�ȣ� 
//�޸����ڣ�2023.11.13 (���Ʊ���ϵͳ) 
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
//������� 
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
//��ҳ�ʼ���� 
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
//������������ 
struct Enemy {
	char name[20];
	char attack_mode[20];
	int Hp;
	int atk; 
};
//��������ģ�� 
struct Enemy create_enemy(int Hp ,int atk ,char name[20],char attack_mode[20]){
	struct Enemy enemy;
	enemy.Hp = Hp;//���⣺��С�İ�p��ɴ�д���ֶ���int HP������HPΪĬ��ֵ 32762��ʷ��ķֱ�Ӱ���ĥ���ˣ� 
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
	//����������� 
	struct Map state = minimap();
	struct Player player = init_player();
	struct Item item;
	//int *veillage;
	printf("�㱻Ů��ת�����������������ļ����ģ����ֻ�ǵ����Ӧ����ħ�����������硣\n");
	Sleep(2000);
	printf("�������һ��ƽ���Ĵ�ׯ��ڸ�ĸ�Ľ����£�����׳�ɳ��������������\n") ;
	Sleep(2000);
	printf("��������������֮·\n");
	while(1){
		//��Ϸ����
		Listen_input(&player,&state,&item); 
	}
	return 0;
}

//ʰȡ�����﹦�� 
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
//�洢
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
//��ȡ
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
//����ƶ� 
void Listen_move(struct Player *player,struct Map *state,struct Item *item){
	printf("������Ҫǰ���ķ���a������ w������ d������ s�����£���\n");
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
			printf("��ѡ���˳������\n");
			Move_player(player,x-1,y,state,item);
			condition=0;
			break;
		case 'w':
		case 'W':
			printf("��ѡ���˳��ϱ���\n");
			Move_player(player,x,y-1,state,item);
			condition=0;
			break;
		case 'd':
		case 'D':
			printf("��ѡ���˳��ұ���\n");
			Move_player(player,x+1,y,state,item);
			condition=0;
			break;
		case 's':
		case 'S':
			printf("��ѡ���˳��±���\n");
			Move_player(player,x,y+1,state,item);
			condition=0;
			break;
		default:printf("��Ч���룬����������\n");
		while(getchar() != '\n');
		scanf("%c",&dir);
		continue;
	}
}
}
//����ƶ� ���жϱ߽磩 
void Move_player(struct Player *player,int x,int y,struct Map *state,struct Item *item){
	int cols = 4;
	int rows = 4;
	if(x < 0 || x >= cols||y < 0 || y >= rows){
		printf("�ѵ���߾�֮�أ�\n");
		printf("���������꣨%d,%d����λ��\n",player->x,player->y);
		return;
	}
	player->x = x;
	player->y = y;
	printf("���������꣨%d,%d����λ��\n",player->x,player->y);
	On_map_cell(player,state,item);
}
//�鿴���� 
void View_Properties_player(struct Player *player){
	printf("Hp:%d Atk��%d Lev��%d Exp:%d Money:%d\n",player->Hp,player->atk,player->lev,player->exp,player->money);
}
//������� 
void Listen_input(struct Player *player,struct Map *state,struct Item *item){
	printf("������Ҫ��ʲô�أ�1���鿴��ͼ��2���ƶ�,3:�鿴����,4���鿴����,5:�浵��6������9���˳���Ϸ\n");
	int type;
	scanf("%d",&type);
	int condition=1;
	while(condition==1){
	
	switch(type){
		case 1:if(state->state_1==1){
			printf("��ѡ���˲鿴��ͼ\n");
			printf("{  ������  ,  ҩ�� ,����}\n");
			printf("{ð���߹���, �峤��,�յ�}\n");
			printf("{  ����2 ,����1, �� }\n");
			condition==0;
			break;
		}else{
		
			printf("��ѡ���˲鿴��ͼ\n");
			printf("{ �ƹ� ,����, ƽԭ }\n");
			printf("{ĸϪ��,��ׯ,С����}\n");
			printf("{ ɽ�� ,����, ƽԭ }\n");
			condition==0;
			break; 
			}
		case 2:Listen_move(player,state,item);condition==0;break; 
		case 3:View_Properties_player(player);condition==0;break;
		case 4://printf("������%s\n",player->bag);
		printf("������%s %d %s %d %s %d %s %d %s %d\n",player->bag_1,player->number_1,player->bag_2,player->number_2,player->bag_3,player->number_3,player->bag_4,player->number_4,player->bag_5,player->number_5);condition==0;break;
		case 5:cc(player);condition==0;break;
		case 6: dq(player);condition==0;break;
		case 9:printf("�˳���Ϸ\n");Exit_game();condition==0;break; 
		default: 
				printf("��Ч���룬����������\n");
				while(getchar() != '\n');
				scanf("%d",&type);
				continue;
	} 
	break;
}
} 
 
//��Ϸ���� 
void Exit_game(){
	printf("good bye~\n");
	exit(0);
}
void Fight(struct Player *player,struct Enemy *enemy){
	Plater_fight_enemy(player,enemy);
	On_fight_victory(player,enemy);	
} 
//ս��ϸ�� 
void Plater_fight_enemy(struct Player *player,struct Enemy *enemy){
	while(enemy->Hp > 0 && player->Hp > 0){
	printf("��γ�ľ��������%s\n",enemy->name);
	enemy->Hp -= player->atk;
	if(enemy->Hp > 0) {
	Sleep(1000); 
	printf("%s�ܵ���Ĺ�����������%d������\n",enemy->name,enemy->attack_mode,player->atk);
	player->Hp -= enemy->atk;
	Sleep(1000); 
	printf("%s%s�����ܵ���%d���˺�\n",enemy->name,enemy->atk);
}
}
	if(player->Hp <=0){
		Sleep(1000); 
		printf("�㵹�ڵ��ϣ��о���ʶ�������ţ�������\n");
		Exit_game();
	}else if(enemy->Hp <=0){
		On_fight_victory(player,enemy);
		//printf("ս����������սʤ�˹���\n");
	}
}
//ս������ 
void On_fight_victory(struct Player *player,struct Enemy *enemy){
	int exp = 10;
	player->exp +=exp;
	printf("ս����������սʤ�˹���,�����%d����\n",exp);
	int upgrade_exp = 3;
	if(player->exp >= upgrade_exp){
		int lev =player->exp /upgrade_exp;
		int left = player->exp % upgrade_exp;
		int ascending_series;
		ascending_series = lev; 
		player->lev += lev;
		player->exp = left;
		printf("�������ˣ��ȼ���%d��ʣ�ྭ�飺%d\n",player->lev,player->exp); 
		player->atk +=ascending_series*1;
	}
}
void go_angling(struct Player *player,struct Item *item){

		int  random_number; 
		int  fish=1;
		random_number=rand()%100+1;
		if(0<=random_number&&random_number<30){
			printf("������ͨ����\n");
			//player->bag_1[20] = {"Fish"};
			//char fish[20]="Fish";
			struct Item fish = crate_item("Fish",1);
				   Item_Pickup(player,&fish); 
		}else if(30<=random_number&&random_number<50){
			printf("�����ƽ�����\n");
			struct Item gold_fish = crate_item("Gold-Fish",1);
				   Item_Pickup(player,&gold_fish); 
		}else{
			printf("��ʲôҲû����\n");
		}
} 
//�������� 
void Map_cell_1(){
	printf("�������ƹݣ��ƹ����������У����ַǷ��������������һ�ã�����ɫɫ�Ĺ����ڴ����ݡ�");
	Sleep(1000); 
	printf("һյҡҷ�ĵ���������ů�Ĺ�â��Ϊ������ֵĳ��������˼������������ء�\n");
	Sleep(1000); 
	printf("��ѡ��: 1:�鿴���� 2����һ�� 3���Է�\n");
	int choose; 
	scanf("%d",&choose);
	switch(choose){
		case 1:printf("ľ�����Σ��¾�ȴ�ɾ���ǽ�Ϲ����˸�ʽ�����ĹҼ�����˸�����µĹ�ԡ�\n����ĺ��Ӿٱ�ʹ������ȵ�Ů���Ღ���ң�����ʫ�˵�����˵���մ��档\n");break;
		case 2:break;
		case 3:break;
		default:break;
	}
	
}
void Map_cell_2(struct Player *player,struct Item *item){
	
	printf("�����Ǵ�ׯ��ĸ�׺�(ĸϪ��)\n");
	Sleep(1000); 
	printf("���߽�������ˮ�����Ĵ��Ű��ߵ�ʯͷ��ˮ�е���Ծ��ˮ�棬��������ͬ��Ȼ�Ľ����֣���������\n");
	srand((unsigned int)time(NULL));
	while(1){
	printf(" 1:���� �������뿪\n");
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
	printf("����һ����͵Ĵ�ׯ�����������������Ѿ�\n");
	printf("�Ƿ���룺1���ǣ�2����\n");
	int choose;
	scanf("%d",&choose);
	if(choose==1){
		 state->state_1=1; 
	} else if(choose==2){
		
	} else{
		printf("�������\n");
	}
}
void Map_cell_5_1 (){
	printf("");
}
void Map_cell_8(struct Player *player)
{

	  printf("���Ǵ��Ӷ��ߵ�С���֣���һֻʷ��ķ�����еĳ��Ų�\n");
	  Sleep(1000);
	  printf("1��������2����֮����\n");
	  int choose;
	  scanf("%d",&choose);
	 struct Enemy slime = create_enemy(6,1,"ʷ��ķ","���������ʴ��Һ");
	  switch(choose){
	  	case 1:Plater_fight_enemy(player,&slime);break;
	  	case 2:printf("����������\n");break;
	  }
	//printf("���Ǵ��Ӷ��ߵ�С���֣����ﾲ���ĵģ�ʲôҲû��\n");
}
void Map_cell_6(struct Player *player){
	printf("������һ��Ƭ�����ɫ��������ͬһƬ���ɫ�ĺ�����е��������\n");
	Sleep(2000);
	printf("��ֵ�＾��ũ�����ڷ����С�\n") ;
	printf("  1:����ũ���ո�ũ���� 2���뿪\n");
	int choose;
	scanf("%d",&choose);
	int money=1;
	switch(choose){
		case 1:
			printf("ũ���Ǻܸ�л�㣬������һЩǮ\n");
		    printf("������100ͭ��\n");
		    player->money += money;
		    break;
		case 2:
			break; 
	}
}
void Map_cell_4(){
	printf("���ֵļ���\n");
}
void Map_cell_9(){
	printf("������һƬ��ԭ\n");
	printf("1��������������2������ԭ������\n");
	int choose,choose_1;
	scanf("%d",&choose);
	if(choose==1){
		printf("�㱻һȺʷ��ķ������\n");
		printf("1��ֱ��Ӳ��2�����·��Ӵ~\n");
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
	//printf("������Ҫ�鿴������������ţ�");
	//printf("����1�ϣ�2����3����4"); 
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
		default: printf("����ʲôҲû��Ŷ~\n");
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

