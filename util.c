/*
 * Copyright (C) wificar, Inc.
 * 工具函数库功能实现
 * @author txf
 * date 2020-04-12 12:12:12
 */
#include "intrins.h"

#define uchar unsigned char 
#define uint unsigned int


static struct modal {
	int time;
	int clock;
};

void delay(uint b){
	uint i = 0,j = 0;
	for(i=0; i < b; i++) {
		for(j=0;j<111;j++);
	}
}