/*
 * Copyright (C) wificar, Inc.
 * ���ߺ����⹦��ʵ��
 * @author txf
 * date 2020-04-12 12:12:12
 */
#include "util.h"
#include "intrins.h"

unsigned char code dofly_DuanMa[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};// ��ʾ����ֵ0~9

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