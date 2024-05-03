#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/fs.h>
#include <sys/types.h>
#include <unistd.h>
#include <ext2fs/ext2_fs.h>
//#include "ext2_fs.h"
int main(int argc, char *argv[]) {
	int fd;
	int count, ngroups, i;
	struct ext2_super_block sb; 
	struct ext2_group_desc bgdesc[1024];

        fd = open(argv[1], O_RDONLY); // argv[1] = /dev/sdb1 
	if(fd == -1) {
		perror("readsuper:");
		exit(errno);
	}

	lseek(fd, 1024, SEEK_CUR);
	printf("size of super block = %lu\n", sizeof(struct ext2_super_block));
	count = read(fd, &sb, sizeof(struct ext2_super_block));
	printf("Magic: %x\n", sb.s_magic);
	printf("Inodes Count: %d\n", sb.s_inodes_count);
	printf("block size entry: %d\n", sb.s_log_block_size);
	printf("size of BG DESC = %lu\n", sizeof(struct ext2_group_desc));

	ngroups = sb.s_blocks_count / sb.s_blocks_per_group;
	lseek(fd, 1024 + 1024 << sb.s_log_block_size, SEEK_SET);
	count = read(fd, bgdesc, sizeof(struct ext2_group_desc) * ngroups );
	for(i = 0; i < ngroups; i++)
		printf("%d): Inode Table: %d\n", i, bgdesc[i].bg_inode_table); 
	close(fd); 
}
