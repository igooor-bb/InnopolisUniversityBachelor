#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    /*
    for (int i = 0; i < 3; i += 1) {
        fork();
    }
    */
    for (int i = 0; i < 5; i += 1) {
        fork();
    }
    sleep(3);

    return 0;
}

/*
Running forks 3 times gives 2^3 = 8 instances of a process.
\-+= 09960 igooor_bb /bin/zsh -l
 |     |-+= 14070 igooor_bb ./ex2
 |     | |-+- 14075 igooor_bb ./ex2
 |     | | |-+- 14078 igooor_bb ./ex2
 |     | | | \--- 14081 igooor_bb ./ex2
 |     | | \--- 14079 igooor_bb ./ex2
 |     | |-+- 14077 igooor_bb ./ex2
 |     | | \--- 14082 igooor_bb ./ex2
 |     | \--- 14080 igooor_bb ./ex2
 |     \-+= 14110 igooor_bb pstree
 |       \--- 14111 root ps -axwwo user,pid,ppid,pgid,command
*/

/*
Running forks 5 times gives 2^5 = 32 instances of a process.
|   \-+= 09960 igooor_bb /bin/zsh -l
 |     |-+= 14228 igooor_bb ./ex2
 |     | |-+- 14244 igooor_bb ./ex2
 |     | | |-+- 14247 igooor_bb ./ex2
 |     | | | |-+- 14254 igooor_bb ./ex2
 |     | | | | |-+- 14262 igooor_bb ./ex2
 |     | | | | | \--- 14274 igooor_bb ./ex2
 |     | | | | \--- 14272 igooor_bb ./ex2
 |     | | | |-+- 14260 igooor_bb ./ex2
 |     | | | | \--- 14273 igooor_bb ./ex2
 |     | | | \--- 14270 igooor_bb ./ex2
 |     | | |-+- 14250 igooor_bb ./ex2
 |     | | | |-+- 14258 igooor_bb ./ex2
 |     | | | | \--- 14271 igooor_bb ./ex2
 |     | | | \--- 14269 igooor_bb ./ex2
 |     | | |-+- 14255 igooor_bb ./ex2
 |     | | | \--- 14267 igooor_bb ./ex2
 |     | | \--- 14263 igooor_bb ./ex2
 |     | |-+- 14245 igooor_bb ./ex2
 |     | | |-+- 14249 igooor_bb ./ex2
 |     | | | |-+- 14256 igooor_bb ./ex2
 |     | | | | \--- 14268 igooor_bb ./ex2
 |     | | | \--- 14264 igooor_bb ./ex2
 |     | | |-+- 14253 igooor_bb ./ex2
 |     | | | \--- 14266 igooor_bb ./ex2
 |     | | \--- 14261 igooor_bb ./ex2
 |     | |-+- 14246 igooor_bb ./ex2
 |     | | |-+- 14252 igooor_bb ./ex2
 |     | | | \--- 14265 igooor_bb ./ex2
 |     | | \--- 14257 igooor_bb ./ex2
 |     | |-+- 14248 igooor_bb ./ex2
 |     | | \--- 14259 igooor_bb ./ex2
 |     | \--- 14251 igooor_bb ./ex2
 |     \-+= 14292 igooor_bb pstree
 |       \--- 14293 root ps -axwwo user,pid,ppid,pgid,command
*/