#ifndef _LGFUNC_H_
#define _LGFUNC_H_

#define U_LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define U_LISTINCEREMENT 1  //线性表存储空间的分配增量

typedef struct USER
{
	char name[12];//账户 
	char code[12];//密码
}USER;

/*******************************************************************/
typedef struct UserList
{
	struct USER* elem;    //存储空间基值
	int length;  //当前长度
	int listsize;  //当前分配存储空间容量
}UserList;//用户线性表 


/*建立一个空表*/
void InitUList(UserList*UL);

/*在线性表UL的末尾插入新的元素e*/
void UListInsert(UserList*UL,struct USER e);

/*删除元素*/
void UListDelete(UserList*L,int i);


/*若线性表L存在，销毁线性表*/
void DestroyUList(UserList*UL);	

/*返回元素e在线性表中的位置*/
int Userposition(UserList UL,USER e);

//显示光标
void show_gb(int x,int y);
//得到显示信息
void Getinfo(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1);
//得到密码
void Getcode(int x1,int y1,char *code,int num,int a1,int b1,int c1,int d1);

/***从存有用户数据的文件中逐个读取并与形参对比***/
int Check_info(struct UserList UL,char *name,char *code);

//保存用户信息
int save_user(USER temp);

void ReadAllUser(UserList *UL);

void UpdataUser(USER user);


#endif
