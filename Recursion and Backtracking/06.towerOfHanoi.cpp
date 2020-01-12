unsigned long long int l=0;

void towerOfHanoi(int n, char source, char destination, char media)
{
    if(n==0) return;
    towerOfHanoi(n-1,source,media,destination);
    cout << ++l << ". Move disk " << n << " " << source << " to " << destination << endl;
    towerOfHanoi(n-1,media,destination,source);
}
/*
*
* 1.....(3,'A','C','B')
* 12....print: 4. Move Disk 3 A to C
* 13....(2,'B','C','A')
*    14.....(1,'B','A','C')
*        15.....(0) return;
*        16......print 5. Move Disk 1 B to A
*        17.....(0) return;
*    18.....print: 6. Move Disk 2 B to C
*    19.....(1,'C','A','B')
*        20.....(0) return;
*        20.....print: 7. Move Disk 1 C to A
*        21.....(0) return;
*
* 2.....(2,'A','B','C')
*    7......print: 2. Move Disk 2 A to B
*    8......(1,'C','B','A')
*        9......(0) return;
*        10.....print: 3. Move Disk 1 C to B
*        11.....(0) return;
*
* 3.....(1,'A','C','B')
*    5.....print: 1. Move Disk 1 A to C
*    6.....(0) return;
*
* 4.....(0) return;
*
*/
