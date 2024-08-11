/**
* Copyright (C) wificar, Inc.
* 主驱动控制程序，包含数字信号，模拟信号之间转换 波特率之间解陆饴虢饴
* @author txf
* @date 2020-04-12 12:12:12
*/
#include<reg52.h> //包含头文件，一般情况不需要改动，头文件包含特殊功能寄存器的定义
#include "util.h"
#include <math.h>
sbit Trig  = P3^4; //雷达产生脉冲引脚
sbit Echo  = P3^5; //接收雷达回波引脚
sbit p1 = P1^0;
sbit p2 = P1^1;
uint switch_action = -1;
/*****************声明函数开始***************/

void init_com_port ( void );
void drive_execute(uchar temp);
/*****************声明函数结束***************/
//*****************程序入口***************************************

void init_com_port ( void ) {
	SCON = 0x50;	/*SCON:work mode 1,8-bit UART E:receive */
    TMOD |= 0x20;	/*TMOD time 1,mode 2 , 8-bit reload*/
   // PCON = 0x00;
  	TH1 = 0xFd;    /*TH1: reload value for 9600 baud @ 11.0592MHZ 波特率*/
  	//TL1 = 0xFd;
  	TR1 = 1;		/*TR1 time 1 run*/
  	EA = 1;  /*open Headquarters suspend*/
	ES = 1;  /*open com port suspend*/	
	//IT0=0;
	//EX0=1; 
}

/*********************外部中断0初始化**********************/
void ex_init( void ) {
	IT0 = 1;//指定外部中断0下降沿触发，INT0 (P3.2
	EX0 = 1;//使能外部中断
	EA = 1; //开总中断
}

/********************定时器0初始化*************/
void tim_init( void ) {
	TMOD = 0X02;//定时器0工作方式2，TH0是重装值，TL0是初值
	TH0=0x00; //重载值
	TL0=0x00; //初始化值
	ET0=1;    //开中断
  	TR0=1; 
}

// 串口中断程序
void com_port ( void ) interrupt 4 {
	unsigned char temp;
	if(RI) {
		RI = 0;/*RI: flag reset*/
		temp = SBUF; /*receive value*/
		drive_execute(temp); 
	}
}

void main ( void ) {
	uint index = 0;
	init_com_port();
	while (1) {
		if(0 == switch_action){
			p1 = 0;
			delay(18);
			p1 = 1;	
			delay(2);
		}else if(1 == switch_action){
			p1 = 0;
			delay(19);
			p1 = 1;	
			delay(1);
		}else if(2 == switch_action){
			p2 = 0;
			delay(18);
			p2 = 1;	
			delay(2);
		}else if(3 == switch_action){
			p2 = 0;
			delay(18.5);
			p2 = 1;	
			delay(1.5);
		}
		if(-1 != switch_action){
			index++;
		}
		if(300<index) {
			switch_action = -1;
			index = 0 ;
		}
		p1 = 0;
		p2 = 0;
	}		
}

void drive_execute (uchar direction) {
	P0 = direction;
	switch(direction){
		case 'a':
			P2 = 0X96;
			delay(1000);
			P2 = 0X00;
		break;
		case 'c':
			P2 = 0X90;
			delay(1000);
			P2 = 0X00;
		break;
		case 'd':
			P2 = 0X06;
			delay(1000);
			P2 = 0X00;
		break;
		case 'b':
			P2 = 0X69;
			delay(1000);
			P2 = 0X00;
		break;
		case 'e':
			switch_action = 2;
			delay(10);
		break;
		case '2':
			switch_action = 3;
			delay(10);
		break;
		case '1':
			switch_action = 0;
			delay(10);
		break;
		case '3':
			switch_action = 1;
			delay(10);
		break;
	}
	P0 = 0XFF;
}





