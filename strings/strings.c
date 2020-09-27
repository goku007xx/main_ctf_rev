#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	setbuf(stdout,NULL);
	setbuf(stdin,NULL);
	setbuf(stderr,NULL);

	int no1=0;
	int no2=1;

	char *xor=   "ZUB*aVrOUsCPS;$R=Q";
	char *secret="!8u)05/>!#,.W/%H-G";
	//char *initial="tb_kfT`LRv|ml|wl|z";

	printf("Use this as ur input:  %s\n",secret);

	char buf[18];
	scanf("%[^\n]%*c",buf);


	char final[19]="";

	for(int y=0 , z=1 ; y<strlen(buf) , z<strlen(xor) ; y+=2 , z+=2 )
	{
		final[no1]=buf[y] ^ xor[z];
		no1+=2;
	}

	for(int o=1 , p=0 ; o<strlen(buf) , p<strlen(xor) ; o+=2 , p+=2 )
	{
		final[no2]=buf[o] ^ xor[p];
		no2+=2;
	}

	int len=strlen(final);
	int mid = len/2;
	int q;
	char pt1[20];
	char pt2[20];

	for(q = 0; q < mid; q++) {
        pt1[q]= final[q];
    }
    pt1[q] = '\0';

    for(int w = mid, e = 0; w <= len; w++, e++) 
    {
 		pt2[e]= final[w];
    }	

// FUCNTION 1

	char str1[10]="";
	int no=3;

	for(int i=0;i<9;i++)
	{
		str1[i]+=(char)((((int)*(pt1+i)+no) - (int)('a')) % 26 + (int)('a'));
		no+=3;
	}

// FUCNTION 2

	char str2[10]="";

	for(int j=0;j<9;j++)
	{
		str2[j]+=(char)((int)('z')-(int)(pt2[j]) + (int)('a'));
	}

// FUCNTION 3

	char str3[19]="";
	for (int k = 0, l = 8 ; k < 9, l >= 0  ; k++ , l-- ) 
	{
		strncat(str3,&str1[k],1);
		strncat(str3,&str2[l],1);
	}
	
	return 0;
}