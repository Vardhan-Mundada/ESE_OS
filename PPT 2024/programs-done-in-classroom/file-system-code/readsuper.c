#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/fs.h>
//#include <linux/ext2_fs.h>
#include "ext2_fs.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY); // argv[1] = /dev/sdb1 
	int count;
	struct ext2_super_block sb; 
	struct ext2_group_desc bgdesc;
	if(fd == -1) {
		perror("readsuper:");
		exit(errno);
	}
	lseek(fd, 1024, SEEK_CUR);
	printf("size of super block = %lu\n", sizeof(struct ext2_super_block));
	count = read(fd, &sb, sizeof(struct ext2_super_block));
	printf("Magic: %x\n", sb.s_magic);
	printf("Inodes Count: %d\n", sb.s_inodes_count);
	printf("size of BG DESC = %lu\n", sizeof(struct ext2_group_desc));
	lseek(fd, 4096, SEEK_SET);
	count = read(fd, &bgdesc, sizeof(struct ext2_group_desc));
	printf("Inode Table: %d\n", bgdesc.bg_inode_table); 
	close(fd); 
}
