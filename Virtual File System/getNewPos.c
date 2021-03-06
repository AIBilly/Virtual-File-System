	//
	//  getNewPos.c
	//  Virtual File System
	//
	//  Created by ئ‍ارسلان ئابلىكىم on 4/6/16.
	//  Copyright © 2016 BUPT. All rights reserved.
	//

#include "getNewPos.h"
int getNewPos(bool ifdir){
	fseek(vfs, 0, SEEK_SET);
	int lastpos;
	fread(&lastpos, sizeof(int), 1, vfs);
	if (ifdir){
		lastpos += sizeof(dir);
		fseek(vfs, 0, SEEK_SET);
		fwrite(&lastpos, sizeof(int), 1, vfs);
		return lastpos - sizeof(dir);
	}else{
		lastpos += sizeof(vfile);
		fseek(vfs, 0, SEEK_SET);
		fwrite(&lastpos, sizeof(int), 1, vfs);
		return lastpos - sizeof(vfile);
	}
}